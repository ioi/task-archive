/* Suboptimal solution, passes for N <= 19
 * Author: Dilshodbek Khujaev
 * Complexity: O(2^N * N^2)
 */

#include "monuments.h"
#include <bits/stdc++.h>

using namespace std;

static const long long INF = (long long)1e16;
static const int RED = 0;  // old
static const int BLUE = 1; // new

#define bit(x, i) (((x) >> (i)) & 1)

long long get_cost(vector<int> X, vector<int> P){
    int N = (int) X.size();
    
    vector<int> color(N, BLUE);
    for (int i : P) color[i] = RED;

    vector<long long> dp(1 << N, INF);
    dp[0] = 0;
    for (int mask = 0; mask < (1 << N); mask++){
        if (dp[mask] == INF) continue;

        for (int i = 0; i < N; i++){
            if (bit(mask, i)) continue;

            int new_mask = mask | (1 << i);
            if (color[i] == BLUE || X[i] == 0){
                dp[new_mask] = min(dp[new_mask], dp[mask] + abs(X[i]));
            }
        }

        for (int i = 0; i < N; i++){
            if (bit(mask, i)) continue;
            for (int j = i + 1; j < N; j++){
                if (bit(mask, j)) continue;

                int new_mask = mask | (1 << i) | (1 << j);
                if (color[i] == RED && color[j] == RED){
                    if (X[i] == -X[j]) {
                        dp[new_mask] = min(dp[new_mask], dp[mask]);
                    }
                } else {
                    dp[new_mask] = min(dp[new_mask], dp[mask] + abs(X[i] + X[j]));
                }
            }
        }

    }

    return (dp.back() == INF ? -1 : dp.back());
}