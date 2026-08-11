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


vector< int > find_structure(int m) {
    vector<int> d(m); 
    
    for (int i = 0; i < m; i++) {
        while (insert(i, 0)) {
            d[i]++;
        }

        collect(); 
    }

    auto find_lca_dep = [&](int i ,int j) {
        int tot = 0;
        while (insert(i, 0)) {
            tot++;
        }

        while (insert(j, 0)) {
            tot++;
        } 

        collect(); 

        int _dlca = d[i] + d[j] - tot;

        return _dlca; 
    }; 

    int cur = m;

    auto make_path = [&](int st, int len) -> pair<int, vector<pair<int, int>> > {
        vector<pair<int, int>> path; 

        if (len == 1) {
            return make_pair(st, path);
        } if (len == 2) {
            path.push_back({st, cur}); 
            cur++;
            return make_pair(cur - 1, path); 
        } 

        path.push_back({st, cur});
        for (int i = 1; i + 1 < len; i++) {
            path.push_back({cur, cur + 1});
            cur++;
        }

        cur++;
        return make_pair(cur - 1, path); 
    };

    auto insert_paths = [&](vector<pair<int, int>>& v1, vector< vector<pair<int, int>> > v2) {
        for (auto v : v2) {
            v1.insert(v1.end(), v.begin(), v.end());
        }

        return v1; 
    };

    vector<int> par;

    if (m == 1) {
        auto [end, path] = make_path(0, d[0]);
        return convert_edges_to_parents( path ); 
    } else {
        int d01 = find_lca_dep(0, 1);

        if (m == 2) {
            auto [end1, path1] = make_path(0, d[0] - d01);
            auto [end2, path2] = make_path(1, d[1] - d01); 

            vector<pair<int, int>> res; 
            res.push_back({end1, cur}); 
            res.push_back({end2, cur}); 
            cur++; 

            auto [root, path3] = make_path(cur - 1, d01); 
            insert_paths(res, {path1, path2, path3});

            // for (auto [x, y] : res) {
            //     cerr << x << " " << y << endl;
            // }

            return convert_edges_to_parents( res );
        } else {
            int d02 = find_lca_dep(0, 2);
            int d12 = find_lca_dep(1, 2);

            vector<int> p = {0, 1, 2}; 
            if (d01 > d02 && d01 > d12) {
                p = {2, 0, 1};
            } else if(d02 > d01 && d02 > d12) {
                p = {1, 0, 2}; 
            }

            int mn = min({d01, d02, d12}); 
            int mx = max({d01, d02, d12}); 

            vector<pair<int, int>> res;

            auto [end1, path1] = make_path(p[0], d[p[0]] - mn); 
            auto [end2, path2] = make_path(p[1], d[p[1]] - mx); 
            auto [end3, path3] = make_path(p[2], d[p[2]] - mx); 

            insert_paths(res, {path1, path2, path3});

            if (mn == mx) {
                res.push_back({end1, cur});
                res.push_back({end2, cur});
                res.push_back({end3, cur});
                cur++;

                auto [end4, path4] = make_path(cur - 1, mn); 
                
                insert_paths(res, {path4});
            } else {
                res.push_back({end2, cur}); 
                res.push_back({end3, cur}); 
                cur++;

                auto [end4, path4] = make_path(cur - 1, mx - mn); 

                res.push_back({end1, cur});
                res.push_back({end4, cur}); 
                cur++;

                auto [end5, path5] = make_path(cur - 1, mn); 

                insert_paths(res, {path4, path5}); 
            }

            return convert_edges_to_parents( res );
        }
    }

}
