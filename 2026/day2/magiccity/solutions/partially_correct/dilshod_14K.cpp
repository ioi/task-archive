#include "magiccity.h"
#include <bits/stdc++.h>

using namespace std;

pair<vector<int>, vector<pair<int, int>>> construct(int K) {
    vector<vector<int>> comp(8);
    for (int i = 0; i < 2 * K; i++){
        comp[i % 8].push_back(i);
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

    vector<vector<int>> groups = {
        {0, 1, 2, 3}, {0, 1, 4, 5}, 
        {0, 1, 6, 7}, {0, 2, 4, 6}, 
        {0, 2, 5, 7}, {0, 3, 4, 7}, 
        {0, 3, 5, 6}, {4, 5, 6, 7}, 
        {2, 3, 6, 7}, {2, 3, 4, 5}, 
        {1, 3, 5, 7}, {1, 3, 4, 6},
        {1, 2, 5, 6}, {1, 2, 4, 7}
    };

    for (vector<int> g : groups){
        vector<vector<int>> A(4);
        for (int i = 0; i < 4; i++){
            for (int x : comp[g[i]]){
                A[i].push_back((int) T.size());
                T.push_back(x);
            }
        }

        for (int i = 0; i < 4; i++){
            add_clique(A[i]);
        }

        for (int i = 0; i < 4; i++){
            for (int j = i + 1; j < 4; j++){
                add_bipartite(A[i], A[j]);
            }
        }

    }

    return {T, E};
}
