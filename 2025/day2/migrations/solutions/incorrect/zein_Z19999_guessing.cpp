// solution/zein_Z19999_guessing.cpp
// {
//   "verdict": "incorrect",
//   "except": {
//     "samples": "correct",
//     "from_root": "partially_correct"
//   }
// }
// END HEADER

#include "migrations.h"
#include <bits/stdc++.h>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

typedef vector<int> vi;

const int MAX_N=10001;

vector<vi> G;

int father[MAX_N];

int new_root;

vi bfs(int start, int N)
{
    vector<int> dis(N, -1);
    queue<int> q;
    q.push(start);
    dis[start] = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto &v : G[u])
        {
            if (dis[v] == -1)
            {
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }

    vector<int> mdis;
    int maxDis=0;
    for(int i=0;i<N;i++){
        if(maxDis<dis[i]){
            maxDis=dis[i];
            mdis.clear();
        }
        if(maxDis==dis[i])
            mdis.push_back(i);
    }
    return mdis;
}

vector<int> leafs;

int send_message(int N, int i, int p)
{

    if (i == 1)
        G.resize(N);

    G[i].push_back(p);
    G[p].push_back(i);
    father[i]=p;

    if (N - 2 == i)
    {   
        leafs=bfs(0,N);
        sort(leafs.begin(),leafs.end());
        new_root = leafs[0];
        return new_root;
    }

    if (N - 1 == i)
    {
        int res=0;
        if(binary_search(leafs.begin(), leafs.end(), p)){
            int a=p, b=new_root;
            while(a!=0 && b!=0){
                if(a==b)
                    res=10000;
                a=father[a];
                b=father[b];   
            }
        }
        int v=bfs(new_root,N)[0];
        res+=v;
        return res;
    }

    return 0;
}

pair<int, int> longest_path(vector<int> S)
{
    int N=S.size();

    bool is_new_root = S.back()/10000;
    int u,v;
    if(is_new_root)
        u=N-1;
    else
        u=S[N-2];
    v=S.back()%10000;
    
    return {u, v};
}
