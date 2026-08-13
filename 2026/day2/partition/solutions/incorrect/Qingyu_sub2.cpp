#include "partition.h"
#include <algorithm>
std::vector<int> add_numbers(std::vector<int> A, int K, int M) {
    int x = (K - A.size() % K) % K;
    return std::vector<int>(x, 1);
}
std::vector<int> find_partition(std::vector<int> B, int K) {
    std::vector<int> ret(B.size());
    for (int i = 0; i < B.size(); ++i) {
        ret[i] = i % K;
    }
    return ret;
}
