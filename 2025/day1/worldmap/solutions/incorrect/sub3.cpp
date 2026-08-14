#include "worldmap.h"
#include <vector>
#include <iostream>
using namespace std;

std::vector<std::vector<int> > create_map(int N, int M, std::vector<int> A, std::vector<int> B) {
	vector<vector<int> > ans(N, std::vector<int>(N, 1));
	int x = 0, y = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			ans[x][y] = i + 1;
			ans[x][y + 1] = j + 1;
			y += 2;
			if (y >= N - 1) {
				x += 1;
				y = 0;
			}
		}
	}
	return ans;
}