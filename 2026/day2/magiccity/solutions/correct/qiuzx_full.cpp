#include "magiccity.h"
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 1000
using namespace std;
int n,k,col[N],to[5]={0,1,2,4,3},tp[10][3]={{0,1,2},{0,1,3},{2,3,5},{2,3,4},{1,4,5},{0,2,4},{1,3,4},{1,2,5},{0,3,5},{0,4,5}};
bool nei[N][N];
void addedge(int x,int y){
	nei[x][y]=nei[y][x]=true;
	return;
}
pair<vector<int>,vector<pair<int,int> > > construct(int K){
	k=K;
	if(k==1){
		n=2;
		col[0]=0,col[1]=1;
		addedge(0,1);
	}
	else if(k==2){
		n=12;
		for(int i=0;i<4;i++){
			vector<int> v;
			for(int j=0;j<4;j++) if(i!=j) v.push_back(j);
			for(int j=0;j<3;j++) col[i*3+j]=v[j];
			addedge(i*3+0,i*3+1),addedge(i*3+1,i*3+2),addedge(i*3+2,i*3+0);
		}
	}
	else if(k==3){
		n=24;
		int o=0;
		for(int t=0;t<2;t++) for(int i=t*3;i<(t+1)*3;i++) for(int j=i+1;j<(t+1)*3;j++){
			vector<int> v;
			for(int x=0;x<6;x++) if(i!=x&&j!=x) v.push_back(x);
			for(int x=0;x<4;x++) col[o*4+x]=v[x];
			for(int x=0;x<4;x++) for(int y=x+1;y<4;y++) addedge(o*4+x,o*4+y);
			o++;
		}
	}
	else if(k==4){
		n=40;
		for(int i=0;i<n;i++) col[i]=i/5;
		for(int i=0;i<k*2;i++) for(int j=0;j<5;j++){
			if("11100"[j]=='1') addedge(i*5+j,((i+1)%(k*2))*5+to[j]);
			if("10010"[j]=='1') addedge(i*5+j,((i+2)%(k*2))*5+to[j]);
			if("01011"[j]=='1') addedge(i*5+j,((i+3)%(k*2))*5+to[j]);
			if("00111"[j]=='1') addedge(i*5+j,((i+4)%(k*2))*5+j);
		}
	}
	else if(k==5){
		n=50;
		for(int i=0;i<n;i++) col[i]=i/5;
		for(int i=0;i<k*2;i++) for(int j=0;j<5;j++){
			if("11100"[j]=='1') addedge(i*5+j,((i+1)%(k*2))*5+to[j]);
			if("10010"[j]=='1') addedge(i*5+j,((i+2)%(k*2))*5+to[j]);
			if("01011"[j]=='1') addedge(i*5+j,((i+3)%(k*2))*5+to[j]);
			if("00111"[j]=='1') addedge(i*5+j,((i+4)%(k*2))*5+to[j]);
			if("11100"[j]=='1') addedge(i*5+j,((i+5)%(k*2))*5+j);
		}
	}
	else{
		n=12*k;
		for(int i=0;i<n;i++) col[i]=i/6;
		for(int i=0;i<n;i++) for(int j=0;j<n;j++) nei[i][j]=false;
		vector<int> seq;
		if(k%6==0) seq=vector<int>{2,4,5,6,8};
		if(k%6==1) seq=vector<int>{1,3,4,5,7,8};
		if(k%6==2) seq=vector<int>{1,2,2,4,5,6,9};
		if(k%6==3) seq=vector<int>{1,1,2,3,4,5,7,9};
		if(k%6==4) seq=vector<int>{2,6,9};
		if(k%6==5) seq=vector<int>{1,3,7,9};
		int lft=(k-((int)seq.size())-1)/6;
		for(int i=0;i<lft;i++){
			seq.push_back(0);
			seq.push_back(1);
			seq.push_back(2);
			seq.push_back(3);
			seq.push_back(4);
			seq.push_back(9);
		}
		assert((int)seq.size()==k-1);
		for(int i=0;i<k*2;i++) for(int j=0;j<k-1;j++){
			for(int o=0;o<3;o++) addedge(i*6+tp[seq[j]][o],((i+j+1)%(k*2))*6+tp[seq[j]][o]);
		}
		for(int i=0;i<k*2;i++) for(int o=0;o<3;o++) addedge(i*6+o,((i+k)%(k*2))*6+o);
	}
	vector<int> _x;
	vector<pair<int,int> > _y;
	for(int i=0;i<n;i++) _x.push_back(col[i]);
	for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) if(nei[i][j]) _y.push_back(make_pair(i,j));
	return make_pair(_x,_y);
}
