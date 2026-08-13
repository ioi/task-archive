#include "train.h"
#include <bits/stdc++.h>
using namespace std;;

const int MAXN = 5000 + 10;

bool b[MAXN], f[MAXN];
int n, qtail;
int q[MAXN];
vector<int> a, r;
vector<int> adj[MAXN];

inline bool is_follower (int v, int who) {
	for (int i = 0; i < (int)adj[v].size(); i++) {
		if (f[adj[v][i]] && who == a[v])
			return true;
		if (!f[adj[v][i]] && who != a[v])
			return false;
	}
	return who != a[v];
}

inline void updateq(int who) {
	while (true) {
		bool flag = false;
		for (int i = qtail - 1; i >= 0; i--) {
			if (is_follower(q[i], who)) {
				f[q[i]] = true;
				swap(q[i], q[qtail-1]);
				qtail--;
				flag = true;
			}
		}
		if (!flag)
			break;
	}
}

vector<int> who_wins(vector<int> a, vector<int> r, vector<int> u, vector<int> v) {
	::a = a;
	::r = r;
	n = (int)a.size();
	for (int i = 0; i < (int)u.size(); i++)
		adj[u[i]].push_back(v[i]);
	while (true) {
		memset(f, false, sizeof f);
		// AREZOU
		for (int i = 0; i < n; i++) {
			if (r[i] && b[i] == false)
				f[i] = true;
			else
				f[i] = false;
		}
		qtail = 0;
		for (int i = 0; i < n; i++) if (b[i] == false && f[i] == false)
			q[qtail++] = i;
		updateq(1);
		if (qtail == 0)
			break;
		for (int i = 0; i < qtail; i++)
			b[q[i]] = true;
		// BORZOU
		qtail = 0;
		for (int i = 0; i < n; i++) {
			if (b[i])
				f[i] = true;
			else
				f[i] = false, q[qtail++] = i;
		}
		updateq(0);
		for (int i = 0; i < n; i++) if (f[i])
			b[i] = true;
	}
	vector<int> res(n, 1);
	for (int i = 0; i < n; i++)
		res[i] = !b[i];
	return res;
}
