#include<bits/stdc++.h>
#include "souvenirs.h"

using namespace std;

void buy_souvenirs(int N, long long P0)
{
    long long cur=P0-1;
    int onc=0;
    for(int i=1;i<N;i++) {
        if(i==N-1 && onc==N-1) break;
        auto ret = transaction(cur);
        if(ret.first.size() > 1) { // Can only happen in case of [X, 1]
            cur-=1 + ret.second; onc++;
            for(int j=0;j<i-1;j++) transaction(cur);
            cur--;

        } else {
            cur=(cur-ret.second);
            for(int j=0;j<i-1 - (i==N-1?onc:0);j++) transaction(cur);
            cur-=1;
        }
    }
}