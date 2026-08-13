#include "partition.h"

#include <bits/stdc++.h>
using namespace std;

using ll=long long;
//#define int ll

bool dbg=false;

#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define pb push_back
#define eb emplace_back
#define a first
#define b second
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
#define si(x) int(x.size())
#ifdef LOCAL
#define dmp(x) cerr<<__LINE__<<" "<<#x<<" "<<x<<endl
#else
#define dmp(x) void(0)
#endif

template<class t,class u> bool chmax(t&a,u b){if(a<b){a=b;return true;}else return false;}
template<class t,class u> bool chmin(t&a,u b){if(b<a){a=b;return true;}else return false;}

template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;

using pi=pair<int,int>;
using vi=vc<int>;
using vvi=vc<vc<int>>;

template<class t,class u>
ostream& operator<<(ostream& os,const pair<t,u>& p){
	return os<<"{"<<p.a<<","<<p.b<<"}";
}

template<int i,class T>
void print_tuple(ostream&,const T&){
}

template<int i,class T,class H,class ...Args>
void print_tuple(ostream&os,const T&t){
	if(i)os<<",";
	os<<get<i>(t);
	print_tuple<i+1,T,Args...>(os,t);
}

template<class ...Args>
ostream& operator<<(ostream&os,const tuple<Args...>&t){
	os<<"{";
	print_tuple<0,tuple<Args...>,Args...>(os,t);
	return os<<"}";
}

template<class t,size_t n>
ostream& operator<<(ostream&os,const array<t,n>&a){
	os<<"{";
	for(auto e:a)os<<e<<",";
	return os<<"}";
}

template<class t> ostream& operator<<(ostream& os,const vc<t>& v){
	os<<"{";
	for(auto e:v)os<<e<<",";
	return os<<"}";
}

#define mp make_pair
#define mt make_tuple
#define one(x) memset(x,-1,sizeof(x))
#define zero(x) memset(x,0,sizeof(x))
#ifdef LOCAL
void dmpr(ostream&os){os<<endl;}
template<class T,class... Args>
void dmpr(ostream&os,const T&t,const Args&... args){
	os<<t<<" ";
	dmpr(os,args...);
}
#define dmp2(...) dmpr(cerr,__LINE__,##__VA_ARGS__)
#else
#define dmp2(...) void(0)
#endif

using uint=unsigned;
using ull=unsigned long long;

ll rand_int(ll l, ll r) { //[l, r]
	//#ifdef LOCAL
	static mt19937_64 gen;
	/*#else
	static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
	#endif*/
	assert(l<=r); //最適化していると↓が l>r でも動いてしまうという事故があったので
	return uniform_int_distribution<ll>(l, r)(gen);
}
ll rand_int(ll k){ //[0,k)
	return rand_int(0,k-1);
}
pi rand_range(int n){
	int l=rand_int(n);
	int r=rand_int(n);
	if(l>r)swap(l,r);
	r++;
	return pi(l,r);
}
string rand_string(int n,char lw,char up){
	string s(n,'?');
	rep(i,n)s[i]=rand_int(lw,up);
	return s;
}

