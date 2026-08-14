// solution/subtask3.cpp
// {
//   "verdict": "incorrect",
//   "except": {
//     "fixed": "correct"
//   }
// }
// END HEADER
#include <algorithm>
#include <cassert>
#include <ranges>
#include <vector>
using namespace std;

#define to(n) (views::iota(0, n))
#define tos(s, n) (views::iota(s, n))
#define from(n) (views::iota(0, n) | views::reverse)

#define DBG(x) cout << #x << " = " << (x) << endl;
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) int((x).size())

vector<int> prefix_sum1, prefix_sum2, prefix_sum3;
void initialize(std::vector<int> T, std::vector<int> H) {
  prefix_sum1.assign(SZ(H) + 1, 0);
  prefix_sum2.assign(SZ(H) + 1, 0);
  prefix_sum3.assign(SZ(H) + 1, 0);

  for (int i : to(SZ(H))) {
    prefix_sum1[i + 1] = prefix_sum1[i] + (T[0] <= H[i]);
    prefix_sum2[i + 1] = prefix_sum2[i] + (T[1] > H[i]);
    prefix_sum3[i + 1] = prefix_sum3[i] + (T[2] <= H[i]);
  }

  return;
}

bool can_reach(int, int, int S, int D) {
  if (prefix_sum1[S] == prefix_sum1[D])
    return true;
  auto s_eq = equal_range(ALL(prefix_sum1), prefix_sum1[S]);
  auto d_eq = equal_range(ALL(prefix_sum1), prefix_sum1[D]);
  if (prefix_sum2[s_eq.first - prefix_sum1.begin()] == prefix_sum2[s_eq.second - prefix_sum1.begin() - 1])
    return false;
  if (prefix_sum2[d_eq.first - prefix_sum1.begin()] == prefix_sum2[d_eq.second - prefix_sum1.begin() - 1])
    return false;
  return prefix_sum3[S] == prefix_sum3[D];
}

#ifndef EVAL
#include "../grader/cpp/grader.cpp"
#endif
