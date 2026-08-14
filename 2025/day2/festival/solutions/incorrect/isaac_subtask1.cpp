// solution/isaac_subtask1.cpp
// {
//   "verdict": "incorrect",
//   "except": {
//     "subtask1": "correct"
//   }
// }
// END HEADER
// 1 <= T[i] <= 1
// complexity: N log(N)

#include "festival.h"
#include <bits/stdc++.h>
#define sz(v) (int)v.size()
using namespace std;
typedef long long ll;
const ll inf = 1e15;

vector<int> max_coupons(int A, vector<int> P, vector<int> T){
    int N = P.size();
    vector<pair<int, int>> Sorted;

    for (int i = 0; i < N; i++){
        Sorted.push_back({P[i], i});
    }

    sort(Sorted.begin(), Sorted.end());

    vector<int> result;
    for(auto i : Sorted){
        if(i.first <= A){
            A -= i.first;
            result.push_back(i.second);
        }
    }
    return result;
}
