// solution/yixuan_subtask4.cpp
// {
//   "verdict": "time_limit_and_runtime_error",
//   "except": {
//     "samples": "correct",
//     "subtask1": "correct",
//     "subtask4": "correct"
//   }
// }
// END HEADER
#include "festival.h"
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
 
int n;
vector<int> cur, best;
 
void work(int pos, ll s, int lim, vector<int> &a, vector<int> &p, vector<int> &t) {
    if (pos == n) {
        if (cur.size() > best.size()) best = cur;
        return;
    }
    if (s >= p[a[pos]] && lim >= t[a[pos]]) {
        cur.push_back(a[pos]);
        work(pos + 1, min((s - p[a[pos]]) * t[a[pos]], INF), lim, a, p, t);
        cur.pop_back();
    }
    work(pos + 1, s, min(lim, t[a[pos]] - 1), a, p, t);
}
 
vector<int> max_coupons(int s, vector<int> p, vector<int> t){
    vector <int> a;
    n = p.size();
    for (int i = 0; i < n; i++)
        a.push_back(i);
    sort(a.begin(), a.end(), [&](int a, int b) {
        if (t[a] == 1 && t[b] == 1) return p[a] < p[b];
        if (t[a] == 1 || t[b] == 1) return t[b] == 1;
        return 1ll * p[a] * t[a] * (t[b] - 1) < 1ll * p[b] * t[b] * (t[a] - 1);
    });
    work(0, s, 4, a, p, t);
    return best;
}