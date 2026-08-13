#include "train.h"

#include <cstdio>
#include <vector>
#include <cassert>

using namespace std;

int main() {
	int n, m;
	assert(2 == scanf("%d %d", &n, &m));

	vector<int> a(n), r(n), u(m), v(m);

	for(int i = 0; i < n; i++)
		assert(1 == scanf("%d", &a[i]));

	for(int i = 0; i < n; i++)
		assert(1 == scanf("%d", &r[i]));

	for(int i = 0; i < m; i++)
		assert(2 == scanf("%d %d", &u[i], &v[i]));

	vector<int> res = who_wins(a, r, u, v);

	for(int i = 0; i < (int)res.size(); i++)
		printf(i ? " %d" : "%d", res[i]);
	printf("\n");

	return 0;
}
