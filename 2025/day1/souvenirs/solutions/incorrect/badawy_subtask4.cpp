#include<bits/stdc++.h>
#include "souvenirs.h"

using namespace std;

void buy_souvenirs(int N, long long P0)
{
    N=N;
    long long cur=P0-1;
    auto ret = transaction(cur);
    if(ret.first.size() == 1) {
        long long curp = cur - ret.second;
        transaction(curp-1);
        transaction(curp-1);
        return;
    }
    long long avg = (cur - ret.second)/2;
    transaction(avg);
}