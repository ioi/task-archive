// solution/zsolt_Z5.cpp
// {
//   "verdict": "partially_correct",
//   "except": {
//     "from_root": "correct",
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
        if (ret  == 0)
            ret = 2 + ri - b;
        else {
            ret = 5;
            a = ri - 2, b = ri - 1;
        }
    }
    return ret;
}

pair<int,int> longest_path(vector<int> S) {
    int N = S.size();
    for (int i = 1; i < N; ++i) {
        int wi = 2 * (N - i);
        if (wi > N || S[i] == 0)
            continue;
        int li = N - wi, ri = N - wi + 2;
        if (S[i] == 5)
            a = ri - 2, b = ri - 1;
        else if (S[i] > 2)
            b = ri + 2 - S[i];
        else
            a = ri - S[i];
    }
    
    return {a, b};
}
