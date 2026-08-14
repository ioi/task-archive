// solution/zein_Z4_M8.cpp
// {
//   "verdict": "model_solution"
// }
// END HEADER
#include "migrations.h"
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;

struct Phase{
    int m,b,k, start;
    bool tri;
    Phase(int _m, int _b,int _k, int _s, bool _tri): m(_m), b(_b), k(_k), start(_s), tri(_tri){}
};

vector<Phase> phases;

int Nglob;

int pickB(int m) {
    int best_b = 1;
    int best_f = INT_MAX;
    int limit = (int)(2 * cbrt((double)(m+1))) + 2;
    for (int b = 1; b <= limit; ++b) {
        int term1 = (m + 1 + b - 1) / b;            
        int term2 = ((b*b - 1) + 4 - 1) / 4;        
        int f     = term1 + term2 - 1;
        if (f < best_f) {
            best_f = f;
            best_b = b;
        }
    }
    return best_b;
}

int pickBFirst(int m){
     int best_b=1, best_f=INT_MAX;
    int limit = 2*cbrt((double)(m+1))+2;
    for(int b=1;b<=limit;++b){
      int t1 = (m+1 + b-1)/b;
      int states = b*(b+1)/2;
      int t2 = ((states-1) + 4-1)/4;
      int f  = t1 + t2 - 1;
      if(f<best_f){ best_f=f; best_b=b; }
    }
    return best_b;
}

void calculateCandidates(vector<Phase>& phase) {
  for(int i=4;i<Nglob-3;++i){
    phase.clear();
    int m=i-1, pos=i-1;
    bool first = true;

    while(pos < Nglob-3 && phase.size()<5){
        int b = first ? pickBFirst(m) : pickB(m);
        int k = first
            ? ((b*(b+1)/2 -1) + 4-1)/4
            : ((b*b    -1) + 4-1)/4;
        phase.emplace_back(m,b,k,pos, first);
        m   = (m + b - 1)/b + k - 1;
        pos += k;
        first = false;
    }
    reverse(phase.begin(), phase.end());

    if(pos==Nglob-3 && phase.size()==5 && m<=4)
      break;
  }
}

vi sliceCandidates(const vi &C,int bu,int b){
    int s = bu*b, e = min((int)C.size(), s+b);
    return vi(C.begin()+s, C.begin()+e);
}

vi candP, candQ;
pair<int,int> delayed; 
int previous;

vector<vi> G;
int bfs_far(int src,int N){
    vi dist(N,-1); queue<int>q;
    dist[src]=0; q.push(src);
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int v:G[u]) if(dist[v]<0){
            dist[v]=dist[u]+1;
            q.push(v);
        }
    }
    return max_element(dist.begin(),dist.end())-dist.begin();
}
pair<int,int> getDiameter(int N){
    int u=bfs_far(0,N);
    int v=bfs_far(u,N);
    return {u,v};
}

bool same(ii a,ii b){
    if(a.first>a.second) swap(a.first, a.second);
    if(b.first>b.second) swap(b.first, b.second);
    return a==b;
}

int P1,P2,Q1,Q2,Q3;
int R1,R2,R3;

int lastU,lastV;

