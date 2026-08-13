#include<bits/stdc++.h>
#include "books.h"
#define X first
#define Y second
using namespace std;

typedef pair<int,int> pii;
const int maxn=1e6,inf=1e9;
long long ans;
int tmpMIN,tmpMAX,n,tmp,MIN[maxn],MAX[maxn],nex[maxn];
bool mark[maxn];
map<pii,int> dp;
pii P[maxn];

void dfs(int v,int u)
{
  mark[v]=true;
  tmpMIN=min(tmpMIN,v),tmpMAX=max(tmpMAX,v);
  MIN[v]=tmpMIN,MAX[v]=tmpMAX;
  if(nex[v]!=u) dfs(nex[v],u);
}

int go(int l,int r)
{
  if(l==0 && r==n-1) return 0;
  if(dp[pii(l,r)]) return dp[pii(l,r)];
  return dp[pii(l,r)]=min((l==0?inf:go(P[l-1].X,max(P[l-1].Y,r))),(r==n-1?inf:go(min(l,P[r+1].X),P[r+1].Y)))+2;
}

pii mol(int l,int r)
{
  int nl=MIN[l],nr=MAX[r];
  while(nl<l || r<nr)
    {
      if(nl<l) l--,nl=min(nl,P[l].X),nr=max(nr,P[l].Y),l=P[l].X;
      else r++,nl=min(nl,MIN[r]),nr=max(nr,MAX[r]);
    }
  return pii(l,r);
}

long long minimum_walk(vector<int> p, int s)
{
  n=p.size();
  for(int i=0;i<n;i++) nex[i]=p[i];
  for(int i=0;i<n;i++)
    {
      ans+=abs(i-p[i]);
      if(!mark[i]) {
	tmpMIN=tmpMAX=i;
	dfs(i,i);
	dfs(i,i);
      }
    }
  if(ans==0) return 0;
  for(int i=0;p[i]==i && i<s;i++)
    ans-=2;
  for(int i=n-1;p[i]==i && i>s;i--)
    ans-=2;
  for(int i=0;i<n;i++) P[i]=mol(i,i);
  ans+=go(P[s].X,P[s].Y);
  return ans;
}
