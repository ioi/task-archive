#include "books.h"

#include <cstdio>
#include <vector>
#include <cassert>

using namespace std;

int main() {
	int n, s;
	assert(2 == scanf("%d %d", &n, &s));

	vector<int> p((unsigned) n);
	for(int i = 0; i < n; i++)
		assert(1 == scanf("%d", &p[(unsigned) i]));

	long long res = minimum_walk(p, s);
	printf("%lld\n", res);

	return 0;
}