int send_message(int N, int i, int p) {

    if(N<=9){
        if(i==1){
            G.assign(N,{});
            lastU=0;
            lastV=1;
        } 
        G[i].push_back(p);
        G[p].push_back(i);
        if(i>=2){
            auto [u,v] = getDiameter(N);
            if(u>v) swap(u,v);
            int mes;
            if      (u==lastU && v==lastV) mes = 0;
            else if (v!= lastV && u==lastU) mes = 1;
            else mes = 2;
            lastU=u;
            lastV=v;
            return mes;
        }
        return 0;
    }

    if(i==1){
        Nglob = N;
        G.assign(N, {});

        calculateCandidates(phases);

        candP.clear(); candQ.clear();
        candP.push_back(0);
        candQ.push_back(0);
        delayed = {-1,-1};
    }

    G[i].push_back(p);
    G[p].push_back(i);
    if(i<N-3){
        candP.push_back(i); candQ.push_back(i);
    }

    if(i == phases.back().start){
        auto [u,v] = getDiameter(N);
        Phase actual = phases.back();

        if(find(candP.begin(), candP.end(), u) == candP.end() ||  find(candQ.begin(), candQ.end(), v)==candQ.end())
            swap(u,v);

        int idU = find(candP.begin(), candP.end(), u) - candP.begin();
        int idV = find(candQ.begin(), candQ.end(), v) - candQ.begin();

        int blockSize=ceil((double)actual.m/(double)actual.b);

        int blockU = idU/blockSize, blockV = idV/blockSize;

        candP = sliceCandidates(candP, blockU, blockSize);
        candQ = sliceCandidates(candQ, blockV, blockSize);

        if(actual.tri){
            if(u>v) {
                swap(u,v);
                swap(candP,candQ);
                swap(blockU, blockV);
            }
            int B = actual.b;
            int index = 0;
            for (int bu = 0; bu < blockU; ++bu)
                index += (B - bu);
            index += (blockV-blockU);

            if (index >= 0) {
                int raw = index-1;
                int card = i + raw / 4;
                int num  = (raw % 4) + 1;
                delayed  = { card, num };
            }
        }
        else{
            int cells = blockU * actual.b + blockV;
            if(cells!=0){
                int card = i + (cells-1) / 4;
                int num = ((cells-1) % 4)+1;
                delayed = {card, num};
            }
        }

        phases.pop_back();
    }

    if(i == delayed.first){
        return delayed.second;
    }

    if(i==N-3){
        while(candP.size()<4) candP.push_back(0);
        while(candQ.size()<4) candQ.push_back(0);
        int p1=candP[0], p2=candP[1], p3=candP[2], p4=candP[3];
        int q1=candQ[0], q2=candQ[1], q3=candQ[2], q4=candQ[3];
    
        vector<ii> cand = {
            ii(p1,q1), ii(p1,q2), ii(p1,q3), ii(p2, q1), ii(p2,q2),
            ii(p1,q4), ii(p1,i), ii(p2,q3), ii(p2, q4), ii(p2,i),
            ii(p3,q1), ii(p3,q2), ii(p4,q1), ii(p4, q2), ii(i,q1),
            ii(p3,q3), ii(p3,q4), ii(p3,i), ii(p4, q4), ii(p4,i),
            ii(p4,q3), ii(i,q2), ii(i,q3), ii(i, q4)
        };
        auto [u,v] = getDiameter(Nglob);
        if(find(cand.begin(),cand.end(), ii(u,v))==cand.end())
            swap(u,v);
        int id = find(cand.begin(), cand.end(), ii(u,v)) - cand.begin();
        int label = id/5;
        previous = label;
        return previous;
    }

    if(i==N-2){
        int a1=candP[0], a2=candP[1], a3=candP[2], a4=candP[3];
        int b1=candQ[0], b2=candQ[1], b3=candQ[2], b4=candQ[3];
        
        if(previous == 0){
            P1=a1; P2=a2; Q1=b1; Q2=b2; Q3=b3;
        }
        if(previous == 1){
            P1=a2; P2=a1; Q1=i-1; Q2=b4; Q3=b3;
        }
        if(previous == 2){
            P1=b1; P2=b2; Q1=a3; Q2=a4; Q3=i-1;
        }
        if(previous == 3){
            P1=a3; P2=a4; Q1=i-1; Q2=b4; Q3=b3;
        }
        if(previous == 4){
            P1=i-1; P2=a4; Q1=b2; Q2=b3; Q3=b4;
        }

        vector<ii> cand = {
            ii(P1, Q1), ii(P2, Q1),
            ii(P1, Q2), ii(P2,Q2),
            ii(P1, Q3), ii(i, Q3),
            ii(i, Q1), ii(i, Q2),
            ii(P1,i), ii(P2,i)
        };
        auto [u,v] = getDiameter(Nglob);
        if(find(cand.begin(),cand.end(), ii(u,v))==cand.end())
            swap(u,v);
        int id = find(cand.begin(), cand.end(), ii(u,v)) - cand.begin();
        int label = id/2;
        previous = label;
        return previous;
    }

    if(i==N-1){
        int r1=0,r2=0,r3=0;
        if(previous == 0){
            r3=Q1; r2=P1; r1=P2;
        }
        if(previous == 1) {
            r3=Q2; r2=P1; r1=P2;
        }
        if(previous == 2) {
            r3=Q3; r2=P1; r1=N-2;
        }
        if(previous == 3){
            r3=N-2; r2=Q1; r1=Q2;
        }
        if(previous == 4){
            r3=N-2; r2=P1; r1=P2; 
        }
        auto [u,v] = getDiameter(Nglob);
        if(same(ii(u,v), ii(r1,r3))) return 0;
        if(same(ii(u,v), ii(r2,r3))) return 1;
        if(same(ii(u,v), ii(r1,i))) return 2;
        if(same(ii(u,v), ii(r2,i))) return 3;
        if(same(ii(u,v), ii(r3,i))) return 4;        
    }
    return 0;
}

