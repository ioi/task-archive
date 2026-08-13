#include "magiccity.h"
#include <bits/stdc++.h>

using namespace std;

pair<vector<int>, vector<pair<int, int>>> construct(int K) {    
    vector<int> T;
    vector<pair<int, int>> E;

    int mn = 2e6;
    int sza, szb, szc;
    for (int i = 1; i < K; i++){
        int j = K - i;
        int a = (2 * K + i - 1) / i;
        int c = (2 * K + j - 1) / j;
        if (a * 2 * c < mn){
            mn = a * 2 * c;
            sza = i, szb = K, szc = j;
        }
    }

    for (int al = 0; al < 2 * K; al += sza){
        int ar = min(al + sza - 1, 2 * K - 1);
        for (int bl = 0; bl < 2 * K; bl += szb){
            int br = min(bl + szb - 1, 2 * K - 1);
            for (int cl = 0; cl < 2 * K; cl += szc){
                int cr = min(cl + szc - 1, 2 * K - 1);
                
                int nxt = (int) T.size();
                for (int i = al; i <= ar; i++) T.push_back(i);
                for (int i = bl; i <= br; i++) T.push_back(i);
                for (int i = cl; i <= cr; i++) T.push_back(i);
                
                for (int i = 0; i <= br - bl; i++){
                    int v = nxt + (ar - al + 1) + i;
                    for (int j = 0; j <= ar - al; j++){
                        E.emplace_back(v, nxt + j);
                    }
                    for (int j = 0; j <= cr - cl; j++){
                        E.emplace_back(v, nxt + (ar - al + 1) + (br - bl + 1) + j);
                    }
                }
            }
        }   
    }

    return {T, E};
}
