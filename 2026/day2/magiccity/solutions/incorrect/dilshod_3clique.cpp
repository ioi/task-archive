#include "magiccity.h"
#include <bits/stdc++.h>

using namespace std;

pair<vector<int>, vector<pair<int, int>>> construct(int K) {
    K *= 2;

    vector<vector<int>> comp;
    for (int a = 0; a < K; a++){
        for (int b = a + 1; b < K; b++){
            for (int c = b + 1; c < K; c++){
                comp.push_back({a, b, c});
            }
        }
    }
    int N = (int) comp.size() * 3;

    vector<int> T(N);
    vector<pair<int, int>> E;
    for (int i = 0; i < N; i++){
        T[i] = i % K;
    }

    vector<int> nxt(K);
    for (int i = 0; i < K; i++) nxt[i] = i;

    for (vector<int> p : comp){
        for (int i = 0; i < 3; i++){
            E.emplace_back(nxt[p[i]], nxt[p[(i + 1) % 3]]);
        }
        for (int i = 0; i < 3; i++){
            nxt[p[i]] += K;
        }
    }

    return {T, E};
}
