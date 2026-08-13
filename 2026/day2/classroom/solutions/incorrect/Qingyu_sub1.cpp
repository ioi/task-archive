#include "classroom.h"

std::vector<std::vector<int>> process_step(int N, int M, int R, std::vector<int> T, std::vector<std::vector<int>> A) {
	std::vector<int> has(N);
    for (int x : T) has[x] = true;
    for (int i = 0; i < N; ++i) {
        if (!has[i]) {
            A[i] = {i};
        }
    }
	return A;
}

std::vector<int> determine_steps(int N, int M, std::vector<std::vector<int>> A) {
	std::vector<int> has(N), ret(N, -1);
    for (int i = 0; i < N; ++i) {
        if (!A[i].empty()) {
            has[A[i].back()] = true;
        }
    }
    for (int i = 0; i < N; ++i) {
        if (!has[i]) {
            ret[i] = 0;
        }
    }
    return ret;
}
