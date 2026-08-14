// solution/zein_wa_Z10^8_naive.cpp
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

vector<vi> G;

int bfs(int start, int N){
    vector<int> dis(N,-1);
    queue<int> q;
    q.push(start);
    dis[start]=0;

    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(auto &v:G[u]){
            if(dis[v]==-1){
                dis[v]=dis[u]+1;
                q.push(v);
            }

        }
    }
    auto it = max_element(dis.begin(), dis.end());
    return it-dis.begin();
}

int send_message(int N, int i, int p)
{

    if (i == 1)
        G.resize(N);
    

    G[i].push_back(p);
    G[p].push_back(i);

    if (N-1 == i)
    {
        int u = bfs(0, N);
        int v = bfs(u, N);
        return u+v*10000;
    }

    return 0;
}

pair<int, int> longest_path(vector<int> S)
{
    int u=S.back()/10000;
    int v=S.back()%10000;

    return {u,v};
}
