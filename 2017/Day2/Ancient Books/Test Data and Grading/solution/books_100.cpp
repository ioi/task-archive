// Library solution for all S in O(N)
// Score: 100
#include "books.h"
#include <cstdlib>
#include <vector>
#include <map>
#include <iostream>
#include <cassert>

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
// if we already connected from S to [l,r] but need to go until we covered
// all of [target_l, target_r].
int connect(int l, int r, int target_l, int target_r, VI &C, VI &L, VI &R) {
	int cost = 0;

	// Repeat as long as [l,r] != [target_l, target_r]
	do {
		extend(l,r,C,L,R);
		// Compute whether there is a next S-including cycle C_l to the left of l 
		// and its reaching cost c_l.
		bool next_l = false; // Does C_l exist?
		int cost_l = 0;
		int l_l=l, r_l=r; // Temporary interval [l_l, r_l].
		while(true) {
			if(l_l<=target_l) break;
			l_l--;
			cost_l += 2;
			extend(l_l,r_l,C,L,R);
			if(r_l>r) { // Detect extension on the other side.
				next_l = true;
				break;
			}
		}
		// Compute whether there is a next S-including cycle C_r to the right of r
		// and its reaching cost c_r.
		bool next_r = false; // Does C_r exist?
		int cost_r = 0;
		int l_r=l, r_r=r; // Temporary interval [l_r, r_r].
		while(true) {
			if(r_r>=target_r) break;
			r_r++;
			cost_r += 2;
			extend(l_r,r_r,C,L,R);
			if(l_r<l) { // Detect extension on the other side.
				next_r = true;
				break;
			}
		}
		// Either there was an S-including cycle on both sides or on none.
		assert(!(next_l ^ next_r)); 
		if(next_l && next_r) { // We can extend on both sides.
			cost += min(cost_l, cost_r); // Take the cheaper of both options.
		} else {
			// If there are no more S-including cycles, then we have to 
			// walk the necessary non-essential steps on both sides.
			cost += cost_l + cost_r;
		}
		// New interval [l,r] = extend(C_l \cup C_r).
		l = min(l_l, l_r);
		r = max(r_l, r_r);
	} while(target_l<l || r<target_r); // As long as Mina needs to explore more.
	return cost;
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
	// Add up the number essential and non-essential steps needed.
	return dP+connect(S, S, l, r, C, L, R);
}
