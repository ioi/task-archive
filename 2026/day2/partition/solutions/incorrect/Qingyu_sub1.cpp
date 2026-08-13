#include "partition.h"
#include <algorithm>
std::vector<int> add_numbers(std::vector<int> A, int K, int M) {
    std::sort(A.begin(), A.end());
    if (A[2] > A[0] + A[1]) {
        return {A[2] - A[0] - A[1]};
    } else if (A[2] == A[0] + A[1]) {
        return {};
    } else {
        return {A[0] + A[1] - A[2]};
    }
}
std::vector<int> find_partition(std::vector<int> B, int K) {
    int N = B.size();
    for (int S = 0; S < (1 << N); ++S) {
        int s0 = 0, s1 = 0;
        std::vector<int> ret;
        for (int i = 0; i < N; ++i) {
            int b = S >> i & 1;
            ret.push_back(b);
            if (b) {
                s0 += B[i];
            } else {
                s1 += B[i];
            }
        }
        if (s0 == s1) {
            return ret;
        }
    }
    return std::vector<int>(N, 0);
}
