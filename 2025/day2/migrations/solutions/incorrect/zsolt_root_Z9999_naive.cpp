// solution/zsolt_root_Z9999_naive.cpp
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

const int MAXN = 10000;
int dep[MAXN];

int send_message(int N, int i, int p) {
    dep[i] = dep[p] + 1;
    if (i + 1 == N) {
        return max_element(dep, dep + N) - dep;
    }
    return 0;
}

pair<int,int> longest_path(vector<int> S) {
    return {0, S.back()};
}
