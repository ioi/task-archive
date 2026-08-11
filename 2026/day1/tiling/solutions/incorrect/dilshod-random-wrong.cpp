#include "tiling.h"
#include <bits/stdc++.h>

using namespace std;

mt19937 rng(42);

int N, M;
vector<vector<int>> grid;
vector<pair<int, int>> ord;

void init(int _N, int _M) {
  N = _N, M = _M;
  grid.assign(2 * N, vector<int>(2 * M, -1));

  for (int i = 0; i < 2 * N; i += 2){
    for (int j = 0; j < 2 * M; j += 2){
        ord.emplace_back(i, j);
    }
  }

  shuffle(ord.begin(), ord.end(), rng);
}

bool check(int x, int y){
  for (int i = max(0, x - 1); i + 1 <= min(2 * N - 1, x + 2); i++){
    for (int j = max(0, y - 1); j + 1 <= min(2 * M - 1, y + 2); j++){
      bool ok = false;
      if (grid[i][j] != 1) ok = true;
      if (grid[i][j + 1] != 1) ok = true;
      if (grid[i + 1][j] != 1) ok = true;
      if (grid[i + 1][j + 1] != 1) ok = true;
      if (!ok) return false;
    }
  }
  return true;
}

std::pair<int, int> receive_block(int TL, int TR, int BL, int BR) {
  if (TL && TR && BL && BR) return {-1, -1};
  for (int i = 0; i < (int)ord.size(); i++){
    auto [x, y] = ord[i];
    grid[x][y] = TL;
    grid[x][y + 1] = TR;
    grid[x + 1][y] = BL;
    grid[x + 1][y + 1] = BR;
    if (check(x, y)){
        ord.erase(ord.begin() + i);
        return {x, y};
    }
    grid[x][y] = grid[x][y + 1] = grid[x + 1][y] = grid[x + 1][y + 1] = -1;
  }
  return {-1, -1};
}
