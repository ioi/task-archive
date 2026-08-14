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
	
	set<set<int>> triples; // faster with vector
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
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
		}
	}
	return (int) triples.size();
}

vector<int> construct_range(int M, int K) {
	return {4, 1, 4, 3, 2, 6, 1};
}
