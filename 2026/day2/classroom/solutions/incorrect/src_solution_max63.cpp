#include "classroom.h"
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> process_step(
    int N, int M, int R, vector<int> T, vector<vector<int>> A
) {
    vector<vector<int>> ans = A;
    set<int> temples;
    for (auto t : T)
        temples.insert(t);
    for (int i = 0; i < N; i ++) {
        if (temples.count(i))
            continue;
        while (ans[i].size() < R)
            ans[i].push_back(0);
        ans[i].push_back(i + 1);
    }
    return ans;
}

vector<int> determine_steps(
    int N, int M, vector<vector<int>> A
) {
    for (int i = 0; i < N; i ++)
        while (A[i].size() < M)
            A[i].push_back(0);
    vector<int> ans(N, -1);
    for (int R = 0; R < M; R ++) {
        vector<int> seen(N, false);
        for (int i = 0; i < N; i ++)
            seen[A[i][R] - 1] = true;
        for (int i = 0; i < N; i ++)
            if (!seen[i])
                ans[i] = R;
    }
    return ans;
}