#include "monuments.h"
#include <cassert>
#include <cstdio>
// BEGIN SECRET
#include <string>
// END SECRET

int main() {
  // BEGIN SECRET
  const std::string input_secret = "ipSPTVdhWvy5NIwVfCigZSNs8joxDWov";
  const std::string output_secret = "GghMFJZhszVz1YuKo7FD2kzkyCvVPcl5";
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
  int N, M;
  assert(2 == scanf("%d %d", &N, &M));

  std::vector<int> X(N);
  for (int i = 0; i < N; i++) {
    assert(1 == scanf("%d", &X[i]));
  }

  std::vector<int> P(M);
  for (int i = 0; i < M; i++) {
    assert(1 == scanf("%d", &P[i]));
  }
  fclose(stdin);

  long long res = get_cost(X, P);

  // BEGIN SECRET
  printf("%s\n", output_secret.c_str());
  printf("OK\n");
  // END SECRET
  printf("%lld\n", res);
  fclose(stdout);
  return 0;
}
