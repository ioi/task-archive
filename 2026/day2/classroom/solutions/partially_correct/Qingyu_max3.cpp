#include "classroom.h"

std::vector<std::vector<int>> process_step(int N, int M, int R, std::vector<int> T, std::vector<std::vector<int>> A) {
	std::vector<int> has(N), active(N);
    for (int x : T) has[x] = true;
    if (R == 0) {
        for (int i = 0; i < N; ++i) {
            if (has[i]) continue;
            A[i] = { i, 0, 0 };
        }
    } 
    else {
        std::vector<std::vector<int>> pool;
        for (int i = 0; i < N; ++i) {
            if (!A[i].empty()) {
                int x = A[i][0], t = A[i][1], finalized = A[i][2];
                if (active[x]) continue;
                if (finalized == 1) {
                    pool.push_back(A[i]);
                }
                else if (t == R - 1) {
                    if (!has[x]) {
                        pool.push_back({x, R, 0});
                    }
                }
                else continue;
                active[x] = true;
            }
        }
        for (int i = 0; i < N; ++i) {
            if (!active[i]) {
                pool.push_back({i, R - 1, 1});
            }
        }
        for (int i = 0; i < N; ++i) {
            if (!has[i]) {
                A[i] = pool.back();
                pool.pop_back();
            }
        }
    }
    return A;
}

std::vector<int> determine_steps(int N, int M, std::vector<std::vector<int>> A) {
    std::vector<int> ret(N, -1), active(N);
	for (int i = 0; i < N; ++i) {
        if (!A[i].empty()) {
            int x = A[i][0], t = A[i][1], finalized = A[i][2];
            if (finalized == 1) {
                ret[x] = t;
                active[x] = 1;
            }
            else if (t == M - 1) {
                ret[x] = -1;
                active[x] = 1;
            }
        }
    }
    for (int i = 0; i < N; ++i) {
        if (!active[i]) {
            ret[i] = M - 1;
        }
    }
    return ret;
}
