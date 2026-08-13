#include "classroom.h"
#include <bits/stdc++.h>

using namespace std;

vector<int> apply_perm(vector<int> &values, vector<int> &perm) {
    vector<int> res(values.size());
    for (int i = 0; i < values.size(); i ++)
        res[perm[i]] = values[i];
    return res;
}

vector<vector<int>> process_step(
    int N, int M, int R, 
    vector<int> T, 
    vector<vector<int>> A
) {
    vector<vector<int>> ans = A;
    set<int> temples;
    for (auto t : T)
        temples.insert(t);
    // one of the last time periods - fill in indices
    if (R >= M - 3) {
        for (int i = 0; i < N; i ++) {
            if (temples.count(i)) continue;
            while (ans[i].size() < (R - (max(0, M - 3))) + (M + 2) / 6)
                ans[i].push_back(0);
            ans[i].push_back(i + 1);
        }
    }
    // otherwise just fill in the blanks with one bit
    else {
        for (int i = 0; i < N; i ++) {
            if (temples.count(i)) continue;
            while (ans[i].size() < R / 6 + 1)
                ans[i].push_back(0);
            ans[i].back() += (1 << (R % 6));
        }
    }
    return ans;
}

vector<int> determine_steps(
    int N, int M, vector<vector<int>> A
) {
    vector<int> ans(N, -1);
    for (int i = 0; i < N; i ++)
        while (A[i].size() < (M + 2) / 6 + min(M, 3))
            A[i].push_back(0);
    // we will use values to reconstruct P
    vector<vector<int>> values(N, vector<int>(4, -1));
    for (int i = 0; i < N; i ++)
        values[i][3] = i;
    // get the answers for last 3 time periods
    for (int R = 0; R < min(M, 3); R ++) {
        int start = (M + 2) / 6 + min(M, 3) - R - 1;
        vector<bool> seen(N, false);
        for (int i = 0; i < N; i ++) {
            int cur = A[i][start];
            if (cur == 0) continue;
            seen[cur - 1] = true;
            values[i][2 - R] = cur - 1;
        }
        for (int i = 0; i < N; i ++)
            if (!seen[i])
                ans[i] = M - R - 1;
    }
    if (M <= 3)
        return ans;
    // reconstruct P (or rather, we need its inverse)
    vector<int> inv_P(N, -1);
    for (int i = 0; i < N; i ++)
        for (int j = 0; j < 3; j ++)
            if (values[i][j] != -1 && values[i][j + 1] != -1)
                inv_P[values[i][j + 1]] = values[i][j];
    // get the data from time periods before M - 3
    vector<int> indices(N);
    iota(indices.begin(), indices.end(), 0);
    indices = apply_perm(indices, inv_P);
    indices = apply_perm(indices, inv_P);
    indices = apply_perm(indices, inv_P);
    for (int R = M - 4; R >= 0; R --) {
        indices = apply_perm(indices, inv_P);
        for (int i = 0; i < N; i ++)
            if (((A[indices[i]][R / 6] >> (R % 6)) & 1) == 0)
                ans[i] = R;
    }
    return ans;
}