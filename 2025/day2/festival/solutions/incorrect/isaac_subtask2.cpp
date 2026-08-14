// solution/isaac_subtask2.cpp
// {
//   "verdict": "incorrect",
//   "except": {
//     "subtask1": "correct",
//     "subtask2": "correct",
//     "subtask3": "time_limit"
//   }
// }
// END HEADER
// 1 <= T[i] <= 2, N<=3000
// complexity: N^2 * log(N)

#include "festival.h"
#include <bits/stdc++.h>
#define sz(v) (int)v.size()
using namespace std;
typedef long long ll;
const ll inf = 1e15;

ll buyCoupons(int A, int m, int type, vector<pair<int, int>> &coupons) {
    ll tokens = A;
    for (int i = 0; i < m; i++) {
        tokens = (tokens - coupons[i].first) * type;
        tokens = min(tokens, inf);
        if (tokens < 0) return -1;
    }
    return tokens;
}

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
    int b = 0;

    for (int i = 0; i <= sz(coupons[2]); i++) {

        ll tokens = buyCoupons(A,i,2,coupons[2]);
        if (tokens < 0)break;
        int j = upper_bound(sum.begin(), sum.end(), tokens) - sum.begin() - 1;

        if (i  + j > a + b) {
            a = i;
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