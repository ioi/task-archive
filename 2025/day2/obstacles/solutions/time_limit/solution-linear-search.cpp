// solution/solution-linear-search.cpp
// {
//   "verdict": "time_limit",
//   "except": {
//     "samples": "correct",
//     "n1": "correct",
//     "inc": "correct",
//     "fixed": "correct",
//     "fewq": "correct"
//   }
// }
// END HEADER
#include <algorithm>
#include <array>
#include <cassert>
#include <map>
#include <numeric>
#include <ranges>
#include <set>
#include <vector>
#include <iostream>
using namespace std;

#define to(n) (views::iota(0, n))
#define tos(s, n) (views::iota(s, n))
#define from(n) (views::iota(0, n) | views::reverse)

#define DBG(x) cout << #x << " = " << (x) << endl;
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) int((x).size())

const int inf = int(1e9 + 1e5);
const int LOG = 20;

struct RangeMinimumQuery {
  int n;
  vector<array<int, LOG>> v;

  RangeMinimumQuery() : n(-1) {
  }

  RangeMinimumQuery(const vector<int>& values) {
    n = SZ(values);
    v.resize(n);
    for (const int i : to(n))
      v[i][0] = values[i];
    for (const int l : to(LOG - 1))
      for (const int i : to(n))
        v[i][l + 1] = min(v[i][l], v[min(n - 1, i + (1 << l))][l]);
  }

  // The smallest value in the range [l, r)
  int range_minimum(const int l, const int r) const {
    assert(n != -1);
    assert(0 <= l && l <= r && r <= n);
    if (l == r)
      return inf;
    const int k = 31 - __builtin_clz(r - l);
    return min(v[l][k], v[r - (1 << k)][k]);
  }

  // The index of the first value in [i, n) less than val
  // n if it doesn't exist
  int first_less(int i, const int val) const {
    assert(n != -1);
    for (const int k : from(LOG))
      if (i + (1 << k) <= n && v[i][k] >= val)
        i += 1 << k;
    return i;
  }

  // The index of the last value in [0, i) less than val
  // -1 if it doesn't exist
  int last_less(int i, const int val) const {
    assert(n != -1);
    for (const int k : from(LOG))
      if (i >= (1 << k) && v[i - (1 << k)][k] >= val)
        i -= 1 << k;
    return i - 1;
  }
};

struct Connection {
  int l, r;
  int node;
};

Connection join(const Connection a, const Connection b) {
  return Connection{max(a.l, b.l), min(a.r, b.r), b.node};
}

struct Layer {
  int row;
  int l, r;
  int parent;
  int pl, pr;
};

vector<Connection> tree_info;
vector<int> depth;
vector<int> position_to_node;

vector<Layer> build_layers(const vector<int>& temperature,
                           const vector<int>& humidity) {
  const int n = SZ(temperature);
  const int m = SZ(humidity);

  vector<int> temperature_maxima = {0};
  for (const int i : tos(1, n))
    if (temperature[i] > temperature[temperature_maxima.back()])
      temperature_maxima.push_back(i);

  vector<int> ord(m);
  iota(ALL(ord), 0);
  sort(ALL(ord), [&](int i, int j) { return humidity[i] > humidity[j]; });

  auto humidity_inv = humidity;
  for (auto& i : humidity_inv)
    i *= -1;
  const auto humidity_rmq = RangeMinimumQuery(humidity);
  const auto humidity_inv_rmq = RangeMinimumQuery(humidity_inv);
  const auto temperature_rmq = RangeMinimumQuery(temperature);

  map<int, int> active_layers;
  vector<Layer> layers;
  for (const int i : temperature_maxima) {
    const int temp = temperature[i];
    vector<int> new_empty_cells;
    while (!ord.empty() && humidity[ord.back()] < temp) {
      new_empty_cells.push_back(ord.back());
      ord.pop_back();
    }

    set<pair<int, int>> new_ranges;
    for (const auto empty_cell : new_empty_cells) {
      assert(humidity[empty_cell] < temp);
      const int l = humidity_inv_rmq.last_less(empty_cell, 1 - temp);
      const int r = humidity_inv_rmq.first_less(empty_cell, 1 - temp);
      new_ranges.insert({l + 1, r});
    }

    for (const auto& [l, r] : new_ranges) {
      const int index = SZ(layers);
      while (true) {
        const auto it = active_layers.lower_bound(l);
        if (it == active_layers.end() || it->first >= r)
          break;

        auto& child = layers[it->second];
        const int min_temp = temperature_rmq.range_minimum(child.row, i + 1);
        if (min_temp > humidity_rmq.range_minimum(child.l, child.r))
          child.pl = humidity_rmq.first_less(child.l, min_temp),
          child.pr = humidity_rmq.last_less(child.r, min_temp),
          child.parent = index;

        active_layers.erase(it);
      }
      active_layers[l] = index;
      layers.push_back(Layer{i, l, r, index, -inf, inf});
    }
  }

  return layers;
}

void initialize(const vector<int> T, const vector<int> H) {
  const auto layers = build_layers(T, H);

  position_to_node.resize(SZ(H), -1);
  for (const int i : to(SZ(layers)))
    if (layers[i].row == 0)
      for (const int j : tos(layers[i].l, layers[i].r))
        position_to_node[j] = i;

  tree_info.resize(SZ(layers));
  depth.resize(SZ(layers));

  for (const int i : from(SZ(layers))) {
    tree_info[i] = Connection{layers[i].pl, layers[i].pr, layers[i].parent};
    depth[i] = layers[i].parent == i ? 0 : 1 + depth[layers[i].parent];
  }
}

bool can_reach(const int L, const int R, int S, int D) {
  if (S > D)
    swap(S, D);
  int a = position_to_node[S];
  int b = position_to_node[D];
  assert(a != -1);
  assert(b != -1);

  int r = int(1e9), l = -int(1e9);
  while (depth[a] > depth[b] && tree_info[b].node != b) {
    r = min(r, tree_info[a].r);
    assert(depth[a] == depth[tree_info[a].node] + 1);
    a = tree_info[a].node;
  }
  while (depth[a] < depth[b] && tree_info[b].node != b) {
    l = max(l, tree_info[b].l);
    assert(depth[b] == depth[tree_info[b].node] + 1);
    b = tree_info[b].node;
  }
  while (tree_info[a].node != a && tree_info[b].node != b && a != b) {
    l = max(l, tree_info[b].l);
    assert(depth[b] == depth[tree_info[b].node] + 1);
    b = tree_info[b].node;
    r = min(r, tree_info[a].r);
    assert(depth[a] == depth[tree_info[a].node] + 1);
    a = tree_info[a].node;
  }
  return a == b && r >= L && l <= R;
}

#ifndef EVAL
#include "../public/cpp/grader.cpp"
#endif
