#include "worldmap.h"
#include <vector>
#include <iostream>
#define MAXK 240
using namespace std;

std::vector<std::vector<int> > create_map(int N, int M, std::vector<int> A, std::vector<int> B) {
	// step #1. preparation
	vector<vector<int> > G(N);
	for (int i = 0; i < M; i++) {
		A[i]--;
		B[i]--;
		G[A[i]].push_back(B[i]);
		G[B[i]].push_back(A[i]);
	}
	
	// step #2. make spanning tree
	vector<bool> vis(N, false);
	vector<int> depth(N);
	vector<int> tour, RA, RB;
	auto dfs = [&](auto& self, int x) -> void {
		vis[x] = true;
		tour.push_back(x);
		for (int i : G[x]) {
			if (!vis[i]) {
				depth[i] = depth[x] + 1;
				self(self, i);
				tour.push_back(x);
			} else if (depth[x] < depth[i]) {
				RA.push_back(x);
				RB.push_back(i);
			}
		}
	};
	dfs(dfs, 0);

	// step #3. construction
	vector<int> rank(N, -1), holder(N, -1);
	for (int i = 0; i < 2 * N - 1; i++) {
		int d = min(i, (2 * N - 2) - i);
		if (rank[tour[i]] < d) {
			rank[tour[i]] = d;
			holder[tour[i]] = i;
		}
	}
	vector<vector<int> > H(N);
	for (int i = 0; i < M - (N - 1); i++) {
		if (rank[RA[i]] < rank[RB[i]]) {
			swap(RA[i], RB[i]);
		}
		H[RA[i]].push_back(RB[i]);
	}
	vector<vector<int> > ans(MAXK+1, vector<int>(MAXK+1, 0));
	int cur = 0, parity = 0;
	for (int i = 0; i < 2 * N - 1; i++) {
		if (i == holder[tour[i]]) {
			int pos = 0;
			for (int j = 0; j < 2 * N; j++) {
				int ya = cur - j;
				if (0 <= ya && ya < 2 * N) {
					ans[j][ya] = tour[i];
				}
				int yb = (cur + 1) - j;
				if (0 <= yb && yb < 2 * N) {
					if (pos < int(H[tour[i]].size())) {
						ans[j][yb] = H[tour[i]][pos];
						pos++;
					} else {
						ans[j][yb] = tour[i];
					}
				}
				int yc = (cur + 2) - j;
				if (0 <= yc && yc < 2 * N) {
					ans[j][yc] = tour[i];
				}
			}
			cur += 3;
			parity ^= 1;
		} else {
			for (int j = 0; j < 2 * N; j++) {
				int ya = cur - j;
				if (0 <= ya && ya < 2 * N) {
					ans[j][ya] = tour[i];
				}
			}
			cur += 1;
		}
	}

  for (int i = 0; i < int(ans.size()); i++) {
		for (int j = 0; j < int(ans.size()); j++) {
			if(i < 2*N && j < 2*N) continue;
      if(i < 2*N) ans[i][j] = ans[i][j-1];
      else ans[i][j] = ans[i-1][j];
		}
	}

	// step #4. final step
	for (int i = 0; i < int(ans.size()); i++) {
		for (int j = 0; j < int(ans.size()); j++) {
			ans[i][j]++;
		}
	}

	return ans;
}