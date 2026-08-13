#include "train.h"
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn=5000;
bool mark[maxn],col[maxn][2];
vector<int> vec,ans,r,arezou,G[maxn],G1[maxn],topo;
int cnt,n,m,t[maxn],mol[maxn],deg[maxn];

bool good(int v)
{
  if(ans[v]==0) return false;
  return (arezou[v]==0 || deg[v]==G[v].size());
}

bool ok(int v)
{
  if(mark[v]) return false;
  return (r[v]==0 && ((arezou[v] &&  col[v][1]==0)||(arezou[v]==0 && col[v][0]==1)));
}

void dfs1(int v)
{
  mark[v]=true;
  mol[v]=cnt;
  t[cnt]++;
  for(int i=0;i<G1[v].size();i++)
    {
      int u=G1[v][i];
      if(ok(u))
	dfs1(u);
    }
}

void dfs(int v)
{
  mark[v]=true;
  for(int i=0;i<G[v].size();i++)
    {
      int u=G[v][i];
      if(ok(u))
	dfs(u);
    }
  topo.push_back(v);
}

void bfs()
{
  while(vec.size())
    {
      int v=vec.back();
      vec.pop_back();
      for(int i=0;i<G1[v].size();i++)
	{
	  int u=G1[v][i];
	  deg[u]++;
	  if(good(u)) vec.push_back(u),ans[u]=0;
	}
    }
}

vector<int> who_wins(vector<int> a, vector<int> R, vector<int> from, vector<int> to)
{
  arezou=a;
  r=R;
  n=a.size(),m=from.size();
  for(int i=0;i<n;i++) ans.push_back(1);
  for(int i=0;i<m;i++)
    {
      G[from[i]].push_back(to[i]);
      G1[to[i]].push_back(from[i]);
      col[from[i]][r[to[i]]]=true;
    }
  for(int i=0;i<n;i++)
    if(ok(i))
      dfs(i);
  memset(mark,false,sizeof mark);
  for(int i=topo.size()-1;i>-1;i--)
    {
      int v=topo[i];
      if(ok(v)){
	cnt++;
	dfs1(v);
      }
    }
  for(int i=0;i<n;i++) if(t[mol[i]]>1) vec.push_back(i),ans[i]=0;
  bfs();
  return ans;
}
