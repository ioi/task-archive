#include "train.h"

std::vector<int> who_wins(std::vector<int> a, std::vector<int> r, std::vector<int> u, std::vector<int> v) {
	std::vector<int> res(a.size());
	for(int i = 0; i < (int)res.size(); i++)
		res[i] = i % 2;
	return res;
}
