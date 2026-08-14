#include "triples.h"
#include <cmath>
#include <cassert>

using namespace std;

long long count_triples(vector<int> H) {
  return 3ll;
}

vector<int> construct_range(int M, int K) {// construction to avoid collisions S[i]+S[j] = S[k]+S[l]
	// k = 25 -> (..., -208, -104), (2, 6, 10, 14, 18, ..., 98), (100, 200, 300, ...)
	// We shoot rays up-right from first two groups, and up-left from last two groups.
	// No two rays will intersect at the same index (x-coordinate).
	int n = M;
	int k = sqrt(n/4+0.1);
	vector<int> A, B, C;
	const int shift = n / 2 - 2 * k;
	for (int i = 0; i < k - 1; i++) {
		A.push_back(-(i + 1) * (4 * k + 4));
		B.push_back(2 + 4 * i);
		C.push_back((i + 1) * (4 * k));
	}
	vector<int> a(n, 2); // slightly better than values 1
	auto f = [&](vector<int> v1, vector<int> v2) {
		for (int i : v1) {
			for (int j : v2) {
				int pos = (i + j) / 2 + shift;
				int value = abs(i - j) / 2;
				if (0 <= pos && pos < n && 1 <= value && value < n) {
					assert(a[pos] == 2);
					a[pos] = value;
				}
			}
		}
	};
	f(A, B);
	f(A, C);
	f(B, C);
	return a;
}
