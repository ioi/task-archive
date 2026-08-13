// Library solution for S=0 in O((N+2)!)
// Score: 20
// Use BFS over the entire state space

#include "books.h"
#include <vector>
#include <queue>
#include <map>
#include <iostream>

using namespace std;

struct state {
	int p; // Minas position
	int b; // Minas current book
	vector<int> s; // shelf
	bool operator < (const state &o) const {
		if(p != o.p) return p<o.p;
		if(b != o.b) return b<o.b;
		return s<o.s;
	}
	bool operator == (const state &o) const {
		return !(*this < o) && !(o < *this);
	}
	void print() const 	{
		cout << "state: p=" << p << " b=" << b << " s=[";
		for(int i=0; i<s.size(); i++) {
			if(i>0) cout << ",";
			cout << s[i];
		}
		cout << "] ";
	}
};

long long minimum_walk(vector<int> order, int s){
	int N = order.size();
	// BFS over the state space
	map<state, int> M; // Distance map for discovered states
	queue<state> Q; // BFS queue

	vector<int> initial(N);
	for(int i=0; i<N; i++) initial[i]=order[i];	
	state start = {0, -1, initial};

	vector<int> sorted(N);
	for(int i=0; i<N; i++) sorted[i]=i;
	state target = {0, -1, sorted};

	if(start==target) return 0;

	M[start] = 0;
	Q.push(start);

	while(!Q.empty()) {
		state s = Q.front(); Q.pop();
		vector<state> succ;
		// generate all possible successor states
		state ns = s;
		for(ns.p = s.p-1; ns.p <= s.p+1; ns.p++) { // next position +/- 1
			if(!(0<=ns.p && ns.p<N)) continue; // don't move out of the shelf

			swap(ns.b, ns.s[s.p]); 
			succ.push_back(ns); // swap only before the step
			swap(ns.b, ns.s[s.p]);

			swap(ns.b, ns.s[ns.p]); 
			succ.push_back(ns); // swap only after the step
			swap(ns.b, ns.s[ns.p]);

			swap(ns.b, ns.s[s.p]); swap(ns.b, ns.s[ns.p]);
			succ.push_back(ns); // swap before and after the step
			swap(ns.b, ns.s[ns.p]); swap(ns.b, ns.s[s.p]);
		}
		// explore all new successor states
		for(auto & ns : succ) {
			if(M.find(ns) == M.end()) {
				M[ns] = M[s] + 1;
				Q.push(ns);
			}
			if(ns == target) {
				return M[s] + 1;
			}
		}
	}
    return -1;
}
