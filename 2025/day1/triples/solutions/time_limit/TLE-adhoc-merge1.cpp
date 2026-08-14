#include "triples.h"
#include <cassert>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

bool goodTriple(int i, int j, int k, const vector<int>& a) {
	assert(i != j && i != k && j != k);
	vector<int> A{a[i], a[j], a[k]};
	vector<int> B{abs(i - j), abs(i - k), abs(j - k)};
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	return A == B;
}

long long count_triples(vector<int> a) {
	int n = a.size();
	vector<vector<int>> triples;
	auto considerPair = [&](int i, int j) {
		for (int k : {i - a[i], i - a[j], j - a[i], j - a[j], i + a[i], i + a[j], j + a[i], j + a[j]}) {
			if (0 <= k && k < n && k != i && k != j) {
				//if (a[i] + a[j] + a[k] == abs(i-j) + abs(i-k) + abs(j-k))
				if (goodTriple(i, j, k, a)) {
					vector<int> t{i, j, k};
					sort(t.begin(), t.end());
					triples.push_back(t);
				}
			}
		}
	};
	
	for (int i = 0; i < n; i++) {
		for (int j : {i - a[i], i + a[i]}) {
			if (0 <= j && j < n) {
				considerPair(i, j);
			}
		}
	}
	map<int, vector<int>> diag1, diag2;
	for (int i = 0; i < n; i++) {
		diag1[i+a[i]].push_back(i);
		diag2[i-a[i]].push_back(i);
	}
	for (int i = 0; i < n; i++) {
		vector<int>& x = diag1[i+a[i]];
		vector<int>& y = diag2[i-a[i]];
		for (int j : x) {
			if (j > i) {
				considerPair(i, j);
			}
		}
	}
	sort(triples.begin(), triples.end());
	return unique(triples.begin(), triples.end()) - triples.begin();
}

vector<int> construct_range(int M, int K) {
	return {};
}
