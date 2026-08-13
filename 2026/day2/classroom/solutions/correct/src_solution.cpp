#include "classroom.h"
#include <algorithm>
#include <set>

using namespace std;

#define PARITY 100
#define DANGER 103
#define loc first
#define time second

vector<pair<int, int>> unpack(vector<vector<int>> A) {
    vector<pair<int, int>> values(A.size());
    for (int i = 0; i < A.size(); i ++) {
        if (A[i].size() == 0)
            values[i] = {-1, -1};
        else if (A[i].size() == 1)
            values[i] = {A[i][0], DANGER};
        else if (A[i][0] == 63)
            values[i] = {A[i][1], PARITY + 2};
        else if (A[i][1] >= 62)
            values[i] = {A[i][0], A[i][1] + PARITY - 62};
        else
            values[i] = {A[i][0], A[i][1]};
    }
    return values;
}

vector<vector<int>> pack(vector<pair<int, int>> values) {
    vector<vector<int>> B(values.size());
    for (int i = 0; i < values.size(); i ++) {
        if (values[i] == pair<int, int>{-1, -1})
            B[i] = vector<int>();
        else if (values[i].time == DANGER)
            B[i] = vector<int>{values[i].loc};
        else if (values[i].time == PARITY + 2)
            B[i] = vector<int>{63, values[i].loc};
        else if (values[i].time >= PARITY)
            B[i] = vector<int>{values[i].loc, values[i].time - (PARITY - 62)};
        else
            B[i] = vector<int>{values[i].loc, values[i].time};
    }
    return B;
}

vector<pair<int, int>> update(int N, vector<pair<int, int>> values, vector<int> T, int R) {
    int cur_parity = (R % 3) + PARITY;
    int req_parity = ((R + 2) % 3) + PARITY;
    vector<pair<int, int>> ans = values;
    // find temples from previous iteration
    set<int> temples;
    for (auto t : T)
        temples.insert(t);
    for (int i = 0; i < N; i ++) {
        if (temples.count(i)) continue;
        bool found = false, finalised = false;
        for (int j = 0; j < N; j ++) {
            if (values[j].loc != i) continue;
            if (values[j].time == req_parity)
                found = true;
            else if (values[j].time < PARITY) {
                finalised = true; ans[i] = values[j];
            }
        }
        if (!finalised && found)
            ans[i] = {i, cur_parity};
        else if (!finalised)
            ans[i] = {i, R - 1};
    }
    // reconstruct the necessary parts of P
    vector<int> P(N, -1);
    for (int i = 0; i < N; i ++)
        if (values[i].loc != -1 && !temples.count(i))
            P[values[i].loc] = i;
    // find dangerous cases
    for (int i = 0; i < N; i ++) {
        if (!temples.count(i)) continue;
        int duplicate = -1;
        for (int j = 0; j < N; j ++)
            if (temples.count(j) && values[j].loc == i && values[j].time == cur_parity)
                duplicate = j;
        if (duplicate == -1) continue;
        // find the path
        vector<int> path = {i};
        while (P[path.back()] != -1)
            path.push_back(P[path.back()]);
        ans[path[path.size() - 1]] = {path[path.size() - 2], DANGER};
        ans[path[path.size() - 2]] = {i, DANGER};
    }
    // fix dangerous cases
    vector<bool> appears(N, false);
    for (int i = 0; i < N; i ++)
        if (values[i].loc != -1 && values[i].time != DANGER)
            appears[values[i].loc] = true;
    for (int i = 0; i < N; i ++) {
        if (values[i].time != DANGER) continue;
        if (appears[values[i].loc]) {
            // points to the problematic temple
            ans[values[i].loc] = {values[i].loc, R - 1};
            ans[i] = {i, R - 2};
        } else {
            // points to the other borrowed location
            ans[values[i].loc] = {values[i].loc, R - 3};
            ans[i] = {i, R - 1};
        }
    }
    return ans;
}

vector<vector<int>> process_step(int N, int M, int R, vector<int> T, vector<vector<int>> A) {
    if (R == 0) {
        vector<pair<int, int>> ans(N);
        for (int i = 0; i < N; i ++)
            ans[i] = {i, PARITY};
        for (auto t : T)
            ans[t] = {-1, -1};
        return pack(ans);
    }
    return pack(update(N, unpack(A), T, R));
}

vector<int> determine_steps(int N, int M, vector<vector<int>> A) {
    vector<pair<int, int>> values = unpack(A);
    values = update(N, values, vector<int>(), M);
    vector<int> ans(N, -1);
    for (int i = 0; i < N; i ++)
        if (values[i].time < M)
            ans[i] = values[i].time;
    return ans;
}