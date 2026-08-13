#include "classroom.h"
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> process_step(
    int N, int M, int R, vector<int> T, vector<vector<int>> A
) {
    vector<vector<int>> ans(N);
    for (int i = 0; i < N; i ++)
        ans[i] = vector<int>{i};
    for (auto t : T)
        ans[t] = vector<int>();
    return ans;
}

vector<int> determine_steps(
    int N, int M, vector<vector<int>> A
) {
    vector<int> ans(N, 0);
    for (int i = 0; i < N; i ++)
        if (A[i].size() == 1)
            ans[A[i][0]] = -1;
    return ans;
}