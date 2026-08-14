#include "worldmap.h"
#include <vector>
#include <iostream>
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
	vector<vector<int> > H(N);
	for (int i = 0; i < M - (N - 1); i++) {
		H[RA[i]].push_back(RB[i]);
	}
	vector<vector<int> > ans(3 * N, vector<int>(3 * N, 0));
	vector<bool> used(N, false);
	int cur = 1, parity = 0;
	for (int i = 0; i < 2 * N - 1; i++) {
		if (!used[tour[i]]) {
			for (int j = 0; j < 3 * N; j++) {
				ans[j][cur] = (j % 2 != parity || j / 2 >= int(H[tour[i]].size()) ? tour[i] : H[tour[i]][j / 2]);
				if (cur != 0 && j % 2 == parity) {
					ans[j][cur - 1] = tour[i];
				}
				if (cur != 3 * N - 1 && j % 2 == parity) {
					ans[j][cur + 1] = tour[i];
				}
			}
			used[tour[i]] = true;
			cur += 2;
			parity ^= 1;
		} else {
			for (int j = 0; j < 3 * N; j++) {
				ans[j][cur - 1 + (j + parity) % 2] = tour[i];
			}
			cur += 1;
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