pair<int,int> longest_path(vector<int> S) {

    int N = S.size(); Nglob=S.size();

    if(N<=9){
        int u=0,v=1;
        for(int i=1;i<N;i++){
            int p=S[i];
            if(p==1) v=i;
            if(p==2){
                u=v;
                v=i;
            }
        }
        return {u,v};
    }

    candP.clear(); candQ.clear();
    calculateCandidates(phases);

    int pos=0;

    while(!phases.empty()){
        Phase phase = phases.back();
        while(pos!=phase.start+1){
            candP.push_back(pos);
            candQ.push_back(pos);
            pos++;
        }

        int c=0, message=-1;
        for(int i=pos-1;i<pos+phase.k-1;i++){
            if(S[i]!=0){
                message=S[i];
                break;
            }
            c++;
        }
        int cells = (message==-1)? 0 : (c*4+message);
        int blockU=0, blockV=0;

        int blockSize=ceil((double)phase.m/(double)phase.b);
        if(phase.tri){
            int B = phase.b;
            cells++;
            for (int u = 0; u < B; ++u) {
                int row = B - u;
                if (cells <= row) {
                    blockU = u;
                    blockV = u + (cells - 1);
                    break;
                }
                cells -= row;
            }
        }
        else{
            blockU = cells/phase.b; blockV = cells%phase.b;
        }
        candP = sliceCandidates(candP, blockU, blockSize);
        candQ = sliceCandidates(candQ, blockV, blockSize);

        for(int i=pos;i<pos+phase.k-1;i++){
            candP.push_back(i);
            candQ.push_back(i);
        }
        pos=pos+phase.k-1;

        phases.pop_back();    
    }

    while(candP.size()<4) candP.push_back(0);
    while(candQ.size()<4) candQ.push_back(0);

    int a1=candP[0], a2=candP[1], a3=candP[2], a4=candP[3];
    int b1=candQ[0], b2=candQ[1], b3=candQ[2], b4=candQ[3];

    if(S[N-3] == 0){
        P1=a1; P2=a2; Q1=b1; Q2=b2; Q3=b3;
    }
    if(S[N-3] == 1){
        P1=a2; P2=a1; Q1=N-3; Q2=b4; Q3=b3;
    }
    if(S[N-3] == 2){
        P1=b1; P2=b2; Q1=a3; Q2=a4; Q3=N-3;
    }
    if(S[N-3] == 3){
        P1=a3; P2=a4; Q1=N-3; Q2=b4; Q3=b3;
    }
    if(S[N-3] == 4){
        P1=N-3; P2=a4; Q1=b2; Q2=b3; Q3=b4;
    }

    int r1 = 0, r2 = 0, r3 = 0;
    if(S[N-2] == 0){
        r3=Q1; r2=P1; r1=P2;
    }
    if(S[N-2] == 1) {
        r3=Q2; r2=P1; r1=P2;
    }
    if(S[N-2] == 2) {
        r3=Q3; r2=P1; r1=N-2;
    }
    if(S[N-2] == 3){
        r3=N-2; r2=Q1; r1=Q2;
    }
    if(S[N-2] == 4){
        r3=N-2; r2=P1; r1=P2; 
    }
    if(S[N-1] == 0) return {r1,r3};
    if(S[N-1] == 1) return {r2,r3};
    if(S[N-1] == 2) return {r1,N-1};
    if(S[N-1] == 3) return {r2,N-1};
    if(S[N-1] == 4) return {r3,N-1};
    
    return {0, 0};
}

