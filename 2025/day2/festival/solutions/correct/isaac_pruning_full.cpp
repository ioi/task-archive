// solution/isaac_pruning_full.cpp
// {
//   "verdict": "correct"
// }
// END HEADER
#include "festival.h"
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll INF = 1e18;

vector<int> cur, best;
int best_type1;

void solve(int pos, ll tokens, int lim, vector<int> &a, vector<pair<ll, int> > &b, vector<int> &p, vector<int> &t) {

    if (lim == 1 || pos == a.size()) {
        auto it = lower_bound(b.begin(), b.end(), make_pair(tokens + 1, -1)) - b.begin();
        if (it + cur.size() > best.size() + best_type1) {
            best = cur;
            best_type1 = it;
        }
        return;
    }

    if (tokens >= p[a[pos]] && lim >= t[a[pos]]) {
        cur.push_back(a[pos]);
        solve(pos + 1, min((tokens - p[a[pos]]) * t[a[pos]], INF), lim, a, b, p, t);
        cur.pop_back();
    }
    solve(pos + 1, tokens, min(lim, t[a[pos]] - 1), a, b, p, t);
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

    vector<int> res;
    ll curTokens = A;

    for (auto i: a) {
        if ((curTokens - P[i]) * T[i] >= curTokens) {
            curTokens = (curTokens - P[i]) * T[i];
            curTokens = min(curTokens, (long long) 1e15);
            res.push_back(i);
        } else {
            break;
        }
    }

    a.erase(a.begin(), a.begin() + (int) res.size());

    solve(0, curTokens, 4, a, b, P, T);

    for (auto i: best) {
        res.push_back(i);
    }

    for (int i = 0; i < best_type1; i++) {
        res.push_back(b[i].second);
    }
    return res;
}