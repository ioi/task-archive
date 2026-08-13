#include "partition.h"
#include <algorithm>
#include <set>
#include <queue>
#include <cassert> 
template<class Fun>
class y_combinator_result {
    Fun fun_;
public:
    template<class T>
    explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

    template<class ...Args>
    decltype(auto) operator()(Args &&...args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};

template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

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
        if (ret.back() != ret[i]) ex.push_back(ret.back() - ret[i]);
    }
    return ex;
}
std::vector<int> find_partition(std::vector<int> B, int K) {
    int N = B.size();
    std::vector<int64_t> cur;
    std::vector<int> ret(N);
    int64_t su = 0;
    for (int x : B) su += x;
    int64_t Z = su / K;
    std::vector<std::pair<int, int>> vec;
    for (int i = 0; i < N; ++i) {
        vec.emplace_back(B[i], i);
    }
    sort(vec.begin(), vec.end());
    auto solve = y_combinator([&](auto self, int i) -> bool {
        if (N - i + cur.size() < K) {
            return false;
        }
        if (i == N) {
            for (int j = 1; j < K; ++j) {
                if (cur[j] != cur[0]) {
                    return false;
                }
            }
            return true;
        } else {
            auto [v, p] = vec[i];
            for (int j = 0; j < cur.size(); ++j) {
                ret[p] = j;
                if (cur[j] + v > Z) continue;
                cur[j] += v;
                if (cur[j] == Z || cur[j] + v <= Z) {
                    if (self(i + 1)) {
                        return true;
                    }
                }
                cur[j] -= v;
            }
            if (cur.size() < K) {
                ret[p] = cur.size();
                cur.push_back(v);
                if (self(i + 1)) return true;
                cur.pop_back();
            }
            return false;
        }
    });
    assert(solve(0));
    return ret;
}
