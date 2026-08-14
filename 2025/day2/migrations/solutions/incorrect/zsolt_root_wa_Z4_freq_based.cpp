// solution/zsolt_root_wa_Z4_freq_based.cpp
// {
//   "verdict": "incorrect",
//   "except": {
//     "samples": "correct"
//   }
// }
// END HEADER
#include "migrations.h"
#include <algorithm>

using namespace std;

const int MAXN = 10000, LST = 4;
int dep[MAXN], ans = 0;

int send_message(int N, int i, int p) {
    dep[i] = dep[p] + 1;
    if (dep[i] > dep[ans])
        ans = i;
    if (i + 1 == N && ans > N - 5) {
        return N - ans;
    }
    if (i - ans == LST)
        return 1;
    return 0;
}

pair<int,int> longest_path(vector<int> S) {
    int N = S.size();
    if (S.back() > 0)
        return {0, N - S.back()};
    while (S.back() == 0)
        S.pop_back();
    return {0, (int)S.size() - 1 - LST};
}
