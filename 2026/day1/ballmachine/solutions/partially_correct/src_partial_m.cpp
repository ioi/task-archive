#include "ballmachine.h"

#include "bits/stdc++.h"
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
  // cout << "ans:\n";

  vector<int> path_par(m, -1); // parent of path
  vector<int> dep(m); // depth of node
  vector<int> path_len(m);

  // query all suffixes
  for(int i = 0; i < m; i++) {
    vector<int> count(m);
    for(int j = i; j < m; j++) {
      while(insert(j, 0)) {
        count[j]++;
      }
    }
    if(i == 0) path_len = count;

    // save depth of leaf i
    dep[i] = count[i];

    // find discrepancies with expected path lengths
    for(int j = i; j < m; j++) {
      if(path_par[j] == -1 && count[j] != path_len[j]) {
        path_par[j] = i - 1;
      }
    }
    collect();
  }

  // for (int i = 0; i < m; i++) {
  //   cout << path_par[i] << " ";
  // }
  // cout << "\n";

  // reconstruct tree

  vector<int> ans(MAXN, -1); 

  int cur = m;
  for(int i = 0; i < m; i++) {
    int last = i;
    for(int _ = 1; _ < path_len[i]; _++) {
      ans[last] = cur;
      last = cur;
      cur++;
    }
    if(i) {
      // connect path to existing tree
      int leaf_dist = dep[path_par[i]] - (dep[i] - path_len[i]); // distance from leaf of parent path
      int parent = path_par[i];
      // walk up from leaf to find connection point
      for(int _ = 0; _ < leaf_dist; _++) {
        parent = ans[parent];
      }
      ans[last] = parent;
    }
  }
  
  vector<pair<int, int>> res;
  for (int i = 0; i < cur; i++) {
    int u = i;
    int p = ans[i]; 
    if (p != -1) res.push_back({i, ans[i]});
  }
  
  // for(auto [x, y] : ans) {
  //   int u = lower_bound(dist.begin(), dist.end(), x) - dist.begin();
  //   int p = lower_bound(dist.begin(), dist.end(), y) - dist.begin();
  //   res.push_back({u, p});
  // }

  // for (auto [x, y] : res) {
  //   cout << x << " "<< y <<endl;
  // }

  return convert_edges_to_parents( res );
  // return vector<pair<int, int>>(ans.begin(), ans.end());
}
