#include "ballmachine.h"
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

// run s = 1000 solution to find depth of a batch of nodes
vector<int> find_depths(vector<int> l) {
  for(int i = l.size() - 1; i >= 0; i--) {
    while(insert(l[i], i));
  }
  auto ord = collect();

  // last occurrence of each value is a leaf
  vector<bool> seen(l.size()), leaf(ord.size());
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
      if(!leaf[i]) {
        edges.push_back({i + 10000, rt + 10000});
        recur();
      } else {
        edges.push_back({ord[i], rt + 10000});
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
  vector<int> ans(l.size());
  for(int i = 0; i < l.size(); i++) {
    ans[i] = dep[i];
  }
  return ans;
}

vector< int > find_structure(int m) {
  int b = 15, c = 15;
  vector<int> path_par(m); // parent of path
  vector<int> dep(m); // depth of node
  vector<int> path_len(m);

  for(int i = 0; i < m; i += b) {
    for(int o = 1; o < m; o *= c) {
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

    // find depths of nodes in this batch
    vector<int> inds(min(b, m - i));
    iota(all(inds), i);
    auto deps = find_depths(inds);
    for(int j = 0; j < inds.size(); j++) {
      dep[i + j] = deps[j];
    }
  }

  // for (int i = 0; i < m; i++) {
  //   cout << path_len[i] << " ";
  // } cout << endl; 

  // for (int i = 0; i < m; i++) {
  //   cout << dep[i] << " ";
  // } cout << endl; 

  // for (int i = 0; i < m; i++) {
  //   cout << path_par[i] << " ";
  // } cout << endl; 

  // reconstruct tree
  map<int, int> ans; // map of child -> parent edges
  int cur = 10000;
  for(int i = 0; i < m; i++) {
    // construct vertical path
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
      // walk up from path path's leaf to find connection point
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
  
  vector<pair<int, int>> res;
  for(auto [x, y] : ans) {
    int u = lower_bound(dist.begin(), dist.end(), x) - dist.begin();
    int p = lower_bound(dist.begin(), dist.end(), y) - dist.begin();
    res.push_back({u, p});
  }

  // for (auto [x, y] : res) {
  //   cout << x << " " << y << "\n";
  // }

  // for (auto [x, y] : res) {
  //   cout << x << " "<< y <<endl;
  // }

  return convert_edges_to_parents( res );
  // return vector<pair<int, int>>(ans.begin(), ans.end());
}
