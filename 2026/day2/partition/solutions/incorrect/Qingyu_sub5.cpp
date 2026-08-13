#include "partition.h"
#include <algorithm>
#include <cmath>
std::vector<int> add_numbers(std::vector<int> A, int K, int M) {
    std::sort(A.begin(), A.end(), std::greater<>());
    int64_t s0 = 0, s1 = 0;
    for (int x : A) {
        if (s0 < s1) s0 += x;
        else s1 += x;
    }
    if (s0 == s1) return {};
    return { (int)std::abs(s0 - s1) };
}
std::vector<int> find_partition(std::vector<int> B, int K) {
    std::vector<std::pair<int, int>> vec;
    int N = B.size();
    for (int i = 0; i < N; ++i) {
        vec.emplace_back(B[i], i);
    }
    std::sort(vec.begin(), vec.end(), std::greater<>());
    int64_t s0 = 0, s1 = 0;
    std::vector<int> ret(N);
    for (auto [v, p] : vec) {
        if (s0 < s1) {
            s0 += v;
            ret[p] = 0;
        } else {
            s1 += v;
            ret[p] = 1;
        }
    }
    return ret;
}
