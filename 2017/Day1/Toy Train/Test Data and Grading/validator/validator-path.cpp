#include "testlib.h"
using namespace std;

int main()
{
	registerValidation();
	string secret = inf.readLine();
	ensuref(secret == "3d2051c242fe2ae63792f9868123a5eb", "Secret not found!");
	int n = inf.readInt();
	inf.readSpace();
	int m = inf.readInt();
	inf.readEoln();

	for(int i = 0; i < n; i++) {
		if (i > 0) inf.readSpace();
		inf.readInt();
	}
	inf.readEoln();

	for(int i = 0; i < n; i++) {
		if (i > 0) inf.readSpace();
		inf.readInt();
	}
	inf.readEoln();

	for (int i = 0; i < m; i++) {
		int u = inf.readInt();
		inf.readSpace();
		int v = inf.readInt();
		ensuref(v == u || v == u+1, "The edges must be either (i, i) or (i, i+1)");
		inf.readEoln();
	}
    inf.readEof();
	return 0;
}
