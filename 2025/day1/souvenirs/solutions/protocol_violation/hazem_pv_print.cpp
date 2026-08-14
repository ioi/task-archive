/**
* protocol violation: print statement
*/

#include "stdio.h"
#include "souvenirs.h"

void buy_souvenirs(int N, long long P0) {
    N=N;
    transaction(P0 - 1);
    printf("print\n");
}
