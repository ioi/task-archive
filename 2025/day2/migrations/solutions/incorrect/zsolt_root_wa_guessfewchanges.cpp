// solution/zsolt_root_wa_guessfewchanges.cpp
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

const int MAXN = 10000;
int dep[MAXN], ans = 0;

int send_message(int N, int i, int p) {
    dep[i] = dep[p] + 1;
    if (dep[i] > dep[ans]) {
        ans = i;
        return 1;
    }
    return 0;
}

pair<int,int> longest_path(vector<int> S) {
    while (S.back() == 0)
        S.pop_back();
    return {0, (int)S.size() - 1};
}
