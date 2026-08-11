#include "ballmachine.h"
#include <bits/stdc++.h>
using namespace std;

/*
argument:
    edges of the return tree

output:
    parent array of the same return tree structure, with root labeled N-1
*/
vector<int> convert_edges_to_parents(vector<pair<int, int>> edges) {
    int N = (int)edges.size() + 1;
    vector<int> par(N, -1); 

    for (int i = 0; i < N - 1; i++) {
        auto [U, P] = edges[i]; 
        assert(0 <= U < N && 0 <= P < N);
        assert(par[U] == -1); 
        par[U] = P; 
    }

    int root = N - 1;
    for (int i = 0; i < N; i++) {
        if (par[i] == -1) {
            root = i; 
        }
    }

    if (root != N - 1){ 
        par[root] = par[N - 1]; 
        par[N - 1] = -1;
        for (int i = 0; i < N; i++) {
            if (par[i] == root) {
                par[i] = N - 1; 
            } else if (par[i] == N - 1) {
                par[i] = root;
            }
        }
    }

    par.pop_back();
    return par; 
}


vector< int > find_structure(int M) {
	int n=0;
	vector<int> len(M,0);
	vector<pair<int,int>> lab(M);
	vector<int> va,vb;
	for (int i=0;i<M;i++) {
		int cnt=0;
		while (insert(i,0)) cnt++,n++;
		len[i]=cnt;
		if (cnt>=2) va.push_back(i);
		else vb.push_back(i);
	}
	collect();
	if (n==1) {
		return {};
	}
	int sa=1;
	int A=va.size();
	while (sa*sa<A) sa++;
	int ls=0;
	vector<vector<int>> g(sa,vector<int>(sa,-1));
	for (int i=0;i<M;i++) if (len[i]>=2) {
		lab[i]=make_pair(ls/sa,ls%sa);
		g[ls/sa][ls%sa]=i;
		insert(i,lab[i].first);
		for (int j=0;j<len[i]-2;j++) {
			insert(i,sa);
		}
		insert(i,lab[i].second+sa+1);
		ls++;
	}

	int C=sa,z=M,pos=0;
	bool fr=0;
	vector<pair<int,int>> sig,eg;
	vector<vector<int>> lch(M);
	vector<int> qlab(n);
	vector<int> seq;
	function<int()> dfs=[&]() {
		int x=seq[pos++];
		int h=z++;
		int cur=h;
		vector<int> ch;
		ch.push_back(cur);
		while (1) {
			if (seq[pos]<C) {
				if (seq[pos]<sa) { // 新的开头
					int v=dfs();
					if (fr==0) eg.push_back(make_pair(cur,v));
				} else {
					int lefid=seq[pos++]-sa;
					sig.push_back(make_pair(cur,lefid));
				}
			} else if (seq[pos]==C) {
				pos++;
				int nxt=z++;
				if (fr==0) eg.push_back(make_pair(cur,nxt));
				ch.push_back(nxt);
				cur=nxt;
			} else {
				int y=seq[pos]-C-1;
				pos++;
				assert(x<sa&&y<sa&&g[x][y]!=-1);
				int lef=g[x][y];
				ch.push_back(lef);
				assert(ch.size()==len[lef]);
				if (fr==0) {
					lch[lef]=ch;
					eg.push_back(make_pair(cur,lef));
				} else {
					for (int i=0;i<lch[lef].size();i++) {
                        qlab[ch[i]] = ch[i]; 
						// qlab[ch[i]]=lch[lef][i];
					}
				}
				break;
			}
		}
		return h;
	};

    for (auto x : seq) {
        cerr << x << " ";
    } cerr << endl; 

	seq=collect();

	dfs();
	int sb=0;
	while (sb*sb<vb.size()) sb++;
	for (int k=0;k<sb;k++) {
		int l=k*sb,r=(k+1)*sb-1;
		r=min<int>(r,vb.size()-1);
		if (l>r) continue;
		int bat=r-l+1;
		C=sa+bat;
		for (int i=0;i<M;i++) if (len[i]>=2) {
			auto [x,y]=lab[i];
			g[x][y]=i;
			insert(i,x);
			for (int j=0;j<len[i]-2;j++) {
				insert(i,C);
			}
			insert(i,y+C+1);
		}
		for (int j=l;j<=r;j++) {
			insert(vb[j],sa+j-l);
		}
		fr=1;
		sig.clear();
		z=M;
		pos=0;
		seq=collect();
		dfs();
		for (auto [x,y]:sig) {
			eg.push_back(make_pair(qlab[x],vb[y+l]));
		}
	}

    // return eg;

    vector<pair<int, int>> tmp;

    for (auto [x, y] : eg) {
        tmp.push_back({y, x}); 
    }
    return convert_edges_to_parents( tmp ); 

    // cerr << sa << " " << sb << "\n";
	// return eg;
}
