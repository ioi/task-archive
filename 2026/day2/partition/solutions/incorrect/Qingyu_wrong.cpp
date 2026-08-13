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
    for (int i = 0; i < K - 1; ++i) {
        auto v = ret.back() - ret[i];
        if (v != 0) {
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
    auto add = [&](int val, int idx) {
        auto [x, id] = que.top(); que.pop();
        x += val;
        ret[idx] = id;
        que.emplace(x, id);
    };
    int offset = std::min(2 * K, (int)B.size());
    for (int i = N - 1; i >= offset; --i) {
        add(vec[i].first, vec[i].second);
    }
    auto ret2 = ret;
    for (uint32_t mask = 0; mask < (1 << offset); ++mask) {
        {
            auto que2 = que;

            for (int i = offset - 1; i >= 0; --i) {
                if (mask >> i & 1) {        
                    add(vec[i].first, vec[i].second);
                }
            }

            for (int i = offset - 1; i >= 0; --i) {
                if (~mask >> i & 1) {        
                    add(vec[i].first, vec[i].second);
                }
            }

            bool ok = true;
            int64_t x = que.top().first; que.pop();
            for (int i = 0; i < K - 1; ++i) {
                if (que.top().first != x) {
                    ok = false;
                }
                que.pop();
            }
            if (ok) {
                return ret;
            }

            que = que2;
        }
    }
    throw;
    return ret;
}
