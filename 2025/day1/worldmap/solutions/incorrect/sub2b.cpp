#include "worldmap.h"
#include <vector>
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

	// step #2. make euler tour
	vector<int> tour;
	auto dfs = [&](auto& self, int x, int pre) -> void {
		tour.push_back(x);
		for (int i : G[x]) {
			if (i != pre) {
				self(self, i, x);
				tour.push_back(x);
			}
		}
	};
	dfs(dfs, 0, -1);

	// step #3. construction
	vector<vector<int> > ans(2 * N - 1, vector<int>(2 * N - 1));
	for (int i = 0; i < 2 * N - 1; i++) {
		for (int j = 0; j < 2 * N - 1; j++) {
			ans[i][j] = tour[j] + 1;
		}
	}
	
	return ans;
}