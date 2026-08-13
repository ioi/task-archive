#include "classroom.h"
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> process_step(
    int N, int M, int R, vector<int> T, vector<vector<int>> A
) {
    if (T.size() == 0)
        return A;
    int temple = T[0];
    for (int i = 0; i < N; i ++) {
        if (i == temple)
            continue;
        if (A[i].size() == 0) {
            A[i] = vector<int>{temple, R};
            return A;
        }
    }
    for (int i = 0; i < N; i ++) {
        if (i == temple)
            continue;
        A[i].push_back(temple);
        A[i].push_back(R);
        return A;
    }
}

vector<int> determine_steps(
    int N, int M, vector<vector<int>> A
) {
    vector<int> ans(N, -1);
    for (int i = 0; i < N; i ++)
        for (int j = 0; j < A[i].size(); j += 2) {
            int temple = A[i][j], time = A[i][j + 1];
            ans[temple] = time;
        }
    return ans;
}