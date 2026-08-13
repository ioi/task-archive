#include "magiccity.h"
#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
#define sz(x) (int)((x).size())
//#define int ll
//#define N
using namespace std;
std::pair<std::vector<int>,std::vector<std::pair<int,int>>> construct(int K) {
	int n=K*2,cnt=0;
	vector<vector<poly>>s(n,vector<poly>(n));
	if (K==1)
	{
		cnt=1;
		s[0][1]={0};
		s[1][0]={0};
	} else if (K==2)
	{
		cnt=3;
		vector<poly>g={
			{0,1},
			{0,2},
			{1,2}
		};
		for (int i=0;i<n;i++)
		{
			int cur=0;
			for (int j=0;j<n;j++)
				if (i!=j)
					s[i][j]=g[cur++];
		}
	} else if (K==3)
	{
		cnt=4;
		vector<poly>g={
			{0,3},
			{1,3},
			{2,3}
		};
		for (int i=0;i<n;i++)
		{
			int cur=0;
			for (int j=0;j<n;j++)
				if (i!=j)
				{
					if (j==(i+1)%n||j==(i+n-1)%n)
						s[i][j]={0,1,2};
					else
						s[i][j]=g[cur++];
				}
		}
	} else if (K==4)
	{
		cnt=5;
		vector<poly>g={
			{0,2,3},
			{0,2,4},
			{0,3,4},
			{1,2,3},
			{1,2,4},
			{1,3,4}
		};
		for (int i=0;i<n;i++)
		{
			int cur=0;
			for (int j=0;j<n;j++)
				if (i!=j)
				{
					if (j==(i^1))
						s[i][j]={0,1};
					else
						s[i][j]=g[cur++];
				}
		}
	} else if (K==5)
	{
		cnt=5;
		vector<poly>g={
			{1,2,3},
			{1,2,3},
			{1,2,4},
			{1,2,4},
			{0,3,4},
			{0,3,4},
			{0,3,4}
		};
		for (int i=0;i<n;i++)
		{
			int cur=0;
			for (int j=0;j<n;j++)
				if (i!=j)
				{
					if (j==(i+n-1)%n)
						s[i][j]={0,1};
					else if (j==(i+1)%n)
						s[i][j]={0,2};
					else
						s[i][j]=g[cur++];
				}
		}
	} else
	{
		cnt=6;
		vector<pa>g={
			{0,1},
			{0,2},
			{0,3},
			{1,2},
			{1,3},
			{2,3}
		};
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++)
				if (i!=j)
				{
					int rk=j-(j>i);
					int col=rk%4;
					for (int k=0;k<6;k++)
						if (g[k].fi==col||g[k].se==col)
							s[i][j].push_back(k);
				}
	}
	vector<int>T(n*cnt);
	vector<pa>E;
	for (int i=0;i<n;i++)
		for (int j=0;j<cnt;j++)
			T[i*cnt+j]=i;
	for (int i=0;i<n;i++)
		for (int j=i+1;j<n;j++)
			for (int k=0;k<sz(s[i][j]);k++)
			{
				int x=i*cnt+s[i][j][k];
				int y=j*cnt+s[j][i][k];
				E.push_back(mp(x,y));
			}
	return mp(T,E);
}