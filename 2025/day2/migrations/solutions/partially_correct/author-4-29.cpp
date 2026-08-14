// solution/author-4-29.cpp
// {
//   "verdict": "partially_correct",
//   "except": {
//     "samples": "correct",
//     "from_root": "correct"
//   }
// }
// END HEADER
// ********************************************************
// ** Solution of Z = 4 with 29 writes
// ********************************************************

#include <bits/stdc++.h>
#include "migrations.h"
using namespace std;

// variables for ahmed
namespace device {
	int N, B;
	vector<int> p;
	int u, v;
	int ubase, vbase, cur;

	// initialization
	void init(int N_) {
		N = N_;
		B = int(ceil(log2(N)));
		p = { -1 };
		u = 0; v = 0;
		ubase = 0; vbase = 0; cur = 0;
	}

	// calculate distance
	int dist(int x, int y) {
		int d = 0;
		while (x != y) {
			if (x > y) {
				x = p[x];
			}
			else {
				y = p[y];
			}
			d += 1;
		}
		return d;
	}

	// function for ahmed
	int ahmed(int t, int parent) {
		// step #1. preparation
		p.push_back(parent);
		int d1 = dist(u, v);
		int d2 = dist(u, t);
		int d3 = dist(v, t);
		int pattern;
		if (d1 >= d2 && d1 >= d3) {
			pattern = 0; // Pattern A
		}
		else if (d1 <= d2 && d2 >= d3) {
			v = t;
			pattern = 1; // Pattern B
		}
		else {
			u = v;
			v = t;
			pattern = 2; // Pattern C
		}
		if (t == N - (B * 2 + 1) - 1) {
			ubase = u;
			vbase = v;
		}

		// step #2. if pre-writing phase, don't write
		if (t < N - (B * 2 + 1)) {
			return 0;
		}

		// step #3. writing phase
		if (pattern == 2) {
			return 4;
		}
		int bit = (cur < B ? (ubase >> cur) & 1 : (cur < 2 * B ? (vbase >> (cur - B)) & 1 : 0));
		cur += 1;
		return pattern * 2 + bit;
	}
}

// dummy function for ahmed
int send_message(int N, int pos, int P) {
	if (pos == 1) {
		device::init(N);
	}
	int res = device::ahmed(pos, P);
	return res;
}

// function for hassan
std::pair<int, int> longest_path(vector<int> Cards) {
	// step #1. preparation
	int N = Cards.size();
	int B = int(ceil(log2(N)));

	// step #2. decoding of (u, v) in pre-writing phase
	int ubase = 0, vbase = 0, cur = 0;
	for (int t = max(N - (2 * B + 1), 1); t < N && cur < 2 * B; t++) {
		if (Cards[t] != 4) {
			int bit = (Cards[t] & 1);
			if (cur < B) {
				ubase += bit << cur;
			}
			else {
				vbase += bit << (cur - B);
			}
			cur += 1;
		}
	}

	// step #3. decode patterns
	int u = ubase, v = vbase;
	for (int t = max(N - (2 * B + 1), 1); t < N; t++) {
		int pattern = Cards[t] / 2;
		if (pattern == 1) {
			v = t; // Pattern B
		}
		if (pattern == 2) {
			u = v;
			v = t; // Pattern C
		}
	}

	return make_pair(u, v);
}