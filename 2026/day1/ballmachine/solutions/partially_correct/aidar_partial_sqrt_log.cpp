#include <bits/stdc++.h>
using namespace std;

#include "ballmachine.h"

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


const int MAXN = 1005;

int TOT_COLLECT = 0;

void find_depth(int l, int r, vector<int>& dep, vector<int>& par, vector<int>& path_len) {
	for (int i = l; i <= r; i++) {
		int value = r - i; 
		
		path_len[i] = 0; 
		while(insert(i, value)) { path_len[i]++; }
	}

	vector<int> ord = collect(); 
	TOT_COLLECT++;

	vector<int> last = {r - l + 1}; 
	for (auto x : ord) {
		if (x > last.back()) {
			int u = r - last.back();
			dep[u] = (int)last.size() - 1;

			while (x > last.back()) {
				last.pop_back(); 
			}
		}

		if (x < last.back()) {
			par[r - x] = r - last.back(); 
		} 
		last.push_back(x); 
	}

	dep[l] = (int)last.size() - 1;
}

vector< int > find_structure(int m) {
	// int b = 3, c = 2, d = 1;
	int b = 22, c = 5; 

	vector<int> dep(m), path_par(m), path_len(m); 

	{
		int B = b + c; 
		for (int i = 0; i < m; i += B) {
			int l = i, r = min(i + B, m) - 1;
			find_depth(l, r, dep, path_par, path_len); 
		}
	}

	// for (int i = 0; i < m; i++) {
	// 	cerr << dep[i] << " ";
	// } cerr << "\n";

	// for (int i = 0; i < m; i++) {
	// 	cerr << path_par[i] << " ";
	// } cerr << "\n";

	// for (int i = 0; i < m; i++) {
	// 	cerr << path_len[i] << " ";
	// } cerr << "\n";

	for (int i = m - b; ; i -= b) {
		int l = i, r = i + b - 1;
		
		if (r < b + c) {
			break;
		}

		for (int j = l; j <= r; j++) {
			path_par[j] = 0; 
		}

		for (int q = 1; q < i; q *= c) {
			for (int j = 0; j < i; j++) {
				int value = (j / q) % c;

				while (insert(j, value + b)) { }
			}

			for (int j = l; j <= r; j++) {
				path_len[j] = 0; 
				while (insert(j, r - j)) { path_len[j]++; }
			}

			vector<int> ord = collect(); 
			TOT_COLLECT++;

            vector<int> last = { b + c }; 

			vector<int> used(b); 
            for (int j = 0; j < (int)ord.size(); j++) {
                while (last.back() <= ord[j]) {
                    last.pop_back();
                }
                int par_c = last.back();
                last.push_back(ord[j]);

                if (!j) continue;

                if (ord[j] < b && !used[ord[j]]) {
					used[ord[j]] = 1;

                    int u =  r - ord[j];
                    if (par_c < b) {
                        int v = r - par_c;
						path_par[u] = v; 
                    } else {
						path_par[u] += (par_c - b) * q; 
                    }
                }
            }

		}
	}

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

	// int S = b + c + d - 1 + TOT_COLLECT;
	// cerr << " --- K = " << b + c + d - 1 << "  Q = " << TOT_COLLECT << " --- \n";
	// cerr << " --- S = " << S << " --- \n";

    return convert_edges_to_parents( res ); 
}
