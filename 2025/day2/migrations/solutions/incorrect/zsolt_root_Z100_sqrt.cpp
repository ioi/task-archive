// solution/zsolt_root_Z100_sqrt.cpp
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

const int MAXN = 10000, SQN = 100;
int dep[MAXN], ans;

int send_message(int N, int i, int p) {
    dep[i] = dep[p] + 1;
    if (i + 2 == N) {
        ans = max_element(dep, dep + N) - dep;
        return ans / SQN;
    }
    if (i + 1 == N) {
        if (dep[i] > dep[ans])
            return SQN;
        else
            return ans % SQN;
    }
    return 0;
}

pair<int,int> longest_path(vector<int> S) {
    int N = S.size();
    if (S.back() == SQN)
        return {0, N - 1};
    else
        return {0, S[N - 2] * 100 + S[N - 1]};
}
