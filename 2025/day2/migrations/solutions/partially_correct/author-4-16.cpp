// solution/author-4-16.cpp
// {
//   "verdict": "partially_correct",
//   "except": {
//     "from_root": "correct",
//     "samples": "correct"
//   }
// }
// END HEADER
// ********************************************************
// ** Solution of Z = 4 with 16 writes
// ********************************************************

#include <bits/stdc++.h>
#include "migrations.h"
using namespace std;

// variables for ahmed
namespace device {
	int N, B;
	vector<int> p;
	int u, v;
	int phase, flag, cur;

	// initialization
	void init(int N_) {
		N = N_;
		B = int(ceil(log2(N)));
		p = { -1 };
		u = 0; v = 0;
		phase = 1; flag = -1; cur = 0;
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

		// step #2. if pre-writing phase, don't write
		if (t < N - (B + 2)) {
			return 0;
		}

		// step #3. phase 1
		if (phase == 1) {
			if (pattern == 1 || pattern == 2) {
				phase = 2;
				flag = pattern - 1;
				return 4;
			}
			int bit1 = ((u >> cur) & 1);
			int bit2 = ((v >> cur) & 1);
			cur += 1;
			if (cur == B) {
				phase = 3;
			}
			return bit1 + bit2 * 2;
		}

		// step #4. phase 2
		if (phase == 2) {
			if (pattern == 2) {
				phase = 3;
				return 4;
			}
			int bit = (cur != B ? ((u >> cur) & 1) : flag);
			cur += 1;
			if (cur == B + 1) {
				phase = 3;
			}
			return pattern * 2 + bit;
		}

		// step #5. phase 3
		return pattern;
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

	// step #2. decoding
	int u = -2, v = -1, ubase = 0, vbase = 0, wbase = 0, phase = 1, cur = 0;
	for (int t = max(N - (B + 2), 1); t < N; t++) {
		if (phase == 1) {
			if (Cards[t] == 4) {
				u = -3;
				v = t;
				phase = 2; // Pattern B or C
			}
			else {
				ubase += (Cards[t] % 2) << cur;
				vbase += (Cards[t] / 2) << cur;
				cur += 1;
				if (cur == B) {
					phase = 3;
				}
			}
		}
		else if (phase == 2) {
			if (Cards[t] == 4) {
				u = v;
				v = t; // Pattern C
				phase = 3;
			}
			else {
				int pattern = Cards[t] / 2;
				int bit = Cards[t] % 2;
				wbase += bit << cur;
				cur += 1;
				if (cur == B + 1) {
					phase = 3;
				}
				if (pattern == 1) {
					v = t; // Pattern B
				}
			}
		}
		else {
			if (Cards[t] == 1) {
				v = t; // Pattern B
			}
			if (Cards[t] == 2) {
				u = v;
				v = t; // Pattern C
			}
		}
	}

	// step #3. restoration
	if (phase != 3) {
		ubase = 0;
		vbase = 0;
	}
	if (((wbase >> B) & 1) == 0) {
		ubase += wbase;
		u = (u == -3 ? -2 : u);
		v = (v == -3 ? -2 : v);
	}
	else {
		vbase += wbase - (1 << B);
		u = (u == -3 ? -1 : u);
		v = (v == -3 ? -1 : v);
	}
	u = (u == -2 ? ubase : (u == -1 ? vbase : u));
	v = (v == -2 ? ubase : (v == -1 ? vbase : v));

	return make_pair(u, v);
}
