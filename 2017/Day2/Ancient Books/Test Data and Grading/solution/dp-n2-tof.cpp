#include<bits/stdc++.h>
#include "books.h"
#define X first
#define Y second
using namespace std;

typedef pair<int,int> pii;
const int maxn=2e6,inf=1e9;
long long ans;
int n,cnt,MIN[maxn],MAX[maxn],nex[maxn],mol[maxn],nl,nr,x,y;
bool mark[maxn],seg[maxn];
map<pii,int> dp;
pii P[maxn];
vector<int>vec;

void dfs(int v,int u)
{
  mark[v]=true;
  mol[v]=cnt;
  MIN[cnt]=min(MIN[cnt],v),MAX[cnt]=max(MAX[cnt],v);
  if(nex[v]!=u) dfs(nex[v],u);
}

int go(int l,int r)
{
  if(l==0 && r==n-1) return 0;
  if(dp[pii(l,r)]) return dp[pii(l,r)];
  return dp[pii(l,r)]=min((l==0?inf:go(P[mol[l-1]].X,max(P[mol[l-1]].Y,r))),(r==n-1?inf:go(min(l,P[mol[r+1]].X),P[mol[r+1]].Y)))+2;
}

void ok(int k)
{
  if(!seg[k])
    nl=min(nl,MIN[k]),nr=max(nr,MAX[k]),vec.push_back(k);
  else
    nl=min(nl,P[k].X),x=min(x,P[k].X),nr=max(nr,P[k].Y),y=max(y,P[k].Y);
}

void fmol(int k)
{
  x=y=MIN[k];
  vec.clear();vec.push_back(k);
  nl=MIN[k],nr=MAX[k];
  while(nl<x || y<nr)
    {
      if(nl<x) x--,ok(mol[x]);
      else y++,ok(mol[y]);
    }
  for(int i=0;i<vec.size();i++)
    P[vec[i]]=pii(x,y),seg[vec[i]]=true;
}

long long minimum_walk(vector<int> p, int s)
{
  n=p.size();
  for(int i=0;i<n;i++) nex[i]=p[i];
  for(int i=0;i<n;i++)
    {
      ans+=abs(i-p[i]);
      if(!mark[i]) {
	MIN[cnt]=MAX[cnt]=i;
	dfs(i,i);
	cnt++;
      }
    }
  if(ans==0) return 0;
  for(int i=0;p[i]==i && i<s;i++)
    ans-=2;
  for(int i=n-1;p[i]==i && i>s;i--)
    ans-=2;
  for(int i=cnt-1;i>-1;i--)
    if(!seg[i])
      fmol(i);
  ans+=go(P[mol[s]].X,P[mol[s]].Y);
  return ans;
}
