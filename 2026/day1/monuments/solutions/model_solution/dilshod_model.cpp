/* Model solution
 * Author: Dilshodbek Khujaev
 * Complexity: O(N*logN)
 */

#include "monuments.h"
#include <cmath>
#include <vector>
#include <cassert>
#include <numeric>
#include <algorithm>

using namespace std;

static const long long INF = (long long)1e16;
static const int RED = 0;  // old
static const int BLUE = 1; // new

template<typename T>
struct fenwick{
    vector<T> f;
    fenwick(int n){
        f.resize(n + 2);
    }
    fenwick(){};

    void add(int i, T val){
        i++;
        while (i < (int)f.size()){
            f[i] += val;
            i += -i & i;
        }
    }

    T get(int i){
        i++;
        T res = 0;
        while (i > 0){
            res += f[i];
            i -= -i & i;
        }
        return res;
    }

    T get(int l, int r){
        if (l > r) return 0;
        return get(r) - get(l - 1);
    }
};

struct monument{
    int x, c;
    monument(){x = 0, c = 0;};
    monument(int _x, int _c){x = _x, c = _c;};
};

struct query{
    int x, y, k;
    query(){x = 0, y = 0, k = 0;};
    query(int _x, int _y, int _k){x = _x, y = _y, k = _k;};
};

vector<long long> process_queries(vector<int> red, vector<int> blue, vector<query> queries){
    int r = (int) red.size(), b = (int) blue.size(), q = (int) queries.size();

    fenwick<long long> fr(r), fb(b);
    for (int i = 0; i < r; i++){
        fr.add(i, red[i]);
    }
    for (int j = 0; j < b; j++){
        fb.add(j, -blue[j]);
    }

    vector<pair<int, int>> diff_red;
    for (int i = 0, j = 0; i < r; i++){
        while (j < b && blue[j] <= red[i]) j++;
        if (j < b) diff_red.emplace_back(j - i, i);
    }

    vector<pair<int, int>> diff_blue;
    for (int i = r - 1, j = b - 1; j >= 0; j--){
        while (i >= 0 && red[i] >= blue[j]) i--;
        diff_blue.emplace_back(j - i, j);
    }

    vector<int> ord(q);
    iota(ord.begin(), ord.end(), 0);

    sort(ord.begin(), ord.end(), [&](int i, int j){
        return queries[i].y - queries[i].x < queries[j].y - queries[j].x;
    });

    sort(diff_red.begin(), diff_red.end());
    sort(diff_blue.begin(), diff_blue.end());

    vector<long long> answer(q, 0);

    int rpos = 0, bpos = 0;
    for (int id : ord){
        auto [x, y, k] = queries[id];
        if (k == 0) continue;

        int dq = y - x;

        while (rpos < (int)diff_red.size()){            
            auto [dr, i] = diff_red[rpos];
            if (dr > dq) break;
            rpos++;
            fr.add(i, -2 * red[i]);
        }

        while (bpos < (int)diff_blue.size()){
            auto [db, j] = diff_blue[bpos];
            if (db > dq) break;
            bpos++;
            fb.add(j, 2 * blue[j]);   
        }

        answer[id] = fr.get(x, x + k - 1) + fb.get(y, y + k - 1);
    }

    return answer;
}

long long solve(vector<monument> A, vector<monument> B){
    int N = (int) A.size();

    vector<int> redA, blueA;
    vector<int> redB, blueB;

    vector<int> cnt_redA(N + 1, 0), cnt_blueA(N + 1, 0);
    vector<int> cnt_redB(N + 1, 0), cnt_blueB(N + 1, 0);
    for (int i = 0; i < N; i++){
        (A[i].c == RED ? redA : blueA).push_back(A[i].x);
        (B[i].c == RED ? redB : blueB).push_back(B[i].x);
        
        cnt_redA[i + 1] = cnt_redA[i] + (A[i].c == RED);
        cnt_blueA[i + 1] = cnt_blueA[i] + (A[i].c == BLUE);
        cnt_redB[i + 1] = cnt_redB[i] + (B[i].c == RED);
        cnt_blueB[i + 1] = cnt_blueB[i] + (B[i].c == BLUE);
    }

    vector<query> qu_AB(N + 1), qu_BA(N + 1);

    vector<int> next(N + 1, -1);
    vector<int> last(4 * N + 1, -1);
    const int offset = 2 * N;
    for (int i = N; i >= 0; i--){
        int delta = cnt_redA[i] - cnt_blueA[i] + cnt_redB[i] - cnt_blueB[i];
        if (last[offset + delta] != -1){
            next[i] = last[offset + delta];
            
            int ir, ib;

            ir = cnt_redA[i];
            ib = cnt_blueB[i];
            qu_AB[i] = query(ir, ib, cnt_redA[next[i]] - ir);

            ir = cnt_redB[i];
            ib = cnt_blueA[i];
            qu_BA[i] = query(ir, ib, cnt_redB[next[i]] - ir);
        }
        last[offset + delta] = i;
    }

    vector<long long> ans_AB = process_queries(redA, blueB, qu_AB);
    vector<long long> ans_BA = process_queries(redB, blueA, qu_BA);

    vector<long long> dp(N + 1, INF);
    dp[0] = 0;

    for (int i = 0; i < N; i++){
        if (A[i].c == BLUE && B[i].c == BLUE){
            dp[i + 1] = min(dp[i + 1], dp[i] + abs(A[i].x - B[i].x));
        }

        if (next[i] != -1){
            int j = next[i];
            long long cost = ans_AB[i] + ans_BA[i];
            dp[j] = min(dp[j], dp[i] + cost);
        }
    }

    return dp[N];
}

long long get_cost(vector<int> X, vector<int> P){
    int N = (int) X.size();
    
    vector<int> color(N, BLUE);
    for (int i : P) color[i] = RED;

    vector<int> red, blue;
    for (int i = 0; i < N; i++){
        if (color[i] == RED && X[i] != 0) red.push_back(X[i]);
        if (color[i] == BLUE) blue.push_back(X[i]);
    }

    int r = (int) red.size(), b = (int) blue.size();
    
    vector<bool> deleted(r, false);
    int j = r - 1;
    for (int i = 0; i < r; i++){
        if (red[i] > 0 || red[j] < 0) break;

        while (j > i && red[j] > -red[i]){
            j--;
        }

        if (red[j] == -red[i]){
            deleted[i] = true;
            deleted[j] = true;
            j--;
        }
    }

    vector<int> red_copy = red;
    red.clear();
    int r1 = 0;
    for (int i = 0; i < r; i++){
        if (!deleted[i]) {
            red.push_back(red_copy[i]);
            if (red_copy[i] < 0) r1++;
        }
    }

    r = (int) red.size();

    if (r > b) return -1;

    N = r + b;

    if (N % 2 == 1){
        red.insert(red.begin() + r1, 0);
        r1++;
        r++;
        N++;
    }

    int b1 = N / 2 - r1;

    int i = 0; j = 0;
    vector<monument> A, B;
    while (i < r1 || j < b1){
        if (j == b1 || (i < r1 && red[i] < blue[j])){
            A.emplace_back(-red[i], RED);
            i++;
        } else {
            A.emplace_back(-blue[j], BLUE);
            j++;
        }
    }

    reverse(A.begin(), A.end());

    assert(i == r1 && j == b1);

    while (i < r || j < b){
        if (j == b || (i < r && red[i] < blue[j])){
            B.emplace_back(red[i], RED);
            i++;
        } else {
            B.emplace_back(blue[j], BLUE);
            j++;
        }
    }

    return solve(A, B);
}