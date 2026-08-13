#include "magiccity.h"

std::pair<std::vector<int>, std::vector<std::pair<int, int>>> construct(int K) {
	std::vector<int> T = {0, 1};
	std::vector<std::pair<int, int>> E = {{0, 1}};
	return {T, E};
}
