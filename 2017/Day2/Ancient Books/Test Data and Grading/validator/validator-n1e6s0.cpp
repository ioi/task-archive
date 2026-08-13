#include "testlib.h"
#include <algorithm>
using namespace std;
int main(int argc, char *argv[])
{
	registerValidation();
	inf.readLine();
	inf.readInt();
	inf.readSpace();
	inf.readInt(0, 0, "s");
	skip_ok();
}
