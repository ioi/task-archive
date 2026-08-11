#include "testlib.h"

#include <string>

const std::string output_secret = "GghMFJZhszVz1YuKo7FD2kzkyCvVPcl5";

int main(int argc, char* argv[]) {
    registerChecker("monuments", argc, argv);
    readBothSecrets(output_secret);
    readBothGraderResults();
    
    compareRemainingLines(1);
}
