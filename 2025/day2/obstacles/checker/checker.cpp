#include "testlib.h"

#include <string>
const std::string output_secret = "i2xwv9fVon02ATMPW3vu6PaetvUcf5iB";
const std::string input_secret = "5jV4Ew5ZLRRQF8JKt2ZiroW7gNGsr8Jk";

int main(int argc, char *argv[]) {
  registerChecker("obstacles", argc, argv);
  readBothSecrets(output_secret);
  readBothGraderResults();

  compareRemainingLines(1);
}
