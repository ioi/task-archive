#include "train.h"

#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <cassert>

using namespace std;

const int MAXN = 15;

const int B = 0;
const int A = 1;

int mask_owner, mask_charge;
int p3[MAXN];
vector<int> adj[MAXN];
map<int, int> dp[MAXN];

inline int get_bit(const int mask, const int p) {
	return (mask >> p) & 1;
}

int go(int cur, int mask_state, int mask3_state, int mask_tail, int mask3_tail) {
	if (dp[cur].find(mask3_state) != dp[cur].end())
		return dp[cur][mask3_state];
	for (int i = 0; i < (int)adj[cur].size(); i++) {
		int v = adj[cur][i];
		if (get_bit(mask_state, v)) {
			if ((get_bit(mask_owner, cur) == A) ^ get_bit(mask_tail, v))
				return dp[cur][mask3_state] = get_bit(mask_owner, cur);
		} else {
			int nmask3_state = mask3_state + p3[v];
			int nmask_tail = mask_tail | (1 << v);
			int nmask3_tail = mask3_tail + p3[v];
			if (get_bit(mask_charge, v)) {
				nmask3_state += nmask3_tail;
				nmask_tail = 0, nmask3_tail = 0;
			}
			if (go(v, mask_state | (1 << v), nmask3_state, nmask_tail, nmask3_tail) == get_bit(mask_owner, cur))
				return dp[cur][mask3_state] = get_bit(mask_owner, cur);
		}
	}
	return dp[cur][mask3_state] = !get_bit(mask_owner, cur);
}

vector<int> who_wins(vector<int> a, vector<int> r, vector<int> u, vector<int> v){
	if ((int)a.size() > MAXN)
		return vector<int>((int)a.size(), 0);
	for (int i = 0; i < (int)u.size(); i++)
		adj[u[i]].push_back(v[i]);
	for (int i = 0; i < (int)a.size(); i++) if (a[i] == A)
		mask_owner |= (1 << i);
	for (int i = 0; i < (int)r.size(); i++) if (r[i] == 1)
		mask_charge = mask_charge | (1 << i);
	p3[0] = 1;
	for (int i = 1; i < (int)a.size(); i++)
		p3[i] = p3[i-1] * 3;
	vector<int> res;
	for (int i = 0; i < (int)a.size(); i++)
		res.push_back(get_bit(mask_charge, i) ?
			go(i, (1 << i), 2 * p3[i], 0, 0) : 
			go(i, (1 << i), p3[i], (1 << i), p3[i]));
	return res;
}
