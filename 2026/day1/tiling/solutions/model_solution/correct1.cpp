#include "tiling.h"
#include <bits/stdc++.h>

using namespace std;

int n, m;
int up, down;
vector<pair<int, int>> bs;

void init(int N, int M) {
    n = N; m = M;
	up = 0; down = n - 1;
	bs.assign(n, {1, m});
}

pair<int, int> get(int i, int j) {
	return {(i + 1) * 2 - 2, j * 2 - 2};
}

pair<int, int> receive_block(int C0, int C1, int C2, int C3) {
	std::vector<int> color = { C0, C1, C2, C3 };
	if (color[0] && color[1] && color[2] && color[3]) {
		return {-1, -1};
	}
	if (color[0] && color[1]) {
		if (bs[up].first > bs[up].second) {
			up++;
		}
		if (!color[3]) {
			//to the left
			return get(up, bs[up].first++);
		} else {
			//to the right
			return get(up, bs[up].second--);
		}
	} else {
		if (bs[down].first > bs[down].second) {
			down--;
		}
		if (!color[1]) {
			//to the left
			return get(down, bs[down].first++);
		} else {
			//to the right
			return get(down, bs[down].second--);
		}
	}
}