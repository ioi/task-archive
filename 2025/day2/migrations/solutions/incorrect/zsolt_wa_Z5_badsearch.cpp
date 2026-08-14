// solution/zsolt_wa_Z5_badsearch.cpp
// {
//   "verdict": "incorrect",
//   "except": {
//     "samples": "correct"
//   }
// }
// END HEADER
#include "migrations.h"

using namespace std;

const int MAXN = 10000;
int dep[MAXN], par[MAXN][14], a = 0, b = 1;

int lca(int x, int y) {
    if (dep[x] < dep[y])
        swap(x, y);
    int d = dep[x] - dep[y];
    for (int j = 0; j < 14; ++j) {
        if (d & (1 << j))
            x = par[x][j];
    }
    if (x == y)
        return x;
    for (int j = 13; j >= 0; --j) {
        int px = par[x][j], py = par[y][j];
        if (px != py)
            x = px, y = py;
    }
    return par[x][0];
}

int send_message(int N, int i, int p) {
    dep[i] = dep[p] + 1;
    par[i][0] = p;
    for (int j = 1; j < 14; ++j)
        par[i][j] = par[par[i][j - 1]][j - 1];
    
    int dab = dep[a] + dep[b] - 2 * dep[lca(a, b)];
    int dai = dep[a] + dep[i] - 2 * dep[lca(a, i)];
    int dbi = dep[b] + dep[i] - 2 * dep[lca(b, i)];
    if (dai > dab)
        b = i;
    else if (dbi > dab)
        a = i;

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
