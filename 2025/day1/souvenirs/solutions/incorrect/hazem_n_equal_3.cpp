#include "bits/stdc++.h"
#include "souvenirs.h"
using namespace std;

void buy_souvenirs(int N, long long P0) {
    N=N;
    auto t = transaction(P0 - 1);
    long long P2 = (P0 - 1 - t.second) / (int)t.first.size();
    P2 -= (t.first.size() == 1);
    transaction(P2);
    if(t.first.size() == 1)
        transaction(P2);
}
