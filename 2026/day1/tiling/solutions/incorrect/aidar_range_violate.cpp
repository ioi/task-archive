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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); 
#define rnd(l, r) uniform_int_distribution<int>(l, r)(rng)

pair<int, int> receive_block(int C0, int C1, int C2, int C3) {
    int x, y;
    x = (rnd(0, 1) ? -1 : 2 * n);
    y = (rnd(0, 1) ? -1 : 2 * m);
    return {x, y};
}