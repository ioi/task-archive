#include "testlib.h"
using namespace std;
const int max_n = 15;

int main()
{
	registerValidation();
	string secret = inf.readLine();
	ensuref(secret == "3d2051c242fe2ae63792f9868123a5eb", "Secret not found!");
	inf.readInt(1, max_n, "n");
	skip_ok();
}
