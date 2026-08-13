#include <cstdio> 
#include <cstring> 
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm> 
#include <string> 
#include <vector> 
#include <set>
#include <map> 
#include <queue>
#include <complex>
using namespace std; 
typedef long long ll;
typedef double D;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

#define MP make_pair 
#define A first 
#define B second 

#define PB push_back 
#define FR(i, a, b) for(int i=(a); i<(b); i++) 
#define FOR(i, n) FR(i, 0, n) 
#define RF(i, a, b) for(int i=(b)-1; i>=(a); i--) 
#define ROF(i, n) RF(i, 0, n) 
#define EACH(it,X) for(__typeof((X).begin()) it=(X).begin(); it!=(X).end(); ++it) 

int n, s, seed;
int width, bias;
const int MAXN = 1000000;
int perm[MAXN];

void moo(int l, int r) {
//fprintf(stderr, "%d---%d\n", l, r);
  if(l + width + 5 > r - width) {
    FOR(i, r - l) {
      swap(perm[l + i], perm[l + rand() % (i + 1)]);
    }
    return;
  }
  FOR(i, width) {
    swap(perm[l + i], perm[l + rand() % (i + 1)]);
  }
  FOR(i, width) {
    if(rand() % (width * 2 - i) < width) {
      swap(perm[r - i], perm[rand() % width + l]);
    } else {
      swap(perm[r - i], perm[r - i - rand() % (width - i)]);
    }
  }
  l += width;
  r -= width;
  int len = r - l;
  int mid = l + rand() % (len * bias / 1000 + 1);
  while(mid < r) {
    moo(l, mid);
    l = mid + 1;
    mid = l + rand() % (len * bias / 1000 + 1);
  }
  moo(l, r);
}

int main(int argt, char **args) {
  sscanf(args[1], "%d", &n); 
  sscanf(args[2], "%d", &width); 
  sscanf(args[3], "%d", &bias); 
  sscanf(args[4], "%d", &seed); 
  if(seed < 0) {
    seed = time(0) + seed;
  }
  srand(seed);

  for(int i = 0; i < n; ++i) {
    perm[i] = i;
  }
  moo(0, n - 1);
  s = rand() % n;
  printf("%d %d\n", n, s);
  FOR(i, n) {
    printf("%d", perm[i]);
    if(i == n - 1) printf("\n");
    else printf(" ");
  }
  return 0;
}



