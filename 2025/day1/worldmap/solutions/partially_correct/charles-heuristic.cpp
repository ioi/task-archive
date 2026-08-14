#include <cassert>
#include <vector>
#include <ranges>
#include <algorithm>
#include <set>
#include <iostream>
using namespace std;

typedef long long ll;

#define to(n) (views::iota(0, n))
#define tos(s, n) (views::iota(s, n))

#define DBG(x) cout << #x << " = " << (x) << endl;
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) int((x).size())

const int inf = 1e8;

template <class x, class y>
ostream& operator<<(ostream& out, pair<x, y> v) {
  out << v.first << ":" << v.second;
  return out;
}

template <class x>
ostream& operator<<(ostream& out, vector<x> v) {
  out << "[ ";
  for (auto y : v)
    out << y << " ";
  out << "]";
  return out;
}

template <class x>
ostream& operator<<(ostream& out, set<x> v) {
  out << "{ ";
  for (auto y : v)
    out << y << " ";
  out << "}";
  return out;
}

vector<int> tsp_small(vector<vector<int>> distances) {
  int n = SZ(distances);
  vector<pair<int, int>> dp(n * (1 << n), {inf, -1});
  for (int i : to(n))
    dp[(1 << i) + (i << n)] = {0, -1};
  for (int b : to(1 << n)) {
    for (int last : to(n)) {
      if (b & (1 << last)) {
        int prev = b ^ (1 << last);
        for (int j : to(n)) {
          if (j != last && ((1 << j) & b)) {
            dp[b + (last << n)] = min(dp[b + (last << n)], {dp[prev + (j << n)].first + distances[last][j], prev + (j << n)});
          }
        }
      }
    }
  }
  int curr = -1;
  for (int i : to(n))
    if (curr == -1 || dp[curr].first > dp[(1 << n) - 1 + (i << n)].first)
      curr = (1 << n) - 1 + (i << n);
  // DBG(dp[curr].first);
  // DBG(distances[2][1]);
  vector<int> sol;
  while (curr != -1) {
    sol.push_back(curr >> n);
    curr = dp[curr].second;
  }
  // DBG(sol);
  return sol;
}

vector<int> tsp_large(vector<vector<int>> distances) {
  srand(1283749281);
  int n = SZ(distances);
  vector<int> sol = {n / 2};
  vector<char> seen(n, false);
  seen[n / 2] = true;
  while (SZ(sol) < n) {
    int best = -1;
    int last = sol.back();
    vector<int> cands;
    for (int i : to(n))
      if (!seen[i]) {
        if (best == -1 || distances[last][best] >= distances[last][i]) {
          if (distances[last][best] > distances[last][i])
            cands.clear();
          cands.push_back(i);
          best = i;
        }
      }
    best = cands[rand() % SZ(cands)];
    seen[best] = true;
    sol.push_back(best);
  }
  assert(SZ(sol) == n);
  // DBG(sol);
  return sol;
}

vector<int> tsp(vector<vector<int>> distances) {
  if (SZ(distances) > 12)
    return tsp_large(distances);
  else
    return tsp_small(distances);
}

struct Dinic {
  int nodes, src, dst;
  vector<int> dist, q, work;
  struct edge {
    int to, rev;
    ll f, cap;
  };
  vector<vector<edge>> g;
  Dinic(int x) : nodes(x), dist(x), q(x), work(x), g(x) {
  }
  void add_edge(int s, int t, ll cap) {
    g[s].push_back((edge){t, SZ(g[t]), 0, cap});
    g[t].push_back((edge){s, SZ(g[s]) - 1, 0, 0});
  }
  bool dinic_bfs() {
    fill(ALL(dist), -1);
    dist[src] = 0;
    int qt = 0;
    q[qt++] = src;
    for (int qh = 0; qh < qt; qh++) {
      int u = q[qh];
      for (int i : to(SZ(g[u]))) {
        edge& e = g[u][i];
        int v = g[u][i].to;
        if (dist[v] < 0 && e.f < e.cap)
          dist[v] = dist[u] + 1, q[qt++] = v;
      }
    }
    return dist[dst] >= 0;
  }
  ll dinic_dfs(int u, ll f) {
    if (u == dst)
      return f;
    for (int& i = work[u]; i < SZ(g[u]); i++) {
      edge& e = g[u][i];
      if (e.cap <= e.f)
        continue;
      int v = e.to;
      if (dist[v] == dist[u] + 1) {
        ll df = dinic_dfs(v, min(f, e.cap - e.f));
        if (df > 0) {
          e.f += df;
          g[v][e.rev].f -= df;
          return df;
        }
      }
    }
    return 0;
  }
  ll max_flow(int _src, int _dst) {
    src = _src;
    dst = _dst;
    ll result = 0;
    while (dinic_bfs()) {
      fill(ALL(work), 0);
      while (ll delta = dinic_dfs(src, inf))
        result += delta;
    }
    return result;
  }
};

