#include "bits/stdc++.h"

#include "ballmachine.h"

using namespace std;

// acceptable ball value ranges; 
const int MAXV = 1000;
const int MINV = 0; 

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); 
inline int rnd(const int& l, const int& r) { return uniform_int_distribution<int>(l, r)(rng); }

vector< int > find_structure(int m) {

    if (rnd(0, 1)) {
        insert(0, MAXV + 1);
    } else {
        insert(0, MINV - 1);
    }
    
    return {}; 
}

