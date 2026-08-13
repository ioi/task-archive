#include "classroom.h"

std::vector<std::vector<int>> process_step(int N, int M, int R, std::vector<int> T, std::vector<std::vector<int>> A) {
	std::vector<int> has(N);
    for (int x : T) has[x] = true;
    for (int i = 0; i < N; ++i) {
        if (has[i]) continue;
        if (A[i].empty()) A[i] = {0, 0};
        int x = A[i][0] * 64 + A[i][1];
        x += R + 1;
        A[i] = {x / 64, x % 64};
    }
	return A;
}

std::vector<int> determine_steps(int N, int M, std::vector<std::vector<int>> A) {
	std::vector<int> has(N), ret(N, -1);
    int S = M * (M + 1) / 2;
    for (int i = 0; i < N; ++i) {
        if (!A[i].empty()) {
            int x = A[i][0] * 64 + A[i][1];
            int y = S - x;
            
            if (y > 0) {
                ret[i] = y - 1;
            }
        }
    }
    return ret;
}
