#include "bits/stdc++.h"

#include "ballmachine.h"
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


const int MAXN = 5005;

vector< int > find_structure(int m) {
    vector<int> d(m); 
    int sum = 0;
    
    for (int i = 0; i < m; i++) {
        while (insert(i, 0)) {
            d[i]++;
        }

        collect(); 

        sum += d[i]; 
    }

    int st = m + 1; 
    vector<int> par(sum - m + 1);
    par[m] = -1;

    for (int i = 0; i < m; i++) {
        int l = st + 1, r = st + d[i] - 3;

        for (int j = l; j <= r; j++) {
            par[j] = j - 1; 
        }

        if (d[i] >= 3) {
            par[st] = m;
            par[i] = r; 
        } else {
            par[i] = m; 
        }

        st += d[i] - 2;
    }

    vector<pair<int, int>> result; 

    for (int i = 0; i < (int)par.size(); i++) {
        if (par[i] == -1) {
            continue; 
        }

        result.push_back({i, par[i]}); 
    }

    return convert_edges_to_parents( result ); 
}