optional<vector<vector<int>>> match(int maxd, vector<pair<int, int>> pars, vector<char> activated) {
  auto flow = Dinic(2 + SZ(pars) + SZ(activated));
  for (int t : to(SZ(pars))) {
    flow.add_edge(0, t + 2, 1);
    if (activated[pars[t].first])
      flow.add_edge(t + 2, 2 + SZ(pars) + pars[t].first, 1);
    if (activated[pars[t].second])
      flow.add_edge(t + 2, 2 + SZ(pars) + pars[t].second, 1);
  }
  for (int i : to(SZ(activated))) {
    if (activated[i])
      flow.add_edge(2 + SZ(pars) + i, 1, maxd);
  }
  ll f = flow.max_flow(0, 1);
  assert(f <= SZ(pars));
  if (f != SZ(pars))
    return {};
  vector<vector<int>> res(SZ(activated));
  for (int i : to(SZ(activated))) {
    for (auto e : flow.g[2 + SZ(pars) + i]) {
      if (e.to != 1 && e.rev != 0) {
        assert(activated[i]);
        int other = pars[e.to - 2].first ^ pars[e.to - 2].second ^ i;
        res[i].push_back(other);
      }
    }
  }
  return res;
}

optional<vector<vector<int>>> can(int n, int maxd, int maxw, vector<pair<int, int>> pars) {
  vector<char> activated(n, true);
  int count = n;
  if (!match(maxd, pars, activated).has_value())
    return {};
  if (count <= maxw)
    return match(maxd, pars, activated);
  for (int i : to(n)) {
    activated[i] = false;
    auto m = match(maxd, pars, activated);
    if (!m.has_value()) {
      activated[i] = true;
    } else {
      count--;
      if (count <= maxw)
        return m;
    }
  }
  return {};
}

