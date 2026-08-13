#include "testlib.h"

using namespace std;

const string output_secret = "d16905a4427c193ad87ae7fa91a2bb55";

int main(int argc, char * argv[]){
    registerChecker("train", argc, argv);

    readBothSecrets(output_secret);
    readBothGraderResults();

    compareRemainingLines(3);
}
