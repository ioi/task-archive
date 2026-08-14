// solution/isaac_full.cpp
// {
//   "verdict": "model_solution"
// }
// END HEADER
// N <= 2e5
// complexity: Nlog(N) + log(A)^3 * log(N)

#include "festival.h"
#include <bits/stdc++.h>
#define sz(v) (int)v.size()
using namespace std;
typedef long long ll;
const ll inf = 1e15;

vector<int> build_dp(vector<pair<int, int> > coupons[5], vector<vector<vector<ll>>> &dp, int i, int j, int k) {
    vector<int> result;

    while (i + j + k) {
        if (i && (dp[i - 1][j][k] - coupons[2][i - 1].first) * 2 == dp[i][j][k]) {
            result.push_back(coupons[2][i - 1].second);
            i--;
        } else if (j && (dp[i][j - 1][k] - coupons[3][j - 1].first) * 3 == dp[i][j][k]) {
            result.push_back(coupons[3][j - 1].second);
            j--;
        } else {
            result.push_back(coupons[4][k - 1].second);
            k--;
        }
    }
    reverse(result.begin(), result.end());
    return result;
}

vector<int> max_coupons(int A, vector<int> P, vector<int> T){
    int N = P.size();
    
    vector<int> result;


    // 1- sort coupons by (A[i] * T[i]) / (T[i] - 1)
    vector<int> Sorted(N);
    iota(Sorted.begin(), Sorted.end(), 0);

    sort(Sorted.begin(), Sorted.end(), [&](int i, int j) {
        if (T[i] == T[j]) return P[i] < P[j];
        return 1ll * P[i] * T[i] * (T[j] - 1) < 1ll * P[j] * T[j] * (T[i] - 1);
    });


    // 2- buy the coupons that will increase the current tokens
    vector<pair<int, int> > coupons[5];
    ll tokens = A;
    for (auto i: Sorted) {
        if ((tokens - P[i]) * T[i] >= tokens) {
            result.push_back(i);

            tokens = (tokens - P[i]) * T[i];

            if (tokens >= inf) {
                return Sorted;
            }
        } else {
            coupons[T[i]].push_back({P[i], i});
        }
    }

    // 3- solve the remaining coupons using DP on types {2,3,4} and BS on type 1


    /* It's guaranteed that the maximum number of coupons of types {2,3,4} that can be bought
    will not exceed log2(2e9 + 2) - 1 < 33 */
    const int M = 33;
    vector<vector<vector<ll>>> dp(M, vector<vector<ll>>(M, vector<ll>(M, -1ll)));

    for (int i = 2; i <= 4; i++) {
        if (coupons[i].size() >= M) coupons[i].resize(M - 1);
    }

    dp[0][0][0] = tokens;
    for (int i = 0; i <= sz(coupons[2]); i++) {
        for (int j = 0; j <= sz(coupons[3]); j++) {
            for (int k = 0; k <= sz(coupons[4]); k++) {
                if (i) {
                    dp[i][j][k] = max(dp[i][j][k], (dp[i - 1][j][k] - coupons[2][i - 1].first) * 2);
                }
                if (j) {
                    dp[i][j][k] = max(dp[i][j][k], (dp[i][j - 1][k] - coupons[3][j - 1].first) * 3);
                }
                if (k) {
                    dp[i][j][k] = max(dp[i][j][k], (dp[i][j][k - 1] - coupons[4][k - 1].first) * 4);
                }
            }
        }
    }

    // 4- calcualte the prefix sum for Type 1
    vector<ll> sum((int) coupons[1].size() + 1, 0);
    for (int i = 1; i <= sz(coupons[1]); i++) {
        sum[i] = sum[i - 1] + coupons[1][i - 1].first;
    }

    // 5- get the best state
    int mx = 0;
    vector<int> state = {0, 0, 0, 0};
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < M; k++) {
                if (dp[i][j][k] < 0)
                    continue;

                // the position of the coupon that can not be bought
                int pos = upper_bound(sum.begin(), sum.end(), dp[i][j][k]) - sum.begin();

                if (i + j + k + pos - 1 > mx) {
                    mx = i + j + k + pos - 1;
                    state = {i, j, k, pos - 1};
                }
            }
        }
    }

    // build the answer
    for (auto i: build_dp(coupons, dp, state[0], state[1], state[2])) {
        result.push_back(i);
    }

    for (int i = 1; i <= state[3]; i++) {
        result.push_back(coupons[1][i - 1].second);
    }
    return result;
}
