// Library solution for S=0 in O(N^2)
// Score: 35
#include "books.h"
#include <cstdlib>
#include <vector>

using namespace std;

long long minimum_walk(vector<int> order, int S) {
	int N = order.size();
	long long int result = 0;
	vector<bool> covered(N-1, false);
	for(int i=0; i<N; i++) {
		result += abs(i-order[i]); // Compute d(pi)
		// Non-optimal linear sweep over the arc [i,order[i]]
		for(int j=min(i,order[i]); j<max(i,order[i]); j++) {
			covered[j] = true;
		}
	}
	int counter = 0;
	for(int i=0; i<N-1; i++) {
		if(!covered[i]) {
			// [i,i+1] is in E' if some uncovered edge follows
			counter++;
		} else {
			result += 2*counter;
			counter = 0;
		}
	}
	return result;
}
