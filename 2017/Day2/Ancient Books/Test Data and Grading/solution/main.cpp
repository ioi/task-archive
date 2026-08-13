#include<bits/stdc++.h>
#include "books.h"
using namespace std;

const int maxn=1e6;
long long ans;
int tmpMIN,tmpMAX,n,ansl,ansr,tmp,MIN[maxn],MAX[maxn],nex[maxn],a[maxn];
bool mark[maxn];
  
void dfs(int v,int u)
{
  mark[v]=true;
  tmpMIN=min(tmpMIN,v),tmpMAX=max(tmpMAX,v);
  MIN[v]=tmpMIN,MAX[v]=tmpMAX;
  if(nex[v]!=u) dfs(nex[v],u);
}

void go(int s)
{
  int l=s,r=s,nl=MIN[s],nr=MAX[s];
  while(nl<l || r<nr)
    {
      if(nl<l) l--,nl=min(nl,MIN[l]),nr=max(nr,MAX[l]);
      else r++,nr=max(nr,MAX[r]),nl=min(nl,MIN[r]);
    }
  while(1)
    {
      int xl=l-1;
      tmp=MIN[xl];
      ansl=1;
      while(xl>=0 && MAX[xl]<l){
	if(tmp>=xl) ansl++;
	xl--;
	tmp=min(tmp,MIN[xl]);
      }
  
      int xr=r+1;
      tmp=MAX[xr];
      ansr=1;
      while(xr<n && MIN[xr]>r){
	if(tmp<=xr) ansr++;
	xr++;
	tmp=max(tmp,MAX[xr]);
      }

      if(xl<0) break;
      ans+=2*min(ansl,ansr);
      while(xl<l || r<xr)
	{
	  if(xl<l)
	    {
	      l--;
	      xl=min(xl,MIN[l]);
	      xr=max(xr,MAX[l]);
	    }
	  else
	    {
	      r++;
	      xl=min(xl,MIN[r]);
	      xr=max(xr,MAX[r]);
	    }
	}
    }
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
	a[tmpMIN]++,a[tmpMAX]--;
      }
    }
  if(ans==0) return 0;
  for(int i=0;i<n;i++)
    {
      if(i) a[i]+=a[i-1];
      if(!a[i] && i<n-1) ans+=2;
    }
  for(int i=0;p[i]==i && i<s;i++)
    ans-=2;
  for(int i=n-1;p[i]==i && i>s;i--)
    ans-=2;
  go(s);
  return ans;
}
