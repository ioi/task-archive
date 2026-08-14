// solution/authors.cpp
// {
//   "verdict": "correct"
// }
// END HEADER
#include <bits/stdc++.h>
using namespace std;

#define rng(i, a, b) for (int i = int(a); i <= int(b); i++)
#define rep(i, b) rng(i, 0, b - 1)
#define gnr(i, b, a) for (int i = int(b); i >= int(a); i--)
#define per(i, b) gnr(i, b - 1, 0)
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define bg begin()
#define ed end()
#define all(x) x.bg, x.ed
#define si(x) int(x.size())
template <class t> using vc = vector<t>;
template <class t> using vvc = vc<vc<t>>;
typedef long long ll;
using pii = pair<int, int>;
using vi = vc<int>;
using uint = unsigned;
using ull = unsigned long long;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using t3 = tuple<int, int, int>;

ll rand_int(ll l, ll r) { //[l, r]
#ifdef LOCAL
  static mt19937_64 gen;
#else
  static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
#endif
  return uniform_int_distribution<ll>(l, r)(gen);
}

vc<vi> w, v;
vc<pii> Q;
int n, m;
#define N_ 510000
#define M_ 1100000
const int SZ = (1 << 19), INF = 2e9;
struct Tree {
  pii IT[SZ + SZ];
  void Put(int a, int b) {
    a += SZ;
    IT[a] = {b, a - SZ};
    while (a != 1) {
      a >>= 1;
      IT[a] = max(IT[a * 2], IT[a * 2 + 1]);
    }
  }
  pii Max(int b, int e) {
    pii res = {-INF, -1};
    b += SZ, e += SZ;
    while (b <= e) {
      res = max(res, IT[b]);
      res = max(res, IT[e]);
      b = (b + 1) >> 1, e = (e - 1) >> 1;
    }
    return res;
  }
  int find_right(int cur,
                 int a) { // find lowest index >=cur, greater or equal to a
    int e = SZ + SZ - 1;
    cur += SZ;
    while (cur <= e) {
      if (IT[cur].fi >= a)
        break;
      cur = (cur + 1) >> 1;
      e >>= 1;
    }
    if (cur > e)
      return INF;
    while (cur < SZ) {
      cur *= 2;
      if (IT[cur].fi < a)
        cur++;
    }
    return cur - SZ;
  }
  int find_left(int cur,
                int a) { // find largest index <=cur, greater or equal to a
    int b = SZ;
    cur += SZ;
    while (cur >= b) {
      if (IT[cur].fi >= a)
        break;
      cur = (cur - 1) >> 1;
      b = (b + 1) >> 1;
    }
    if (cur < b)
      return -1;
    while (cur < SZ) {
      cur = cur * 2 + 1;
      if (IT[cur].fi < a)
        cur--;
    }
    return cur - SZ;
  }
} ITA, ITB, ITC, ITD;
struct Node {
  int x, by, ey;
} X[M_];
int cnt, par[M_][21], pL[M_][21], pR[M_][21], Dep[M_];
int L[N_];
void Build(int nd, int x, int b, int e) { // node : [x~, ] x [b, e]
  // printf("%d %d %d %d\n",nd,x,b,e);

  if (!x) { // node is leaf
    rng(i, b, e) L[i] = nd;
    return;
  }
  auto [mxA, idA] = ITA.Max(0, x - 1);

  int cur = b;
  vi Y;
  Y.pb(b - 1);
  while (1) {
    cur = ITB.find_right(cur, mxA + 1);
    if (cur > e)
      break;
    Y.pb(cur);
    cur++;
  }
  Y.pb(e + 1);
  rep(i, si(Y) - 1) {
    if (Y[i] + 1 < Y[i + 1]) {
      int by = Y[i] + 1, ey = Y[i + 1] - 1;
      auto mxB = ITB.Max(by, ey).fi;
      int nx = ITA.find_right(0, mxB);
      assert(nx < x);
      X[++cnt] = {nx, by, ey};
      par[cnt][0] = nd;

      int mn = -ITC.Max(nx, x - 1).fi;
      int l = ITD.find_right(by, -mn);

      if (l <= ey) {
        int r = ITD.find_left(ey, -mn);
        pL[cnt][0] = l;
        pR[cnt][0] = r;
      } else {
        par[cnt][0] = 0;
      }

      Dep[cnt] = Dep[par[cnt][0]] + 1;

      Build(cnt, nx, by, ey);
    }
  }
}
void initialize(vector<int> A, vector<int> B) { // (i,j) Available : A_i >= B_j
  for (auto &i : B)
    i++;
  n = si(A);
  m = si(B);
  rep(i, n) {
    ITA.Put(i, A[i]);
    ITC.Put(i, -A[i]);
  }
  rep(i, m) {
    ITB.Put(i, B[i]);
    ITD.Put(i, -B[i]);
  }
  cnt = 0;
  if (ITA.Max(0, n - 1).fi >= ITB.Max(0, m - 1).fi) {
    int x = ITA.find_right(0, ITB.Max(0, m - 1).fi);
    X[++cnt] = {x, 0, m - 1};
    Build(cnt, X[cnt].x, 0, m - 1);
  } else {
    Build(cnt, n, 0, m - 1);
  }
  rep(i, 20) {
    rng(j, 1, cnt) {
      par[j][i + 1] = par[par[j][i]][i];
      pL[j][i + 1] = max(pL[j][i], pL[par[j][i]][i]);
      pR[j][i + 1] = min(pR[j][i], pR[par[j][i]][i]);
    }
  }
}
int LCA(int a, int b) {
  if (Dep[a] < Dep[b])
    return LCA(b, a);
  int d = Dep[a] - Dep[b];
  rep(i, 20) if ((d >> i) & 1) a = par[a][i];
  per(i, 21) {
    if (par[a][i] != par[b][i])
      a = par[a][i], b = par[b][i];
  }
  if (a != b)
    a = par[a][0];
  return a;
}
bool can_reach(int l, int r, int s, int t) { // l<=s<t<=r
  if (s == t)
    return true;
  if (s > t)
    swap(s, t);
  if (!L[s] || !L[t])
    return 0;
  int a = L[s], b = L[t];
  int p = LCA(a, b);

  // printf("%d %d %d\n",a,b,p);
  if (!p)
    return false;

  int d = Dep[a] - Dep[p];

  int mn = r, mx = l;
  rep(i, 21) {
    if ((d >> i) & 1) {
      mn = min(mn, pR[a][i]);
      a = par[a][i];
    }
  }

  d = Dep[b] - Dep[p];
  rep(i, 21) {
    if ((d >> i) & 1) {
      mx = max(mx, pL[b][i]);
      b = par[b][i];
    }
  }
  // printf("%d %d\n",mn,mx);
  if (l <= mn && mx <= r)
    return true;
  return false;
}

#ifndef EVAL
#include "../public/cpp/grader.cpp"
#endif
