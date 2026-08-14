// solution/zsolt_root_Z9950_naive_imp.cpp
// {
//   "verdict": "incorrect",
//   "except": {
//     "samples": "correct",
//     "from_root": "partially_correct"
//   }
// }
// END HEADER
#include "migrations.h"
#include <algorithm>

using namespace std;

const int MAXN = 10000, LST = 50;
int dep[MAXN], ans;

int send_message(int N, int i, int p) {
    dep[i] = dep[p] + 1;
    if (i + LST == N) {
        ans = max_element(dep, dep + N) - dep;
        return ans;
    }
    else if (i + LST > N && dep[i] > dep[ans]) {
        ans = i;
        return 1;
    }
    return 0;
}

pair<int,int> longest_path(vector<int> S) {
    int N = S.size();
    for (int i = 0; i + 1 < LST; ++i) {
        if (S[N - i])
            return {0, N - i};
    }
    return {0, S[N - LST]};
}
