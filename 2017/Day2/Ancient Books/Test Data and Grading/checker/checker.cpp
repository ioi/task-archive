#include "testlib.h"
using namespace std;

static string output_secret = "9048298f-efa0-4f8a-9322-0c8855609a66";

int main(int argc, char * argv[])
{
	registerChecker("books", argc, argv);

	readBothSecrets(output_secret);
	readBothGraderResults();

	compareRemainingLines(3);
}
