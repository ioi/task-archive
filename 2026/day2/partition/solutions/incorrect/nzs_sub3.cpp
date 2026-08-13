#include "partition.h"
#include <algorithm>
#include <numeric>

std::vector<int> add_numbers(std::vector<int> A, int K, int M) {
    int s = std::accumulate(A.begin(), A.end(), 0);
    std::vector<int> C;
    if (s % 2)
        C.push_back(1), s += 1;
    while (s % K != 0 || s / K % 2 != 0)
        C.push_back(2), s += 2;
    if (M == 1 || C.size() >= K) {
        C.clear();
        s = std::accumulate(A.begin(), A.end(), 0);
        while (s % K != 0)
            C.push_back(1), s += 1;
    }
    return C;
}
std::vector<int> find_partition(std::vector<int> B, int K) {
    std::vector<int> ans(B.size());
    int sg = std::accumulate(B.begin(), B.end(), 0) / K;
    int j = 0, i = B.size() - 1, g = 0, cs = 0;
    while (g < K) {
        while (i >= 0 && cs + B[i] <= sg) {
            cs += B[i];
            ans[i] = g;
            --i;
        }
        if (cs < sg) {
            cs += B[j];
            ans[j] = g;
            ++j;
        }
        ++g, cs = 0;
    }
    return ans;
}
