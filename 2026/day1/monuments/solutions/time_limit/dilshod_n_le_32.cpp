/* Suboptimal solution, passes for N <= 36
 * Author: Dilshodbek Khujaev
 * Complexity: O(N-M choose M)
 */

#include "monuments.h"
#include <bits/stdc++.h>

using namespace std;

static const long long INF = (long long)1e16;
static const int RED = 0;  // old
static const int BLUE = 1; // new

long long solve(vector<int> red, vector<int> blue){
    int r = (int) red.size(), b = (int) blue.size();
    if (r > b) return -1;
    
    vector<int> chosen(b, 0);
    fill(chosen.end() - r, chosen.end(), 1);

    long long ans = INF;
    do {
        vector<int> RB, BB;
        for (int i = 0; i < b; i++){
            (chosen[i] ? RB : BB).push_back(blue[i]);
        }

        long long cur = 0;
        for (int i = 0; i < r; i++){
            cur += llabs(red[i] + RB[r - i - 1]);
        }

        int i = 0, j = b - r - 1;
        while (i < j){
            cur += llabs(BB[i] + BB[j]);
            i++;
            j--;
        }
        
        if (i == j) cur += abs(BB[i]);
        
        ans = min(ans, cur);
    } while (next_permutation(chosen.begin(), chosen.end()));

    return ans;
}

long long get_cost(vector<int> X, vector<int> P){
    int N = (int) X.size();
    
    vector<int> color(N, BLUE);
    for (int i : P) color[i] = RED;

    map<int, int> cnt;
    for (int i = 0; i < N; i++){
        if (color[i] == RED) cnt[X[i]]++;
    }

    for (auto &[x, c] : cnt){
        if (x > 0) continue;
        if (x == 0){
            c = 0;
            continue;
        }

        int rem = min(c, cnt[-x]);
        c -= rem;
        cnt[-x] -= rem;
    }

    vector<int> red, blue;
    for (auto [x, c] : cnt){
        while (c--){
            red.push_back(x);
        }
    }

    for (int i = 0; i < N; i++){
        if (color[i] == BLUE) blue.push_back(X[i]);
    }

    return solve(red, blue);
}