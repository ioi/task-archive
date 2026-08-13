#include "train.h"

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

const int MAXN = 5000+10;

const int B = 0;
const int A = 1;

bool del[MAXN];
int n;
int mark[MAXN], need[MAXN], par[MAXN];
vector<int> a, r, res;
vector<int> adj[MAXN], bak[MAXN];

bool dfs (int v) {
    mark[v] = 1;
    for (int i = 0; i < (int)adj[v].size(); i++) {
        int u = adj[v][i];
        if (del[u] || r[u])
            continue;
        if (mark[u] == 0) {
            par[u] = v;
            if (dfs(u))
                return true;
        } else if (mark[u] == 1) {
            int cur = v;
            while (true) {
                res[cur] = B;
                if (cur == u)
                    break;
                cur = par[cur];
            }
            return true;
        }
    }
    mark[v] = 2;
    return false;
}

vector<int> who_wins(vector<int> a, vector<int> r, vector<int> u, vector<int> v){
    ::a = a, ::r = r;
    for (int i = 0; i < (int)u.size(); i++) {
        adj[u[i]].push_back(v[i]);
        bak[v[i]].push_back(u[i]);
    }
    n = (int)a.size();
    res.resize(n, A);
    while (true) {
        memset(mark, 0, sizeof mark);
        bool flag = false;
        for (int i = 0; i < n && !flag; i++) if (r[i] == 0 && del[i] == false && mark[i] == 0)
            flag = dfs(i);
        if (flag == false)
            break;
        memset(need, 0, sizeof need);
        queue<int> q;
        for (int i = 0; i < n; i++) if (del[i] == false) {
            if (res[i] == B)
                q.push(i);
            else {
                if (a[i] == B)
                    need[i] = 1;
                else {
                    for (int j = 0; j < (int)adj[i].size(); j++) if (del[adj[i][j]] == false)
                        need[i]++;
                }
            }
        }
        while (!q.empty()) {
            int front = q.front(); q.pop();
            del[front] = true;
            for (int i = 0; i < (int)bak[front].size(); i++) {
                int temp = bak[front][i];
                --need[temp];
                if (need[temp] == 0 && res[temp] == A) {
                    res[temp] = B;
                    q.push(temp);
                }
            }
        }
    }
    return res;
}
