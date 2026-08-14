// solution/isaac_subtask3.cpp
// {
//   "verdict": "incorrect",
//   "except": {
//     "subtask1": "correct",
//     "subtask2": "correct",
//     "subtask3": "correct"
//   }
// }
// END HEADER
// 1 <= T[i] <= 2
// complexity: N log(N)

#include "festival.h"
#include <bits/stdc++.h>
#define sz(v) (int)v.size()
using namespace std;
typedef long long ll;
const ll inf = 1e15;

vector<int> max_coupons(int A, vector<int> P, vector<int> T){
    int N = P.size();

    vector<pair<int, int> > coupons[5];
    for (int i = 0; i < N; i++) {
        coupons[T[i]].push_back({P[i], i});
    }

    sort(coupons[1].begin(), coupons[1].end());
    sort(coupons[2].begin(), coupons[2].end());

    vector<ll> sum((int) coupons[1].size() + 1, 0);
    for (int i = 1; i <= sz(coupons[1]); i++) {
        sum[i] = sum[i - 1] + coupons[1][i - 1].first;
    }
    int a = 0;
    int b = upper_bound(sum.begin(), sum.end(), A) - sum.begin() - 1;

    ll tokens = A;

    for (int i = 0; i < sz(coupons[2]); i++) {
        tokens = (tokens - coupons[2][i].first) * 2;
        tokens = min(tokens, inf);
        
        if (tokens < 0)break;
        int j = upper_bound(sum.begin(), sum.end(), tokens) - sum.begin() - 1;

        if (i + 1 + j > a + b) {
            a = i + 1;
            b = j;
        }
    }

    vector<int> result;
    for (int i = 0; i < a; i++) {
        result.push_back(coupons[2][i].second);
    }
    for (int i = 0; i < b; i++) {
        result.push_back(coupons[1][i].second);
    }
    return result;
}