#include "magiccity.h"
#include <bits/stdc++.h>
using namespace std;

std::pair<std::vector<int>, std::vector<std::pair<int, int>>> construct(int k) {
    int n=2*k;
    array<int,4> gr{k/2,k/2,k/2,n-1-k/2*3};
    vector<vector<int>> g(n,vector<int>(n,0));
    for (int i=0;i<n;i++) {
        int v=i;
        for (int j=0;j<4;j++) {
            for (int z=0;z<gr[j];z++) {
                v=(v+1)%n;
                g[i][v]=j;
            }
        }
    }
    vector<pair<int,int>> ans;
    for (int i=0;i<n;i++) for (int j=i+1;j<n;j++) {
        int p1=g[i][j],p2=g[j][i];
        int tt=0;
        vector<int> v0,v1;
        for (int a=0;a<=3;a++) for (int b=a+1;b<=3;b++) {
            if (a==p1||b==p1) v0.push_back(6*i+tt);
            if (a==p2||b==p2) v1.push_back(6*j+tt);
            tt++;
        }
        assert(tt==6);
        assert(v0.size()==3);
        assert(v1.size()==3);
        for (int z=0;z<3;z++) {
            ans.push_back({v0[z],v1[z]});
        }
    }
    vector<int> T;
    for (int i=0;i<6*n;i++) T.push_back(i/6);
	return {T, ans};
}