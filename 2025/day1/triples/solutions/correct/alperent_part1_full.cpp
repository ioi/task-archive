#include <bits/stdc++.h>
#include "triples.h"

using namespace std;

int get_max_last(vector<int> h){
    int n = h.size();
    int ans = 0;

    for(int k = 0; k < n; k++){
        int i = k - h[k];

        if(i >= 0){
            int j1 = i + h[i], j2 = k - h[i];

            if(i < j1 && j1 < k && h[j1] == h[k] - h[i]) ans++;
            if(j1 != j2 && i < j2 && j2 < k && h[j2] == h[k] - h[i]) ans++;
        }
    }

    return ans;
}

int get_max_first(vector<int> h){
    reverse(h.begin(), h.end());

    return get_max_last(h);
}

int get_max_mid_easy_variant(vector<int> h){
    int n = h.size();
    int ans = 0;

    for(int i = 0; i < n; i++){
        int j = i + h[i];

        if(j < n){
            int k = i + h[j];

            if(k < n){
                if(h[k] == k - j) ans++;
            }
        }
    }

    return ans;
}

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

using hash_mp = gp_hash_table<int, bool>;

long long get_max_mid_hard_variant(vector<int> h){
    int n = h.size();
    long long ans = 0;

    hash_mp left[n * 3], right[n * 3];
    vector<int> leftvec[n * 3], rightvec[n * 3];

    for(int i = 0; i < n; i++){
        int leftval = h[i] - i + n, rightval = h[i] + i + n;

        left[leftval][i] = true;
        leftvec[leftval].push_back(i);

        right[rightval][i] = true;
        rightvec[rightval].push_back(i);
    }

    for(int j = 0; j < n; j++){
        int leftval = h[j] - j + n, rightval = h[j] + j + n;

        if(leftvec[leftval].size() < rightvec[rightval].size()){
            for(auto i : leftvec[leftval]){
                if(right[rightval].find(i + h[j]) != right[rightval].end()) ans++;
            }
        }
        else{
            for(auto k : rightvec[rightval]){
                if(left[leftval].find(k - h[j]) != left[leftval].end()) ans++;
            }
        }
    }

    return ans;
}

int get_max_mid_duplicate(vector<int> h){
    int n = h.size();
    int ans = 0;

    for(int j = 0; j < n; j++){
        if(h[j] % 2 == 0){
            int i = j - h[j] / 2, k = j + h[j] / 2;

            if(i >= 0 && k < n && h[i] == h[j] / 2 && h[k] == h[j] / 2) ans++;
        }
    }

    return ans;
}

long long count_triples(vector<int> h){
    return get_max_first(h) + get_max_last(h) + get_max_mid_easy_variant(h) + get_max_mid_hard_variant(h) - get_max_mid_duplicate(h);
}

vector<int> construct_range(int M, int K){
    return {};
}
