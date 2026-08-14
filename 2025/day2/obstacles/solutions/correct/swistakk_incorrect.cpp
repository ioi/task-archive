// solution/swistakk_incorrect.cpp
// {
//   "verdict": "correct",
//   "except": {
//     "fewq": "wrong_answer",
//     "unrestricted": "wrong_answer",
//     "full": "wrong_answer"
//   }
// }
// END HEADER
#include "obstacles.h"
#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define st first
#define nd second
#define rd third
#define FOR(i, a, b) for(int i =(a); i <=(b); ++i)
#define RE(i, n) FOR(i, 1, n)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define REP(i, n) for(int i = 0;i <(n); ++i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define __builtin_ctz __builtin_ctzll
#define __builtin_clz __builtin_clzll
#define __builtin_popcount __builtin_popcountll
using namespace std;
#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<"\n"; }}
#else
#define debug(...) (__VA_ARGS__)
#define debugv(x)
#define cerr if(0)cout
#endif
#define next ____next
#define prev ____prev
#define left ____left
#define hash ____hash
typedef long long ll;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VLL;
typedef vector<pair<int, int> > VPII;
typedef vector<pair<ll, ll> > VPLL;

template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
template<class T1, class T2>
ostream& operator<< (ostream &out, pair<T1, T2> pair) { return out << "(" << pair.first << ", " << pair.second << ")";}
template<class A, class B, class C> struct Triple { A first; B second; C third;
  bool operator<(const Triple& t) const { if (st != t.st) return st < t.st; if (nd != t.nd) return nd < t.nd; return rd < t.rd; } };
  template<class T> void ResizeVec(T&, vector<int>) {}
  template<class T> void ResizeVec(vector<T>& vec, vector<int> sz) {
    vec.resize(sz[0]); sz.erase(sz.begin()); if (sz.empty()) { return; }
    for (T& v : vec) { ResizeVec(v, sz); }
  }
  typedef Triple<int, int, int> TIII;
  template<class A, class B, class C>
  ostream& operator<< (ostream &out, Triple<A, B, C> t) { return out << "(" << t.st << ", " << t.nd << ", " << t.rd << ")"; }
  template<class T> ostream& operator<<(ostream& out, vector<T> vec) { out<<"("; for (auto& v: vec) out<<v<<", "; return out<<")"; }
  template<class T> ostream& operator<<(ostream& out, set<T> vec) { out<<"("; for (auto& v: vec) out<<v<<", "; return out<<")"; }
  template<class L, class R> ostream& operator<<(ostream& out, map<L, R> vec) { out<<"("; for (auto& v: vec) out<<v<<", "; return out<<")"; }
  // ostream& operator<<(ostream& out, __int128_t x) {
  //   if (x < 0) { out<<"-"; x = -x; }
  //   if (x == 0) { return out<<"0"; }
  //   VI digs;
  //   while (x) {
  //     digs.PB(x % 10);
  //     x /= 10;
  //   }
  //   reverse(ALL(digs));
  //   for (auto d : digs) { out<<d; }
  //   return out;
  // }
  template<typename TH> void _dbg(const char* sdbg, TH h) { cerr<<sdbg<<"="<<h<<"\n"; }
  template<typename TH, typename... TA> void _dbg(const char* sdbg, TH h, TA... t) {
    while(*sdbg != ',') { cerr<<*sdbg++; } cerr<<"="<<h<<","; _dbg(sdbg+1, t...);
  }

  
vector<int> T, H;
int n, m;
const int M = 1 << 19;
vector<int> drz1, drz2;
vector<int> lewo, prawo;
int ReadMin(int a, int b) {
  a += M;
  b += M;
  int r = min(drz1[a], drz1[b]);
  while (a / 2 != b / 2) {
    if (a % 2 == 0) {
      mini(r, drz1[a + 1]);
    }
    if (b % 2 == 1) {
      mini(r, drz1[b - 1]);
    }
    a /= 2;
    b /= 2;
  }
  return r;
}
int ReadMax(int a, int b) {
  a += M;
  b += M;
  int r = max(drz2[a], drz2[b]);
  while (a / 2 != b / 2) {
    if (a % 2 == 0) {
      maxi(r, drz2[a + 1]);
    }
    if (b % 2 == 1) {
      maxi(r, drz2[b - 1]);
    }
    a /= 2;
    b /= 2;
  }
  return r;
}

vector<int> Tmin;
vector<int> big;
vector<int> sum;
void initialize(std::vector<int> TT, std::vector<int> HH) {
  T = TT;
  H = HH;
  n = SZ(T);
  m = SZ(H);
  // REP (i, n) { assert(T[i] <= 1); }
  // REP (i, m) { assert(H[i] <= 1); }
  Tmin = T;
  lewo.resize(m);
  prawo.resize(m);
  big.PB(0);
  sum = H;
  FOR (i, 1, n - 1) {
    mini(Tmin[i], Tmin[i - 1]);
    if (T[i] > T[big.back()]) {
      big.PB(i);
    }
  }
  drz1.resize(2 * M + 5);
  drz2.resize(2 * M + 5);
  REP (i, m) {
    drz1[i + M] = H[i];
    drz2[i + M] = H[i];
    if (i) {
      sum[i] += sum[i - 1];
    }
    if (T[0] > H[i]) {
      lewo[i] = i;
      if (i && lewo[i - 1] != m) {
        lewo[i] = lewo[i - 1];
      }
    } else {
      lewo[i] = m;
    }
  }
  FORD (i, M - 1, 1) {
    drz1[i] = min(drz1[2 * i], drz1[2 * i + 1]);
    drz2[i] = max(drz2[2 * i], drz2[2 * i + 1]);
  }
  FORD (i, m - 1, 0) {
    if (T[0] > H[i]) {
      prawo[i] = i;
      if (i != m - 1 && prawo[i + 1] != -1) {
        prawo[i] = prawo[i + 1];
      }
    } else {
      prawo[i] = -1;
    }
  }
}
bool can_reach(int L, int R, int S, int D) {
  if (S > D) { swap(S, D); }
  
  assert(L <= R && R < M && L <= S && D <= R);
  assert(T[0] > H[S] && T[0] > H[D]);
  if (S + 1 >= D) { return true; }
  // return sum[S] == sum[D];
  int biggest_H = ReadMax(S + 1, D - 1);
  //return biggest_H == 0;
  // FOR (i, S + 1, D - 1) {
  //   maxi(biggest_H, H[i]);
  // }
  int smallest_T = 2e9;
  {
    int faj = n;
    int kl = 0, kp = SZ(big) - 1;
    while (kl <= kp) {
      int aktc = (kl + kp) / 2;
      if (T[big[aktc]] > biggest_H) {
        faj = big[aktc];
        kp = aktc - 1;
      } else {
        kl = aktc + 1;
      }
    }
    if (faj == 0) { return true; }
    if (faj == n) { return false; }
    smallest_T = Tmin[faj];
  }
  function<bool(int)> Check = [&](int i) {
    int l = max(L, lewo[i]);
    int r = min(R, prawo[i]);
    return ReadMin(l, r) < smallest_T;
    // for (int j = i; j <= R; j++) {
    //   if (T[0] <= H[j]) {
    //     break;
    //   }
    //   if (H[j] < smallest_T) {
    //     return true;
    //   }
    // }
    // for (int j = i; j >= L; j--) {
    //   if (T[0] <= H[j]) { break; }
    //   if (H[j] < smallest_T) {
    //     return true;
    //   }
    // }
    //return false;
    
  };
  if (Check(S) && Check(D)) { return true; }
  return false;
  
}
