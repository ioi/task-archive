// solution/isaac_pruning_partial.cpp
// {
//   "verdict": "time_limit_and_runtime_error",
//   "except": {
//     "samples": "correct",
//     "subtask1": "correct",
//     "subtask2": "correct",
//     "subtask3": "correct",
//     "subtask4": "correct",
//     "subtask6": "correct"
//   }
// }
// END HEADER
#include "festival.h"
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll INF = 1e18;

vector<int> cur, best;
int best_type1;

void solve(int pos, ll s, int lim, vector<int> &a, vector<pair<ll, int> > &b, vector<int> &p, vector<int> &t) {

    if (lim == 1 || pos == a.size()) {
        auto it = lower_bound(b.begin(), b.end(), make_pair(s + 1, -1)) - b.begin();
        if (it + cur.size() > best.size() + best_type1) {
            best = cur;
            best_type1 = it;
        }
        return;
    }

    if (s >= p[a[pos]] && lim >= t[a[pos]]) {
        cur.push_back(a[pos]);
        solve(pos + 1, min((s - p[a[pos]]) * t[a[pos]], INF), lim, a, b, p, t);
        cur.pop_back();
    }
    
    solve(pos + 1, s, min(lim, t[a[pos]] - 1), a, b, p, t);
}

vector<int> max_coupons(int A, vector<int> P, vector<int> T) {
    vector<int> a;
    vector<pair<ll, int> > b;
    int n = P.size();
    for (int i = 0; i < n; i++) {
        if (T[i] > 1) a.push_back(i);
        else b.push_back({P[i], i});
    }

    sort(a.begin(), a.end(), [&](int i, int j) {
        if (T[i] == T[j]) return P[i] < P[j];
        return 1ll * P[i] * T[i] * (T[j] - 1) < 1ll * P[j] * T[j] * (T[i] - 1);
    });


    sort(b.begin(), b.end());
    for (int i = 1; i < b.size(); i++) {
        b[i].first += b[i - 1].first;
    }

    solve(0, A, 4, a, b, P, T);
    for (int i = 0; i < best_type1; i++) {
        best.push_back(b[i].second);
    }
    return best;
}