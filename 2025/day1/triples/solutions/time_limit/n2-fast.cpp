#include "triples.h"
#include <cassert>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>

#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")

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
	set<set<int>> triples;
	for(int i=0;i<n;i++){

      int j,k;

      k = i+a[i];
      if(k < n){
        j = i+a[k];
        if(j < k && goodTriple(i,j,k,a))
          triples.insert(set<int>{i, j, k});
        j = k+a[k];
        if(j < n && goodTriple(i,j,k,a))
          triples.insert(set<int>{i, j, k});
        j = i+a[k];
        if(j < n && j != k && goodTriple(i,j,k,a))
          triples.insert(set<int>{i, j, k});
      }
      if(k < n && k-a[k] != i+a[k]){
        j = k-a[k];
        if(j > i && goodTriple(i,j,k,a))
          triples.insert(set<int>{i, j, k});
      }

      k=i-a[i];
      if(k >= 0){
        j = i-a[k];
        if(j > k && goodTriple(i,j,k,a))
          triples.insert(set<int>{i, j, k});
        j = k-a[k];
        if(j >= 0 && goodTriple(i,j,k,a))
          triples.insert(set<int>{i, j, k});
        j = i-a[k];
        if(j >= 0 && j != k && goodTriple(i,j,k,a))
          triples.insert(set<int>{i, j, k});
      }
      if(k >= 0 && k+a[k] != i-a[k]){
        j = k+a[k];
        if(j < i && goodTriple(i,j,k,a))
          triples.insert(set<int>{i, j, k});
      }


      if(i < n/2){
        for(j=i-1;j>=0 && j>=i-a[i];j--){
          k = i+a[j];
          if(k > i && k < n && a[k]==i-j && a[i] == a[j]+a[k] && a[j] != a[k])
            ans++;
        }
      }
      else{
        for(j=i+1;j<n && j<=i+a[i];j++){
          k = i-a[j];
          if(k < i && k >= 0 && a[k] == j-i && a[i] == a[j]+a[k] && a[j] != a[k])
            ans++;
        }
      }


  }
	return ans+triples.size();
}

vector<int> construct_range(int M, int K) {
	return {};
}
