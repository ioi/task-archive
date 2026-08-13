#include "classroom.h"
#include <bits/stdc++.h>

using namespace std;

#define loc first
#define time second
#define FINISHED (1 << 6)

vector<pair<int, int>> unpack(vector<vector<int>> A) {
    vector<pair<int, int>> ans;
    for (int i = 0; i < A.size(); i ++) {
        if (A[i].size() == 0) {
            ans.push_back({-1, 0});
        } else {
            ans.push_back({A[i][0] - 1, A[i][1] + FINISHED * A[i][2]});
        }
    }
    return ans;
}

vector<vector<int>> pack(vector<pair<int, int>> values) {
    vector<vector<int>> A(values.size());
    for (int i = 0; i < values.size(); i ++) {
        if (values[i].loc == -1)
            continue;
        A[i].push_back(values[i].loc + 1);
        A[i].push_back(values[i].time % FINISHED);
        A[i].push_back(values[i].time / FINISHED);
    }
    return A;
}

vector<pair<int, int>> update(int N, vector<pair<int, int>> values, vector<int> T, int R) {
    vector<pair<int, int>> ans = values;
    set<int> temples;
    for (auto t : T)
        temples.insert(t);
    for (int i = 0; i < N; i ++) {
        if (temples.count(i)) continue;
        bool seen = false;
        for (int j = 0; j < N; j ++) {
            if (values[j].loc == i) {
                // finalised - copy the value
                if (values[j].time >= FINISHED) {
                    ans[i] = values[j];
                    seen = true; break;
                }
                // not a temple
                else if (values[j].time == R - 1) {
                    ans[i] = {i, R};
                    seen = true; break;
                }
            }
        }
        // was a temple in previous time period
        if (!seen)
            ans[i] = {i, FINISHED + R - 1};
    }
    return ans;
}

vector<vector<int>> process_step(
    int N, int M, int R, vector<int> T, vector<vector<int>> A
) {
    if (R == 0) {
        vector<pair<int, int>> ans(N);
        for (int i = 0; i < N; i ++)
            ans[i] = {i, 0};
        for (auto t : T)
            ans[t] = {-1, 0};
        return pack(ans);
    }
    return pack(update(N, unpack(A), T, R));
}

vector<int> determine_steps(
    int N, int M, vector<vector<int>> A
) {
    vector<pair<int, int>> values = unpack(A);
    values = update(N, values, vector<int>(), M);
    vector<int> ans(N, -1);
    for (int i = 0; i < N; i ++)
        if (values[i].time >= FINISHED)
            ans[i] = values[i].time - FINISHED;
    return ans;
}