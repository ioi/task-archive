// solution/witt_heuristic.cpp
// {
//   "verdict": "incorrect",
//   "except": {
//     "samples": "correct",
//     "subtask1": "correct",
//     "subtask5": "correct"
//   }
// }
// END HEADER
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct info {
    int cost;
    int mul;
    int id;
};

constexpr ll max_val = 1e9;
constexpr int types = 4;

vector<int> max_coupons(int A, vector<int> P, vector<int> T) {
    int n = P.size();

    vector<info> v;
    for(int i = 0; i < n; i++)
        v.push_back(info{P[i], T[i], i});

    sort(v.begin(), v.end(), [&](info a, info b) {
        if(a.mul == b.mul)
            return a.cost < b.cost;

        return ll(a.cost) * a.mul * (b.mul - 1) < ll(b.cost) * b.mul * (a.mul - 1);  
    });


    vector<info> good;

    ll hp = A;

    vector<info> rest;

    for(auto el : v) {
        ll nval = ll(hp - el.cost) * el.mul;
        if(nval >= hp) {
            hp = nval;
            good.emplace_back(el);
        }
        else {
            rest.emplace_back(el);
        }
        if(hp > ll(n) * max_val) {
            vector<int> ans(n);
            for(int i = 0; i < n; i++)
                ans[i] = v[i].id;
            return ans;
        }

    }

    for(auto el : rest) {
        ll nval = ll(hp - el.cost) * el.mul;
        if(nval >= 0) {
            good.emplace_back(el);
            hp = nval;
        }
        if(hp == 0)
            break;
    }

    vector<int> ans;

    for(int i = 0; i < int(good.size()); i++)
        ans.emplace_back(good[i].id);

    return ans;
}
