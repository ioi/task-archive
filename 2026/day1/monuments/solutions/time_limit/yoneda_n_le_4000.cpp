
#include "monuments.h"
#include <map>
#include <cmath>
#include <random>
#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;

using ll = long long;

const ll INF = 7LL << 58;

struct point {
	ll x; int c;
};

ll solve_lines(int N, const vector<point>& LA, const vector<point>& LB) {
	vector<ll> a0, a1;
	for (int i = 0; i < N; i++) {
		if (LA[i].c == 0) {
			a0.push_back(LA[i].x);
		} else {
			a1.push_back(LA[i].x);
		}
	}
	vector<vector<ll>> dp(a1.size() + 1, vector<ll>(a0.size() + 1, -1));
	auto recur = [&](auto& self, int x, int y) -> ll {
		if (x == (int)a1.size() && y == (int)a0.size()) {
			return 0;
		}
		if (dp[x][y] != -1) {
			return dp[x][y];
		}
		ll res = INF;
		if (x != (int)a1.size()) {
			ll subres = self(self, x + 1, y);
			ll cost = abs(a1[x] - LB[x + y].x);
			res = min(res, subres + cost);
		}
		if (y != (int)a0.size() && LB[x + y].c == 1) {
			ll subres = self(self, x, y + 1);
			ll cost = abs(LB[x + y].x - a0[y]);
			res = min(res, subres + cost);
		}
		dp[x][y] = res;
		return res;
	};
	ll ans = recur(recur, 0, 0);
	return ans;
}

ll get_cost(vector<int> X, vector<int> P) {
    int N = (int) X.size();
	// remove the red points in the symmetric position
	vector<int> C(N, 1); // 0: red, 1: blue
	for (int i : P) {
		C[i] = 0;
	}
	map<pair<ll, int>, int> d;
	for (int i = 0; i < N; i++) {
		d[{X[i], C[i]}]++;
	}
	for (const auto &[x, y] : d) {
		if (x.second == 0 && x.first > 0 && d.find({-x.first, 0}) != d.end()) {
			int dec = min(d[{-x.first, 0}], y);
			d[{x.first, 0}] -= dec;
			d[{-x.first, 0}] -= dec;
		}
	}
	if (d.find({0, 0}) != d.end()) {
		d[{0, 0}] = d[{0, 0}] % 2;
	}
	if (N % 2 == 1) {
		d[{0, 0}] += 1;
	}
	vector<int> NX;
	vector<int> NC;
	for (const auto &[x, y] : d) {
		for (int i = 0; i < y; i++) {
			NX.push_back(x.first);
			NC.push_back(x.second);
		}
	}
	N = NX.size();
	X = NX;
	C = NC;
	int left_red = 0, red = 0;
	for (int i = 0; i < N; i++) {
		if (C[i] == 0) {
			red++;
			if (X[i] < 0) {
				left_red++;
			}
		}
	}
	if (red > N / 2) {
		return -1;
	}
	vector<point> LA, LB;
	int left_blue_cnt = 0;
	for (int i = 0; i < N; i++) {
		if (C[i] == 0) {
			if (X[i] < 0) {
				LA.push_back(point{-X[i], 0});
			} else {
				LB.push_back(point{X[i], 0});
			}
		} else {
			if (left_blue_cnt < N / 2 - left_red) {
				LA.push_back(point{-X[i], 1});
				left_blue_cnt++;
			} else {
				LB.push_back(point{X[i], 1});
			}
		}
	}
	reverse(LA.begin(), LA.end());
	ll ans = solve_lines(N / 2, LA, LB);
	return ans;
}