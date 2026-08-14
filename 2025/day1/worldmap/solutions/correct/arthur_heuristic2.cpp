// find any DFS tree, do the 3N with the two following optimization:
// - don't return after we reach the deepest node
// - only create an extra line in the matrix to add backedges if all such backedges are going down 
// repeat this N times, rooting at each vertex

#include "worldmap.h"
#include <vector>
#include <iostream>
#define debug 
using namespace std;

#define maxn 120
int longest[maxn];
int tin[maxn];
int vis[maxn];
int prof[maxn];

vector<int> add[maxn];

vector<vector<int> > G,T;
vector<vector<int> > ans;
int K;

int cnt;
int up;
int mxp;
int leaves;
int endpoint;

pair<int,int> dfs(int vx,int par=-1){
  debug("dfs %d\n",vx);
	vis[vx] = 1;
	tin[vx] = cnt++;
	int depth = 0;
  pair<int,int> res ({0,vx});

	for(int viz : G[vx]){
		if(!vis[viz]){
			T[vx].push_back(viz);
			prof[viz] = 1 + prof[vx];
			auto u = dfs(viz,vx);
			if(u.first+1 > res.first){
				res.first = u.first+1;
				longest[vx] = viz;
        res.second = u.second;
			}
		}
		else if(tin[viz] > tin[vx]){
			add[vx].push_back(viz);
		}
	}
	return res;
}

int N;
void add_edge(int a,int b){
  debug("add %d %d\n",a,b);
	if(K == 0){
		for(int i=0;i<3*N;i++)
			ans[0][i] = (i%2) ? a : b;
		K++;
		return;
	}
	if(ans[K-1][0] == b || ans[K-1][1] == b)
		swap(a,b);

	if(ans[K-1][0] == a)
		swap(a,b);

	for(int i=0;i<3*N;i++)
			ans[K][i] = (i%2) ? b : a;

		K++;
		
}

void add_adj(int vx){
  if(K == 0){
    int t = 0;
    for(int i=0;i<3*N;i++){
      if(i%2 == 0 && t < add[vx].size()){
        ans[K][i] = add[vx][t];
        up = max(up, i+1);
        t++;
		  }
		  else
			  ans[K][i] = vx;
    }
    K++;
    return;
  }
	int t = 0;
	for(int i=0;i<3*N;i++){
		if(ans[K-1][i] == vx && t < add[vx].size()){
			ans[K][i] = add[vx][t];
      up = max(up, i+1);
			t++;
		}
		else
			ans[K][i] = vx;
	}
	K++;
}

int stop;
void dfs2(int vx,int ret){
  up = max(up,2);
  if(T[vx].size() == 0) {
    leaves++;
    if(vx == endpoint){
      debug("!stop\n");
      stop = 1;
    } 
    return;
  }
  debug("dfs2 %d longest %d list :",vx,longest[vx]); for(int a : T[vx]) debug("%d ",a); debug("\n");
	if(add[vx].size())
		add_adj(vx);

	for(int viz : T[vx])
		if(viz != longest[vx]){
			add_edge(vx,viz);
			dfs2(viz,ret);
			if(!stop)
        add_edge(vx,viz);
		}

	add_edge(vx,longest[vx]);
  debug("oi");
	dfs2(longest[vx],0);
  if(!stop && T[longest[vx]].size() > 0)
    add_edge(vx,longest[vx]);

}

std::vector<std::vector<int> > create_map(int _N, int M, std::vector<int> A, std::vector<int> B) {
	// step #1. preparation
  vector<vector<int> > best;
  N = _N;
  if(N == 1){
    ans = vector<vector<int> > (1, vector<int>(1));
    ans[0][0] = 1;
    return ans;
  }
	G = vector<vector<int> > (N);

	for (int i = 0; i < M; i++) {
		A[i]--;
		B[i]--;
		G[A[i]].push_back(B[i]);
		G[B[i]].push_back(A[i]);
	}

  for(int r=0;r<N;r++){

    T = vector<vector<int> > (N);
    ans = vector<vector<int> > (3*N, vector<int>(3*N));
    cnt = K = up = mxp = stop = leaves = 0;

    for(int i=0;i<N;i++){
      vis[i] = 0;
      add[i].clear();
    }
    debug("ok\n");
    endpoint = dfs(r).second;
    debug("ok2\n");
    dfs2(r,1);
    debug("ok3\n");
    debug("diam %d, leaves %d\n",mxp,leaves);


    // step #4. final step
    for (int i = 0; i < int(ans.size()); i++) {
      for (int j = 0; j < int(ans.size()); j++) {
        ans[i][j]++;
      }
    }

    for(int i=K;i<3*N;i++)
      for(int j=0;j<3*N;j++)
        ans[i][j] = ans[i-1][j];

    K = max(K,up);
    vector<vector<int> >  ret (K, vector<int>(K));

    for(int i=0;i<K;i++)
      for(int j=0;j<K;j++)
        ret[i][j] = ans[i][j];

    if(r == 0 || ret.size() < best.size())
      best = ret;
  }
	return best;
}