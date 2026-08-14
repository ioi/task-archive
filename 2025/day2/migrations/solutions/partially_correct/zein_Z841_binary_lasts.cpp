// solution/zein_Z841_binary_lasts.cpp
// {
//   "verdict": "partially_correct",
//   "except": {
//     "samples": "correct"
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

const int MAX_N = 10000;

vector<vi> G;
vi binU, binV;

int u, v;
int B;

int bfs(int start, int N)
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
    auto it = max_element(dis.begin(), dis.end());
    return it - dis.begin();
}

pair<int, int> getEndPoints(int N)
{
    int u = bfs(0, N);
    int v = bfs(u, N);
    if (u > v)
        swap(u, v);
    return {u, v};
}

vector<int> toBinary(int n)
{
    vector<int> bin;
    for (int i = 0; i < B; i++)
    {
        if (n & (1 << i))
            bin.push_back(1);
        else
            bin.push_back(2);
    }
    reverse(bin.begin(), bin.end());
    return bin;
}

// For smallers N
bool freeze=0;

// Where B=ceil( log_2(N) )
// Using (2*B+1) * (2*B) + (2*B+1) = 841
int send_message(int N, int i, int p)
{
    if (i == 1)
    {
        G.resize(N);
        B = ceil(log2(N));
    }
    
    G[i].push_back(p);
    G[p].push_back(i);
    
    if (i >= N - 2 * B - 1 && !freeze)
    {
        freeze = 1;
        auto [a, b] = getEndPoints(N);
        u = a;
        v = b;

        binU = toBinary(u);
        binV = toBinary(v);
    }

    if (i == N - 1)
    {
        auto [a, b] = getEndPoints(N);
        int res = 0;
        if (a != u)
        {
            int dis = i - a + 1;
            res += dis * 2 * B;
        }
        if (b != v)
        {
            int dis = i - b + 1;
            res += dis;
        }
        return res;
    }
    else if (i >= N - B - 1)
    {
        int last = binV.back();
        binV.pop_back();
        return last;
    }
    else if (i >= N - 2 * B - 1)
    {
        int last = binU.back();
        binU.pop_back();
        return last;
    }

    return 0;
}

int toNumber(int l, int r, vector<int> &S)
{
    int p = 1;
    int s = 0;
    for (int i = l; i < r; i++)
    {
        if (S[i] == 1)
            s += p;
        p *= 2;
    }
    return s;
}

pair<int, int> longest_path(vector<int> S)
{
    S.insert(S.begin(), 0);
    int N = S.size();
    B = ceil(log2(N));
    u = toNumber(N - 2 * B - 1, N - B - 1, S);
    v = toNumber(N - B - 1, N - 1, S);
    int difU = S.back() / (2 * B);
    int difV = S.back() % (2 * B);
    if (difU != 0)
        u = N - difU - 1;

    if (difV != 0)
        v = N - difV - 1;

    return {u, v};
}
