#include "worldmap.h"
#include <vector>
using namespace std;

std::vector<std::vector<int> > create_map(int N, int M, std::vector<int> A, std::vector<int> B) {
	std::vector<std::vector<int> > ans(N, std::vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ans[i][j] = j + 1;
		}
	}
	return ans;
}