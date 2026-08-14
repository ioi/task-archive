// solution/shahali-subtask12-accidentalQ1.cpp
// {
//   "verdict": "wrong_answer",
//   "except": {
//     "n1": "correct"
//   }
// }
// END HEADER
#include "obstacles.h"
#include<bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> pi3;
typedef pair<ll, int> pli;
typedef vector<int> vi;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
#define all(x) x.begin(), x.end()
#define pb push_back
#define SZ(x) ((int)x.size())
#define kill(x) return cout<<x<<'\n', 0;
#define getbit(x,y) (((x)>>(y))&1)
#define popcount(x) (__builtin_popcount(x))

const int inf=1000000010;
const ll INF=1000000000000001000LL;
const int mod=998244353;
const int MAXN=500010, LOG=19;

int n, m, k;
int T[MAXN], H[MAXN];
int maxH[LOG][MAXN];

inline int lg2(int x){ return 31-__builtin_clz(x);}

int range_max_h(int l, int r){ // [l, r)
	int lg = lg2(r-l);
	return max(maxH[lg][l], maxH[lg][r-(1<<lg)]);
}

void initialize(std::vector<int> _T, std::vector<int> _H){
	n = SZ(_T);
	m = SZ(_H);
	for (int i=0; i<n; i++) T[i+1]=_T[i];
	for (int i=0; i<m; i++) H[i+1]=_H[i];
	// ----------------------------------

	for (int i=1; i<=m; i++) maxH[0][i]=H[i];
	for (int j=1; j<LOG; j++)
		for (int i=1; i+(1<<j)<=m+1; i++)
			maxH[j][i] = max(maxH[j-1][i], maxH[j-1][i+(1<<(j-1))]);

}

bool can_reach(int l, int r, int s, int d){
	l++;
	r++;
	s++;
	d++;
	if (s>d) swap(s, d);
	
	return range_max_h(s, d+1) < T[1];
}
