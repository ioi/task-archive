#include "classroom.h"
#include <bits/stdc++.h>

using namespace std;

void fix_worst_case(int N, int R, vector<vector<int>> &A) {
    for (int i = 0; i < N; i ++) {
        if (A[i].size() == 0)
            continue;
        if (A[i][0] == 63) {
            int orig_time = A[i][1];
            vector<bool> exists(N, false);
            for (int j = 0; j < N; j ++)
                if (A[j].size() && A[j][0] != 63)
                    exists[A[j][0]] = true;
            int temple;
            for (int j = 0; j < N; j ++)
                if (!exists[j] && !exists[(j + 1) % N])
                    temple = j;
            vector<int> free;
            for (int j = 0; j < N; j ++)
                if (!A[j].size() || A[j][0] == 63)
                    free.push_back(j);
            A[free[0]] = vector<int>{temple, R - 1};
            A[free[1]] = vector<int>{(temple + 1) % N, orig_time};
        }
    }
}

vector<vector<int>> process_step(
    int N, int M, int R, vector<int> T, vector<vector<int>> A
) {
    fix_worst_case(N, R, A);
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
    // worst case
    int target = (temple + 1) % N;
    for (int i = 0; i < N; i ++)
        if (A[i].size() != 0 && A[i][0] == target)
            A[i][0] = 63;
    return A;
}

vector<int> determine_steps(
    int N, int M, vector<vector<int>> A
) {
    fix_worst_case(N, M, A);
    vector<int> ans(N, -1);
    for (int i = 0; i < N; i ++)
        for (int j = 0; j < A[i].size(); j += 2) {
            int temple = A[i][j], time = A[i][j + 1];
            ans[temple] = time;
        }
    return ans;
}