vector<vector<int>> create_map(int n, int m, vector<int> as, vector<int> bs) {
  for (int& i : as)
    i--;
  for (int& i : bs)
    i--;
  vector<vector<int>> distances(n, vector<int>(n, inf));
  vector<vector<int>> from(n, vector<int>(n, -1));
  for (int i : to(n))
    distances[i][i] = 0;
  for (int i : to(m)) {
    distances[as[i]][bs[i]] = distances[bs[i]][as[i]] = 1;
    from[as[i]][bs[i]] = bs[i];
    from[bs[i]][as[i]] = as[i];
  }
  for (int j : to(n))
    for (int i : to(n))
      for (int k : to(n))
        if (distances[i][k] > distances[i][j] + distances[j][k])
          distances[i][k] = distances[i][j] + distances[j][k],
          from[i][k] = from[i][j];

  vector<int> optimal = tsp(distances);
  vector<int> path;
  for (auto i : optimal) {
    if (path.empty()) {
      path.push_back(i);
      continue;
    }
    while (path.back() != i) {
      path.push_back(from[path.back()][i]);
    }
  }
  set<pair<int, int>> covered;
  for (int i : to(SZ(path) - 1)) {
    int a = path[i], b = path[i + 1];
    covered.insert({a, b});
    covered.insert({b, a});
  }

  vector<pair<int, int>> uncovered;
  for (int i : to(m))
    if (!covered.count({as[i], bs[i]}))
      uncovered.push_back({as[i], bs[i]});

  // DBG(path);
  // DBG(n);
  assert(SZ(path) >= n);
  int lo = SZ(path) - 1;
  int hi = max(2 * n, n + SZ(path));
  assert(can(n, hi / 2, hi - SZ(path), uncovered).has_value());
  while (hi - lo > 1) {
    int mid = (hi + lo) / 2;
    int maxd = mid / 2;
    int maxw = mid - SZ(path);
    auto c = can(n, maxd, maxw, uncovered);
    if (c.has_value())
      hi = mid;
    else
      lo = mid;
  }
  int maxd = hi / 2;
  int maxw = hi - SZ(path);
  // DBG(maxw);
  auto c = can(n, maxd, maxw, uncovered).value();

  set<int> widened;
  vector<int> wide(SZ(path), -1);
  for (int i : to(SZ(path))) {
    if (SZ(c[path[i]]) != 0 && !widened.count(path[i])) {
      wide[i] = SZ(widened) % 2;
      widened.insert(path[i]);
    }
  }

  // DBG(path);
  // DBG(wide);
  // DBG(c);
  // DBG(uncovered);

  vector<vector<int>> res(hi, vector<int>(hi + 1, -1));
  for (int i : to(hi)) {
    int curr = hi - (i + 1) % 2;
    for (int j : to(SZ(path))) {
      int v = path[min(SZ(path) - 1, j)];
      if (curr >= 0)
        res[i][curr--] = v;
      if ((i + 1) % 2 == wide[min(SZ(path) - 1, j)]) {
        // DBG(v);
        if (curr >= 0)
          res[i][curr--] = v;
        if (curr >= 0)
          res[i][curr--] = v;
      }
    }
  }
  for (auto& v : res) {
    v.pop_back();
    for (int i : to(hi)) {
      if (v[hi - i - 1] == -1)
        v[hi - i - 1] = v[hi - i];
    }
  }

  set<pair<int, int>> prefill;
  for (int i : to(m))
    prefill.insert({min(as[i], bs[i]), max(as[i], bs[i])});

  for (int i : to(hi))
    for (int j : to(hi)) {
      if (i != 0)
        prefill.insert({min(res[i - 1][j], res[i][j]), max(res[i - 1][j], res[i][j])});
      if (j != 0)
        prefill.insert({min(res[i][j - 1], res[i][j]), max(res[i][j - 1], res[i][j])});
    }

  // DBG(c);
  // for (auto v : res) {
  //   for (int i : v) {
  //     if (i < 10)
  //       cout << " ";
  //     cout << i << " ";
  //   }
  //   cout << endl;
  // }

  // DBG(prefill);
  // DBG(uncovered);
  // DBG(path);

  for (int i : to(n)) {
    for (int v : c[i]) {
      bool found = false;
      for (int x : to(hi)) {
        for (int y : to(hi)) {
          if (!found && res[x][y] == i && (x == 0 || res[x - 1][y] == i) && (x == hi - 1 || res[x + 1][y] == i) && (y == 0 || res[x][y - 1] == i) && (y == hi - 1 || res[x][y + 1] == i)) {
            found = true;
            res[x][y] = v;
          }
        }
      }
      // DBG(i);
      // DBG(v);
      assert(found);
    }
  }

  set<pair<int, int>> expected, actual;
  for (int i : to(m))
    expected.insert({min(as[i], bs[i]), max(as[i], bs[i])});

  for (int i : to(hi))
    for (int j : to(hi)) {
      if (i != 0 && res[i - 1][j] != res[i][j])
        actual.insert({min(res[i - 1][j], res[i][j]), max(res[i - 1][j], res[i][j])});
      if (j != 0 && res[i][j - 1] != res[i][j])
        actual.insert({min(res[i][j - 1], res[i][j]), max(res[i][j - 1], res[i][j])});
    }

  // DBG(actual);
  // DBG(expected);

  assert(actual == expected);

  // for (auto v : res)
  //   DBG(v);
  for (auto& v : res)
    for (int& i : v)
      i++;
  return res;
}

#ifndef EVAL
#include "../grader/cpp/grader.cpp"
#endif
