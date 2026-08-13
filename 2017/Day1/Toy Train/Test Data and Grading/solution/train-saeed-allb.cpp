#include "train.h"

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN = 5000+10;

const int B = 0;
const int A = 1;

bool win[MAXN], mark[MAXN];
int n_comp;
int comp[MAXN], gomark[MAXN];
vector<int> r;
vector<int> order;
vector<int> adj[MAXN], bak[MAXN], q[MAXN];

void dfs(int v) {
    mark[v] = true;
    for (int i = 0; i < (int)adj[v].size(); i++) if (!mark[adj[v][i]])
        dfs(adj[v][i]);
    order.push_back(v);
}

void dfs2(int v, int id) {
    comp[v] = id;
    for (int i = 0; i < (int)bak[v].size(); i++) if (comp[bak[v][i]] == -1)
        dfs2(bak[v][i], id);
    q[id].push_back(v);
}

bool go(int v) {
    gomark[v] = 1;
    for (int i = 0; i < (int)adj[v].size(); i++) {
        int u = adj[v][i];
        if (r[u] || comp[u] != comp[v])
            continue;
        if (gomark[u] == 0) {
            if (go(u))
                return true;
        } else if (gomark[u] == 1)
            return true;
    }
    gomark[v] = 2;
    return false;
}

vector<int> who_wins(vector<int> a, vector<int> r, vector<int> u, vector<int> v){
    ::r = r;
    for (int i = 0; i < (int)u.size(); i++) {
        adj[u[i]].push_back(v[i]);
        bak[v[i]].push_back(u[i]);
    }
    int n = (int)a.size();
    for (int i = 0; i < n; i++) if (mark[i] == false)
        dfs(i);
    memset(comp, -1, sizeof comp);
    memset(mark, 0, sizeof mark);
    for (int i = n-1; i >= 0; i--) if (comp[order[i]] == -1) {
        dfs2(order[i], n_comp++);
        for (int j = 0; j < (int)q[n_comp-1].size() && !win[n_comp-1]; j++) if (gomark[q[n_comp-1][j]] == 0 && r[q[n_comp-1][j]] == 0)
            win[n_comp-1] |= go(q[n_comp-1][j]);
    }
	for (int i = n_comp-1; i >= 0; i--)
		for (int j = 0; j < (int)q[i].size(); j++)
			for (int k = 0; k < (int)adj[q[i][j]].size(); k++)
				win[comp[q[i][j]]] |= win[comp[adj[q[i][j]][k]]];
    vector<int> res;
    for (int i = 0; i < n; i++)
        res.push_back(win[comp[i]] ? B : A);
    return res;
}
