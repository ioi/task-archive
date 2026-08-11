/* Full solution
 * Author: Hirotaka Yoneda & Masataka Yoneda
 * Complexity: O(N*logN)
 */

#include "monuments.h"
#include <map>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

using ll = long long;

const ll INF = 7LL << 58;

class fenwick_tree {
private:
	int n;
	vector<ll> val;
public:
	fenwick_tree(int n_) : n(n_), val(n_ + 1) {}
	void add(int pos, ll x) {
		for (int i = pos + 1; i <= n; i += i & (-i)) {
			val[i] += x;
		}
	}
	ll sum(int r) const {
		ll res = 0;
		for (int i = r; i >= 1; i -= i & (-i)) {
			res += val[i];
		}
		return res;
	}
};

struct point {
	ll x; int c;
};

struct query {
	int a, b, k;
};

vector<ll> process_queries(int Q, const vector<ll>& A, const vector<ll>& B, const vector<query>& qs) {
	// compute |A[a] - B[b]| + ... + |A[a+k-1] - B[b+k-1]| for given (a, b, k)
	// assumption: A[0] <= ... <= A[N-1], B[0] <= ... <= B[M-1]
	int N = A.size(), M = B.size();
	vector<tuple<int, int, int>> changes;
	for (int i = 0; i < N; i++) {
		int pos = lower_bound(B.begin(), B.end(), A[i] + 1) - B.begin();
		changes.push_back({pos - i, 0, i});
	}
	for (int i = 0; i < M; i++) {
		int pos = (int)(lower_bound(A.begin(), A.end(), B[i]) - A.begin()) - 1;
		changes.push_back({i - pos, 1, i});
	}
	sort(changes.begin(), changes.end());
	fenwick_tree za(N), zb(M);
	for (int i = 0; i < N; i++) {
		za.add(i, +A[i]);
	}
	for (int i = 0; i < M; i++) {
		zb.add(i, -B[i]);
	}
	vector<int> p;
	for (int i = 0; i < Q; i++) {
		if (qs[i].k != -1) {
			p.push_back(i);
		}
	}
	sort(p.begin(), p.end(), [&](int x, int y) -> bool {
		int dx = qs[x].b - qs[x].a;
		int dy = qs[y].b - qs[y].a;
		return dx < dy;
	});
	int pos = 0;
	vector<ll> ans(Q);
	for (int i : p) {
		while (pos != N + M && get<0>(changes[pos]) <= qs[i].b - qs[i].a) {
			int s = get<1>(changes[pos]);
			int t = get<2>(changes[pos]);
			if (s == 0) {
				za.add(t, -2 * A[t]);
			} else {
				zb.add(t, +2 * B[t]);
			}
			pos++;
		}
		ll cost = 0;
		cost += za.sum(qs[i].a + qs[i].k) - za.sum(qs[i].a);
		cost += zb.sum(qs[i].b + qs[i].k) - zb.sum(qs[i].b);
		ans[i] = cost;
	}
	return ans;
}

ll solve_lines(int N, const vector<point>& LA, const vector<point>& LB) {
	// step #1. preparation
	vector<ll> a0, a1, b0, b1;
	vector<int> sa0(N + 1), sa1(N + 1), sb0(N + 1), sb1(N + 1);
	for (int i = 0; i < N; i++) {
		if (LA[i].c == 0) {
			a0.push_back(LA[i].x);
		} else {
			a1.push_back(LA[i].x);
		}
		if (LB[i].c == 0) {
			b0.push_back(LB[i].x);
		} else {
			b1.push_back(LB[i].x);
		}
		sa0[i + 1] = sa0[i] + (int)(LA[i].c == 0);
		sa1[i + 1] = sa1[i] + (int)(LA[i].c == 1);
		sb0[i + 1] = sb0[i] + (int)(LB[i].c == 0);
		sb1[i + 1] = sb1[i] + (int)(LB[i].c == 1);
	}

	// step #2. calculate jumps and queries
	vector<query> qs0(N + 1, query{-1, -1, -1});
	vector<query> qs1(N + 1, query{-1, -1, -1});
	vector<int> pre(2 * N + 1, -1);
	vector<int> jump(N + 1, -1);
	pre[N] = 0;
	for (int i = 1; i <= N; i++) {
		int level = (sa0[i] + sb0[i]) - i + N;
		int l = pre[level];
		jump[i] = l;
		pre[level] = i;
		if (l != -1) {
			qs0[i] = query{sa0[l], sb1[l], sa0[i] - sa0[l]};
			qs1[i] = query{sa1[l], sb0[l], sa1[i] - sa1[l]};
		}
	}

	// step #3. query processing
	vector<ll> res0 = process_queries(N + 1, a0, b1, qs0);
	vector<ll> res1 = process_queries(N + 1, a1, b0, qs1);

	// step #4. dynamic programming
	vector<ll> dp(N + 1, INF);
	dp[0] = 0;
	for (int i = 1; i <= N; i++) {
		if (LA[i - 1].c == 1 && LB[i - 1].c == 1) {
			ll cost = abs(LA[i - 1].x - LB[i - 1].x);
			dp[i] = min(dp[i], dp[i - 1] + cost);
		}
		if (jump[i] != -1) {
			ll cost = res0[i] + res1[i];
			dp[i] = min(dp[i], dp[jump[i]] + cost);
		}
	}
	ll ans = dp[N];

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
    
    if (N % 2 == 1) {
		d[{0, 0}] += 1;
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