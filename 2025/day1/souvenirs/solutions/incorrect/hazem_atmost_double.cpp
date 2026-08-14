#include "bits/stdc++.h"
#include "souvenirs.h"
using namespace std;

struct cart{
    long long total;
    vector <int> items;
};

void buy_souvenirs(int N, long long P0) {
    vector <int> cnt(N);
    iota(cnt.begin(), cnt.end(), 0);
    auto query = [&](long long M){
        auto t = transaction(M);
        for(int&i : t.first)
            cnt[i]--;
        return cart{M - t.second, t.first};
    };

    vector <cart> lead(N);
    cart t = query(P0 - 1);
    lead[1] = t;
    while(t.items[0] != N - 1){
        t = query(t.total / (int)t.items.size() - (t.items.size() == 1));
        lead[t.items[0]] = t;
    }
    for(int i = N - 1; i > 0; i--){
        if(lead[i].total == 0){
            lead[i] = query(2 * lead[i+1].total);
        }
        while(lead[i].items.size() > 1){
            int j = lead[i].items.back();
            lead[i].total -= lead[j].total;
            lead[i].items.pop_back();
        }
    }
    for(int i = 0; i < N; i++)
        while(cnt[i] > 0)
            query(lead[i].total);
}
