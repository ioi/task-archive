#include "classroom.h"
std::vector<std::vector<int>> process_step(int N, int M, int R, std::vector<int> T, std::vector<std::vector<int>> A) {
    if (!T.empty()) {
        int x = T[0];
        [&](){
            for (int sz : {0, 2}) {
                for (int i = 0; i < N; ++i) {
                    if (i != x && A[i].size() <= sz) {
                        if (A[i].empty()) A[i].push_back(x);
                        A[i].push_back(R);
                        return;
                    }
                }
            }
        }();
    }
	return A;
}

std::vector<int> determine_steps(int N, int M, std::vector<std::vector<int>> A) {
	std::vector<int> ret(N, -1);
    int x = -1;
    for (int i = 0; i < N; ++i) {
        if (A[i].empty()) continue;
        ret[A[i][0]] = A[i][1];
        if (A[i].size() >= 3) x = A[i][2];
    }
    if (x != -1) {
        for (int i = 0; i < N; ++i) if (ret[i] == -1) ret[i] = x;
    }
    return ret;
}
