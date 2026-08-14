// solution/zein_Z62_mark_last.cpp
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
            bin.push_back(0);
    }
    reverse(bin.begin(), bin.end());
    return bin;
}

// For smallers N
bool freeze = 0;

int lastWritten = -1;

int send_message(int N, int i, int p)
{
    if (i == 1)
    {
        G.resize(N);
        B = ceil(log2(N));
    }

    G[i].push_back(p);
    G[p].push_back(i);

    if (i >= N - 2 * B)
    {
        auto [a, b] = getEndPoints(N);
        if (!freeze)
        {
            freeze = 1;
            u = a;
            v = b;

            lastWritten=v;

            binU = toBinary(u);
            binV = toBinary(v);
        }

        int base = 0;
        if (!binU.empty())
        {
            if (binU.back())
                base = 4 + 2 * B;
            binU.pop_back();
        }
        else
        {
            if (binV.back())
                base = 4 + 2 * B;
            binV.pop_back();
        }
        if (b != lastWritten)
        {
            if (a == u)
                base++;
            else if (a == v)
                base += 2;
            else
                base += 2 + (b - a);
            lastWritten = b;
        }
        return base;
    }
    return 0;
}

int toNumber(int l, int r, vector<int> &S)
{
    int p = 1;
    int s = 0;
    for (int i = l; i < r; i++)
    {
        if (S[i] >= 4 + 2 * B)
            s += p;
        p *= 2;
    }
    return s;
}

pair<int, int> longest_path(vector<int> S)
{
    int N = S.size();
    B = ceil(log2(N));
    u = toNumber(N - 2 * B, N - B, S);
    v = toNumber(N - B, N, S);

    int a = u, b = v;

    for (auto &v : S)
    {
        if (v >= 4 + 2 * B)
            v -= 4 + 2 * B;
    }

    for (int i = N - 2 * B; i < N; i++)
    {
        if (S[i] != 0)
        {
            b = i;
            if (S[i] == 1)
                a = u;
            else if (S[i] == 2)
                a = v;
            else
            {
                int dif = S[i] - 2;
                a = b - dif;
            }
        }
    }

    return {a, b};
}
