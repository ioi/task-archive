// solution/badawy_correct_sort.cpp
// {
//   "verdict": "incorrect",
//   "except": {
//     "samples": "correct",
//     "subtask1": "correct",
//     "subtask5": "correct"
//   }
// }
// END HEADER
#include "festival.h"
#include <bits/stdc++.h>

using namespace std;

const long long MX = 1e18;

vector<int> max_coupons(int A, vector<int> P, vector<int> T){
    int N=P.size();
    vector<int> sorted(N);
    iota(sorted.begin(), sorted.end(), 0);

    sort(sorted.begin(), sorted.end(), [&](int i, int j) {
        if (T[i] == T[j]) return P[i] < P[j];
        return 1ll * P[i] * T[i] * (T[j] - 1) < 1ll * P[j] * T[j] * (T[i] - 1);
    });

    vector<int> ans;
    long long curt = A;
    for(int it=0;it<N;it++)
    {
        int i=sorted[it];
        if(curt >= P[i])
        {
            curt = (curt-P[i])*T[i];
            curt = min(curt, MX);
            ans.push_back(i);
        }
    }
    return ans;
}