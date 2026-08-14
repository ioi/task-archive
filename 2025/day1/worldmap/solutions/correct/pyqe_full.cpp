#include <bits/stdc++.h>
#include "worldmap.h"

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long nn,eu[169],peu[169],lna[169],pln[169],sq[169][169],zs;
vector<long long> al[69];
bitset<69> vtd,ve[69];
pair<long long,long long> as[69];

void dfs(long long x)
{
	long long i,l,sz=al[x].size();
	
	vtd[x]=1;
	eu[nn]=x;
	lna[nn]=3;
	peu[x]=nn;
	nn++;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			dfs(l);
			eu[nn]=x;
			lna[nn]=1;
			nn++;
		}
	}
}

vector<vector<int>> create_map(int n,int m,vector<int> ka,vector<int> la)
{
	long long i,j,k,l,w,p,sz,ofs;
	vector<int> v;
	vector<vector<int>> ret;
	
	for(i=1;i<=n;i++)
	{
		al[i].clear();
		as[i]={0,i};
		ve[i].reset();
	}
	vtd.reset();
	for(i=0;i<m;i++)
	{
		k=ka[i];
		l=la[i];
		al[k].push_back(l);
		al[l].push_back(k);
	}
	nn=0;
	dfs(1);
	for(;nn&&lna[nn-1]==1;nn--);
	for(i=1;i<=nn;i++)
	{
		pln[i]=pln[i-1]+lna[i-1];
		ve[eu[i-1]][eu[i]]=1;
		ve[eu[i]][eu[i-1]]=1;
	}
	zs=n*2;
	ofs=zs-1-pln[nn]/2;
	for(i=0;i<=zs*2-2;i++)
	{
		p=min(max((long long)(upper_bound(pln,pln+nn+1,i-ofs)-pln-1),0ll),nn-1);
		for(j=0;j<zs;j++)
		{
			if(i-j>=0&&i-j<zs)
			{
				sq[i-j][j]=eu[p];
				if(lna[p]==3&&i==pln[p]+1+ofs)
				{
					as[eu[p]].fr++;
				}
			}
		}
	}
	sort(as+1,as+n+1,greater<pair<long long,long long>>());
	for(i=1;i<=n;i++)
	{
		k=as[i].sc;
		w=pln[peu[k]]+1+ofs;
		sz=al[k].size();
		for(p=0,j=0;j<zs;j++)
		{
			if(w-j>=0&&w-j<zs)
			{
				for(;p<sz;p++)
				{
					l=al[k][p];
					if(!ve[k][l])
					{
						break;
					}
				}
				if(p>=sz)
				{
					break;
				}
				sq[w-j][j]=l;
				ve[k][l]=1;
				ve[l][k]=1;
				p++;
			}
		}
	}
	for(i=0;i<zs;i++)
	{
		v.clear();
		for(j=0;j<zs;j++)
		{
			v.push_back(sq[i][j]);
		}
		ret.push_back(v);
	}
	return ret;
}
