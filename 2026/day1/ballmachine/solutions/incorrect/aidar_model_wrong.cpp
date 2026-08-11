#include "ballmachine.h"
#include "bits/stdc++.h"

using namespace std;


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
    
    vector<int> len(m); 
    vector<int> lp, sp; 
    int n = 0;

    for (int i = 0; i < m; i++) {
        while(insert(i, 0)) {
            len[i]++; 
            n++;
        }

        if (len[i] >= 2) {
            lp.push_back(i); 
        } else {
            sp.push_back(i); 
        }
    }

    collect();

    int ls = lp.size(); 
    int lg = sqrt(ls);
    if (lg * lg < ls) lg++; 
    vector< vector<int> > lp_id(lg, vector<int>(lg, -1)); 

    int ss = sp.size();
    int sg = sqrt(ss);
    if (sg * sg < ss) sg++;

    // answer
    vector<int> par(n, -1); 


    // dfs arguments
    vector<int> ord, single_path_map(1000); 
    int ord_id = 0; 
    int SINGLE_PATH = 0; 
    int vertex_cnt = m; 

    int case_ = 0;
    #define BUILDING_TREE   0
    #define ATTACH_LEAF     1

    function<int()> dfs = [&](){ 
        int u_x = ord[ord_id++]; 
        int u_y = 0; 
        int cur = vertex_cnt++; 
        int path_root = cur;

        vector< pair<int, int> > single_paths; 
        vector< int > path_mem = { cur };
        int dep = 0; 
        int first_mixed_dep = -1;
        bool has_long_child_here = false;

        while (true) {
            int x = ord[ord_id]; 

            if (x < lg) {
                // start of each path
                int v = dfs(); 
                has_long_child_here = true;

                if (case_ == BUILDING_TREE) {
                    par[v] = cur; 
                }
            } else if(x < SINGLE_PATH) {
                // the single vertex path case
                // only entered when the handling paths with a single vertex
                int v = single_path_map[x]; 

                if (case_ == ATTACH_LEAF) {
                    int leaf_dep = dep;
                    if (has_long_child_here) {
                        if (first_mixed_dep == -1) first_mixed_dep = dep;
                        leaf_dep = first_mixed_dep;
                    }
                    single_paths.push_back({leaf_dep, v}); 
                }
            } else if(x == SINGLE_PATH) {
                // child of u on a path (non-leaf)
                int old_cur = cur;

                cur = vertex_cnt++; 
                dep++;
                has_long_child_here = false;

                if (case_ == BUILDING_TREE) {
                    par[cur] = old_cur;
                }
            } else {
                // leaf of the path

                u_y = x - SINGLE_PATH - 1; 
                break;
            }

            ord_id++;
        }


        dep++;
        assert( lp_id[u_x][u_y] != -1 );
        int leaf = lp[ lp_id[u_x][u_y] ]; 
        if (case_ == BUILDING_TREE) {
            par[leaf] = cur;
        }

        // {
        //     cerr << "path start" << endl;
        //     int ver = leaf; 
        //     for (int k = 0; k <= len[ leaf ]; k++) {
        //         cerr << ver << " ";
        //         ver = par[ver]; 
        //     }
        //     cerr << endl;
        // }

        if (case_ == ATTACH_LEAF) {
            reverse(single_paths.begin(), single_paths.end()); 
            
            int v = leaf, j = 0; 
            for (int d = dep; d >= 0; d--) {
                while (j < (int)single_paths.size() && single_paths[j].first == d) {
                    int child_leaf = single_paths[j].second;

                    par[child_leaf] = v; 
                    j++;
                }

                v = par[v]; 
            }
        }

        return path_root;
    }; 

    vector< int > x(ls), y(ls); 
    {
        for (int i = 0; i < ls; i++) {
            x[i] = i / lg, y[i] = i % lg;
            lp_id[ x[i] ][ y[i] ] = i; 

            insert(lp[i], x[i]); 
            for (int j = 0; j < len[ lp[i] ] - 2; j++) insert(lp[i], lg); 
            insert(lp[i], lg + 1 + y[i]); 
        }

        ord = collect(); 
        ord_id = 0;
        SINGLE_PATH = lg;
        vertex_cnt = m;
        case_ = 0;

        // for (auto x : ord) {
        //     cerr << x << " "; 
        // } cerr << endl;

        dfs(); 
    }

    // for (int i = 0; i < n; i++) {
    //     cerr << i << " " << par[i] << endl;
    // } cerr << endl;

    {
        for (int i_ = 0; i_ < ss; i_ += sg) {
            int l = i_, r = min(ss, i_ + sg);
            SINGLE_PATH = lg + r - l; 

            for (int j = 0; j < ls; j++) {
                insert(lp[j], x[j]);

                for (int k = 0; k < len[ lp[j] ] - 2; k++) insert(lp[j], SINGLE_PATH);
                insert(lp[j], SINGLE_PATH + 1 + y[j]); 
            }

            for (int j = l; j < r; j++) {
                insert(sp[j], j - l + lg); 
                single_path_map[j - l + lg] = sp[j]; 
            }

            ord = collect(); 

            // for (auto x : ord) {
            //     cerr << x << " ";
            // } cerr << endl;

            ord_id = 0;
            vertex_cnt = m;
            case_ = 1;

            dfs();
        }
    }

    vector< pair<int, int> > res;
    for (int i = 0; i < n; i++) {
        if (par[i] != -1) {
            res.push_back( make_pair(i, par[i]) );
        }
    }

    return convert_edges_to_parents( res );
}