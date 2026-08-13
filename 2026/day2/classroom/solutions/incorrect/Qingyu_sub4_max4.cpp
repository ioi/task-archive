#include "classroom.h"
std::vector<std::vector<int>> process_step(int N, int M, int R, std::vector<int> T, std::vector<std::vector<int>> A) {
    if (!T.empty()) {
        int x = T[0];
        [&](){
            for (int sz : {0, 2}) {
                for (int i = 0; i < N; ++i) {
                    if (i != x && A[i].size() <= sz) {
                        A[i].push_back(x);
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
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j + 1 < A[i].size(); j += 2) {
            ret[A[i][j]] = A[i][j + 1];
        }
    }
    return ret;
}
