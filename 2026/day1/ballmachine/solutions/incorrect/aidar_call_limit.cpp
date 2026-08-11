#include "bits/stdc++.h"

#include "ballmachine.h"

using namespace std;

const int MAXC = 1000;

vector< int > find_structure(int m) {
    int cnt = 0;

    for (int i = 0; i < MAXC; i++) {
        for (int j = 0; j < m; j++) {
            while (insert(j, 0)) {
                cnt ++;
            }
            cnt++;
        }

        collect();
    }

    // cerr << cnt << endl;

    return {};
}
