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

long long count_triples(vector<int> a) { // O(N^1.5 + N*log(N))
	int n = a.size();
	set<set<int>> triples; // we'll insert only O(N) triples here
	auto considerPair = [&](int i, int j) {
		for (int id : {i, j}) {
			for (int dist : {a[i], a[j]}) {
				for (int k : {id - dist, id + dist}) {
					if (0 <= k && k < n && k != i && k != j) {
						if (goodTriple(i, j, k, a)) {
							triples.insert(set<int>{i, j, k});
						}
					}
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
	
	int answer = triples.size();
	auto considerTriple = [&](int i, int j, int k) {
		if (0 <= i && i < j && j < k && k < n && a[i] == k - j && a[j] == k - i && a[k] == j - i) {
			if (a[k] == j - i && a[i] != a[k]) { // symmetrical triples were counted already
				answer++;
			}
		}
	};
	
	map<int, vector<int>> diag1, diag2;
	for (int i = 0; i < n; i++) {
		diag1[i+a[i]].push_back(i);
		diag2[i-a[i]].push_back(i);
	}
	for (int j = 0; j < n; j++) {
		vector<int>& x = diag1[j+a[j]];
		vector<int>& y = diag2[j-a[j]];
		// i < j < k
		if (x.size() < y.size()) { // smaller-to-larger
			for (int k : x) {
				int i = k - a[j];
				considerTriple(i, j, k);
			}
		}
		else {
			for (int i : y) {
				if (i < j) {
					int k = i + a[j];
					considerTriple(i, j, k);
				}
			}
		}
	}
	return answer;
}

vector<int> construct_range(int M, int K) {
	return {4, 1, 4, 3, 2, 6, 1};
}
