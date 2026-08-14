#include<bits/stdc++.h>
using namespace std;


//#include "worldmap.h"
#include <cassert>
#include <cstdio>








//#include "worldmap.h"
const int c=105;
int n, m, n2, be[c], el[c][c], cnt, cur;
bool v[c], kesz[c];
vector<int> sz[c], sor;
vector<vector<int>> ans;
void dfs(int a) {
    v[a]=true;
    be[a]=++cnt;
    sor.push_back(a);
    for (auto x:sz[a]) {
        if (!v[x]) {
            dfs(x);
            sor.push_back(a);
        }
    }
}
void fix(int a, bool adj) {
    vector<pair<int, int> > p;
    for (int i=0; i<n2; i++) {
        for (int j=0; j<n2; j++) {
            if (i+j==cur) {
                p.push_back({i, j});
            }
        }
    }
    if (adj) {
        for (int i=1; i<=n; i++) {
            if (be[i]<be[a] && el[i][a]) {
                assert(p.size()>0);
                ans[p.back().first][p.back().second]=i;
                p.pop_back();
            }
        }
    }
    while (p.size()>0) {
        ans[p.back().first][p.back().second]=a;
        p.pop_back();
    }
    cur++;
}
std::vector<std::vector<int> > create_map(int N, int M, std::vector<int> A, std::vector<int> B) {
    n=N, m=M, n2=2*n;
    ans.resize(n2);
    for (int i=0; i<n2; i++) {
        ans[i].resize(n2);
        for (int j=0; j<n2; j++) {
            ans[i][j]=0;
        }
    }
    for (int i=0; i<m; i++) {
        int a=A[i], b=B[i];
        sz[a].push_back(b), sz[b].push_back(a);
        el[a][b]=el[b][a]=1;
    }
    for (int i=1; i<=n; i++) {
        if (sz[i].size()>0 && !v[i]) {
            dfs(i);
        }
    }
    if (sor.size()==0) {
        sor.push_back(1);
    }
    for (auto x:sor) {
        //cout << "ertek " << x << "\n";
        fix(x, 0);
        if (!kesz[x]) {
            fix(x, 1);
            kesz[x]=1;
            fix(x, 0);
        }
    }
    while (cur<2*n2-1) {
        fix(sor.back(), 0);
    }


    for (int i=1; i<=n; i++) {
        be[i]=0, v[i]=0, kesz[i]=0;
        sz[i].clear();
        for (int j=1; j<=n; j++) {
            el[i][j]=0;
        }
    }
    cnt=0, cur=0;
    sor.clear();
	return ans;
}



/*
2
5 10
1 2
1 3
1 4
1 5
2 3
2 4
2 5
3 4
3 5
4 5

4 4
1 2
2 3
3 4
1 4
*/




/*
bool test=0;

int main() {
    if (test) {
        int t;
        cin >> t;
        while (t--) {
            int n;
            cin >> n;
            int m=n-1;
            vector<int> a, b;
            for (int i=1; i<n; i++) {
                a.push_back(i), b.push_back(i+1);
            }
            auto c=create_map(n, m, a, b);
            for (auto x:c) {
                for (auto y:x) {
                    cout << y << " ";
                }
                cout << "\n";
            }
        }
        return 0;
    }
  int T;
  cin >> T;

  std::vector<int>  Nt(T), Mt(T);
  std::vector<std::pair<std::vector<int>, std::vector<int> > > AB;

  for(int t = 0; t < T; ++t) {
    cin >> Nt[t] >> Mt[t];

    int M = Mt[t];
    std::vector<int> A(M), B(M);

    for (int i = 0; i < Mt[t]; i++){
      cin >> A[i] >> B[i];
    }
    AB.push_back(make_pair(A, B));
  }


  std::vector<std::vector<std::vector<int> > > Ct;

  for(int t = 0; t < T; t++) {
    int N = Nt[t], M = Mt[t];
    std::vector<int> A = AB[t].first, B = AB[t].second;

    auto C = create_map(N, M, A, B);
    Ct.push_back(C);
  }

  for(int t = 0; t < T; t++) {
    auto& C = Ct[t];
    int P = (int)C.size();

    std::vector<int> Q(P);
    for (int i = 0; i < P; ++i)
      Q[i] = (int)C[i].size();

    //printf("%d\n", P);
    //for (int i = 0; i < P; ++i)
      //printf("%d%c", Q[i], " \n"[i + 1 == P]);
    for (int i = 0; i < P; i++) {
      for (int j = 0; j < Q[i]; j++) {
        printf("%d%c", C[i][j], " \n"[j + 1 == Q[i]]);
      }
    }
  }

  fclose(stdout);

  return 0;
}
*/
