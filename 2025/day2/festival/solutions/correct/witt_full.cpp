// solution/witt_full.cpp
// {
//   "verdict": "correct"
// }
// END HEADER
#include<bits/stdc++.h>
#define ssize(x) int(x.size())
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
    int n = ssize(P);

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

    array<vector<info>, types + 1> rest;

    for(auto el : v) {
        ll nval = ll(hp - el.cost) * el.mul;
        if(nval >= hp) {
            hp = nval;
            good.emplace_back(el);
        }
        else {
            if(el.mul == 1 || rest[el.mul].size() < 49)
            rest[el.mul].emplace_back(el);
        }
        if(hp > ll(n) * max_val) {
            vector<int> ans(n);
            for(int i = 0; i < n; i++)
                ans[i] = v[i].id;
            return ans;
        }
    }

    constexpr int siz = 50;

    array<array<array<pair<ll, int>, siz + 1>, siz + 1>, siz + 1> dp;

    for(int i = 0; i < siz; i++)
        for(int j = 0; j < siz; j++)
            for(int k = 0; k < siz; k++)
                dp[i][j][k] = {-1, -1};

    auto ins = [] (pair<ll, int> &a, ll b, int c) {
        if(b > a.first) {
            a.first = b;
            a.second = c;
        }
    };

    auto apply = [] (ll a, info i) {
        return (a - i.cost) * i.mul;
    };

    vector<ll> one(rest[1].size());

    {
        for(int i = 0; i < ssize(rest[1]); i++) {
            one[i] = rest[1][i].cost;
            if(i)
                one[i] += one[i - 1];
        }
    }

    int best = 0;
    int p1 = 0, p2 = 0, p3 = 0, p4 = 0;

    dp[0][0][0] = {hp, 0};

    for(int i2 = 0; i2 <= ssize(rest[2]); i2++) {
        for(int i3 = 0; i3 <= ssize(rest[3]); i3++) {
            for(int i4 = 0; i4 <= ssize(rest[4]); i4++) {

                if(i2)
                    ins(dp[i2][i3][i4], apply(dp[i2 - 1][i3][i4].first, rest[2][i2 - 1]), 2);
                if(i3)
                    ins(dp[i2][i3][i4], apply(dp[i2][i3 - 1][i4].first, rest[3][i3 - 1]), 3);
                if(i4)
                    ins(dp[i2][i3][i4], apply(dp[i2][i3][i4 - 1].first, rest[4][i4 - 1]), 4);

                if(dp[i2][i3][i4].first < 0LL)
                    continue;

                int ptr = int(upper_bound(one.begin(), one.end(), dp[i2][i3][i4].first) - one.begin());

                int score = i2 + i3 + i4 + ptr;

                if(score > best) {
                    best = score;
                    p1 = ptr;
                    p2 = i2;
                    p3 = i3;
                    p4 = i4;
                }
            }
        }
    }

    vector<info> suf;

    try {
        while(true) {
            int dir = dp[p2][p3][p4].second;
            switch(dir) {
                case 0:
                throw 1;

                case 2:
                    --p2;
                    suf.emplace_back(rest[2][p2]);
                break;

                case 3:
                    --p3;
                    suf.emplace_back(rest[3][p3]);
                break;

                case 4:
                    --p4;
                    suf.emplace_back(rest[4][p4]);
                break;
            }
        }
    }
    catch (int x) {

    }

    reverse(suf.begin(), suf.end());

    for(int i = 0; i < p1; i++) {
        suf.emplace_back(rest[1][i]);
    }

    vector<int> ans;
    for(auto el : good)
        ans.emplace_back(el.id);

    for(auto el : suf)
        ans.emplace_back(el.id);

    return ans;
}
