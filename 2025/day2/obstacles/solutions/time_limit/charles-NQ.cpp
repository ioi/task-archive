// solution/charles-NQ.cpp
// {
//   "verdict": "time_limit",
//   "except": {
//     "samples": "wrong_answer",
//     "n1": "correct",
//     "fixed": "correct",
//     "fewq": "correct"
//   }
// }
// END HEADER
#include <algorithm>
#include <array>
#include <cassert>
#include <ranges>
#include <vector>
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
    assert(0 <= l);
    assert(l <= r);
    assert(r <= n);
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

struct SuperRMQ {
  RangeMinimumQuery positive, negative;
  SuperRMQ() {
  }
  SuperRMQ(vector<int> values) {
    positive = RangeMinimumQuery(values);
    for (auto& i : values)
      i *= -1;
    negative = RangeMinimumQuery(values);
  }

  int range_minimum(const int l, const int r) const {
    return positive.range_minimum(l, r);
  }
  int first_less(const int l, const int r) const {
    return positive.first_less(l, r);
  }
  int last_less(const int l, const int r) const {
    return positive.last_less(l, r);
  }

  int range_maximum(const int l, const int r) const {
    return -negative.range_minimum(l, r);
  }
  int first_more(const int l, const int r) const {
    return negative.first_less(l, -r);
  }
  int last_more(const int l, const int r) const {
    return negative.last_less(l, -r);
  }
};

vector<int> Tv, Hv;

SuperRMQ Tr, Hr;

void initialize(const vector<int> _T, const vector<int> _H) {
  Tv = _T;
  Hv = _H;

  Tr = SuperRMQ(Tv);
  Hr = SuperRMQ(Hv);
}

struct Level {
  int y;
  int x1;
  int x2;
  bool operator==(Level l) {
    return y == l.y && x1 == l.x1 && x2 == l.x2;
  }
};

optional<Level> next(Level level) {
  int yy = Tr.first_more(level.y, Tv[level.y]);
  if (yy == SZ(Tv))
    return {};
  int min_t = Tr.range_minimum(level.y, yy + 1);
  int min_h = Hr.range_minimum(level.x1, level.x2 + 1);
  if (min_t <= min_h)
    return {};
  return Level{yy, Hr.last_more(level.x1, Tv[yy] - 1) + 1, Hr.first_more(level.x2, Tv[yy] - 1) - 1};
}

Level initial(int v) {
  return Level{0, Hr.last_more(v, Tv[0] - 1) + 1, Hr.first_more(v, Tv[0] - 1) - 1};
}

bool can_reach(const int, const int, int S, int D) {
  optional<Level> a = initial(S);
  optional<Level> b = initial(D);
  while (a.has_value() && b.has_value()) {
    if (a.value() == b.value())
      return true;
    a = next(a.value());
    b = next(b.value());
  }
  return false;
}

#ifndef EVAL
#include "../grader/cpp/grader.cpp"
#endif
