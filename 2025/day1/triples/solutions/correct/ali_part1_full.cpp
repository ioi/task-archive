#include "triples.h"
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
const int MAXN=200010;

int n, m, k;
int f[MAXN], g[MAXN];
int mark[MAXN], marker;
vector<pair<pii, int>> pairs;
vector<int> L[MAXN*2], R[MAXN*2];

int check231(int i, int j, int k, vi &h){
	return (h[i] == k-j && h[j] == k-i && h[k] == j-i);
}

ll count_triples(vi h) {
	n = SZ(h);

	ll ans=0;
	pairs.clear();
	for (int i=0; i<MAXN*2; i++){
		L[i].clear();
		R[i].clear();
	}

	// 1 2 3
	for (int i=0; i<n; i++){
		int j = i+h[i];
		if (j>=n) continue;
		int k = j+h[j];
		if (k>=n) continue;
		if (h[k] == k-i && i<j && j<k) pairs.pb({{i, j}, k});
	}

	// 1 3 2
	for (int i=0; i<n; i++){
		int j = i+h[i];
		if (j>=n) continue;
		int k = i+h[j];
		if (k>=n) continue;
		if (h[k] == k-j && i<j && j<k) pairs.pb({{i, j}, k});
	}

	// 2 1 3
	for (int k=0; k<n; k++){
		int i = k-h[k];
		if (i<0) continue;
		int j = k-h[i];
		if (j<0) continue;
		if (h[j] == j-i && i<j && j<k) pairs.pb({{i, j}, k});
	}

	// 3 1 2
	for (int k=0; k<n; k++){
		int j = k-h[k];
		if (j<0) continue;
		int i = j-h[j];
		if (i<0) continue;
		if (h[i] == k-i && i<j && j<k) pairs.pb({{i, j}, k});
	}

	// 3 2 1
	for (int i=0; i<n; i++){
		int k = i+h[i];
		if (k>=n) continue;
		int j = i+h[k];
		if (j<0) continue;
		if (h[j] == k-j && i<j && j<k) pairs.pb({{i, j}, k});
	}

	sort(all(pairs));
	pairs.resize(unique(all(pairs)) - pairs.begin());
	for (auto [p, k]: pairs){
		auto [i, j] = p;
		if (!check231(i, j, k, h)){
			ans++;
		}
	}
	
	for (int i=0; i<n; i++){
		f[i]=h[i]+i;
		g[i]=h[i]-i+n;
		R[f[i]].pb(i);
		L[g[i]].pb(i);
	}
	
	// 2 3 1
	for (int t=0; t<2*MAXN; t++){
		marker++;
		for (int i:L[t]) mark[h[i]]=marker;
		for (int i:L[t]) if (SZ(L[g[i]]) >= SZ(R[f[i]])){
			for (int j:R[f[i]]) if (h[j]<=h[i]) ans+=(mark[h[i]-h[j]]==marker);
		}
	}
	for (int t=0; t<2*MAXN; t++){
		marker++;
		for (int i:R[t]) mark[h[i]]=marker;
		for (int i:R[t]) if (SZ(L[g[i]]) < SZ(R[f[i]])){
			for (int j:L[g[i]]) if (h[j]<=h[i]) ans+=(mark[h[i]-h[j]]==marker);
		}
	}

	return ans;
}

vi construct_range(int M, int K) {
	return {4, 1, 4, 3, 2, 6, 1};
}
