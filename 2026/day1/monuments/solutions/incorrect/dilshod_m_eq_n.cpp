/* Solution for M = N
 * Author: Dilshodbek Khujaev
 * Complexity: O(N)
 */

#include "monuments.h"
#include <bits/stdc++.h>

using namespace std;

long long get_cost(vector<int> X, vector<int> P){
    int N = (int) X.size(), M = (int) P.size();
    if (N != M) return -1;

    for (int i = 0; i < N; i++){
        if (X[i] != -X[N - i - 1]) return -1;
    }
    
    if (N % 2 == 1 && X[N / 2] != 0){
        return -1;
    }

    return 0;
}