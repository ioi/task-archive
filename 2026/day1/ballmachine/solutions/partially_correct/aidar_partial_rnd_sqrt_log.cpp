#include "bits/stdc++.h"

#include "ballmachine.h"

using namespace std;
const int M = 200; 
const int MAXN = 1005;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline int rnd(int l, int r) { return uniform_int_distribution<int>(l, r)(rng); }

/*
argument:
    edges of the return tree

output:
    parent array of the same return tree structure, with root labeled N-1
*/
vector<int> convert_edges_to_parents(vector<pair<int, int>> edges) {
    int N = (int)edges.size() + 1;
    vector<int> par(N, -1); 

    for (int i = 0; i < N - 1; i++) {
        auto [U, P] = edges[i]; 
        assert(0 <= U < N && 0 <= P < N);
        assert(par[U] == -1); 
        par[U] = P; 
    }

    int root = N - 1;
    for (int i = 0; i < N; i++) {
        if (par[i] == -1) {
            root = i; 
        }
    }

    if (root != N - 1){ 
        par[root] = par[N - 1]; 
        par[N - 1] = -1;
        for (int i = 0; i < N; i++) {
            if (par[i] == root) {
                par[i] = N - 1; 
            } else if (par[i] == N - 1) {
                par[i] = root;
            }
        }
    }

    par.pop_back();
    return par; 
}


vector< int > find_structure(int m) {
    int b = 20, c = 20;

    vector< bitset<200> > possible(m); 

    vector< bitset<200> > single(m); 

    for (int i = 0; i < m; i++) {
        single[i][i] = 1;
    }

    vector<int> path_len(m), dep(m), path_par(m, -1); 

    for (int i = 0; i < m; i += b) {
        int r = min(i + b, m);

        vector<int> col(m); 

        for (int j = max(i, 1); j < r; j++) {
            for (int k = 0; k < r; k++) {
                possible[j][k] = 1;
            }
        }

        for (int j = 0; j < i; j++) {
            col[j] = j % c + b;
        }

        while (true) {
            vector< bitset<200> > mask(c); 

            shuffle(col.begin(), col.begin() + i, rng); 

            for (int j = 0; j < i; j++) {
                
                while (insert(j, col[j])) { }
                mask[col[j] - b][j] = 1;
            }

            for (int j = i; j < r; j++) {
                path_len[j] = 0;
                while (insert(j, b - (j - i) - 1)) { 
                    path_len[j]++; 
                }
            }

            vector<int> ord = collect(); 
            vector<int> last = { b + c }; 

            for (int j = 0; j < (int)ord.size(); j++) {
                while (last.back() <= ord[j]) {
                    last.pop_back();
                }
                int par_c = last.back();
                last.push_back(ord[j]);

                if (!j) continue;

                if (ord[j] < b) {
                    int u =  i + (b - ord[j] - 1);

                    if (par_c < b) {
                        int v = i + (b - par_c - 1);

                        // cerr << "par of " << u << " is " << v << "\n";

                        possible[u] &= single[v];
                    } else {
                        possible[u] &= mask[par_c - b];
                    }
                }
            }

            bool finish = true;
            for (int j = i; j < r; j++) {
                if (possible[j].count() > 1) {
                    finish = false; 
                }
            }

            if (finish) {
                break;
            }
        }

        for (int j = i; j < r; j++) {
            for (int k = 0; k < r; k++) {
                if (possible[j][k] == 1) {
                    path_par[j] = k; 
                }
            }
        }
    }

    int B = b + c;
    for (int i = 0; i < m; i += B) {
        int r = min(m, i + B); 
        for (int j = i; j < r; j++) {
            while (insert(j, B - (j - i) - 1)) {
            }
        }

        vector<int> ord = collect(); 

        // for (auto x : ord) {
        //     cerr << x << " ";
        // } cerr << "\n";

        vector<int> last = {B}; 
        for (auto x : ord) {
            if (x <= last.back()) {
                last.push_back(x); 
            } else {
                int u = i + (B - 1 - last.back());
                dep[u] = (int)last.size() - 1;

                while (x > last.back()) {
                    last.pop_back(); 
                }
                last.push_back(x); 
            }
        }

        dep[i] = (int)last.size() - 1;
    }

    // for (int i = 0; i < m; i++) {
    //     cerr << dep[i] << " ";
    // } cerr << "\n";

    // for (int i = 0; i < m; i++) {
    //     cerr << path_len[i] << " ";
    // } cerr << "\n";

    // for (int i = 0; i < m; i++) {
    //     cerr << path_par[i] << " ";
    // } cerr << "\n";

    vector<int> par(MAXN, -1); 
    int cur = m; 

    par[0] = cur; 
    for (int i = 1; i + 1 < path_len[0]; i++) {
        par[cur] = cur + 1;
        cur++;
    }
    cur++;


    for (int i = 1 ;i < m; i++) {
        int dep_link = dep[i] - path_len[i];

        int x = path_par[i];
        for (int j = 0; j < dep[ path_par[i] ] - dep_link; j++){
            x = par[x]; 
        }

        if (path_len[i] == 1) {
            par[i] = x;
            continue;
        }

        par[i] = cur; 
        for (int j = 1; j + 1 < path_len[i]; j++) {
            par[cur] = cur + 1;
            cur++;
        }

        par[cur] = x;
        cur++;
    }

    vector<pair<int, int>> res;

    for (int i = 0; i < cur; i++) {
        if (par[i] != -1) {
            res.push_back(make_pair(i, par[i]));
        }
    }

    // cerr << (int)res.size() << "\n";
    // for (auto [x, y] : res) {
    //     cerr << x << " " << y << "\n";
    // }

    return convert_edges_to_parents( res ); 
}

