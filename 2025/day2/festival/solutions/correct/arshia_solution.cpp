// solution/arshia_solution.cpp
// {
//   "verdict": "correct"
// }
// END HEADER
#include "festival.h"
#include <algorithm>
#include <vector>
using namespace std;

const int LG = 30;
const long long INF = 1e15;

long long apply(long long A, int P, int T) {
    return min((A - P) * T, INF);
}

vector<int> max_coupons(int A, vector<int> P, vector<int> T) {
    int N = P.size();
    vector<int> others;
    vector<pair<long long, int>> ones;
    for (int i = 0; i < N; i++)
        if (T[i] > 1)
            others.push_back(i);
        else
            ones.push_back({P[i], i});

    sort(ones.begin(), ones.end());
    int K = ones.size(), M = others.size();
    for (int i = 1; i < K; i++)
        ones[i].first += ones[i - 1].first;
    sort(others.begin(), others.end(), [&](int i, int j) {
        return (T[j] - 1LL) * P[i] * T[i] < (T[i] - 1LL) * P[j] * T[j];
    });

    int tmp = 0;
    vector<int> ans;
    long long money = A;
    for ( ; tmp < M; tmp++) {
        if (money < P[others[tmp]])
            continue;
        long long nxt = apply(money, P[others[tmp]], T[others[tmp]]);
        if (nxt < money)
            break;
        money = nxt, ans.push_back(others[tmp]);
    }
    if (tmp) {
        others.erase(others.begin(), others.begin() + tmp);
        M = others.size();
    }

    vector<vector<int>> par(M + 1, vector<int>(3 * LG + 1, -1));
    vector<vector<long long>> dp(M + 1, vector<long long>(3 * LG + 1, -1));
    for (int i = 0; i <= M; i++)
        dp[i][0] = money, par[i][0] = 0;
    for (int i = 0; i < M; i++)
        for (int j = 1; j <= 3 * LG; j++) {
            dp[i + 1][j] = dp[i][j], par[i + 1][j] = j;
            if (dp[i][j - 1] >= P[others[i]]) {
                long long cost = apply(dp[i][j - 1], P[others[i]], T[others[i]]);
                if (dp[i + 1][j] < cost)
                    dp[i + 1][j] = cost, par[i + 1][j] = j - 1;
            }
        }

    int best = -1, ted = -1;
    for (int i = 0; i <= 3 * LG; i++) {
        if (dp[M][i] < 0)
            continue;

        int cnt = lower_bound(ones.begin(), ones.end(), make_pair(dp[M][i] + 1, -1)) - ones.begin() + i;
        if (cnt > ted)
            ted = cnt, best = i;
    }
    ted -= best;

    tmp = ans.size();
    for (int i = M; i; best = par[i--][best])
        if (par[i][best] < best)
            ans.push_back(others[i - 1]);
    reverse(ans.begin() + tmp, ans.end());
    for (int i = 0; i < ted; i++)
        ans.push_back(ones[i].second);

    return ans;
}

// int main() {
//     char secret[100];
//     scanf("%s", secret);

//     int N, A;
//     scanf("%d %d", &N, &A);
//     vector<int> P(N), T(N);
//     for (int i = 0; i < N; i++)
//         scanf("%d %d", &P[i], &T[i]);

//     vector<int> ans = max_coupons(A, P, T);
//     printf("%d\n", (int)ans.size());
//     // printf("%d: ", (int)ans.size());
//     // for (int x : ans)
//     //     printf("%d ", x);
//     // printf("\n");
// }