int current_run_id,run_batch_size=1000;
int calc_random_limit(){
	return current_run_id/run_batch_size+1;
}
template<class t>
void generate_single(t&a){
	a=rand_int(1,calc_random_limit());
}
void generate_single(string&a){
	int n;generate_single(n);
	a=rand_string(n,'a','b');
}
template<class t,class u>
void generate_single(pair<t,u>&a){
	generate_single(a.a);
	generate_single(a.b);
}
//https://trap.jp/post/1224/
template<class... Args>
void input(Args&... a){
	if(dbg){
		(generate_single(a),...);
	}else{
		#ifdef USE_FAST_IO
		sc.read(a...);
		#else
		(cin >> ... >> a);
		#endif
	}
}
#define INT(...) int __VA_ARGS__;input(__VA_ARGS__)
#define LL(...) ll __VA_ARGS__;input(__VA_ARGS__)
#define ULL(...) ull __VA_ARGS__;input(__VA_ARGS__)
#define STR(...) string __VA_ARGS__;input(__VA_ARGS__)
#define CHR(...) char __VA_ARGS__;input(__VA_ARGS__)
#define DBL(...) double __VA_ARGS__;input(__VA_ARGS__)
#define LD(...) ld __VA_ARGS__;input(__VA_ARGS__)
#define overload3(a,b,c,d,...) d
#define VI2(name,size) vi name(size);rep(i_##name,size)input(name[i_##name]);
#define VI3(name,size,offset) vi name(size);rep(i_##name,size)input(name[i_##name]),name[i_##name]+=offset;
#define VI(...) overload3(__VA_ARGS__,VI3,VI2)(__VA_ARGS__)
#define VPI(name,size) vc<pi> name(size);rep(i_##name,size)input(name[i_##name].a,name[i_##name].b);
#define VVI(name,sizeN,sizeM) vvi name(sizeN,vi(sizeM));\
rep(i_##name,sizeN)rep(j_##name,sizeM)input(name[i_##name][j_##name]);
#define VS(name,size) vc<string> name(size);rep(i_##name,size)input(name[i_##name]);
#define VMI(name,size) vc<mint> name(size);rep(i_##name,size){INT(tmp_##name);name[i_##name]=tmp_##name;};

#define overload5(a,b,c,d,e,f,...) f
#define VVC4(type,name,sizeN,sizeM) vvc<type> name(sizeN,vc<type>(sizeM));
#define VVC5(type,name,sizeN,sizeM,ini) vvc<type> name(sizeN,vc<type>(sizeM,ini));
#define VVC(...) overload5(__VA_ARGS__,VVC5,VVC4)(__VA_ARGS__)

#define VRANGE(name,size) VPI(name,size);for(auto&[l,r]:name)l--;

template<class T>
T vvvc(T v){
	return v;
}

template<class T,class...Args>
auto vvvc(int n,T v,Args...args){
	return vector(n,vvvc(v,args...));
}

void printsuc(int suc){
	#ifdef USE_FAST_IO
		if(suc==1)pr.write('\n');
		if(suc==2)pr.write(' ');
	#else
		if(suc==1){
			if(dbg)cout<<endl;
			else{
				#ifdef LOCAL
				cout<<endl;
				#else
				cout<<"\n";
				#endif
			}
		}
		if(suc==2)
			cout<<" ";
	#endif
}

template<class t>
void print_single(t x,int suc=1){
	#ifdef USE_FAST_IO
	pr.write(x);
	#else
	cout<<x;
	#endif
	printsuc(suc);
}

template<class t,class u>
void print_single(const pair<t,u>&p,int suc=1){
	print_single(p.a,2);
	print_single(p.b,suc);
}

template<class T>
void print_single(const vector<T>&v,int suc=1){
	rep(i,v.size())
		print_single(v[i],i==int(v.size())-1?3:2);
	printsuc(suc);
}

template<class T,size_t N>
void print_single(const array<T,N>&v,int suc=1){
	rep(i,N)
		print_single(v[i],i==int(N)-1?3:2);
	printsuc(suc);
}

template<class T>
void print(const T&t){
	print_single(t);
}

template<class T,class ...Args>
void print(const T&t,const Args&...args){
	print_single(t,2);
	print(args...);
}

template<class T>
void printvv(const vvc<T>&vs){
	for(const auto&row:vs)print(row);
}

string readString(){
	string s;
	cin>>s;
	return s;
}

template<class T>
T sq(const T& t){
	return t*t;
}

void YES(bool ex=true){
	cout<<"YES\n";
	if(ex)exit(0);
	#ifdef LOCAL
	cout.flush();
	#endif
}
void NO(bool ex=true){
	cout<<"NO\n";
	if(ex)exit(0);
	#ifdef LOCAL
	cout.flush();
	#endif
}
void Yes(bool ex=true){
	cout<<"Yes\n";
	if(ex)exit(0);
	#ifdef LOCAL
	cout.flush();
	#endif
}
void No(bool ex=true){
	cout<<"No\n";
	if(ex)exit(0);
	#ifdef LOCAL
	cout.flush();
	#endif
}
//#define CAPITAL
/*
void yes(bool ex=true){
	#ifdef CAPITAL
	cout<<"YES"<<"\n";
	#else
	cout<<"Yes"<<"\n";
	#endif
	if(ex)exit(0);
	#ifdef LOCAL
	cout.flush();
	#endif
}
void no(bool ex=true){
	#ifdef CAPITAL
	cout<<"NO"<<"\n";
	#else
	cout<<"No"<<"\n";
	#endif
	if(ex)exit(0);
	#ifdef LOCAL
	cout.flush();
	#endif
}*/
void possible(bool ex=true){
	#ifdef CAPITAL
	cout<<"POSSIBLE"<<"\n";
	#else
	cout<<"Possible"<<"\n";
	#endif
	if(ex)exit(0);
	#ifdef LOCAL
	cout.flush();
	#endif
}
void impossible(bool ex=true){
	#ifdef CAPITAL
	cout<<"IMPOSSIBLE"<<"\n";
	#else
	cout<<"Impossible"<<"\n";
	#endif
	if(ex)exit(0);
	#ifdef LOCAL
	cout.flush();
	#endif
}

constexpr ll ten(int n){
	return n==0?1:ten(n-1)*10;
}

const ll infLL=LLONG_MAX/3;

#ifdef int
const int inf=infLL;
#else
const int inf=INT_MAX/2-100;
#endif

int topbit(signed t){
	return t==0?-1:31-__builtin_clz(t);
}
int topbit(ll t){
	return t==0?-1:63-__builtin_clzll(t);
}
int topbit(ull t){
	return t==0?-1:63-__builtin_clzll(t);
}
int botbit(signed a){
	return a==0?32:__builtin_ctz(a);
}
int botbit(ll a){
	return a==0?64:__builtin_ctzll(a);
}
int botbit(ull a){
	return a==0?64:__builtin_ctzll(a);
}
int popcount(signed t){
	return __builtin_popcount(t);
}
int popcount(ll t){
	return __builtin_popcountll(t);
}
int popcount(ull t){
	return __builtin_popcountll(t);
}
int bitparity(ll t){
	return __builtin_parityll(t);
}
bool ispow2(int i){
	return i&&(i&-i)==i;
}
ll mask(int i){
	return (ll(1)<<i)-1;
}
inline ull umask(int i){
	return (ull(1)<<i)-1;
}
inline ull umask(int l,int r){
	return l==64?0:r-l==64?-1:umask(r-l)<<l;
}
ll minp2(ll n){
	if(n<=1)return 1;
	else return ll(1)<<(topbit(n-1)+1);
}

bool inc(int a,int b,int c){
	return a<=b&&b<=c;
}

template<class S> void mkuni(S&v){
	sort(all(v));
	v.erase(unique(all(v)),v.ed);
}

template<class t> bool isuni(vc<t> v){
	int s=si(v);
	mkuni(v);
	return si(v)==s;
}

bool isperm(const vi&p){
	int n=si(p);
	vc<bool> used(n);
	for(auto v:p){
		if(!inc(0,v,n-1))return false;
		if(used[v])return false;
		used[v]=true;
	}
	return true;
}

template<class t>
void myshuffle(vc<t>&a){
	rep(i,si(a))swap(a[i],a[rand_int(0,i)]);
}

template<class S,class u>
int lwb(const S&v,const u&a){
	return lower_bound(all(v),a)-v.bg;
}
template<class t,class u>
bool bis(const vc<t>&v,const u&a){
	return binary_search(all(v),a);
}

//VERIFY: yosupo
//KUPC2017J
//AOJDSL1A
//without rank
struct unionfind{
	vi p,s;
	int c;
	unionfind(int n):p(n,-1),s(n,1),c(n){}
	void clear(){
		fill(all(p),-1);
		fill(all(s),1);
		c=si(p);
	}
	int find(int a){
		return p[a]==-1?a:(p[a]=find(p[a]));
	}
	//set b to a child of a
	bool unite(int a,int b){
		a=find(a);
		b=find(b);
		if(a==b)return false;
		p[b]=a;
		s[a]+=s[b];
		c--;
		return true;
	}
	bool same(int a,int b){
		return find(a)==find(b);
	}
	int sz(int a){
		return s[find(a)];
	}
};

vvc<int> readGraph(int n,int m){
	vvc<int> g(n);
	rep(i,m){
		INT(a,b);
		a--;b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	return g;
}

vvc<int> initUG(int n,const vc<pi>&es){
	vvc<int> g(n);
	for(auto [a,b]:es){
		g[a].pb(b);
		g[b].pb(a);
	}
	return g;
}

vvc<int> rand_tree(int n){
	vvc<int> t(n);
	unionfind uf(n);
	while(uf.c>1){
		int a=rand_int(n);
		int b=rand_int(n);
		if(uf.unite(a,b)){
			t[a].pb(b);
			t[b].pb(a);
		}
	}
	return t;
}

vvc<int> readTree(int n){
	if(dbg){
		return rand_tree(n);
	}else{
		return readGraph(n,n-1);
	}
}

vi readRooted(int n){
	assert(!dbg);
	vi par(n,-1);
	rng(i,1,n){
		input(par[i]);
		par[i]--;
		assert(inc(0,par[i],i-1));
	}
	return par;
}

void printTree(const vvc<int> t){
	int n=si(t);
	int degsum=0;
	rep(i,n)degsum+=si(t[i]);
	if(degsum==n-1){
		//directed
		rep(i,si(t))for(auto j:t[i]){
			print(i+1,j+1);
		}
	}else if(degsum==2*(n-1)){
		//undirected
		rep(i,si(t))for(auto j:t[i])if(i<j){
			print(i+1,j+1);
		}
	}else{
		assert(false);
	}
}

template<class t>
vc<t> presum(const vc<t>&a){
	vc<t> s(si(a)+1);
	rep(i,si(a))s[i+1]=s[i]+a[i];
	return s;
}
vc<ll> presum(const vi&a){
	vc<ll> s(si(a)+1);
	rep(i,si(a))s[i+1]=s[i]+a[i];
	return s;
}
//BIT で数列を管理するときに使う (CF850C)
template<class t>
vc<t> predif(vc<t> a){
	gnr(i,1,si(a))a[i]-=a[i-1];
	return a;
}
template<class t>
vvc<ll> imos(const vvc<t>&a){
	int n=si(a),m=si(a[0]);
	vvc<ll> b(n+1,vc<ll>(m+1));
	rep(i,n)rep(j,m)
		b[i+1][j+1]=b[i+1][j]+b[i][j+1]-b[i][j]+a[i][j];
	return b;
}

//verify してないや
void transvvc(int&n,int&m){
	swap(n,m);
}
template<class t,class... Args>
void transvvc(int&n,int&m,vvc<t>&a,Args&...args){
	assert(si(a)==n);
	vvc<t> b(m,vi(n));
	rep(i,n){
		assert(si(a[i])==m);
		rep(j,m)b[j][i]=a[i][j];
	}
	a.swap(b);
	transvvc(n,m,args...);
}
//CF854E
void rotvvc(int&n,int&m){
	swap(n,m);
}
template<class t,class... Args>
void rotvvc(int&n,int&m,vvc<t>&a,Args&...args){
	assert(si(a)==n);
	vvc<t> b(m,vi(n));
	rep(i,n){
		assert(si(a[i])==m);
		rep(j,m)b[m-1-j][i]=a[i][j];
	}
	a.swap(b);
	rotvvc(n,m,args...);
}

//ソートして i 番目が idx[i]
//CF850C
template<class t>
vi sortidx(const vc<t>&a){
	int n=si(a);
	vi idx(n);iota(all(idx),0);
	sort(all(idx),[&](int i,int j){return a[i]<a[j];});
	return idx;
}
//vs[i]=a[idx[i]]
//例えば sortidx で得た idx を使えば単にソート列になって返ってくる
//CF850C
template<class t>
vc<t> a_idx(const vc<t>&a,const vi&idx){
	int n=si(a);
	assert(si(idx)==n);
	vc<t> vs(n);
	rep(i,n)vs[i]=a[idx[i]];
	return vs;
}
//CF850C
vi invperm(const vi&p){
	int n=si(p);
	vi q(n);
	rep(i,n)q[p[i]]=i;
	return q;
}

template<class t,class s=t>
s SUM(const vc<t>&a){
	return accumulate(all(a),s(0));
}
ll SUM(const vi&a){
	return accumulate(all(a),ll(0));
}
template<class t,size_t K,class s=t>
s SUM(const array<t,K>&a){
	return accumulate(all(a),s(0));
}

template<class t>
t MAX(const vc<t>&a){
	return *max_element(all(a));
}

template<class t>
pair<t,int> MAXi(const vc<t>&a){
	auto itr=max_element(all(a));
	return mp(*itr,itr-a.bg);
}

template<class A>
auto MIN(const A&a){
	return *min_element(all(a));
}

template<class t>
pair<t,int> MINi(const vc<t>&a){
	auto itr=min_element(all(a));
	return mp(*itr,itr-a.bg);
}

vi vid(int n){
	vi res(n);iota(all(res),0);
	return res;
}

template<class S>
void soin(S&s){
	sort(all(s));
}

template<class S,class F>
void soin(S&s,F&&f){
	sort(all(s),forward<F>(f));
}

template<class S>
S soout(S s){
	soin(s);
	return s;
}

template<class S>
void rein(S&s){
	reverse(all(s));
}

template<class S>
S reout(S s){
	rein(s);
	return s;
}

template<class t,class u>
pair<t,u>&operator+=(pair<t,u>&a,pair<t,u> b){
	a.a+=b.a;a.b+=b.b;return a;}
template<class t,class u>
pair<t,u>&operator-=(pair<t,u>&a,pair<t,u> b){
	a.a-=b.a;a.b-=b.b;return a;}
template<class t,class u>
pair<t,u> operator+(pair<t,u> a,pair<t,u> b){return mp(a.a+b.a,a.b+b.b);}
template<class t,class u>
pair<t,u> operator-(pair<t,u> a,pair<t,u> b){return mp(a.a-b.a,a.b-b.b);}
template<class t,class u,class v>
pair<t,u>&operator*=(pair<t,u>&a,v b){
	a.a*=b;a.b*=b;return a;}
template<class t,class u,class v>
pair<t,u> operator*(pair<t,u> a,v b){return a*=b;}
template<class t,class u>
pair<t,u> operator-(pair<t,u> a){return mp(-a.a,-a.b);}
namespace std{
template<class t,class u>
istream&operator>>(istream&is,pair<t,u>&a){
	return is>>a.a>>a.b;
}
}

template<class t,size_t n>
array<t,n>&operator+=(array<t,n>&a,const array<t,n>&b){
	rep(i,n)a[i]+=b[i];
	return a;
}
template<class t,size_t n>
array<t,n>&operator-=(array<t,n>&a,const array<t,n>&b){
	rep(i,n)a[i]-=b[i];
	return a;
}
template<class t,size_t n,class v>
array<t,n>&operator*=(array<t,n>&a,v b){
	rep(i,n)a[i]*=b;
	return a;
}
template<class t,size_t n>
array<t,n> operator+(array<t,n> a,const array<t,n>&b){return a+=b;}
template<class t,size_t n>
array<t,n> operator-(array<t,n> a,const array<t,n>&b){return a-=b;}
template<class t,size_t n,class v>
array<t,n> operator*(array<t,n> a,v b){return a*=b;}

template<class t>
t gpp(vc<t>&vs){
	assert(si(vs));
	t res=move(vs.back());
	vs.pop_back();
	return res;
}

template<class t,class u>
void pb(vc<t>&a,const vc<u>&b){
	a.insert(a.ed,all(b));
}

template<class t,class...Args>
vc<t> cat(vc<t> a,Args&&...b){
	(pb(a,forward<Args>(b)),...);
	return a;
}

template<class t,class u>
vc<t>& operator+=(vc<t>&a,u x){
	for(auto&v:a)v+=x;
	return a;
}

template<class t,class u>
vc<t> operator+(vc<t> a,u x){
	return a+=x;
}

template<class t>
vc<t>& operator+=(vc<t>&a,const vc<t>&b){
	a.resize(max(si(a),si(b)));
	rep(i,si(b))a[i]+=b[i];
	return a;
}

template<class t>
vc<t> operator+(const vc<t>&a,const vc<t>&b){
	vc<t> c(max(si(a),si(b)));
	rep(i,si(a))c[i]+=a[i];
	rep(i,si(b))c[i]+=b[i];
	return c;
}

template<class t,class u>
vc<t>& operator-=(vc<t>&a,u x){
	for(auto&v:a)v-=x;
	return a;
}
template<class t,class u>
vc<t> operator-(vc<t> a,u x){
	return a-=x;
}
template<class t>
vc<t>& operator-=(vc<t>&a,const vc<t>&b){
	a.resize(max(si(a),si(b)));
	rep(i,si(b))a[i]-=b[i];
	return a;
}
template<class t>
vc<t> operator-(const vc<t>&a,const vc<t>&b){
	vc<t> c(max(si(a),si(b)));
	rep(i,si(a))c[i]+=a[i];
	rep(i,si(b))c[i]-=b[i];
	return c;
}
template<class t,class u>
vc<t>& operator*=(vc<t>&a,u x){
	for(auto&v:a)v*=x;
	return a;
}
template<class t,class u>
vc<t> operator*(vc<t> a,u x){
	return a*=x;
}

template<class t,class u>
vc<t>& operator/=(vc<t>&a,u x){
	for(auto&v:a)v/=x;
	return a;
}
template<class t,class u>
vc<t> operator/(vc<t> a,u x){
	return a/=x;
}

template<class t>
vc<t>& operator<<=(vc<t>&a,int k){
	assert(k>=0);
	a.insert(a.bg,k,t(0));
	return a;
}
template<class t>
vc<t> operator<<(vc<t> a,int k){
	return a<<=k;
}

template<class t>
vc<t>& operator>>=(vc<t>&a,int k){
	if(si(a)<=k)a.clear();
	else a.erase(a.bg,a.bg+k);
	return a;
}
template<class t>
vc<t> operator>>(vc<t> a,int k){
	return a>>=k;
}

//消した要素の個数を返してくれる
//not verified
template<class t,class u>
int remval(vc<t>&a,const u&v){
	auto itr=remove(all(a),v);
	int res=a.ed-itr;
	a.erase(itr,a.ed);
	return res;
}
//消した要素の個数を返してくれる
//UCUP 2-8-F
template<class t,class F>
int remif(vc<t>&a,F f){
	auto itr=remove_if(all(a),f);
	int res=a.ed-itr;
	a.erase(itr,a.ed);
	return res;
}
template<class t>
void rempos(vc<t>&a,int i){
	assert(inc(0,i,si(a)-1));
	a.erase(a.bg+i);
}

template<class VS,class u>
void fila(VS&vs,const u&a){
	fill(all(vs),a);
}

template<class t,class u>
int findid(const vc<t>&vs,const u&a){
	auto itr=find(all(vs),a);
	if(itr==vs.ed)return -1;
	else return itr-vs.bg;
}

template<class t>
void rtt(vc<t>&vs,int i){
	rotate(vs.bg,vs.bg+i,vs.ed);
}

//Multiuni2023-8 C
//f(lw)=false,...,f(n-1)=false,f(n)=true,...,f(up)=true,
//のときに n を返す
template<class F>
ll find_min_true(ll lw,ll up,F f){
	while(up-lw>1){
		const ll mid=(lw+up)/2;
		if(f(mid))up=mid;
		else lw=mid;
	}
	return up;
}
//f(lw)=true,f(up)=false
template<class F>
ll find_max_true(ll lw,ll up,F f){
	while(up-lw>1){
		const ll mid=(lw+up)/2;
		if(f(mid))lw=mid;
		else up=mid;
	}
	return lw;
}

template<class t> using pqmin=priority_queue<t,vc<t>,greater<t>>;
template<class t> using pqmax=priority_queue<t>;
using T=tuple<int,int,int>;

std::vector<int> add_numbers(std::vector<int> A, int K, int M) {
	dmp2(A,K);
	int n=si(A);
	soin(A);
	ll V=find_min_true(MAX(A)-1,SUM(A),[&](ll v){
		int res=0;
		for(int i=0;i<n;){
			ll s=0;
			while(i<n&&s+A[i]<=v){
				s+=A[i++];
			}
			res++;
		}
		return res<=K;
	});
	dmp(V);
	vi pre(K+1),suf(K+1);
	{
		int i=0;
		pre[0]=0;
		rep(step,K){
			ll s=0;
			while(i<n&&s+A[i]<=V){
				s+=A[i++];
			}
			pre[step+1]=i;
		}
	}
	dmp(pre);
	{
		int i=n;
		suf[K]=n;
		per(step,K){
			ll s=0;
			while(i>0&&s+A[i-1]<=V-1){
				s+=A[--i];
			}
			suf[step]=i;
		}
	}
	dmp(suf);
	int f=-1;
	rep(i,K+1)if(pre[i]==suf[i]){
		f=i;
		break;
	}
	assert(f!=-1);
	vi res;
	rep(i,K){
		int l,r;
		if(i<f){
			l=pre[i],r=pre[i+1];
		}else{
			l=suf[i],r=suf[i+1];
		}
		ll s=0;
		rng(j,l,r)s+=A[j];
		if(s<V)res.pb(V-s);
	}
	return res;
}

std::vector<int> find_partition(std::vector<int> B, int K){
	int n=si(B);
	ll tot=SUM(B);
	assert(tot%K==0);
	ll tar=tot/K;
	multiset<int> avail(all(B));
	vc<pi> buf;
	rep(step,K){
		ll s=0;
		vi ls;
		while(si(avail)){
			auto itr=prev(avail.ed);
			if(s+*itr<=tar){
				s+=*itr;
				ls.pb(*itr);
				avail.erase(itr);
			}else{
				break;
			}
		}
		if(s<tar){
			int need=tar-s;
			auto itr=avail.find(need);
			assert(itr!=avail.ed);
			s+=*itr;
			ls.pb(*itr);
			avail.erase(itr);
		}
		assert(s==tar);
		for(auto v:ls)buf.eb(v,step);
	}
	soin(buf);
	vi ans(n);
	rep(i,n)ans[i]=buf[i].b;
	return ans;
}
