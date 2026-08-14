// solution/subtask2.cpp
// {
//   "verdict": "incorrect",
//   "except": {
//     "n1": "correct",
//     "inc": "correct"
//   }
// }
// END HEADER
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

vector<int> prefix_sum;
void initialize(std::vector<int> T, std::vector<int> H) {
  prefix_sum.assign(SZ(H) + 1, 0);

  for (int i : to(SZ(H)))
    prefix_sum[i + 1] = prefix_sum[i] + (T.back() <= H[i]);

  return;
}

bool can_reach(int, int, int S, int D) {
  return prefix_sum[S] == prefix_sum[D];
}

#ifndef EVAL
#include "../grader/cpp/grader.cpp"
#endif
