#include "tiling.h"
#include <bits/stdc++.h>

using namespace std;

int n, m;
int l, r;
int pos_left, pos_right;

void init(int N, int M) {
    n = N; m = M;
	l = 0; r = m - 1;
    pos_left = 0;
    pos_right = n - 1;
}

pair<int, int> get(int i, int j) {
	return {i * 2, j * 2};
}

pair<int, int> receive_block(int C0, int C1, int C2, int C3) {
	vector<int> color = { C0, C1, C2, C3 };
	if (color[0] && color[1] && color[2] && color[3]) {
		return {-1, -1};
	}
	if (color[0] && color[2]) {
        auto res = get(pos_left, l);
        pos_left++;
        if (pos_left == n) {
            l++;
            pos_left = 0;
        }
        return res;
	} else {
        auto res = get(pos_right, r);
        pos_right--;
        if (pos_right == -1) {
            r--;
            pos_right = n - 1;
        }
        return res;
	}
}