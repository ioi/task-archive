#include "classroom.h"
std::vector<std::vector<int>> process_step(int N, int M, int R, std::vector<int> T, std::vector<std::vector<int>> A) {
	std::vector<int> has(N);
    int y = -1;
    for (int x : T) {
        y = x;
    }
    if (y == -1) y = N;
    int cnt = 0;
    for (int i = 0; i < N && cnt < y; ++i) {
        if (i != y) {
            int j = R / 6, k = R % 6;
            while (A[i].size() <= j) A[i].push_back(0);
            A[i][j] |= 1 << k;
            ++cnt;
        }
    }
	return A;
}

std::vector<int> determine_steps(int N, int M, std::vector<std::vector<int>> A) {
	std::vector<int> has(N), ret(N, -1);
    for (int i = 0; i < M; ++i) {
        int cnt = 0;
        int x = i / 6, y = i % 6;
        for (int j = 0; j < N; ++j) {
            if (A[j].size() > x) {
                cnt += (A[j][x] >> y & 1);
            }
        }
        if (cnt != N) {
            ret[cnt] = i;
        }
    }
    return ret;
}
