#include "worldmap.h"
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
const int MAXN=500;

int n, m, k;
bool mark[MAXN], mark2[MAXN];
vector<int> G[MAXN], vec, adj[MAXN];
vector<pii> pos[MAXN];

void dfs(int node){
	vec.pb(node);
	mark[node]=1;
	for (int v:G[node]) if (!mark[v]){
		dfs(v);
		vec.pb(node);
	}
}

vector<vector<int>> create_map(int _n, int _m, vector<int> A, vector<int> B) {
	n = _n;
	m = _m;
	for (int i=1; i<=n; i++){
		G[i].clear();
		adj[i].clear();
		mark[i]=0;
		mark2[i]=0;
	}
	vec.clear();
	for (int i=0; i<MAXN; i++) pos[i].clear();

	for (int i=0; i<m; i++){
		G[A[i]].pb(B[i]);
		G[B[i]].pb(A[i]);
		int x = A[i], y = B[i];
		if (x>y) swap(x, y);
		if (y <= x+n/2) adj[x].pb(y);
		else adj[y].pb(x);
	}
	dfs(1);
	k = 2*n;
	// debug(k)
	// debugv(vec)
	for (int i=0; i<k; i++) for (int j=0; j<k; j++) pos[i+j].pb({i, j});

	vector<vi> ans;
	for (int i=0; i<k; i++) ans.pb(vi(k, 1));
	int s=n/2;
	for (int x:vec){
		for (auto &[i, j]: pos[s]) ans[i][j]=x;
		s++;

		if (mark2[x]) continue;
		mark2[x]=1;
		
		int t=0;
		for (auto &[i, j]: pos[s]){
			if (t<SZ(adj[x])) ans[i][j] = adj[x][t++];
			else ans[i][j]=x;
			// debug2(i, j)
		}
		s++;
		
		for (auto &[i, j]: pos[s]) ans[i][j]=x;
		s++;
	}


	return ans;
}
