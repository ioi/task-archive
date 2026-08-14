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
	
	// step #2. make tour
	vector<bool> vis(N, false);
	vector<int> tour;
	vector<int> depth(N);
	auto dfs = [&](auto& self, int x) -> void {
		vis[x] = true;
		tour.push_back(x);
		for (int i : G[x]) {
			if (!vis[i]) {
				depth[i] = depth[x] + 1;
				self(self, i);
				tour.push_back(x);
			} else if (depth[x] < depth[i]) {
				tour.push_back(i);
				tour.push_back(x);
			}
		}
	};
	dfs(dfs, 0);

	// step #3. construction
	vector<vector<int> > ans(2 * M + 1, vector<int>(2 * M + 1));
	for (int i = 0; i < 2 * M + 1; i++) {
		for (int j = 0; j < 2 * M + 1; j++) {
			ans[i][j] = tour[j];
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