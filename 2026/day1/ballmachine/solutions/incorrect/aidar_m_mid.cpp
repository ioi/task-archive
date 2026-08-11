#include "bits/stdc++.h"

#include "ballmachine.h"

using namespace std;
const int MAXN = 5005;

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

vector<int> find_structure(int m) {
    vector<int> d(m); 
    vector<vector<int>> dlca(m, vector<int>(m)); 

    while (insert(0, 0)) {
        d[0]++;
    } collect();

    for (int i = 0, j = 1; j < m; j++) {
        while (insert(j, 0)) {
            d[j]++;
        }

        int tot = d[j];
        while (insert(i, 0)) {
            tot++;
        }

        collect(); 

        dlca[i][j] = dlca[j][i] = d[i] + d[j] - tot; 
    }

    for (int i = 1; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            int tot = 0;
            while (insert(i, 0)) {
                tot++;
            }

            while (insert(j, 0)) {
                tot++;
            }

            collect(); 

            int _dlca = d[i] + d[j] - tot;
            dlca[i][j] = dlca[j][i] = _dlca; 
        }
    }

    vector<int> par(m); 

    function<void(int, vector<int>)> dfs = [&](int u, vector<int> sub) {
        map<int, int> vis; 

        for (int _i = 0; _i < (int)sub.size(); _i ++) {

            int x = sub[_i]; 
            if (vis[x]) continue;

            vector<int> child; 
            child.push_back(x); 
            vis[x] = 1; 

            for (int _j = _i + 1; _j < (int)sub.size(); _j++ ) {
                int y = sub[_j]; 
                if (dlca[x][y] != d[u]) {
                    child.push_back(y); 
                    vis[y] = 1;
                }
            }

            if ((int)child.size() == 1 && d[u] + 1 == d[x]) {
                par[x] = u; 
                continue;
            }

            par.push_back(u);
            d.push_back(d[u] + 1); 
            
            dfs(m++, child); 
        }
    }; 

    vector<int> leaves(m);
    iota(leaves.begin(), leaves.end(), 0); 

    par.push_back(-1);
    d.push_back(1); 
    dfs(m++, leaves); 

    vector<pair<int, int>> result;

    for (int i = 0; i < m; i++) {
        if (par[i] == -1) continue;
        result.push_back(make_pair( i, par[i] )); 
    }

    return convert_edges_to_parents( result ); 
}

