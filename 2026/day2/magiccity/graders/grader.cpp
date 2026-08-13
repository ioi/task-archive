#include "magiccity.h"
#include <cassert>
#include <cstdio>
#include <utility>
#include <vector>
// BEGIN SECRET
#include <string>
// END SECRET

int main() {
  // BEGIN SECRET
  const std::string input_secret = "dDIZTjOnVjhIDrUsCub93axaXK54larl";
  const std::string output_secret1 = "AWmSCSuAvEsx26UlX7YQwxi7mlumajPI";
  const std::string output_secret2 = "vSsge5g7k6Z1q3r8X9y0p4b2nLhJtRPe";
  char secret[1000];
  assert(1 == scanf("%999s", secret));
  if (std::string(secret) != input_secret) {
    printf("%s\n%s\n", output_secret1.c_str(), output_secret2.c_str());
    printf("PV\n");
    printf("Possible tampering with the input\n");
    fclose(stdout);
    return 0;
  }
  // END SECRET
  int K;
  assert(1 == scanf("%d", &K));
  fclose(stdin);

  // BEGIN SECRET
  printf("%s\n", output_secret1.c_str());
  // END SECRET
  std::pair<std::vector<int>, std::vector<std::pair<int, int>>> result =
      construct(K);
  const std::vector<int> &T = result.first;
  const std::vector<std::pair<int, int>> &E = result.second;
  int N = (int)T.size();
  int M = (int)E.size();

  // BEGIN SECRET
  printf("%s\n", output_secret2.c_str());
  printf("OK\n");
  // END SECRET
  printf("%d %d\n", N, M);
  for (int i = 0; i < N; i++) {
    printf("%d%c", T[i], " \n"[i + 1 == N]);
  }
  if (N == 0) {
    printf("\n");
  }
  for (int j = 0; j < M; j++) {
    auto &[U, V] = E[j];
    printf("%d %d\n", U, V);
  }
  fclose(stdout);
  return 0;
}
