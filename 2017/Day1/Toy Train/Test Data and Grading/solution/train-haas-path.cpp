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
vector <int> adj[max_n];

vector<int> who_wins(vector<int> a, vector<int> r, vector<int> u, vector<int> v) {
	n = (int)a.size();
	for (int i = 0; i < u.size(); i++)
		adj[u[i]].push_back(v[i]);
	vector <int> res(n, B);
	for (int i = n-1; i >= 0; i--) {
		bool self_loop = false, next = false;
		for (auto x : adj[i])
			self_loop |= (x == i),
			next |= (x == i+1);
		if (self_loop && r[i] == true && a[i] == A) res[i] = A;
		else if (self_loop && r[i] == false && a[i] == B) res[i] = B;
		else if (next) res[i] = res[i + 1];
		else res[i] = r[i];
	}
	return res;
}
