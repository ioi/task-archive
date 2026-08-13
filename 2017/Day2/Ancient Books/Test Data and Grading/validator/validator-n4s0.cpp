#include "testlib.h"
#include <algorithm>
using namespace std;
const int MAX = 4;
int main(int argc, char *argv[])
{
	registerValidation();
	inf.readLine();
	inf.readInt(1, MAX, "n");
	inf.readSpace();
	inf.readInt(0, 0, "s");
	skip_ok();
}
