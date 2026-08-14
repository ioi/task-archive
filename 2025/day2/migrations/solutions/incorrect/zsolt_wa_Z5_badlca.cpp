// solution/zsolt_wa_Z5_badlca.cpp
// {
//   "verdict": "incorrect"
// }
// END HEADER
#include "migrations.h"

using namespace std;

const int MAXN = 10000;
int dep[MAXN], a = 0, b = 1;

int send_message(int N, int i, int p) {
    dep[i] = dep[p] + 1;
    if (dep[i] > dep[a])
        a = i;
    else if (dep[i] > dep[b])
        b = i;
    int wi = 2 * (N - i);
    if (wi > N)
        return 0;
    int li = N - wi, ri = N - wi + 2;
    int ret = 0;
    if (li <= a && a < ri) {
        ret = ri - a;
    }
    if (li <= b && b < ri) {
        ret = (ret == 0 ? 2 + ri - b : 5);
    }
    return ret;
}

pair<int,int> longest_path(vector<int> S) {
    int N = S.size();
    int i = 1;
    while (S[N - i] == 0)
        ++i;

    int s = S[N - i];
    int wi = 2 * i;
    int li = N - wi, ri = N - wi + 2;
    if (s == 5) {
        return {ri - 1, ri - 2};
    }
    if (s > 2)
        b = ri - s + 2;
    else
        b = ri - s;
    
    ++i;
    while (S[N - i] == 0)
        ++i;
    
    s = S[N - i];
    wi = 2 * i;
    li = N - wi, ri = N - wi + 2;
    if (s > 2)
        a = ri - s + 2;
    else
        a = ri - s;

    return {a, b};
}
