// Library solution for all S in O(N^2)
// Score: 70
#include "books.h"
#include <cstdlib>
#include <vector>
#include <map>
#include <iostream>

const int INFTY = 10000000;

using namespace std;
using VI = vector<int>;

// Compute extend(l,r), initially assuming that the only
// cycles not checked yet are C[l] and C[r].
void extend(int &l, int &r, VI &C, VI &L, VI &R) {
	// [ll, rr] is always the current extension,
	// while only [l,r] was already checked for
	// further overlapping cycles.
	int ll = l, rr = r;
	ll = min(ll,min(L[C[l]], L[C[r]]));
	rr = max(rr,max(R[C[l]], R[C[r]]));

	while(ll<l || r<rr) {
		if(ll<l) {
			l--;
			ll = min(ll,L[C[l]]);
			rr = max(rr,R[C[l]]);
		} else {
			r++;
			ll = min(ll,L[C[r]]);
			rr = max(rr,R[C[r]]);
		}
	}
}

// Compute the remaining cost of non-essentially connecting all the cycles
// if we already connected from S to [l,r].
long long int connect(int l, int r, VI &C, VI &L, VI &R, map<pair<int,int>, int> &Memo) {
	extend(l,r,C,L,R);
	// Memoization lookup: Did we compute it already?
	if(Memo.find({l,r}) != Memo.end()) {
		return Memo[{l,r}];
	}
	// If we have to do something, try going one step to the left or to the right
	// and then take the cheaper of the two.
	int nl, nr; // New interval [nl, nr]
	long long int res = INFTY;
	if(l>0) { // Extend to the left.
		nl = l-1; nr = r;
		extend(nl, nr, C, L, R);
		res = 2+connect(nl, nr, C, L, R, Memo);
	}
	if(r<C.size()-1) {
		nl = l; nr = r+1;
		extend(nl, nr, C, L, R);
		res = min(res,2+connect(nl, nr, C, L, R, Memo));
	}
	Memo[{l,r}] = res;
	return res;
}

long long minimum_walk(vector<int> order, int S) {
	int N = order.size();
	long long int dP = 0;
	
	// For every slot i, determine its cycle C[i].
	// For every cycle c, determine its interval [L[c], R[c]].
	vector<int> C(N, -1), L(N), R(N);
	int l = S, r = S; // Compute the range that Mina needs to visit.
	int c = 0; // Number of cycles of Pi.
	for(int i=0; i<N; i++) {
		dP += abs(i-order[i]); // Compute d(pi).
		if(C[i] == -1) { // New cycle detected.
			L[c] = i; R[c] = i; // Initialize its leftmost and rightmost slot
			int j = i;
			do { // Loop over the cycle.
				C[j] = c;
				R[c] = max(R[c], j);
				j = order[j];
			} while (i != j);
			if(i != order[i]) {
				// If the cycle is non-trivial, it needs to be part of the
				// range that Mina has to visit.
				l = min(l,L[c]);
				r = max(r,R[c]);
			}
			c++; // Finished processing the cycle containing slot i.
		}
	}

	// Use dynamic programming to compute the cost of connecting all cycles.
	map<pair<int,int>, int> Memo;
	Memo[{l,r}] = 0; // If we reach the target we are done.
	return dP+connect(S, S, C, L, R, Memo);
}
