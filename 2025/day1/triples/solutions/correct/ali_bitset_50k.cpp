#include "triples.h"
#include <bits/stdc++.h>
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
const int MAXN=50010;
 
int n, m, k;
int f[MAXN];
int g[MAXN];
int cnt[MAXN];
vector<pair<pii, int>> pairs;
vector<int> vec[MAXN];
bitset<MAXN> L[MAXN*2], R[MAXN*2];
 
int check231(int i, int j, int k, vi &h){
    return (h[i] == k-j && h[j] == k-i && h[k] == j-i);
}
 
ll count_triples(vi h) {
    n = SZ(h);
    if (n >= MAXN)
        return -1;
 
    ll ans=0;
    pairs.clear();
    for (int i=0; i<MAXN; i++) vec[i].clear();
    memset(cnt, 0, sizeof(cnt));
    for (int i=0; i<MAXN*2; i++){
        L[i].reset();
        R[i].reset();
    }
 
    // 1 2 3
    for (int i=0; i<n; i++){
        int j = i+h[i];
        if (j>=n) continue;
        int k = j+h[j];
        if (k>=n) continue;
        if (h[k] == k-i && i<j && j<k) pairs.pb({{i, j}, k});
    }
 
    // 1 3 2
    for (int i=0; i<n; i++){
        int j = i+h[i];
        if (j>=n) continue;
        int k = i+h[j];
        if (k>=n) continue;
        if (h[k] == k-j && i<j && j<k) pairs.pb({{i, j}, k});
    }
 
    // 2 1 3
    for (int k=0; k<n; k++){
        int i = k-h[k];
        if (i<0) continue;
        int j = k-h[i];
        if (j<0) continue;
        if (h[j] == j-i && i<j && j<k) pairs.pb({{i, j}, k});
    }
 
    // 3 1 2
    for (int k=0; k<n; k++){
        int j = k-h[k];
        if (j<0) continue;
        int i = j-h[j];
        if (i<0) continue;
        if (h[i] == k-i && i<j && j<k) pairs.pb({{i, j}, k});
    }
 
    // 3 2 1
    for (int i=0; i<n; i++){
        int k = i+h[i];
        if (k>=n) continue;
        int j = i+h[k];
        if (j<0) continue;
        if (h[j] == k-j && i<j && j<k) pairs.pb({{i, j}, k});
    }
 
    sort(all(pairs));
    pairs.resize(unique(all(pairs)) - pairs.begin());
    for (auto [p, k]: pairs){
        auto [i, j] = p;
        if (!check231(i, j, k, h)){
            ans++;
            // cerr<<"found "<<i<<" "<<j<<" "<<k<<"\n";
        }
    }
    // debug(ans)
 
    // 2 3 1
     
    // for (int i=0; i<n; i++)
    //  for (int j=i+1; j<n; j++){
    //      int k = j+h[i];
    //      if (k<n && check231(i, j, k, h)){
    //          cerr<<"slow found "<<i<<" "<<j<<" "<<k<<"\n";
    //      }
    //  }
 
    for (int i=0; i<n; i++){
        f[i]=h[i]+i;
        g[i]=h[i]-i+n;
        R[f[i]].set(i);
        L[g[i]].set(i);
        // vec[h[i]].pb(i);
    }
 
    for (int i=0; i<n; i++){
        int res = (L[g[i]]&(R[f[i]]>>h[i])).count();
        ans+=res;
    }
 
    return ans;
}
 
vi construct_range(int M, int K) {
    return {4, 1, 4, 3, 2, 6, 1};
}
