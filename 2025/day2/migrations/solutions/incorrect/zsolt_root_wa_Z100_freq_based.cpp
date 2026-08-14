// solution/zsolt_root_wa_Z100_freq_based.cpp
// {
//   "verdict": "incorrect"
// }
// END HEADER
#include "migrations.h"
#include <algorithm>

using namespace std;

const int MAXN = 10000, LST = 100;
int dep[MAXN], ans = 0;

int send_message(int N, int i, int p) {
    dep[i] = dep[p] + 1;
    if (i >= LST && dep[i] > dep[ans])
        ans = i;
    if (i + 1 == N && ans > N - LST - 1) {
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
