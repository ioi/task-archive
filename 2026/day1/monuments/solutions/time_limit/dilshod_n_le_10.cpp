/* Suboptimal solution, passes for N <= 10
 * Author: Dilshodbek Khujaev
 * Complexity: O(N!)
 */

#include "monuments.h"
#include <bits/stdc++.h>

using namespace std;

static const long long INF = (long long)1e16;
static const int RED = 0;  // old
static const int BLUE = 1; // new

long long get_cost(vector<int> X, vector<int> P){
    int N = (int) X.size();
    
    vector<int> color(N, BLUE);
    for (int i : P) color[i] = RED;

    long long ans = INF;
    for (int k = 0; k * 2 <= N; k++){
        vector<int> where(N, 0);
        for (int i = 0; i < k; i++) where[i] = -1;
        for (int i = N - k; i < N; i++) where[i] = +1;

        do {
            long long rest = 0;
            vector<int> neg, pos;
            for (int i = 0; i < N; i++){
                if (where[i] == -1) neg.push_back(i);
                if (where[i] == +1) pos.push_back(i);

                if (where[i] == 0){
                    if (color[i] == RED && X[i] != 0) rest += INF;
                    rest += abs(X[i]);
                }
            }
            
            if (rest >= INF) continue;

            if (k == 0) ans = min(ans, rest);

            do {
                long long match = 0;
                for (int id = 0; id < k; id++){
                    int i = neg[id], j = pos[id];
                    if (color[i] == RED && color[j] == RED){
                        if (X[i] != -X[j]) match += INF;
                    } else {
                        match += abs(X[i] + X[j]);
                    }
                }

                ans = min(ans, match + rest);
            } while (next_permutation(neg.begin(), neg.end()));
            
        } while (next_permutation(where.begin(), where.end()));
    }

    return (ans == INF ? -1 : ans);
}