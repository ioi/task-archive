#include <bits/stdc++.h>
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


using pii = pair<int, int>;

#define all(x) x.begin(), x.end()

#include "ballmachine.h"

// s = 1000 solution
struct result {
  vector<int> path_par, dep, path_len;
};

result s_1000(vector<int> l) {
  int m = l.size();
  result res = {
    vector<int>(m),
    vector<int>(m),
    vector<int>(m),
  };
  for(int i = 0; i < m; i++) {
    while(insert(l[i], m - 1 - i)) {
      res.path_len[i]++;
    }
  }
  auto ord = collect();

  // last occurrence of each value is a leaf
  vector<bool> seen(m), leaf(ord.size());
  for(int i = ord.size() - 1; i >= 0; i--) {
    if(!seen[ord[i]]) {
      leaf[i] = true;
      seen[ord[i]] = true;
    }
  }

  vector<pii> edges;
  int i = 0;
  function<void()> recur = [&]() {
    int rt = i;
    i++;
    while(i < ord.size() && ord[i] <= ord[rt]) {
      // add 10000 to avoid collisions with leaves
      if(ord[rt] != ord[i]) {
        res.path_par[m - 1 - ord[i]] = m - 1 - ord[rt];
      }
      if(!leaf[i]) {
        edges.push_back({i + 10000, rt + 10000});
        recur();
      } else {
        edges.push_back({m - 1 - ord[i], rt + 10000});
        i++;
      }
    }
  };
  recur();

  map<int, int> dep;
  dep[10000] = 0;
  for(auto [c, p] : edges) {
    dep[c] = dep[p] + 1;
  }
  for(int i = 0; i < m; i++) {
    res.dep[i] = dep[i];
  }
  return res;
}

vector< int > find_structure(int m) {
  int b = 21, c = 13;
  vector<int> path_par(m); // parent of path
  vector<int> dep(m); // depth of node
  vector<int> path_len(m);

  // solve first b + c leaves directly
  vector<int> first_bc(min(b + c, m));
  iota(all(first_bc), 0);
  auto res = s_1000(first_bc);
  for(int i = 0; i < first_bc.size(); i++) {
    path_par[i] = res.path_par[i];
    dep[i] = res.dep[i];
    path_len[i] = res.path_len[i];
  }

  for(int i = b + c; i < m; i += b) {
    for(int o = 1; o < i; o *= c) {
      // insert labels for paths in X
      for(int j = 0; j < i; j++) {
        while(insert(j, b + j / o % c));
      }
      // insert labels for paths in Y
      for(int j = i; j < min(m, i + b); j++) {
        path_len[j] = 0;
        while(insert(j, b - 1 - (j - i))) {
          path_len[j]++;
        }
      }

      auto ord = collect();

      // find parent of each path using a similar recursive algorithm to s = 1000
      int j = 0;
      function<void()> recur = [&]() {
        int rt = j;
        j++;
        while(j < ord.size() && ord[j] <= ord[rt]) {
          if(ord[j] != ord[rt] && ord[j] < b) {
            if(ord[rt] < b) {
              path_par[i + b - 1 - ord[j]] = i + b - 1 - ord[rt];
            } else {
              path_par[i + b - 1 - ord[j]] += (ord[rt] - b) * o;
            }
          }
          recur();
        }
      };
      while(j + 1 < ord.size()) {
        // if this node has a child with a B-label, then descend into its subtree
        if(ord[j + 1] < b) {
          recur();
        } else {
          j++;
        }
      }
    }
  }

  // find depths in batches of size b + c
  for(int i = b + c; i < m; i += b + c) {
    vector<int> inds(min(b + c, m - i));
    iota(all(inds), i);
    auto deps = s_1000(inds).dep;
    for(int j = 0; j < inds.size(); j++) {
      dep[i + j] = deps[j];
    }
  }

  // reconstruct tree
  map<int, int> ans; // map of child -> parent edges
  int cur = 10000;
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

    
  vector<int> dist;
  for (auto [x, y] : ans) {
    dist.push_back(x);
    dist.push_back(y);
  }

  sort(dist.begin(), dist.end());
  dist.erase(unique(dist.begin(), dist.end()), dist.end());
  
  vector<pair<int, int>> RR;
  for(auto [x, y] : ans) {
    int u = lower_bound(dist.begin(), dist.end(), x) - dist.begin();
    int p = lower_bound(dist.begin(), dist.end(), y) - dist.begin();
    RR.push_back({u, p});
  }

  return convert_edges_to_parents( RR );

  // return vector<pii>(all(ans));
}
