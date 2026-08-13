#include "magiccity.h"
#include <array>
#include <vector>
#include <utility>
using namespace std;

std::pair<std::vector<int>, std::vector<std::pair<int, int>>> construct(int K) {
	vector<vector<int>> decomp;
	if (K == 1) {
		decomp.push_back({1});
	} else if (K == 2) {
		decomp.push_back({1, 2});
		decomp.push_back({1, 3});
		decomp.push_back({2, 3});
	} else if (K == 3) {
		decomp.push_back({2, 3, 4});
		decomp.push_back({2, 1, 5});
		decomp.push_back({3, 1, 5});
		decomp.push_back({4, 1, 5});
	} else if (K == 4) {
		decomp.push_back({1, 2, 6, 7});
		decomp.push_back({1, 3, 4, 5});
		decomp.push_back({2, 3, 4, 5});
		decomp.push_back({6, 3, 4, 5});
		decomp.push_back({7, 3, 4, 5});
	} else if (K == 5) {
		decomp.push_back({1, 9, 2, 3, 4});
		decomp.push_back({1, 5, 6, 7, 8});
		decomp.push_back({9, 5, 6, 7, 8});
		decomp.push_back({2, 3, 4, 5, 6});
		decomp.push_back({2, 3, 4, 7, 8});
	} else {
		vector<int> sep(5);
		for (int i = 0; i <= 4; i++) {
			sep[i] = 1 + (2 * K - 1) * i / 4;
		}
		const vector<array<int, 2>> tag = {
			{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}, {2, 3}
		};
		for (int i = 0; i < 6; i++) {
			decomp.push_back(vector<int>());
			for (int j = 0; j < 2; j++) {
				int t = tag[i][j];
				for (int k = sep[t]; k < sep[t + 1]; k++) {
					decomp.back().push_back(k);
				}
			}
		}
	}
	int Z = decomp.size();
	vector<int> col(2 * Z * K);
	for (int i = 0; i < 2 * Z * K; i++) {
		col[i] = i % (2 * K);
	}
	vector<vector<pair<int, bool>>> arrow(2 * Z * K);
	for (int i = 0; i < 2 * K; i++) {
		for (int j = 0; j < Z; j++) {
			int u = (2 * K) * j + i;
			for (int k : decomp[j]) {
				arrow[u].push_back({(i + k) % (2 * K), false});
			}
		}
	}
	vector<pair<int, int>> edges;
	for (int i = 0; i < 2 * Z * K; i++) {
		int g = i % (2 * K);
		for (pair<int, bool>& p : arrow[i]) {
			if (!p.second) {
				bool found = false;
				for (int j = 0; j < Z && !found; j++) {
					int v = (2 * K) * j + p.first;
					for (pair<int, bool>& q : arrow[v]) {
						if (q.first == g && !q.second) {
							edges.push_back({i, v});
							p.second = true;
							q.second = true;
							found = true;
							break;
						}
					}
				}
			}
		}
	}
	return {col, edges};
}
