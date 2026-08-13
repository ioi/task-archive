#include "testlib.h"
#include <algorithm>
using namespace std;
const int MAX = 1000;
int main(int argc, char *argv[])
{
	registerValidation();
	inf.readLine();
	inf.readInt(1, MAX, "n");
	skip_ok();
}
