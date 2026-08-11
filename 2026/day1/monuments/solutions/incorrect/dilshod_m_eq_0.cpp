/* Solution for M = 0
 * Author: Dilshodbek Khujaev
 * Complexity: O(N)
 */

#include "monuments.h"
#include <bits/stdc++.h>

using namespace std;

long long get_cost(vector<int> X, vector<int> P){
    int N = (int) X.size(), M = (int) P.size();
    if (M != 0) return -1;

    long long ans = 0;
    int i = 0, j = N - 1;
    while (i < j){
        ans += abs(X[i] + X[j]);
        i++;
        j--;
    }

    if (i == j) ans += abs(X[i]);

    return ans;
}