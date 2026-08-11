#include "tiling.h"
#include <bits/stdc++.h>

using namespace std;

int n, m, tot;
vector<vector<int>> val;
set<pair<int, int>> _left;

void init(int N, int M) {
    n = N; m = M;
	tot = n * m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			_left.insert({i, j});
		}
	}
	val.assign(2 * n + 2, vector<int> (2 * m + 2));
}

bool place_tile(int ti, int tj, vector<int> color) {
	int r = 2 * ti - 1, c = 2 * tj - 1;
	val[r][c] = color[0];
	val[r][c + 1] = color[1];
	val[r + 1][c] = color[2];
	val[r + 1][c + 1] = color[3];
	bool ok = true;
	for (int dr = -1; dr <= 1; dr++)
		for (int dc = -1; dc <= 1; dc++) {
			int sr = r + dr, sc = c + dc;
			if (sr < 1 || sc < 1 || sr + 1 > 2 * n || sc + 1 > 2 * m) continue;
			if (val[sr][sc] && val[sr][sc + 1] &&
				val[sr + 1][sc] && val[sr + 1][sc + 1])
				ok = false;
		}	
	if (!ok) {
		val[r][c] = 0;
		val[r][c + 1] = 0;
		val[r + 1][c] = 0;
		val[r + 1][c + 1] = 0;
		return false;
	}
	return ok;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

pair<int, int> receive_block(int C0, int C1, int C2, int C3) {
	std::vector<int> color = { C0, C1, C2, C3 };
	if (color[0] && color[1] && color[2] && color[3]) {
		return {-1, -1};
	}
	vector<pair<int, int>> cur;
	for (auto [x, y] : _left) {
		cur.push_back({x, y});
	}
	int sz = cur.size();
	bool can = false;
	pair<int, int> res;
	for (int _ = 0; _ < 1000; _++) {
		int x = rng() % sz;
		if (place_tile(cur[x].first, cur[x].second, color)) {
			can = true;
			res = {2 * cur[x].first - 2, 2 * cur[x].second - 2};
			_left.erase(_left.find(cur[x]));
			break;
		}
	}
	if (!can) {
		return {-1, -1};
	}
	return res;
}