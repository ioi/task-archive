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

	// step #2. build tree
	vector<int> subsize(N, 1);
	vector<vector<int> > children(N);
	auto dfs1 = [&](auto& self, int x, int pre) -> void {
		for (int i : G[x]) {
			if (i != pre) {
				children[x].push_back(i);
				self(self, i, x);
				subsize[x] += subsize[i];
			}
		}
	};
	dfs1(dfs1, 0, -1);

	// step #3. construction
	vector<vector<int> > ans(2 * N - 1, vector<int>(2 * N - 1));
	auto dfs2 = [&](auto& self, int x, int l, int r, int d) -> void {
		std::cerr << "! " << x << ' ' << l << ' ' << r << ' ' << d << std::endl;
		for (int i = d; i < 2 * N - 1; i++) {
			ans[i][l] = x + 1;
		}
		for (int i = l; i < r; i++) {
			ans[d][i] = x + 1;
		}
		int pos = l + 1;
		for (int i : children[x]) {
			self(self, i, pos, pos + 2 * subsize[i] - 1, d + 1);
			pos += 2 * subsize[i] - 1;
			for (int j = d; j < 2 * N - 1; j++) {
				ans[j][pos] = x + 1;
			}
			pos += 1;
		}
	};
	dfs2(dfs2, 0, 0, 2 * N - 1, 0);

	return ans;
}
