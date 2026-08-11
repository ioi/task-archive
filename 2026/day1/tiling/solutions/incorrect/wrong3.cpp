#include "tiling.h"
#include <bits/stdc++.h>

using namespace std;

int n, m;
int up, down;
int pos_up, pos_down;

void init(int N, int M) {
    n = N; m = M;
	up = 0; down = n - 1;
    pos_up = 0;
    pos_down = m - 1;
}

pair<int, int> get(int i, int j) {
	return {i * 2, j * 2};
}

pair<int, int> receive_block(int C0, int C1, int C2, int C3) {
	vector<int> color = { C0, C1, C2, C3 };
	if (color[0] && color[1] && color[2] && color[3]) {
		return {-1, -1};
	}
	if (color[0] && color[1]) {
        auto res = get(up, pos_up);
        pos_up++;
        if (pos_up == m) {
            up++;
            pos_up = 0;
        }
        return res;
	} else {
        auto res = get(down, pos_down);
        pos_down--;
        if (pos_down == -1) {
            down--;
            pos_down = m - 1;
        }
        return res;
	}
}