// solution/yixuan_greedy.cpp
// {
//   "verdict": "incorrect",
//   "except": {
//     "samples": "correct",
//     "subtask1": "correct",
//     "subtask5": "correct"
//   }
// }
// END HEADER
#include "festival.h"
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
vector<int> max_coupons(int s, vector<int> p, vector<int> t){
    vector <int> a;
    int n = p.size();
    for (int i = 0; i < n; i++)
        a.push_back(i);
    sort(a.begin(), a.end(), [&](int a, int b) {
        if (t[a] == 1 && t[b] == 1) return p[a] < p[b];
        if (t[a] == 1 || t[b] == 1) return t[b] == 1;
        return 1ll * p[a] * t[a] * (t[b] - 1) < 1ll * p[b] * t[b] * (t[a] - 1);
    });
    ll remain = s;
    vector <int> ret;
    for (auto x : a) {
        if (remain >= p[x]) {
            remain = min((remain - p[x]) * t[x], INF);
            ret.push_back(x);
        }
    }
    return ret;
}