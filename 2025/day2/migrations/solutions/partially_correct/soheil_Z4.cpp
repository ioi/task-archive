// solution/soheil_Z4.cpp
// {
//   "verdict": "partially_correct",
//   "except": {
//     "from_root": "correct",
//     "samples": "correct"
//   }
// }
// END HEADER
#include "migrations.h"
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pll;

#define X		first
#define Y		second
#define debug(x)	cerr << #x << ": " << x << endl;

const int MAXN = 10000 + 10;
const int BASE = 2;
const int LOG = 14;

namespace A {
	int dist[2][MAXN];
	vector<int> adj[MAXN];
	pll d = {1, 1}, fd = {1, 1};
	bool BM = false;

	void dfs(int ind, int v, int p) {
		dist[ind][v] = dist[ind][p] + 1;
		for (int u : adj[v]) {
			if (u == p) continue;
			dfs(ind, u, v);
		}
	}

	int score(pll x) {
		return int(x.X == d.X) + int(x.Y == d.Y);
	}

	int send_message(int n, int v, int p) {
		v++; p++; // 1-based
		adj[p].push_back(v);
		adj[v].push_back(p);

		if (v > n - 2 * LOG && !BM) {
			BM = true;
			fd = d;
			fd.X = fd.X - 1;
			fd.Y = fd.Y - 1;
		}

		pll dn = {-1, -1};
	 	int dl = -1;

		auto [a, b] = d;
		dfs(0, a, 0);
		dfs(1, b, 0);
	
		for (int i = 1; i <= v; i++) {
			pll dc = {a, i};
			int lc = dist[0][i];

			if (lc > dl) {
				dn = dc;
				dl = lc;
			} else if (lc == dl && score(dc) > score(dn)) {
				dn = dc;
			}
		}

		for (int i = 1; i <= v; i++) {
			pll dc = {i, b};
			int lc = dist[1][i];

			if (lc > dl) {
				dn = dc;
				dl = lc;
			} else if (lc == dl && score(dc) > score(dn)) {
				dn = dc;
			}
		}
		
		if (!BM) {
			d = dn;
			return 0;
		}

		int part = ((v > n - LOG) ? 1 : 0);
		int base = ((part == 0) ? (n - 2 * LOG + 1) : (n - LOG + 1));	
		int sent = (part ? (fd.Y >> (v - base) & 1) : (fd.X >> (v - base) & 1));

		if (dn.X != d.X) {
			if (part == 0) sent = 4;
			else sent += 2;
		}

		if (dn.Y != d.Y) {
			if (part == 1) sent = 4;
			else sent += 2;
		}

		assert(score(dn) > 0);
		d = dn;
		
	//	cerr << endl << "! " <<  d.X << ' ' << d.Y << endl;
		return sent;
	}
}

namespace B {
	pll ans = {0, 0};
	pll m = {-1, -1};
	pll answer(vector<int> S) {	
		int n = S.size();
		for (int i = 0; i < n; i++) {
			int x = S[i];
			if (i >= n - LOG) {
				int ind = i - (n - LOG);
				if (x == 4) m.Y = i;
				else {
					if (x >= 2) {
						x -= 2;
						m.X = i;
					}

					ans.Y = ans.Y ^ (x << ind);
				}
			} else if (i >= n - 2 * LOG) {
				int ind = i - (n - 2 * LOG);
				if (x == 4) m.X = i;
				else {
					if (x >= 2) {
						x -= 2;
						m.Y = i;
					}

					ans.X = ans.X ^ (x << ind);
				}
			}
		}

		if (m.X != -1) ans.X = m.X;
		if (m.Y != -1) ans.Y = m.Y;
		return ans;
	}
}

int send_message(int N, int i, int P) {
	return A::send_message(N, i, P);
}

pair<int, int> longest_path(vector<int> S) {
	return B::answer(S);
}
