#include "train.h"

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 5000+10;

const int B = 0;
const int A = 1;

int need[MAXN]; 
vector<int> adj[MAXN], bak[MAXN];

vector<int> who_wins(vector<int> a, vector<int> r, vector<int> u, vector<int> v){
    for (int i = 0; i < (int)u.size(); i++) {
        adj[u[i]].push_back(v[i]);
        bak[v[i]].push_back(u[i]);
    }
    int n = (int)a.size();
    for (int i = 0; i < n; i++) {
        if (a[i] == A)
            need[i] = 1;
        else
            need[i] = adj[i].size();
    }
    int who = 0;
    for (int i = 0; i < n; i++) if (r[i] == 1)
        who = i;
    vector<int> res(n, B);
    res[who] = A;
    queue<int> q;
    q.push(who);
    while (!q.empty()) {
        int front = q.front(); q.pop();
        for (int i = 0; i < (int)bak[front].size(); i++) {
            int temp = bak[front][i];
            --need[temp];
            if (need[temp] == 0 && res[temp] == B) {
                q.push(temp);
                res[temp] = A;
            }
        }
    }
    if (need[who] > 0)
        res = vector<int>(n, B);
    return res;
}
