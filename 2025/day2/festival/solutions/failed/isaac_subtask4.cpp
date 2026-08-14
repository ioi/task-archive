// solution/isaac_subtask4.cpp
// {
//   "verdict": "failed",
//   "except": {
//     "samples": "correct",
//     "subtask4": "correct"
//   }
// }
// END HEADER
// N <= 70
// complexity: N^4

#include <bits/stdc++.h>

#define sz(v) (int)v.size()
using namespace std;
typedef long long ll;
const ll inf = 1e15;

const int M = 71;
ll dp[M][M][M][M];

vector<int> build_dp(vector<pair<int, int> > coupons[5], vector<int> state) {
    vector<int> result;

    while (state[0] + state[1] + state[2] + state[3]) {
        ll cur_tokens = dp[state[0]][state[1]][state[2]][state[3]];

        for (int i = 1; i <= 4; i++) {
            if (state[i - 1] == 0)continue;

            ll prv = dp[state[0] - (i == 1)][state[1] - (i == 2)][state[2] - (i == 3)][state[3] - (i == 4)];
            if (min((prv - coupons[i][state[i - 1] - 1].first) * i, inf) == cur_tokens) {
                result.push_back(coupons[i][state[i - 1] - 1].second);
                state[i - 1]--;
                break;
            }
        }
    }
    reverse(result.begin(), result.end());
    return result;
}

vector<int> solve_dp(int tokens , vector<pair<int, int> > coupons[5]){
    memset(dp, -1, sizeof dp);
    dp[0][0][0][0] = tokens;

    vector<int> best_state = {0,0,0,0};
    int idx[5] = {0};
    for (idx[1] = 0; idx[1] <= sz(coupons[1]); idx[1]++) {
        for (idx[2] = 0; idx[2] <= sz(coupons[2]); idx[2]++) {
            for (idx[3] = 0; idx[3] <= sz(coupons[3]); idx[3]++) {
                for (idx[4] = 0; idx[4] <= sz(coupons[4]); idx[4]++) {

                    ll &ans = dp[idx[1]][idx[2]][idx[3]][idx[4]];

                    for (int i = 1; i <= 4; i++) {
                        if (idx[i] == 0)continue;
                        ll &prv = dp[idx[1] - (i == 1)][idx[2] - (i == 2)][idx[3] - (i == 3)][idx[4] - (i == 4)];
                        ans = max(ans, (prv - coupons[i][idx[i] - 1].first) * i);
                    }

                    ans = min(ans, inf);

                    if(ans >= 0 && idx[1] + idx[2] + idx[3] + idx[4] > accumulate(best_state.begin(),best_state.end(),0)){
                        best_state = {idx[1] , idx[2] , idx[3] , idx[4]};
                    }
                }
            }
        }
    }
    return best_state;
}
vector<int> max_coupons(int A, vector<int> P, vector<int> T){
    int N = P.size();
    

    vector<pair<int, int> > coupons[5];
    for (int i = 0; i < N; i++) {
        coupons[T[i]].push_back({P[i], i});
    }

    for (int i = 1; i <= 4; i++) {
        sort(coupons[i].begin(), coupons[i].end());
    }

    // get best state using DP
    vector<int> best_state = solve_dp(A , coupons);

    // build the answer
    return build_dp(coupons, best_state);
}
