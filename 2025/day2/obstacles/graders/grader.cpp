#include "obstacles.h"
#include <cassert>
#include <cstdio>
// BEGIN SECRET
#include <string>
// END SECRET

int main() {
  // BEGIN SECRET
  const std::string input_secret = "5jV4Ew5ZLRRQF8JKt2ZiroW7gNGsr8Jk";
  const std::string output_secret = "i2xwv9fVon02ATMPW3vu6PaetvUcf5iB";
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
  std::vector<int> T(N), H(M);
  for (int i = 0; i < N; i++)
    assert(1 == scanf("%d", &T[i]));
  for (int i = 0; i < M; i++)
    assert(1 == scanf("%d", &H[i]));

  int Q;
  assert(1 == scanf("%d", &Q));
  std::vector<int> L(Q), R(Q), S(Q), D(Q);
  for (int i = 0; i < Q; i++)
    assert(4 == scanf("%d %d %d %d", &L[i], &R[i], &S[i], &D[i]));

  fclose(stdin);

  std::vector<bool> A(Q);

  initialize(T, H);

  for (int i = 0; i < Q; i++)
    A[i] = can_reach(L[i], R[i], S[i], D[i]);

  // BEGIN SECRET
  printf("%s\n", output_secret.c_str());
  printf("OK\n");
  // END SECRET
  for (int i = 0; i < Q; i++)
    if (A[i])
      printf("1\n");
    else
      printf("0\n");
  fclose(stdout);

  return 0;
}
