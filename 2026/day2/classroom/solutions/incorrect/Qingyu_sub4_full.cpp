#include "classroom.h"
#include <cassert>

namespace {
    bool detect_worst_case(int N, const std::vector<std::vector<int>> &A) {
        for (int i = 0; i < N; ++i) if (!A[i].empty()) {
            if (A[i][0] == N) {
                return true;
            }
        }
        return false;
    }
    void fix_worst_case(int N, int M, int R, std::vector<std::vector<int>> &A) {
        // handle bad case
        // first, find the missing time and missing pos
        int bad_pos = -1, empty_pos = -1, timestamp = -1;
        for (int i = 0; i < N; ++i) {
            if (A[i].empty()) {
                empty_pos = i;
            }
            else {
                if (A[i][0] == N) {
                    bad_pos = i;
                    timestamp = A[i][1];
                }
            }
        }
        std::vector<int> has_t(M), has_p(M);
        for (int i = 0; i < N; ++i) {
            if (!A[i].empty() && i != bad_pos) {
                has_p[A[i][0]] = 1;
                has_t[A[i][1]] = 1;
            }
        }
        assert(!has_t[M - 1]);
        int missing_t = -1, missing_p = -1;
        for (int i = 0; i < N; ++i) {
            if (!has_p[i]) {
                missing_p = i;
                if (missing_p == 0) missing_p = N - 1;
                assert(!has_p[missing_p] && !has_p[(missing_p + 1) % N]);
                break;
            }
        }
        for (int i = 0; i < M - 1; ++i) {
            if (!has_t[i]) {
                missing_t = i;
                break;
            }
        }
        A[empty_pos] = {missing_p, R - 1};
        A[bad_pos] = {(missing_p + 1) % N, timestamp};
    }
}

std::vector<std::vector<int>> process_step(int N, int M, int R, std::vector<int> T, std::vector<std::vector<int>> A) {
    if (detect_worst_case(N, A)) {
        assert(T.empty());
        fix_worst_case(N, M, R, A);
    }
    if (!T.empty()) {
        int x = T[0];
        for (int i = 0; i < N; ++i) {
            if (i != x && A[i].empty()) {
                A[i].push_back(x);
                A[i].push_back(R);
                return A;
            }
        }
        // bad case happened
        int y = (x + 1) % N;
        for (int i = 0; i < N; ++i) {
            if (!A[i].empty() && A[i][0] == y) {
                A[i][0] = N;
            }
        }
    }
	return A;
}

std::vector<int> determine_steps(int N, int M, std::vector<std::vector<int>> A) {
    if (detect_worst_case(N, A)) {
        fix_worst_case(N, M, M, A);
    }
	std::vector<int> ret(N, -1);
    int x = -1;
    bool bad = false;
    int bad_pos = -1;

    for (int i = 0; i < N; ++i) if (!A[i].empty()) {
        if (A[i][0] == N) {
            bad = true;
            bad_pos = i;
        }
    }

    for (int i = 0; i < N; ++i) {
        if (A[i].empty()) continue;
        if (A[i][0] != N) {
            ret[A[i][0]] = A[i][1];
        }
    }
    return ret;
}
