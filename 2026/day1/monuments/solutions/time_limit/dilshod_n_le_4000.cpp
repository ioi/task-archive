/* Suboptimal solution, passes for N <= 4000
 * Author: Dilshodbek Khujaev
 * Complexity: O(N^2)
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

    vector<int> A_red, A_blue;
    for (int i = 0; i < N; i++){
        (A[i].c == RED ? A_red : A_blue).push_back(A[i].x);
    }

    vector<vector<long long>> dp(1 + A_blue.size(), vector<long long>(1 + A_red.size(), INF));
    dp[0][0] = 0;

    for (int x = 0; x <= (int)A_blue.size(); x++){
        for (int y = 0; y <= (int)A_red.size(); y++){
            if (x < (int) A_blue.size()){
                dp[x + 1][y] = min(dp[x + 1][y], dp[x][y] + abs(A_blue[x] - B[x + y].x));
            }

            if (y < (int) A_red.size() && B[x + y].c == BLUE){
                dp[x][y + 1] = min(dp[x][y + 1], dp[x][y] + abs(A_red[y] - B[x + y].x));
            }
        }
    }

    long long ans = dp[A_blue.size()][A_red.size()];
    if (ans == INF) ans = -1;

    return ans;
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