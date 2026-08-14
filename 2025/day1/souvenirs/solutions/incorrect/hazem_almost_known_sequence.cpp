#include "bits/stdc++.h"
#include "souvenirs.h"
using namespace std;

void buy_souvenirs(int N, long long P0) {
    int last_times = N - 1;
    long long last_price = P0;
    for(int i = 1; i < N - 1; i++){
        auto t = transaction(last_price - 1);
        last_price -= 1 + t.second;
        last_price -= (t.first.size() == 2);
        last_times -= (t.first.size() == 2);
        for(int j = 0; j < i - 1; j++)
            transaction(last_price);
    }
    for(int j = 0; j < last_times; j++)
        transaction(last_price - 1);
}
