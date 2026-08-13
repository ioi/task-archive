#include "partition.h"

#include <algorithm>
#include <cstdint>
#include <numeric>
#include <utility>
#include <vector>

namespace {

int64_t f(int64_t S, int g, int K) {
    return S / K + (g < S % K);
}

bool solve(std::vector<int> vec, int K, int64_t S, auto &h) {
    std::vector<int64_t> sums(K);
    int g = 0;
    for (int v : vec) {
        while (g < K && sums[g] + v > f(S, g, K)) ++g;
        if (g == K) return false;
        sums[g] += v;
    }
    h = sums;
    return true;
}

} 

std::vector<int> add_numbers(std::vector<int> A, int K, int) {
    std::sort(A.begin(), A.end());
    std::vector<int64_t> gs;
    int64_t sum = 0;
    for (int x : A) sum += x;
    int64_t l = 0, r = sum * K, ans = -1;
    while (r >= l) {
        int64_t mid = (l + r) >> 1;
        if (solve(A, K, mid, gs)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    solve(A, K, ans, gs);

    int64_t Z = (ans + K - 1) / K;
    std::vector<int64_t> w(K);
    for (int g = 0; g < K; ++g)
        w[g] = Z - gs[g];

    int64_t base = *std::min_element(w.begin(), w.end());
    std::vector<int> ret;
    for (int64_t y : w) {
        if (y - base > 0)
            ret.push_back(y - base);
    }
    return ret;
}

std::vector<int> find_partition(std::vector<int> B, int K) {
    int N = B.size();
    int64_t sum = 0;
    for (int x : B) sum += x;
    int64_t Z = sum / K;

    std::vector<std::pair<int, int>> vec;
    for (int i = 0; i < N; ++i) {
        vec.emplace_back(B[i], i);
    }
    std::sort(vec.begin(), vec.end());

    std::vector<int> ret(N, -1);
    for (int g = 0; g < K; ++g) {
        int64_t gsum = 0;
        for (int i = N - 1; i >= 0; --i) {
            auto [v, idx] = vec[i];
            if (ret[idx] == -1 && gsum + v <= Z) {
                ret[idx] = g;
                gsum += v;
            }
        }
    }
    return ret;
}
