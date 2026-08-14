#include "festival.h"
#include <cassert>
#include <cstdio>
// BEGIN SECRET
#include <string>
// END SECRET

int main() {
  // BEGIN SECRET
  const std::string input_secret = "ylQedwYNTcFgpd2Epe0kHFfnG4rqrt2X";
  const std::string output_secret = "z0H2zDqz4usrRWQ5xeg9s2tOOGvlMue8";
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
  int N, A;
  assert(2 == scanf("%d %d", &N, &A));
  std::vector<int> P(N), T(N);
  for (int i = 0; i < N; i++)
    assert(2 == scanf("%d %d", &P[i], &T[i]));
  fclose(stdin);

  std::vector<int> R = max_coupons(A, P, T);

  // BEGIN SECRET
  printf("%s\n", output_secret.c_str());
  if ((int)R.size() > N) {
    printf("WA\n");
    printf("R.size() (%d) is larger than N (%d)\n", (int)R.size(), N);
    fclose(stdout);
    return 0;
  }
  printf("OK\n");
  // END SECRET
  int S = R.size();
  printf("%d\n", S);
  for (int i = 0; i < S; i++)
    printf("%s%d", (i == 0 ? "" : " "), R[i]);
  printf("\n");
  fclose(stdout);

  return 0;
}
