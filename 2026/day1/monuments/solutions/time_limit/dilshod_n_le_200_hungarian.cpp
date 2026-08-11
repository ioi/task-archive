/* Suboptimal solution, passes for N <= 4000
 * Author: Dilshodbek Khujaev
 * Complexity: O(N^2)
 */

#include "monuments.h"
#include <bits/stdc++.h>

using namespace std;

static const long long INF = (long long)1e15;
static const int RED = 0;  // old
static const int BLUE = 1; // new

struct monument{
    int x, c;
    monument(){x = 0, c = 0;};
    monument(int _x, int _c){x = _x, c = _c;};
};

long long solve(vector<monument> A, vector<monument> B){
    int N = (int) A.size();

    vector<vector<long long>> mat(N + 1, vector<long long>(N + 1, 0));
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (A[i].c == RED && B[j].c == RED){
                mat[i + 1][j + 1] = INF;
            } else {
                mat[i + 1][j + 1] = abs(A[i].x - B[j].x);
            }
        }
    }

    vector<long long> u(N + 1), v(N + 1);
    vector<int> p(N + 1), way(N + 1);
    for (int i = 1; i <= N; ++i) {
        p[0] = i;
        int j0 = 0;
        vector<long long> minv(N + 1, INF);
        vector<bool> used(N + 1, false);
        do {
            used[j0] = true;
            int i0 = p[j0], j1 = -1;
            long long delta = INF;
            for (int j = 1; j <= N; ++j)
                if (!used[j]) {
                    long long cur = mat[i0][j] - u[i0] - v[j];
                    if (cur < minv[j])
                        minv[j] = cur, way[j] = j0;
                    if (minv[j] < delta)
                        delta = minv[j], j1 = j;
                }
            for (int j = 0; j <= N; ++j)
                if (used[j])
                    u[p[j]] += delta, v[j] -= delta;
                else
                    minv[j] -= delta;
            j0 = j1;
        } while (p[j0] != 0);

        do {
            int j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
        } while (j0);
    }

    return (long long) -v[0];
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