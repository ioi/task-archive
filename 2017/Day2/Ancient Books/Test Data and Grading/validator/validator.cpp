#include "testlib.h"
#include <algorithm>
using namespace std;
const string input_secret = "f58fb993-f209-43d7-9391-c46c61f180b9";
const int MAX = 1000000;
int p[MAX];
int main(int argc, char *argv[])
{
	registerValidation();
	string secret = inf.readLine();
	ensuref(secret == input_secret, "Secret not found!");
	int n = inf.readInt(1, MAX, "n");
	inf.readSpace();
	int s = inf.readInt(0, n - 1, "s");
	inf.readEoln();
	for (int i = 0; i < n; i++)
	{
		p[i] = inf.readInt(0, n - 1, "p_i");
		if (i + 1 < n)
			inf.readSpace();
		else
			inf.readEoln();
	}
	sort(p, p + n);
	ensuref(unique(p, p + n) - p == n, "Given array is not a premutation!");
	inf.readEof();
	return 0;
}
