// solution/shahali_Z4_M21.cpp
// {
//   "verdict": "partially_correct",
//   "except": {
//     "from_root": "correct",
//     "samples": "correct"
//   }
// }
// END HEADER
#include "migrations.h"
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
const int MAXN=10010, LOG4=7, LOG3=9, TRESHOLD=24;

int n, m, k, x, y;
int par[MAXN], h[MAXN], ans, tmp, curr;
int fx[MAXN], fy[MAXN];

int dist(int u, int v){
	int res=0;
	while (u!=v){
		if (h[u]<h[v]) v=par[v];
		else u=par[u];
		res++;
	}
	return res;
}

int get_type(int v){
	if (dist(x, v)>ans) return 1;
	if (dist(y, v)>ans) return 2;
	return 0;
}

int send_message(int _N, int v, int _P) {
	n=_N;
	par[v]=_P;
	h[v]=h[par[v]]+1;
	if (v==1){
		ans=1;
		x=0;
		y=1;
		return 0;
	}

	if (n<=TRESHOLD){
		if (dist(x, v)>ans){
			y=v;
			ans++;
			return 1;
		}
		if (dist(v, y)>ans){
			x=v;
			ans++;
			return 2;
		}
		return 0;
	}

	// n > 24
	fx[v]=fy[v]=0;
	if (dist(x, v)>ans){
		y=v;
		fy[v]=1;
		ans++;
	}
	else if (dist(v, y)>ans){
		x=v;
		fx[v]=1;
		ans++;
	}
	if (v==13){
		debug2(x, y)
		debug(dist(x, y))
		debug(dist(1, 13))
	}
	// debug2(x, y)
	
	if (v<n-21) return 0;

	if (v==n-21) tmp=x;
	if (v<n-14){
		if (fx[v]) return 0;
		int out = tmp%4 + 1;
		tmp/=4;
		return out;
	}

	if (v==n-14) tmp=y;
	if (v<n-7){
		if (fy[v]) return 0;
		int out = tmp%4 + 1;
		tmp/=4;
		return out;
	}

	// v>=n-7
	int res=0;
	if (fy[v]) res=1;
	if (fx[v]) res=2;
	if (x==v-7) res+=3;
	return res;
}

pii longest_path(vi S) {
	n=SZ(S);
	if (n<=TRESHOLD){
		x=0;
		y=1;
		for (int i=2; i<n; i++){
			if (S[i]==1) y=i;
			if (S[i]==2) x=i;
		}
		return {x, y};
	}

	x=0;
	for (int i=n-21; i<n-14; i++) if (!S[i]) x=i;
	if (!x){
		for (int i=n-15; i>=n-21; i--)
			x = 4*x + (S[i]-1);
	}

	y=0;
	for (int i=n-14; i<n-7; i++) if (!S[i]) y=i;
	if (!y){
		for (int i=n-8; i>=n-14; i--){
			y = 4*y + (S[i]-1);
			// debug2(S[i], y)
		}
	}
	debug2(x, y)

	for (int i=n-7; i<n; i++){
		int tmp=S[i];
		if (tmp>=3){
			x=i-7;
			tmp-=3;
		}
		if (tmp==1) y=i;
		if (tmp==2) x=i;
	}
	return {x, y};	
}
