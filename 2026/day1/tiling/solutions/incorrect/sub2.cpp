#include "tiling.h"
#include <bits/stdc++.h>

using namespace std;

int n, m;
int up, down;
vector<vector<pair<int, int>>> have(4);

void init(int N, int M) {
    n = N; m = M;
	for (int i = 0; i < n / 2; i++) {
		for (int j = 0; j < m / 2; j++) {
			have[3].push_back({i, j});
		}
		for (int j = m / 2; j < m; j++) {
			have[2].push_back({i, j});
		}
	}
	for (int i = n / 2; i < n; i++) {
		for (int j = 0; j < m / 2; j++) {
			have[1].push_back({i, j});
		}
		for (int j = m / 2; j < m; j++) {
			have[0].push_back({i, j});
		}
	}
}

pair<int, int> get(int i, int j) {
	return {i * 2, j * 2};
}


pair<int, int> receive_block(int C0, int C1, int C2, int C3) {
	std::vector<int> color = { C0, C1, C2, C3 };
	int cur;
	for (int i = 0; i < 4; i++) {
		if (!color[i]) cur = i;
	}
	pair<int, int> res = have[cur].back();
	have[cur].pop_back();
	return get(res.first, res.second);
}