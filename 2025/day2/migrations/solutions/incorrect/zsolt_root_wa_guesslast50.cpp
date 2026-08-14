// solution/zsolt_root_wa_guesslast50.cpp
// {
//   "verdict": "incorrect"
// }
// END HEADER
#include "migrations.h"
#include <algorithm>

using namespace std;

const int MAXN = 10000, LST = 50;
int dep[MAXN], ans;

int send_message(int N, int i, int p) {
    dep[i] = dep[p] + 1;
    if (i + LST == N)
        ans = max_element(dep, dep + N) - dep;
    if (i + LST >= N && dep[i] >= dep[ans]) {
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
