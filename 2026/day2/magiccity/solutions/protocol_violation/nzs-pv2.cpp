#include "magiccity.h"
#include <iostream>

std::pair<std::vector<int>, std::vector<std::pair<int, int>>> construct(int K) {
	std::cout << "2 1\n0 1\n0 1\n";
	std::vector<int> T = {0, 1};
	std::vector<std::pair<int, int>> E = {{0, 1}};
	return {T, E};
}
