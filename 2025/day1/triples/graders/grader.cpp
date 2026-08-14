#include "triples.h"
#include <cassert>
#include <cstdio>
// BEGIN SECRET
#include <string>
// END SECRET

namespace {
// BEGIN SECRET
const std::string input_secret  = "jB7KRtelfNrzhva6IhSoGAcDptqeBHJr";
const std::string output_secret = "qOpG8GoYprN2GHwBEAOkfIfpiiFWanMx";
const std::string extra_secret  = "nxz3K1mLpvlEac8SbN9hu4cFQ2jnBxG9";
// END SECRET

void run_part1() {
  int N;
  assert(1 == scanf("%d", &N));
  std::vector<int> H(N);
  for (int i = 0; i < N; i++)
    assert(1 == scanf("%d", &H[i]));
  fclose(stdin);

  long long T = count_triples(H);

  // BEGIN SECRET
  printf("%s\n", output_secret.c_str());
  printf("OK\n");
  // END SECRET
  printf("%lld\n", T);
  fclose(stdout);
}

void run_part2() {
  int M, K;
  assert(2 == scanf("%d %d", &M, &K));
  fclose(stdin);

  // BEGIN SECRET
  printf("%s\n", output_secret.c_str());
  // END SECRET
  std::vector<int> H = construct_range(M, K);

  // BEGIN SECRET
  printf("%s\n", extra_secret.c_str());
  // END SECRET
  int N = H.size();
  printf("%d\n", N);
  for (int i = 0; i < N; i++)
    printf("%d%c", H[i], " \n"[i + 1 == N]);
  fclose(stdout);
}

} // namespace

int main() {
  // BEGIN SECRET
  char secret[1000];
  assert(1 == scanf("%999s", secret));
  if (std::string(secret) != input_secret) {
    printf("%s\n", output_secret.c_str());
    printf("PV\n");
    printf("Possible tampering with the input\n");
    fclose(stdout);
    return 0;
  }
  // END SECRET
  int part;
  assert(1 == scanf("%d", &part));
  if (part == 1)
    run_part1();
  else if (part == 2)
    run_part2();
  // BEGIN SECRET
  else {
    printf("%s\n", output_secret.c_str());
    printf("PV\n");
    printf("Possible tampering with the input\n");
    fclose(stdout);
    return 0;
  }
  // END SECRET

  return 0;
}
