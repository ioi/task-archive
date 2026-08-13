// .... .... .....!
// ...... ......!
// .... ....... ..... ..!
// ...... ... ... .... ... .... .....!
// ... .. ... .... ...?

#include "train.h"
#include <vector>
#include <algorithm>
using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define fer(i, x, n) for (int i = (int)(x), _n = (int)(n); i < _n; i++)
#define rof(i, n, x) for (int i = (int)(n), _x = (int)(x); i-- > _x; )
#define sz(x) (int((x).size()))
#define pb push_back
#define all(X) (X).begin(),(X).end()
#define X first
#define Y second

template<class P, class Q> inline void smin(P &a, Q b) { if (b < a) a = b; }
template<class P, class Q> inline void smax(P &a, Q b) { if (a < b) a = b; }

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 300000 + 100;

vector<int> radj[maxn];
int deg[maxn], need[maxn];

void dfs(int u, vector<int> &w) {
	for(int v: radj[u]) {
		need[v]--;
		if(!w[v] && need[v] == 0) dfs(v, w); // only dfs through non-charging vertices
	}
}

vector<int> who_wins(vector<int> a, vector<int> r, vector<int> u, vector<int> v) {
	int n = sz(a);
	rep(i, sz(u)) radj[v[i]].pb(u[i]), deg[u[i]]++;
	vector<int> res(n, 1);
	for(bool cng = true; !(cng = !cng); ) {
		rep(i, n) need[i] = (a[i] ? 1 : deg[i]); // d only matters here
		rep(i, n) if(r[i] && res[i]) dfs(i, r); // dfs from yet-has-a-chance-to-win wells
		rep(i, n) if(r[i] && res[i] && need[i] > 0) res[i] = false, cng = true; // and see if they had no chance
	}
	rep(i, n) res[i] &= (need[i] <= 0); // look, more fopdoodles
	return res;
}
