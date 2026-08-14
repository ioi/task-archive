#include "worldmap.h"
#include <cassert>
#include <cstdio>
// BEGIN SECRET
#include <string>
// END SECRET

int main() {
  // BEGIN SECRET
  const std::string input_secret = "gGzKyiRu0FjeHg0twE4tTLSHo28LuHIO";
  const std::string output_secret = "BsojyV31hMGnnMhLIbwpzucVYHlLMM21";
  char secret[1000];
  assert(1 == scanf("%999s", secret));
  if (std::string(secret) != input_secret) {
    printf("%s\n", output_secret.c_str());
    printf("PV\n");
    printf("Possible tampering with the input\n");
    fclose(stdout);
    return 0;
  }
  int subtask;
  assert(1 == scanf("%d", &subtask));
  // END SECRET
  int T;
  assert(1 == scanf("%d", &T));

  std::vector<int> Nt(T), Mt(T);
  std::vector<std::pair<std::vector<int>, std::vector<int>>> AB;

  for (int t = 0; t < T; ++t) {
    assert(2 == scanf("%d %d", &Nt[t], &Mt[t]));

    int M = Mt[t];
    std::vector<int> A(M), B(M);

    for (int i = 0; i < Mt[t]; i++) {
      assert(2 == scanf("%d %d", &A[i], &B[i]));
    }
    AB.push_back(make_pair(A, B));
  }

  fclose(stdin);

  std::vector<std::vector<std::vector<int>>> Ct;

  for (int t = 0; t < T; t++) {
    int N = Nt[t], M = Mt[t];
    std::vector<int> A = AB[t].first, B = AB[t].second;

    auto C = create_map(N, M, A, B);
    // BEGIN SECRET
    int P = C.size();
    if (P > 240) {
      printf("%s\n", output_secret.c_str());
      printf("WA\n");
      fclose(stdout);
      return 0;
    }
    for (int i = 0; i < P; i++) {
      int Q = (int)C[i].size();
      if (Q != P) {
        printf("%s\n", output_secret.c_str());
        printf("WA\n");
        fclose(stdout);
        return 0;
      }
      for (int j = 0; j < Q; ++j) {
        if (C[i][j] < 1 || C[i][j] > N) {
          printf("%s\n", output_secret.c_str());
          printf("WA\n");
          fclose(stdout);
          return 0;
        }
      }
    }
    // END SECRET
    Ct.push_back(C);
  }

  // BEGIN SECRET
  printf("%s\n", output_secret.c_str());
  printf("OK\n");
  // END SECRET
  for (int t = 0; t < T; t++) {
    auto& C = Ct[t];
    int P = (int)C.size();

    std::vector<int> Q(P);
    for (int i = 0; i < P; ++i)
      Q[i] = (int)C[i].size();

    printf("%d\n", P);
    for (int i = 0; i < P; ++i)
      printf("%d%c", Q[i], " \n"[i + 1 == P]);
    printf("\n");
    for (int i = 0; i < P; i++) {
      for (int j = 0; j < Q[i]; j++) {
        printf("%d%c", C[i][j], " \n"[j + 1 == Q[i]]);
      }
    }
    if (t < T - 1)
      printf("\n");
  }

  fclose(stdout);

  return 0;
}
