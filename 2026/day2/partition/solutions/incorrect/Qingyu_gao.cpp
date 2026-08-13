#include "partition.h"
#include <algorithm>
#include <cmath>
#include <queue>
#include <cassert>
std::vector<int> add_numbers(std::vector<int> A, int K, int M) {
    std::sort(A.begin(), A.end());
    int N = A.size();
    std::priority_queue<int64_t, std::vector<int64_t>, std::greater<int64_t>> que;
    for (int i = 0; i < K; ++i) que.emplace(0);
    for (int i = N - 1; i >= 0; --i) {
        int64_t x = que.top(); que.pop();
        x += A[i];
        que.emplace(x);
    }
    std::vector<int64_t> ret; 
    std::vector<int> ex;
    for (int i = 0; i < K; ++i) {
        ret.push_back(que.top()); que.pop();
    }
    auto min = *std::min_element(A.begin(), A.end());
    for (int i = 0; i < K - 1; ++i) {
        auto v = ret.back() - ret[i];
        if (v != 0) {
            assert(v <= min);
            ex.push_back(ret.back() - ret[i]);
        }
    }
    return ex;
}
std::vector<int> find_partition(std::vector<int> B, int K) {
    int N = B.size();
    std::vector<std::pair<int, int>> vec;
    for (int i = 0; i < N; ++i) {
        vec.emplace_back(B[i], i);
    }
    std::sort(vec.begin(), vec.end());
    std::vector<int> ret(N);

    typedef std::pair<int64_t, int> d_t;
    std::priority_queue<d_t, std::vector<d_t>, std::greater<d_t>> que;
    for (int i = 0; i < K; ++i) que.emplace(0, i);
    for (int i = N - 1; i >= 0; --i) {
        auto [x, id] = que.top(); que.pop();
        x += vec[i].first;
        ret[vec[i].second] = id;
        que.emplace(x, id);
    }
    return ret;
}
