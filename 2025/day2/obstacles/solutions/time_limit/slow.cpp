// solution/slow.cpp
// {
//   "verdict": "time_limit",
//   "except": {
//     "samples": "correct",
//     "n1": "correct",
//     "fixed": "correct"
//   }
// }
// END HEADER
#include <cassert>
#include <unistd.h>
#include <vector>
using namespace std;

#define to(n) (views::iota(0, n))
#define tos(s, n) (views::iota(s, n))

#define DBG(x) cout << #x << " = " << (x) << endl;
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) int((x).size())

vector<int> temperature, humidity;
int n, m;

void initialize(vector<int> _T, vector<int> _H) {
  temperature = _T;
  humidity = _H;
  n = SZ(temperature);
  m = SZ(humidity);
}

int curr = 0;
int seen[int(3e6)];

int Li = -1, Ri = -1;
void dfs(int x, int y) {
  if (temperature[x] <= humidity[y] || seen[x + y * n] == curr)
    return;
  seen[x + y * n] = curr;
  if (x + 1 < n)
    dfs(x + 1, y);
  if (x - 1 >= 0)
    dfs(x - 1, y);
  if (y + 1 <= Ri)
    dfs(x, y + 1);
  if (y - 1 >= Li)
    dfs(x, y - 1);
}

int last_valid = 0;

bool can_reach(int _L, int _R, int S, int D) {
  if (n * m > int(3e6))
    sleep(10);

  if (Li != _L || Ri != _R) {
    Li = _L;
    Ri = _R;
    ++curr;
    last_valid = curr;
    dfs(0, S);
    return seen[D * n] == curr;
  } else {
    if (seen[S * n] >= last_valid)
      return seen[D * n] == seen[S * n];
    else {
      ++curr;
      dfs(0, S);
      return seen[D * n] == curr;
    }
  }
}

#ifndef EVAL
#include "../public/cpp/grader.cpp"
#endif
