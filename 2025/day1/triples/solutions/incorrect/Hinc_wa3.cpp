#include "triples.h"
#include <cassert>
#include <cmath>
#include <algorithm>

using namespace std;

bool goodTriple(int i, int j, int k, const vector<int>& a) {
	assert(i != j && i != k && j != k);
	vector<int> A{a[i], a[j], a[k]};
	vector<int> B{abs(i - j), abs(i - k), abs(j - k)};
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	return A == B;
}

long long count_triples(vector<int> H) {
	int N = H.size();
	int answer = 0;
	for (int h = 2; h < N; ++h) {
		if (H[h] > h)
            continue;
        int l = h - H[h];
        if (l + H[l] < h)
            answer += goodTriple(l, l + H[l], h, H);
        if (h - H[l] > l)
            answer += goodTriple(l, h - H[l], h, H);
	}
	return answer;
}

vector<int> construct_range(int M, int K) {
	return {};
}
