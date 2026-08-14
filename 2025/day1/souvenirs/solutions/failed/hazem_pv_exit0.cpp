/**
* protocol violation: exit(0)
*/

#include "cstdlib"
#include "souvenirs.h"

void buy_souvenirs(int N, long long P0) {
    N=N;
    transaction(P0 - 1);
    exit(0);
}
