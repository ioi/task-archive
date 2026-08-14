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
	vector<vector<int> > ans(4 * N - 1, vector<int>(4 * N - 1));
	vector<bool> used(N, false);
	int cur = 0;
	for (int i = 0; i < 2 * N - 1; i++) {
		if (!used[tour[i]]) {
			for (int j = 0; j < 4 * N - 1; j++) {
				ans[j][cur + 0] = tour[i];
				ans[j][cur + 1] = tour[i];
				ans[j][cur + 2] = tour[i];
			}
			for (int j = 0; j < int(H[tour[i]].size()); j++) {
				ans[j * 2 + 1][cur + 1] = H[tour[i]][j];
			}
			used[tour[i]] = true;
			cur += 3;
		} else {
			for (int j = 0; j < 4 * N - 1; j++) {
				ans[j][cur] = tour[i];
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