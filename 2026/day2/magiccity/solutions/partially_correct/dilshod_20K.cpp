#include "magiccity.h"
#include <bits/stdc++.h>

using namespace std;

pair<vector<int>, vector<pair<int, int>>> construct(int K) {
    vector<vector<int>> comp(6);
    for (int i = 0; i < 2 * K; i++){
        comp[i % 6].push_back(i);
    }

    vector<int> T;
    vector<pair<int, int>> E;

    auto add_clique = [&](vector<int> A){
        for (int i : A){
            for (int j : A){
                if (i < j) E.emplace_back(i, j);
            }
        }
    };

    auto add_bipartite = [&](vector<int> A, vector<int> B){
        for (int i : A){
            for (int j : B){
                E.emplace_back(i, j);
            }
        }
    };

    for (int x = 0; x < 6; x++){
        for (int y = x + 1; y < 6; y++){
            for (int z = y + 1; z < 6; z++){
                
                vector<int> X, Y, Z;
                for (int i : comp[x]){
                    X.push_back((int) T.size());
                    T.push_back(i);
                }
                for (int i : comp[y]){
                    Y.push_back((int) T.size());
                    T.push_back(i);
                }
                for (int i : comp[z]){
                    Z.push_back((int) T.size());
                    T.push_back(i);
                }

                add_clique(X);
                add_clique(Y);
                add_clique(Z);
                
                add_bipartite(X, Y);
                add_bipartite(X, Z);
                add_bipartite(Y, Z);
            }
        }   
    }

    return {T, E};
}
