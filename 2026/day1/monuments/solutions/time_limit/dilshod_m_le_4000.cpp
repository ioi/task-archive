/* Suboptimal solution, passes for M <= 4000
 * Author: Dilshodbek Khujaev
 * Complexity: O(N + M^2)
 */

#include "monuments.h"
#include <bits/stdc++.h>

using namespace std;

static const long long INF = (long long)1e16;
static const int RED = 0;  // old
static const int BLUE = 1; // new

struct monument{
    int x, c;
    monument(){x = 0, c = 0;};
    monument(int _x, int _c){x = _x, c = _c;};
};

long long solve(vector<monument> A, vector<monument> B){
    int N = (int) A.size();

    function<long long(int, int)> cost = [&](int l, int r){
        long long res = 0;

        queue<int> blue;
        for (int i = l; i <= r; i++){
            if (B[i].c == BLUE) blue.push(B[i].x);
        }
        for (int i = l; i <= r; i++){
            if (A[i].c == RED){
                res += abs(A[i].x - blue.front());
                blue.pop();
            }
        }

        for (int i = l; i <= r; i++){
            if (A[i].c == BLUE) blue.push(A[i].x);
        }
        for (int i = l; i <= r; i++){
            if (B[i].c == RED){
                res += abs(B[i].x - blue.front());
                blue.pop();
            }
        }

        return res;
    };

    vector<int> pref(N + 1, 0);
    for (int i = 0; i < N; i++){
        pref[i + 1] = pref[i];
        pref[i + 1] += (A[i].c == BLUE) + (B[i].c == BLUE);
        pref[i + 1] -= (A[i].c == RED) + (B[i].c == RED);
    }

    vector<int> next(N, -1);
    map<int, int> last;
    for (int i = N; i >= 0; i--){
        if (last.contains(pref[i])){
            next[i] = last[pref[i]];
        }
        last[pref[i]] = i;
    }

    vector<long long> dp(N + 1, INF);
    dp[0] = 0;

    for (int i = 0; i < N; i++){
        if (A[i].c == BLUE && B[i].c == BLUE){
            dp[i + 1] = min(dp[i + 1], dp[i] + abs(A[i].x - B[i].x));
        }

        if (next[i] != -1){
            int j = next[i];
            dp[j] = min(dp[j], dp[i] + cost(i, j - 1));
        }
    }

    return dp[N];
}

long long get_cost(vector<int> X, vector<int> P){
    int N = (int) X.size();
    
    vector<int> color(N, BLUE);
    for (int i : P) color[i] = RED;

    vector<int> red, blue;
    for (int i = 0; i < N; i++){
        if (color[i] == RED && X[i] != 0) red.push_back(X[i]);
        if (color[i] == BLUE) blue.push_back(X[i]);
    }

    int r = (int) red.size(), b = (int) blue.size();
    
    vector<bool> deleted(r, false);
    int j = r - 1;
    for (int i = 0; i < r; i++){
        if (red[i] > 0 || red[j] < 0) break;

        while (j > i && red[j] > -red[i]){
            j--;
        }

        if (red[j] == -red[i]){
            deleted[i] = true;
            deleted[j] = true;
            j--;
        }
    }

    vector<int> red_copy = red;
    red.clear();
    int r1 = 0;
    for (int i = 0; i < r; i++){
        if (!deleted[i]) {
            red.push_back(red_copy[i]);
            if (red_copy[i] < 0) r1++;
        }
    }

    r = (int) red.size();

    if (r > b) return -1;

    N = r + b;

    if (N % 2 == 1){
        red.insert(red.begin() + r1, 0);
        r1++;
        r++;
        N++;
    }

    int b1 = N / 2 - r1;

    int i = 0; j = 0;
    vector<monument> A, B;
    while (i < r1 || j < b1){
        if (j == b1 || (i < r1 && red[i] < blue[j])){
            A.emplace_back(-red[i], RED);
            i++;
        } else {
            A.emplace_back(-blue[j], BLUE);
            j++;
        }
    }

    reverse(A.begin(), A.end());

    while (i < r || j < b){
        if (j == b || (i < r && red[i] < blue[j])){
            B.emplace_back(red[i], RED);
            i++;
        } else {
            B.emplace_back(blue[j], BLUE);
            j++;
        }
    }

    return solve(A, B);
}