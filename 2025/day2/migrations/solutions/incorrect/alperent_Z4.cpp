// solution/alperent_Z4.cpp
// {
//   "verdict": "incorrect",
//   "except": {
//     "from_root": "correct",
//     "samples": "correct"
//   }
// }
// END HEADER
#include <bits/stdc++.h>
#include "migrations.h"

using namespace std;

const int CNT = 21;

vector<vector<int>> tree;

int n, maxdist, a, b;

int dfs(int v, int p, int x){
    if(v == x) return 0;

    for(auto e : tree[v]){
        if(e != p){
            int eans = dfs(e, v, x);

            if(eans != -1) return eans + 1;
        }
    }

    return -1;
}

int getdist(int a, int b){
    return dfs(a, -1, b);
}

int val_to_write;

int send_message(int N, int i, int p){
    if(tree.empty()){
        n = N;
        tree.assign(n, {});
    }

    tree[p].push_back(i);
    tree[i].push_back(p);

    if(n <= CNT){
        int adist = getdist(a, i), bdist = getdist(b, i);

        if(adist > maxdist){
            // b changed

            b = i;
            maxdist = adist;

            return 2;
        }
        else if(bdist > maxdist){
            // a changed

            a = i;
            maxdist = adist;

            return 1;
        }
        else return 0;
    }

    int adist = getdist(a, i), bdist = getdist(b, i);

    bool achanged = false, bchanged = false;

    if(adist > maxdist){
        // b changed

        bchanged = true;
        b = i;
        maxdist = adist;
    }
    else if(bdist > maxdist){
        // a changed

        achanged = true;
        a = i;
        maxdist = adist;
    }

    if(i < n - 21) return 0;

    if(n - 21 <= i && i <= n - 15){
        if(i == n - 21) val_to_write = a;

        if(achanged) return 4;
        else{
            int x = val_to_write % 4;
            val_to_write /= 4;

            return x;
        }
    }
    else if(n - 14 <= i){
        if(i == n - 14) val_to_write = b;

        if(bchanged) return 4;
        else{
            int x = val_to_write % 2;
            val_to_write /= 2;

            if(achanged) return x + 2;
            else return x;
        }
    }

    assert(false);
}

pair<int, int> longest_path(vector<int> S){
    n = S.size();

    if(n <= CNT){
        for(int i = 1; i < n; i++){
            if(S[i] == 1) a = i;
            else if(S[i] == 2) b = i;
        }

        return {a, b};
    }
    else{
        a = b = -1;

        int aread = 0, bread = 0;

        int pw = 1;

        for(int i = n - 21; i <= n - 15; i++){
            if(S[i] == 4) a = i;
            else aread += S[i] * pw;

            pw *= 4;
        }

        if(a == -1) a = aread;

        pw = 1;

        for(int i = n - 14; i <= n - 1; i++){
            if(S[i] == 4) b = i;
            else{
                int x = S[i];

                if(x >= 2){
                    a = i;
                    x -= 2;
                }

                bread += x * pw;
            }

            pw *= 2;
        }

        if(b == -1) b = bread;

        return {a, b};
    }
}
