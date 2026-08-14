// solution/shahali-full-correct.cpp
// {
//   "verdict": "correct"
// }
// END HEADER
#include "obstacles.h"
#include<bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> pi3;
typedef pair<ll, int> pli;
typedef vector<int> vi;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
#define all(x) x.begin(), x.end()
#define pb push_back
#define SZ(x) ((int)x.size())
#define kill(x) return cout<<x<<'\n', 0;
#define getbit(x,y) (((x)>>(y))&1)
#define popcount(x) (__builtin_popcount(x))

const int inf=1000000010;
const ll INF=1000000000000001000LL;
const int mod=998244353;
const int MAXN=500010, LOG=19;

int n, m, k;
int T[MAXN], H[MAXN];
int minH[LOG][MAXN];
int maxH[LOG][MAXN];
int pref_minT[MAXN];
int pref_maxT[MAXN];
int L[MAXN], R[MAXN];
int nexL[MAXN], nexR[MAXN];
int tmp[MAXN];
int spL[LOG][MAXN], spR[LOG][MAXN];
pair<int, pii> spLR[LOG][MAXN];

inline int lg2(int x){ return 31-__builtin_clz(x);}

int range_min_h(int l, int r){ // [l, r)
	int lg = lg2(r-l);
	return min(minH[lg][l], minH[lg][r-(1<<lg)]);
}
int range_max_h(int l, int r){ // [l, r)
	int lg = lg2(r-l);
	return max(maxH[lg][l], maxH[lg][r-(1<<lg)]);
}

void read_and_normalize_input(vi &_T, vi &_H){
	n = SZ(_T);
	m = SZ(_H);
	vector<pair<pii, int>> shit;
	for (int i=0; i<n; i++) shit.pb({{_T[i], 0}, i});
	for (int i=0; i<m; i++) shit.pb({{_H[i], 1}, i});
	sort(all(shit));
	for (int i=0; i<n+m; i++){
		auto &[p, idx] = shit[i];
		if (p.second) H[idx+1] = i+1;
		else T[idx+1] = i+1;
	}
	// cerr<<"T: "; for (int i=1; i<=n; i++) cerr<<T[i]<<" \n"[i==n];
	// cerr<<"H: "; for (int i=1; i<=m; i++) cerr<<H[i]<<" \n"[i==m];
}

void initialize(vi _T, vi _H){
	read_and_normalize_input(_T, _H);

	for (int i=1; i<=m; i++) minH[0][i]=H[i];
	for (int j=1; j<LOG; j++)
		for (int i=1; i+(1<<j)<=m+1; i++)
			minH[j][i] = min(minH[j-1][i], minH[j-1][i+(1<<(j-1))]);

	for (int i=1; i<=m; i++) maxH[0][i]=H[i];
	for (int j=1; j<LOG; j++)
		for (int i=1; i+(1<<j)<=m+1; i++)
			maxH[j][i] = max(maxH[j-1][i], maxH[j-1][i+(1<<(j-1))]);

	for (int i=1; i<=m; i++) for (L[i]=i-1; L[i] && H[L[i]]>=H[i]; L[i]=L[L[i]]);
	for (int i=m; i; i--) for (R[i]=i+1; R[i]<=m && H[R[i]]>=H[i]; R[i]=R[R[i]]);

	pref_minT[0]=inf;
	for (int i=1; i<=n; i++) pref_minT[i] = min(pref_minT[i-1], T[i]);
	pref_maxT[0]=-inf;
	for (int i=1; i<=n; i++) pref_maxT[i] = max(pref_maxT[i-1], T[i]);
	
	for (int i=0; i<=n; i++) tmp[i]=-pref_minT[i];
	for (int i=1; i<=m; i++){
		nexL[i] = nexR[i] = i;
		int row = lower_bound(tmp, tmp+n+1, -H[i])-tmp-1;
		if (!row) continue;
		int tmax = pref_maxT[row];
		if (L[i] && range_max_h(L[i], i) < tmax) nexL[i] = L[i];
		if (R[i]<=m && range_max_h(i, R[i]+1) < tmax) nexR[i] = R[i];
	}
	// cerr<<"nexL: "; for (int i=1; i<=m; i++) cerr<<nexL[i]<<" \n"[i==m];
	// cerr<<"nexR: "; for (int i=1; i<=m; i++) cerr<<nexR[i]<<" \n"[i==m];
	for (int i=1; i<=m; i++){
		spL[0][i]=nexL[i];
		spR[0][i]=nexR[i];
		int x = nexL[nexR[i]];
		spLR[0][i]={x, {x, nexR[i]}};
	}
	for (int j=1; j<LOG; j++)
		for (int i=1; i<=m; i++) spL[j][i] = spL[j-1][spL[j-1][i]];
	for (int j=1; j<LOG; j++)
		for (int i=1; i<=m; i++) spR[j][i] = spR[j-1][spR[j-1][i]];
	for (int j=1; j<LOG; j++)
		for (int i=1; i<=m; i++){
			auto [x, p1] = spLR[j-1][i];
			auto [y, p2] = spLR[j-1][x];
			spLR[j][i] = {y, {min(p1.first, p2.first), max(p1.second, p2.second)}};
		}
}

int go(int l, int r, int x){
	for (int i=LOG-1; ~i; i--){
		auto [pl, pr] = spLR[i][x].second;
		if (l<=pl && pr<=r) x = spLR[i][x].first;
	}
	for (int i=LOG-1; ~i; i--) if (spL[i][x]!=x && l<=spL[i][x]) x=spL[i][x];
	for (int i=LOG-1; ~i; i--) if (spR[i][x]!=x && spR[i][x]<=r) x=spR[i][x];
	return x;
}

bool can_reach(int l, int r, int s, int d){
	l++;
	r++;
	s++;
	d++;
	if (s>d) swap(s, d);

	s = go(l, r, s);
	d = go(l, r, d);
	return s==d;
}
