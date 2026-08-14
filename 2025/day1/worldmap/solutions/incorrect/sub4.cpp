#include "worldmap.h"
#include <vector>
#include <iostream>
using namespace std;

std::vector<std::vector<int> > create_map(int N, int M, std::vector<int> A, std::vector<int> B) {
	std::vector<std::vector<int> > ans(2 * N, std::vector<int>(2 * N, 1));
	for (int i = 1; i < N; i++) {
		ans[0][(i - 1) * 2] = i + 1;
	}
	int x = 2, y = 0;
	for (int i = 0; i < M; i++) {
		if (A[i] != 1 && B[i] != 1) {
			ans[x][y] = A[i];
			ans[x][y + 1] = B[i];
			y += 4;
			if (y >= 2 * N - 1) {
				x += 2;
				y = 0;
			}
		}
	}
	return ans;
}