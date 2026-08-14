// solution/isaac_subtask5.cpp
// {
//   "verdict": "incorrect",
//   "except": {
//     "subtask5": "correct"
//   }
// }
// END HEADER
// N <= 3000
// complexity: N log(N)

#include "festival.h"
#include <bits/stdc++.h>
#define sz(v) (int)v.size()
using namespace std;
typedef long long ll;


vector<int> max_coupons(int A, vector<int> P, vector<int> T){
    int N = P.size();
    
    vector<int> Sorted(N);
    iota(Sorted.begin(), Sorted.end(), 0);

    sort(Sorted.begin(), Sorted.end(), [&](int i, int j) {
        if (T[i] == T[j]) return P[i] < P[j];
        return 1ll * P[i] * T[i] * (T[j] - 1) < 1ll * P[j] * T[j] * (T[i] - 1);
    });

    return Sorted;

}