//		Red : charging station
//		Blue : not charging station

#include "train.h"
#include <iostream>
#include <vector>
#include <cstring>
#include <set>

using namespace std;

const int max_n = 5000;
const bool A = true;
const bool B = false;

int n;
std::vector <int> a[max_n], b[max_n];
bool owners[max_n];
int rem[max_n];

set <int> fill_followers(set <int> sources, bool player) {
	//cerr << "FILL [";
	//for (auto x : sources) cerr << x << ' ';
	//cerr << "] " << player << endl;
	memset (rem, 0, sizeof rem);
	set <int> res(sources);
	vector <int> queue;
	for (int i = 0; i < n; i++) if (sources.count(i) == 0) {
		rem[i] = a[i].size();
		if (owners[i] == player) rem[i] = min(rem[i], 1);
		for (auto adj : a[i]) if (sources.count(adj) > 0) rem[i] = max(0, rem[i] - 1);
		//cerr << " @rem " << i << " = " << rem[i] << endl;
		//if (rem[i] == 0) cerr << " ~ " << i << endl;
		if (rem[i] == 0) queue.push_back(i);
	}

	for (int i = 0; i < (int)queue.size(); i++) {
		int k = queue[i];
		//cerr << "BFS " << k << endl;
		res.insert(k);
		for (auto adj : b[k]) if (rem[adj] > 0) {
			rem[adj] = max(0, rem[adj] - 1);
			//cerr << " @rem " << adj << " = " << rem[adj] << endl;
			//if (rem[adj] == 0) cerr << " ~ " << adj << endl;
			if (rem[adj] == 0) queue.push_back(adj);
		}
	}

	return res;
}

vector <int> who_wins(vector <int> owner, vector <int> r, vector <int> from, vector <int> to)
{
	n = owner.size();
	int m = from.size();
	vector <int> red;
	for(int i = 0; i < n; i++)
		if(r[i])
			red.push_back(i);

	for (int i = 0; i < m; i++)
		a[from[i]].push_back(to[i]),
		b[to[i]].push_back(from[i]);
	for (int i = 0; i < n; i++)
		owners[i] = owner[i];

	set <int> sources;
	int k = red.size();
	for (int i = 0; i < k; i++) sources.insert(red[i]);
	cerr << sources.size() << endl;

	for (int i = 0; i < k; i++) {
		set <int> alice = fill_followers(sources, A), not_alice;
		for (int j = 0; j < n; j++) 
			if (alice.count(j) == 0)
				not_alice.insert(j);

		//cerr << "iteration " << i << endl;
		//for (auto x : alice) cerr << x << ' '; cerr << endl;
		//for (auto x : not_alice) cerr << x << ' '; cerr << endl;

		set <int> bob = fill_followers(not_alice, B);
		//for (auto x : bob) cerr << x << ' '; cerr << endl;
		for (auto x : bob) sources.erase(x);
	}
	vector <int> winner(n);
	set <int> alice = fill_followers(sources, A);
	for (int i = 0; i < n; i++) winner[i] = B;
	for (auto x : alice) winner[x] = A;
	return winner;
}

