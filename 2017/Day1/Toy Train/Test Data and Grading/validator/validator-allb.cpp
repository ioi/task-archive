#include "testlib.h"
using namespace std;

int main()
{
	registerValidation();
	string secret = inf.readLine();
	ensuref(secret == "3d2051c242fe2ae63792f9868123a5eb", "Secret not found!");
	int n = inf.readInt();
	inf.readSpace();
	inf.readInt();
	inf.readEoln();
	for(int i = 0; i < n; i++) {
		if (i > 0) inf.readSpace();
		inf.readInt(0, 0, "d_" + to_string(i));
	}
	skip_ok();
}
