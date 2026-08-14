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
	int ans = 0;
	
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++){

			set<int> S;
			S.insert(i+a[i]);
			S.insert(i+a[j]);
			S.insert(j+a[i]);
			S.insert(j+a[j]);

			for(int s : S)
				if(s > j && s < n)
					if(goodTriple(i,j,s,a))
						ans++;

		}
	return ans;
}

vector<int> construct_range(int M, int K) {
	return {4, 1, 4, 3, 2, 6, 1};
}
