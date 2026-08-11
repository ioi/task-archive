#include "tiling.h"
#include <bits/stdc++.h>

using namespace std;

int n, m;
int up, down;

void init(int N, int M) {
    n = N; m = M;
	up = 0; down = n * m - 1;
}

pair<int, int> get(int i, int j) {
	return {i * 2, j * 2};
}


pair<int, int> receive_block(int C0, int C1, int C2, int C3) {
	std::vector<int> color = { C0, C1, C2, C3 };
	if (color[0] || color[1]) {
		int x = up / m;
		int y = up % m;
		up++;
		return get(x, y);
	} else {
		int x = down / m;
		int y = down % m;
		down--;
		return get(x, y);
	}
}