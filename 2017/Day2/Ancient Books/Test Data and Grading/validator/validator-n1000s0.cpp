#include "testlib.h"
#include <algorithm>
using namespace std;
const int MAX = 1000;
int main(int argc, char *argv[])
{
	registerValidation();
	inf.readLine();
	int n = inf.readInt(1, MAX, "n");
	inf.readSpace();
	int s = inf.readInt(0, 0, "s");
	skip_ok();
}
