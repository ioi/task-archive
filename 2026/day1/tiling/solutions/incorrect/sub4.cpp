#include "tiling.h"
#include <bits/stdc++.h>

using namespace std;

int n, m;
int up, down;
vector<pair<int, int>> bs;
vector<vector<int>> top = {
	{0, 1, 0, 1},
	{1, 1, 0, 0},
	{1, 0, 1, 0}
};

void init(int N, int M) {
    n = N; m = M;
	up = 0; down = n - 1;
	bs.assign(n, {0, m - 1});
}

pair<int, int> get(int i, int j) {
	return {i * 2, j * 2};
}

pair<int, int> receive_block(int C0, int C1, int C2, int C3) {
	std::vector<int> color = { C0, C1, C2, C3 };
	if (color[0] && color[1] && color[2] && color[3]) {
		return {-1, -1};
	}
	bool isTop = false;
	for (auto x : top) {
		if (x == color) {
			isTop = true;
		}
	}
	if (isTop) {
		if (bs[up].first > bs[up].second) {
			up++;
		}
		if (color[0]) {
			return get(up, bs[up].first++);
		} else {
			return get(up, bs[up].second--);
		}
	} else {
		if (bs[down].first > bs[down].second) {
			down--;
		}
		if (color[0]) {
			return get(down, bs[down].first++);
		} else {
			return get(down, bs[down].second--);
		}
	}
}