#include "partition.h"

#include <algorithm>
#include <cstdint>
#include <numeric>
#include <vector>

typedef __int128 int128_t;

namespace {

bool solve(const std::vector<int128_t> &vec, int K, int128_t Z) {
    int128_t sum = 0;
    int g = 1;
    for (int128_t v : vec) {
        if (sum + v > Z) {
            sum = 0;
            if (++g > K) return false;
        }
        sum += v;
    }
    return true;
}

struct dsu_t {
    std::vector<int> f;
    dsu_t(int n) {
        f = std::vector<int>(n + 1);
        std::iota(f.begin(), f.end(), 0);
    }
    int find(int x) {
        while (x != f[x]) x = f[x] = f[f[x]];
        return x;
    }
};

}

std::vector<int> add_numbers(std::vector<int> A, int K, int /*M*/) {
    std::sort(A.begin(), A.end());
    int N = A.size();
    int128_t Q = 1ll * N * (N + 1) / 2 + N + 1;
    std::vector<int128_t> vec(N);
    int128_t l = 0, r = 0, ans = -1;
    for (int i = 0; i < N; ++i) {
        vec[i] = A[i] * Q + i + 1;
        l = std::max(l, vec[i]);
        r += vec[i];
    }

    while (r >= l) {
        int128_t mid = (l + r) >> 1;
        if (solve(vec, K, mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    int128_t Z = ans / Q, sum = 0, wsum = 0;
    int g = 1;
    std::vector<int> ret;
    for (int i = 0; i < N; ++i) {
        if (wsum + vec[i] > ans) {
            if (sum < Z) ret.push_back(Z - sum);
            ++g;
            sum = wsum = 0;
        }
        sum += A[i], wsum += vec[i];
    }
    if (sum < Z) ret.push_back(Z - sum);
    while (g++ < K) ret.push_back(Z);
    return ret;
}

std::vector<int> find_partition(std::vector<int> B, int K) {
    int N = B.size();
    int64_t sum = 0;
    for (int x : B) sum += x;
    int64_t Z = sum / K;

    std::vector<int> ret(N);
    dsu_t f(N);
    for (int g = 0; g < K; ++g) {
        int64_t rem = Z;
        while (rem > 0) {
            int id = std::upper_bound(B.begin(), B.end(), rem) - B.begin(), x = f.find(id);
            rem -= B[x - 1];
            ret[x - 1] = g;
            f.f[x] = f.find(x - 1);
        }
    }
    return ret;
}
