// find a long path in the graph with a simple greedy, then find a DFS tree that contains this path, and do the 3N with the two following optimization:
// - don't return after we reach the deepest node
// - only create an extra line in the matrix to add backedges if all such backedges are going down 
// repeat this N times, rooting at each vertex

#include "worldmap.h"
#include <vector>
#include <iostream>
#include <bits/stdc++.h>
#define debug 
using namespace std;

#define maxn 40


vector<vector<int> > G;




std::vector<std::vector<int> > create_map(int N, int M, std::vector<int> A, std::vector<int> B) {
	// step #1. preparation
  srand(0);
  vector<vector<int> > best, ans;
  if(N == 1){
    ans = vector<vector<int> > (1, vector<int>(1));
    ans[0][0] = 1;
    return ans;
  }
	G = vector<vector<int> > (N, vector<int> (0));

  int K = 3*N;


	for (int i = 0; i < M; i++) {
		A[i]--;
		B[i]--;
		G[A[i]].push_back(B[i]);
		G[B[i]].push_back(A[i]);
	}

  for(int r=0;r<N;r++){

    ans = vector<vector<int> > (K, vector<int>(K));

    ans[0][0] = r;

    vector<vector<int> >  mrk (N, vector<int>(N,0)); // 0 = can't use, 1 = already used, 2 = has to add

    for(int i=0;i<M;i++)
      mrk[A[i]][B[i]] = mrk[B[i]][A[i]] = 2;

    for(int i=0;i<K;i++)
      for(int j=0;j<K;j++){

        if(i == 0 && j == 0) continue;

        int a = -1, b = -1;
        if(i) a = ans[i-1][j];
        if(j) b = ans[i][j-1];

        if(a == -1) a = b;
        if(b == -1) b = a;

       for(int k=0;k<G[a].size();k++)
        swap(G[a][k], G[a][rand()%(k+1)]);

        vector<int> allowed (N,0);
        for(int w : G[b]) allowed[w]++;

        int to = -1;
        for(int w : G[a]){
          if(allowed[w]){
            if(to == -1)
              to = w;
            else if(mrk[a][to] == 1 && mrk[a][w] == 2)
              to = w;
          }
        }

        assert(to != -1);
        ans[i][j] = to;
        mrk[a][to] = mrk[to][a] = mrk[b][to] = mrk[to][b] = 1;

      }



    // step #4. final step
    assert(ans.size() == K);
    for (int i = 0; i < int(ans.size()); i++) {
      assert(ans[i].size() == K);
      for (int j = 0; j < int(ans.size()); j++) {
        ans[i][j]++;
        assert(ans[i][j] >= 1 && ans[i][j] <= N);
      }
    }


    if(r == 0 || ans.size() < best.size())
      best = ans;
  }

	return best;
}