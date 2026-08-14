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

int dfs(int vx,int par=-1){
  debug("dfs %d\n",vx);
	vis[vx] = 1;
	tin[vx] = cnt++;
	int depth = 0;
	for(int viz : G[vx]){
		if(!vis[viz]){
			T[vx].push_back(viz);
			prof[viz] = 1 + prof[vx];
			int u = 1+dfs(viz,vx);
			if(u > depth){
				depth = u;
				longest[vx] = viz;
			}
		}
		else if(tin[viz] > tin[vx]){
			add[vx].push_back(viz);
		}
	}
	debug("longest[%d] = %d\n",vx,longest[vx]);
	return depth;
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

void dfs2(int vx){
  up = max(up,2);
  if(T[vx].size() == 0) return;
  debug("dfs2 %d longest %d list :",vx,longest[vx]); for(int a : T[vx]) debug("%d ",a); debug("\n");
	if(add[vx].size())
		add_adj(vx);

	for(int viz : T[vx])
		if(viz != longest[vx]){
			add_edge(vx,viz);
			dfs2(viz);
			add_edge(vx,viz);
		}

	add_edge(vx,longest[vx]);
  debug("oi");
	dfs2(longest[vx]);

}

std::vector<std::vector<int> > create_map(int _N, int M, std::vector<int> A, std::vector<int> B) {
	// step #1. preparation
  N = _N;
	G = vector<vector<int> > (N);
	T = vector<vector<int> > (N);
	ans = vector<vector<int> > (3*N, vector<int>(3*N));
	cnt = K = up = 0;

	for (int i = 0; i < M; i++) {
		A[i]--;
		B[i]--;
		G[A[i]].push_back(B[i]);
		G[B[i]].push_back(A[i]);
	}

	for(int i=0;i<N;i++){
		vis[i] = 0;
    add[i].clear();
  }
  debug("ok\n");
	dfs(0);
  debug("ok2\n");
	dfs2(0);
  debug("ok3\n");

	// step #4. final step
	for (int i = 0; i < int(ans.size()); i++) {
		for (int j = 0; j < int(ans.size()); j++) {
			ans[i][j]++;
		}
	}

  K = max(K,up);
  vector<vector<int> >  ret (K, vector<int>(K));

  for(int i=0;i<K;i++)
    for(int j=0;j<K;j++)
      ret[i][j] = ans[i][j];
	return ret;
}