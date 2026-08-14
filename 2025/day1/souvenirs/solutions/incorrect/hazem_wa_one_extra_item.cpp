/**
* incorrect: one extra item
*/

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
    auto reduce = [&](cart c){
        vector <int> red;
        for(int j : c.items){
            if(lead[j].items.size() == 1 && j != c.items[0])
                c.total -= lead[j].total;
            else
                red.push_back(j);
        }
        c.items = red;
        return c;
    };

    cart t = query(P0 - 1);
    lead[1] = t;
    while(t.items[0] != N - 1){
        t = query(t.total / (int)t.items.size() - (t.items.size() == 1));
        lead[t.items[0]] = t;
    }
    for(int i = N - 1; i > 0; i--){
        if(lead[i].total == 0){
            int j = i;
            while(lead[--j].total == 0);
            t = reduce(lead[j]);
            while(t.items[0] != i){
                t = reduce(query(t.total / (int)t.items.size() - (t.items.size() == 1)));
                lead[t.items[0]] = t;
            }
        }
        lead[i] = reduce(lead[i]);
    }
    for(int i = 0; i < N; i++)
        while(cnt[i] > 0)
            query(lead[i].total);

    transaction(lead[rand() % (N - 1) + 1].total);
}
