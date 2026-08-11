#include "bits/stdc++.h"

#include "ballmachine.h"

using namespace std;
const int MINV = 0;
const int MAXV = 1000;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline int rnd(const int& l, const int& r) { return uniform_int_distribution<int>(l, r)(rng); }

vector< int > find_structure(int m) {
    vector<int> res(m); 
    // vector<pair<int, int>> res;

    for (int i = 0; i < m; i++) {
        res[i] = m;
        // res.push_back({i, m});
    }

    return res;
}

