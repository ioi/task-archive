#include "classroom.h"
#include <bits/stdc++.h>

using namespace std;


struct state {
    int loc; int time; bool is_free;
};

vector<pair<state, state>> unpack(vector<vector<int>> A) {
    vector<pair<state, state>> ans(A.size());
    for (int i = 0; i < A.size(); i ++) {
        state group_1, group_2;
        if (A[i].size() > 0)
            group_1 = {A[i][0], A[i][1], false},
            group_2 = {A[i][2], A[i][3], A[i][4] > 0};
        else
            group_1 = group_2 = {0, 0, false};
        ans[i] = {group_1, group_2};
    }
    return ans;
}

vector<vector<int>> pack(vector<pair<state, state>> values) {
    vector<vector<int>> ans(values.size());
    for (int i = 0; i < values.size(); i ++) {
        if (values[i].first.loc != 0 || values[i].second.loc != 0)
            ans[i] = {
                values[i].first.loc, values[i].first.time,
                values[i].second.loc, values[i].second.time, values[i].second.is_free
            };
    }
    return ans;
}

vector<vector<int>> process_step(
    int N, int M, int R, vector<int> T, vector<vector<int>> A
) {
    vector<pair<state, state>> values = unpack(A);
    set<int> temples;
    for (auto t : T)
        temples.insert(t);
    vector<state> to_record;
    // too many temples - record empty space
    if (temples.size() > N / 2) {
        for (int i = 0; i < N; i ++)
            if (!temples.count(i))
                to_record.push_back((state){i + 1, R, true});
    }
    // record temples
    else {
        for (auto t : T)
            to_record.push_back((state){t + 1, R, false});
    }
    for (auto data : to_record) {
        // if possible, place into group 1
        bool done = false;
        if (!data.is_free) {
            for (int i = 0; i < N; i ++)
                if (!temples.count(i) && values[i].first.loc == 0) {
                    values[i].first = data;
                    done = true; break;
                }
        }
        if (!done) {
            for (int i = 0; i < N; i ++)
                if (!temples.count(i) && values[i].second.loc == 0) {
                    values[i].second = data;
                    done = true; break;
                }
        }
    }
    return pack(values);
}

vector<int> determine_steps(
    int N, int M, vector<vector<int>> A
) {
    vector<pair<state, state>> values = unpack(A);
    vector<state> data;
    for (auto a : values)
        data.push_back(a.first), data.push_back(a.second);
    vector<int> ans(N, -1);
    bool seen_special = false;
    vector<int> special_temples(N, -1);
    for (int i = 0; i < data.size(); i ++) {
        if (data[i].loc == 0)
            continue;
        if (data[i].is_free) {
            if (!seen_special) {
                seen_special = true;
                special_temples = vector<int>(N, data[i].time);
            }
            special_temples[data[i].loc - 1] = -1;
        } else {
            ans[data[i].loc - 1] = data[i].time;
        }
    }
    for (int i = 0; i < N; i ++)
        if (special_temples[i] != -1)
            ans[i] = special_temples[i];
    return ans;
}