#include "train.h"

#include <cstdio>
#include <vector>
#include <cassert>
// BEGIN SECRET
#include <string>
// END SECRET

using namespace std;

// BEGIN SECRET
const string input_secret = "3d2051c242fe2ae63792f9868123a5eb";
const string output_secret = "d16905a4427c193ad87ae7fa91a2bb55";
// END SECRET
int main() {
	// BEGIN SECRET
	char secret[1000];
	assert(1 == scanf("%s", secret));
	if (string(secret) != input_secret) {
		printf("%s\n", output_secret.c_str());
		printf("SV\n");
		return 0;
	}
	// END SECRET
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

	// BEGIN SECRET
	printf("%s\n", output_secret.c_str());

	if((int)res.size() != n) {
		printf("WA\n");
		printf("Wrong returned array size\n");
	} else
		printf("OK\n");
	// END SECRET
	for(int i = 0; i < (int)res.size(); i++)
		printf(i ? " %d" : "%d", res[i]);
	printf("\n");

	return 0;
}
