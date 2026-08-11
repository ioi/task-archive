#include "tiling.h"
#include <vector>
namespace {
    int N, M;
    std::vector<std::vector<int>> pool;
}

void init(int N, int M) {
    ::N = N;
    ::M = M;
    pool = std::vector(N, std::vector<int>(M));
}

std::pair<int, int> receive_block(int C0, int C1, int C2, int C3) {
    if (C0 && C1 && C2 && C3) return {-1, -1};
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            int _i = i, _j = j;
            if (C3) { _i = N - i - 1, _j = M - j - 1; }
            if (!pool[_i][_j]) {
                pool[_i][_j] = 1;
                return {2 * _i, 2 * _j};
            }
        }
    }
    throw;
}