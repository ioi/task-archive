/* Solution for X[P[i]] < 0
 * Author: Dilshodbek Khujaev
 * Complexity: O(N logN)
 */

#include "monuments.h"
#include <bits/stdc++.h>

using namespace std;

static const long long INF = (long long)1e16;
static const int RED = 0;  // old
static const int BLUE = 1; // new

long long get_cost(vector<int> X, vector<int> P){
    int N = (int) X.size(), M = (int) P.size();
    
    vector<int> color(N, BLUE);
    for (int i : P) color[i] = RED;

    vector<int> A; // all reds + some blues
    vector<int> B; // the rest of blues
    for (int i = 0; i < N; i++){
        if (color[i] == RED && X[i] != 0) A.push_back(X[i]);
        if (color[i] == BLUE) B.push_back(X[i]);
    }

    if (M > N - M) return -1;

    if (N % 2 == 1){
        A.push_back(0);
        M++;
        N++;
    }

    int need = N / 2 - M;

    A.insert(A.end(), B.begin(), B.begin() + need);
    B.erase(B.begin(), B.begin() + need);

    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());

    long long ans = 0;
    for (int i = 0; i < N / 2; i++){
        ans += abs(A[i] + B[i]);
    }

    return ans;
}