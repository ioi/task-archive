#include<bits/stdc++.h>
#include "souvenirs.h"

using namespace std;

void buy_souvenirs(int N, long long P0)
{
    for(int i=1;i<N;i++) {
        for(int j=1;j<=i;j++) {
            transaction(P0-i);
        }
    }
}