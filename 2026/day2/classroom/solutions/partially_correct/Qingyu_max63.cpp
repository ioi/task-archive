#include "classroom.h"

std::vector<std::vector<int>> process_step(int N, int M, int R, std::vector<int> T, std::vector<std::vector<int>> A) {
	int state = 0;
    std::vector<int> base(N, 0), has(N);
    for (auto vec : A) {
        if (vec.empty()) continue;
        for (int i = 0; i < N; ++i) {
            base[i] = std::max(base[i], vec[i]);
        }
    }
    for (int x : T) {
        base[x] = R + 1;
        has[x] = true;
    }
    for (int i = 0; i < N; ++i) {
        if (!has[i]) {
            A[i] = base;
        }
    }
    return A;
}

std::vector<int> determine_steps(int N, int M, std::vector<std::vector<int>> A) {
	std::vector<int> ret(N, -1);
    for (auto vec : A) {
        if (vec.empty()) continue;
        for (int i = 0; i < N; ++i) {
            ret[i] = std::max(ret[i], vec[i] - 1);
        }
    }
    return ret;
}
