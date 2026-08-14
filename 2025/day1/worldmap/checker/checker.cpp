#include "testlib.h"

#include <string>

const int qy[] = {1, 0, -1, 0};
const int qx[] = {0, 1, 0, -1};
const int MAXK = 240;

int main(int argc, char *argv[]) {
  const std::string output_secret = "BsojyV31hMGnnMhLIbwpzucVYHlLMM21";
  const std::string input_secret = "gGzKyiRu0FjeHg0twE4tTLSHo28LuHIO";
  registerChecker("worldmap", argc, argv);
  readBothSecrets(output_secret);
  readBothGraderResults();

	inf.readToken(input_secret);
	inf.readEoln();

  int partial_score = inf.readInt();
  inf.readEoln();
  int T = inf.readInt();
  
  int WORST_RATIO = -1;
  int WORST_K = 0, WORST_N = 0;

  for(int t = 0; t < T; t++) {

    int N = inf.readInt();
    int M = inf.readInt();

    std::vector<int> A(M), B(M);
    std::set<std::pair<int,int>> edges, edges_o;

    for (int i = 0; i < M; i++) {
        A[i] = inf.readInt();
        B[i] = inf.readInt();
        if (A[i] > B[i])
          edges.insert({A[i], B[i]});
        else
          edges.insert({B[i], A[i]});
    }
    int K = ouf.readInt(1, MAXK);
    ouf.readEoln();
    for (int i = 0; i < K; ++i) {
      ouf.readInt(K, K);
    }
    std::vector<std::vector<int>> R(K, std::vector<int>(K, 0));
    for (int i = 0; i < K; i++) {
      for (int j = 0; j < K; j++) {
        R[i][j] = ouf.readInt();
      }
      ouf.readEoln();
    }
    
    int yy, xx, ai, bi;

    for (int l = 0; l < 4; l++) {
      for (int i = 0; i < K; i++) {
        for (int j = 0; j < K; j++) {
          yy = i + qy[l];
          xx = j + qx[l];
          if (yy < 0 || xx < 0 || yy>= K || xx>= K) continue;
          ai = R[i][j];
          bi = R[yy][xx];
          if (ai == bi) continue;
          if (edges.find({ai, bi}) == edges.end() && edges.find({bi, ai}) == edges.end()) {
            quitf(_wa, " there are some extra edges in your graph ");
          }
          if (ai > bi)
            edges_o.insert({ai, bi});
          else 
            edges_o.insert({bi, ai});
        }
      }
    }
    if ((int)edges.size() != (int) edges_o.size()) {
      quitf(_wa, " there are some missing edges in your graph ");
    }

    int TWICE_RATIO = 0;
    while(TWICE_RATIO * N < 2*K)
      TWICE_RATIO++;
    if (TWICE_RATIO > WORST_RATIO) {
      WORST_RATIO = TWICE_RATIO;
      WORST_K = K, WORST_N = N;
    }
  }

  if(partial_score == 0)
    quitf(_ok, "correct");
  else if (WORST_RATIO <= 4) {
    quitf(_ok, "K <= 2N, K=%d, N=%d", WORST_K, WORST_N);
  } else if (WORST_RATIO <= 5) {
    quitp(0.875, "K <= 2.5N, K=%d, N=%d", WORST_K, WORST_N);
  } else if (WORST_RATIO <= 6) {
    quitp(0.75, "K <= 3N, K=%d, N=%d", WORST_K, WORST_N);
  } else if (WORST_RATIO <= 8) {
    quitp(0.5, "K <= 4N, K=%d, N=%d", WORST_K, WORST_N);
  } else if (WORST_RATIO <= 12) {
    quitp(0.25, "K <= 6N, K=%d, N=%d", WORST_K, WORST_N);
  } else{
    quitf(_wa, "K > 6N");
  }
  return 0;
}
