// solution/zsolt_root_Z2_binary.cpp
// {
//   "verdict": "incorrect",
//   "except": {
//     "samples": "correct",
//     "from_root": "correct"
//   }
// }
// END HEADER
#include "migrations.h"
#include <algorithm>

using namespace std;

const int MAXN = 10000, LST = 14;
int dep[MAXN], ans;

int send_message(int N, int i, int p) {
    dep[i] = dep[p] + 1;
    if (i + LST == N)
        ans = max_element(dep, dep + N) - dep;
    if (i + LST >= N) {
        if (dep[i] > dep[ans]) {
            ans = i;
            return 2;
        }
        else
            return (ans & (1 << (N - 1 - i))) > 0;
    }
    return 0;
}

pair<int,int> longest_path(vector<int> S) {
    int N = S.size();
    ans = 0;
    for (int i = 0; i < LST; ++i) {
        if (S.back() == 2)
            return {0, N - 1 - i};
        else
            ans += S.back() * (1 << i);
        S.pop_back();
    }
    return {0, ans};
}
