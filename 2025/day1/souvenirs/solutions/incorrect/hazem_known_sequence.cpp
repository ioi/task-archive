#include "bits/stdc++.h"
#include "souvenirs.h"
using namespace std;

void buy_souvenirs(int N, long long P0) {
    P0=P0;
    for(int i = 0; i < N; i++)
    for(int j = 0; j < i; j++)
        transaction(N - i);
}
