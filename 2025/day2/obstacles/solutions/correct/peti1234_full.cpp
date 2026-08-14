// solution/peti1234_full.cpp
// {
//   "verdict": "correct"
// }
// END HEADER
//#include "obstacles.h"
#include <cassert>
#include <cstdio>
#include<bits/stdc++.h>
using namespace std;

const int c=500005, k=20;
int n, m;
int t[c], prefmax[c], prefmin[c], ert[c]; // meddig mehet az adott oszlopban
int balkov[c], jobbkov[c]; // balra kovetkezo <=, jobbra kovetkekzo <
int lg[c], maxi[c][k]; // sparse table

int balfel[c][k], maxbal[c][k]; // balra / jobbra lepes preferalom mi a legjobb ertek
int jobbfel[c][k], minjobb[c][k];
vector<pair<int, int> > ord;

int maxval(int l, int r) {
    // [l, r]
    r++;
    int s=lg[r-l];
    return max(maxi[l][s], maxi[r-(1<<s)][s]); // jo lenne atgondolni
}
bool jo(int a, int b) {
    int aa=min(a, b), bb=max(a, b);
    return (prefmax[ert[a]]>maxval(aa, bb));
}
void initialize(vector<int> A, vector<int> B) {
    m=A.size(), n=B.size(); // forditva, mint a feladatban
    prefmax[1]=prefmin[1]=A[0];
    for (int i=2; i<=m; i++) {
        prefmax[i]=max(prefmax[i-1], A[i-1]);
        prefmin[i]=min(prefmin[i-1], A[i-1]);
    }
    for (int i=1; i<=n; i++) {
        t[i]=B[i-1];
        int lo=0, hi=m+1, mid;
        while (hi-lo>1) {
            mid=(hi+lo)/2;
            if (t[i]<prefmin[mid]) {
                lo=mid;
            } else {
                hi=mid;
            }
        }
        ert[i]=lo;
    }

    for (int i=2; i<=n; i++) {
        lg[i]=lg[i/2]+1;
    }
    for (int i=1; i<=n; i++) {
        maxi[i][0]=t[i];
    }
    for (int j=1; j<k; j++) {
        for (int i=1; i+(1<<j)<=n+1; i++) {
            maxi[i][j]=max(maxi[i][j-1], maxi[i+(1<<(j-1))][j-1]);
        }
    }

    /*cout << "ert\n";
    for (int i=1; i<=n; i++) {
        cout << ert[i] << " ";
    }
    cout << "\n";*/

    vector<int> sor;
    sor.push_back(0);
    for (int i=1; i<=n; i++) {
        while (sor.back()>0 && t[i]<t[sor.back()]) {
            sor.pop_back();
        }
        balkov[i]=sor.back();
        sor.push_back(i);
    }
    sor.clear();
    sor.push_back(n+1);
    for (int i=n; i>=1; i--) {
        while (sor.back()<n+1 && t[i]<=t[sor.back()]) {
            sor.pop_back();
        }
        jobbkov[i]=sor.back();
        sor.push_back(i);
    }
    sor.clear();

    /*for (int i=1; i<=n; i++) {
        cout << i << " " << balkov[i] << " " << jobbkov[i] << "\n";
    }*/

    for (int i=1; i<=n; i++) {
        ord.push_back({t[i], i});
    }
    sort(ord.begin(), ord.end());

    for (int i=0; i<k; i++) {
        minjobb[0][i]=0;
        maxbal[n+1][0]=n+1;
    }

    for (auto p:ord) {
        int a=p.second;
        int x=balkov[a], y=jobbkov[a];
        bool bb=(x>0 && jo(a, x)), jj=(y<=n && jo(a, y));
        if (bb) {
            balfel[a][0]=x;
        } else if (jj) {
            balfel[a][0]=y;
        } else {
            balfel[a][0]=n+1;
        }

        if (jj) {
            jobbfel[a][0]=y;
        } else if (bb) {
            jobbfel[a][0]=x;
        } else {
            jobbfel[a][0]=0;
        }

        maxbal[a][0]=balfel[a][0], minjobb[a][0]=jobbfel[a][0];
        for (int i=1; i<k; i++) {
            int s=balfel[a][i-1];
            balfel[a][i]=balfel[s][i-1];
            maxbal[a][i]=max(maxbal[a][i-1], maxbal[s][i-1]);

            s=jobbfel[a][i-1];
            jobbfel[a][i]=jobbfel[s][i-1];
            minjobb[a][i]=min(minjobb[a][i-1], minjobb[s][i-1]);
        }

    }


}
bool can_reach(int l, int r, int s, int f) {
    l++, r++, s++, f++;
    if (s>f) swap(s, f);
    int ss=s, ff=f;
    // s-bol jobbra, f-bol balra kell menni
    for (int i=k-1; i>=0; i--) {
        if (minjobb[s][i]>=l) {
            s=jobbfel[s][i];
        }
        if (maxbal[f][i]<=r) {
            f=balfel[f][i];
        }
    }
    int val=min(ert[f], ert[s]);
    return (prefmax[val]>maxval(ss, ff));
    //return (f<=s);
}
/*
3 4
2 1 3
0 1 2 0
2
0 3 1 3
1 3 1 3

*/
/*
int main() {
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

    for (int i = 0; i < Q; i++)
    if (A[i])
      printf("1\n");
    else
      printf("0\n");
    fclose(stdout);

  return 0;
}
*/
