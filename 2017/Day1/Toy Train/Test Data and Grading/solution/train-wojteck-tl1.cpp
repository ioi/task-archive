#include "train.h"

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
using namespace std;
template<typename TH> void _dbg(const char* sdbg, TH h) { cerr<<sdbg<<"="<<h<<"\n"; }
template<typename TH, typename... TA> void _dbg(const char* sdbg, TH h, TA... t) {
	while(*sdbg != ',')cerr<<*sdbg++; cerr<<"="<<h<<","; _dbg(sdbg+1, t...);
}
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


std::vector<int> who_wins(std::vector<int> a, std::vector<int> r, std::vector<int> uu, std::vector<int> vv) {
	int n = SZ(a);
	VVI slo(n + 2);
	REP (i, SZ(uu)) {
		slo[uu[i]].PB(vv[i]);
	}
	VI orig_r = r;
	VVI bors;
	VI bor(n);
	VI last_bor = bor;
	int obrot = 0;
	while (1) {
		obrot++;
		//debug(obrot);
		//assert(obrot <= 2);
		r = orig_r;
		REP (i, n) {
			if (bor[i]) {
				r[i] = 0;
			}
		}
		while (1) {
			int got = 0;
			REP (v, n) {
				if (r[v]) { continue; }
				int fine = 0;
				if (a[v] == 0) {
					int all_r = 1;
					for (auto nxt : slo[v]) {
						if (!r[nxt]) {
							all_r = 0;
							break;
						}
					}
					fine = all_r;
				} else {
					for (auto nxt : slo[v]) {
						if (r[nxt]) {
							fine = 1;
							break;
						}
					}
				}
				if (fine) {
					got = 1;
					r[v] = 1;
				}
			}
			if (got == 0) {
				break;
			}
		}
		REP (i, n) {
			if (r[i] == 0) {
				bor[i] = 1;
			}
		}
		while (1) {
			int got = 0;
			REP (v, n) {
				if (bor[v]) { continue; }
				int fine = 0;
				if (a[v]) {
					int all_r = 1;
					for (auto nxt : slo[v]) {
						//             if (v == 3) {
						//               debug(nxt, !bor[nxt] && nxt != v, v == nxt && orig_r[v]);
						//             }
						if (!bor[nxt] && nxt != v) {
							all_r = 0;
							break;
						}
						if (v == nxt && orig_r[v]) {
							all_r = 0;
							break;
						}
					}
					fine = all_r;
				} else {
					for (auto nxt : slo[v]) {
						if (bor[nxt]) {
							fine = 1;
							break;
						}
					}
				}
				if (fine) {
					got = 1;
					bor[v] = 1;
				}
			}
			if (got == 0) {
				break;
			}
		}
		debug(bor);
		if (bor == last_bor) {
			break;
		}
		last_bor = bor;
	}
	VI ans(n);
	REP (i, n) {
		ans[i] = 1 - bor[i];
	}
	return ans;
}
