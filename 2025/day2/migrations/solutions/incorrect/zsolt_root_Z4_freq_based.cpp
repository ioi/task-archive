// solution/zsolt_root_Z4_freq_based.cpp
// {
//   "verdict": "incorrect",
//   "except": {
//     "samples": "correct",
//     "from_root": "correct"
//   }
// }
// END HEADER
#include "migrations.h"

using namespace std;

const int MAXN = 10000;
int dep[MAXN], ans = 0;

int send_message(int N, int i, int p) {
    dep[i] = dep[p] + 1;
    if (dep[i] > dep[ans])
        ans = i;
    int wi = 4 * (N - i);
    if (wi > N)
        return 0;
    int li = N - wi, ri = N - wi + 4;
    if (li <= ans && ans < ri) {
        return ri - ans;
    }
    return 0;
}

pair<int,int> longest_path(vector<int> S) {
    int N = S.size();
    int i = 1;
    while (S[N - i] == 0)
        ++i;

    int wi = 4 * i;
    int li = N - wi, ri = N - wi + 4;
    int s = S[N - i];
    return {0, ri - s};
}
