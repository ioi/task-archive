// solution/zein_wa_Z4_M16.cpp
// {
//   "verdict": "incorrect",
//   "except": {
//     "from_root": "correct",
//     "samples": "correct"
//   }
// }
// END HEADER
#include "migrations.h"
#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

const int MAX_N = 10000;

vector<vi> G;
vi binU, binV;
vi rem;

int u, v;
int B;

int bfs(int start, int N)
{
    vector<int> dis(N, -1);
    queue<int> q;
    q.push(start);
    dis[start] = 0;

    while (!q.empty()){
        int u = q.front();
        q.pop();
        for (auto &v : G[u]){
            if (dis[v] == -1){
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
    auto it = max_element(dis.begin(), dis.end());
    return it - dis.begin();
}

pair<int, int> getEndPoints(int N){
    int u = bfs(0, N);
    int v = bfs(u, N);
    if (u > v)
        swap(u, v);
    return {u, v};
}

vector<int> toBinary(int n){
    vector<int> bin;
    for (int i = 0; i < B; i++){
        if (n & (1 << i))
            bin.push_back(1);
        else
            bin.push_back(0);
    }
    reverse(bin.begin(), bin.end());
    return bin;
}

// For smallers N
bool freeze = 0;
int phase;

int hasChangeToU = -1;

int send_message(int N, int i, int p){
    int message=0;

    if (i == 1){
        G.resize(N);
        B = ceil(log2(N-1));
        phase = 0;
    }

    G[i].push_back(p);
    G[p].push_back(i);

    if (i >= N - B - 2){
        auto [a, b] = getEndPoints(N);
        if (!freeze){
            freeze = 1;
            binU = toBinary(a);
            binV = toBinary(b);
            u=a; v=b;
            phase = 1;
        }
        if (phase == 1){
            if (b != v){
                if (a == u){
                    rem = binU;
                    hasChangeToU = 1;
                }
                else{
                    rem = binV;
                    hasChangeToU = 0;
                }
                phase = 2;
                message = 4;
            }
            else{
                message = binU.back() + binV.back() * 2;
                binU.pop_back();
                binV.pop_back();
                if (binU.empty())
                    phase = 3;
            }
        }
        else if (phase == 2){
            if (b != v && u != a){
                hasChangeToU = -1;
                message = 4;
                phase = 3;
            }
            else{
                if (b != v)
                    message = 2;

                if (!rem.empty()){
                    message += rem.back();
                    rem.pop_back();
                }
                else{
                    message += hasChangeToU;
                    phase = 3;
                }
            }
        }
        else{
            if (a == u && v == b)
                message = 0;
            if (a == u && v != b)
                message = 1;
            if (a != u && v != b)
                message = 2;
        }
        u = a;
        v = b;
        return message;
    }
    return 0;
}

pair<int, int> longest_path(vector<int> S){
    int N = S.size();
    B = ceil(log2(N-1));
    u = 0;
    v = 0;

    int c = 0;
    int last;
    for (int i = N - B - 2; i < N; i++){
        if (S[i] == 4){
            c++;
            if (v != 0)
                swap(u, v);
            v = i;
            if (c == 2){
                last = i + 1;
                break;
            }
        }
    }
    if (c < 2){
        u = v = 0;
        phase = 1;
        int pot2 = 1;
        last = (c == 0) ? N - 2 : N;
        for (int i = N - B - 2; i < last; i++){
            if (phase == 1){
                if (S[i] == 4){
                    if (S[N - 1] % 2 == 0)
                        u = v;
                    v = i;
                    phase = 2;
                }
                else{
                    u += pot2 * (S[i] % 2);
                    v += pot2 * (S[i] / 2);
                    pot2 *= 2;
                }
            }
            else{
                if (i != N - 1){
                    u += pot2 * (S[i] % 2);
                    pot2 *= 2;
                }
                if (S[i] >= 2)
                    v = i;
            }
        }
    }

    for (int i = last; i < N; i++){
        if (S[i] == 1){
            v = i;
        }
        if (S[i] == 2){
            u = v;
            v = i;
        }
    }

    return {u, v};
}
