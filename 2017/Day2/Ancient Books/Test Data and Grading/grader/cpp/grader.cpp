#include "books.h"

#include <cstdio>
#include <vector>
#include <cassert>
// BEGIN SECRET
#include <string>
// END SECRET

using namespace std;

int main() {
	// BEGIN SECRET
	static const string input_secret = "f58fb993-f209-43d7-9391-c46c61f180b9";
	static const string output_secret = "9048298f-efa0-4f8a-9322-0c8855609a66";

	char secret[1000];
	assert(1 == scanf("%s", secret));
	if (string(secret) != input_secret) {
		printf("%s\n", output_secret.c_str());
		printf("SV\n");
		return 0;
	}
	// END SECRET
	int n, s;
	assert(2 == scanf("%d %d", &n, &s));

	vector<int> p((unsigned) n);
	for(int i = 0; i < n; i++)
		assert(1 == scanf("%d", &p[(unsigned) i]));

	long long res = minimum_walk(p, s);
	// BEGIN SECRET
	printf("%s\n", output_secret.c_str());
	printf("OK\n");
	// END SECRET
	printf("%lld\n", res);

	return 0;
}
