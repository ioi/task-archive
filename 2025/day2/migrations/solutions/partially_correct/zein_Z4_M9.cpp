// solution/zein_Z4_M9.cpp
// {
//   "verdict": "partially_correct",
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
typedef pair<int,int> ii;

struct Phase{
    int m,b,k, start;
    Phase(int _m, int _b,int _k, int _s): m(_m), b(_b), k(_k), start(_s){}
};

vector<Phase> phases;

int Nglob;

void calculateCandidates(vector<Phase> &phase){
    for(int i=2;i<Nglob-2;i++){
        phase.clear();
        int m=i-1;
        int pos=i-1;
        while(pos < Nglob-2 && phase.size()<8){
            m++;
            int b=(int)ceil(pow(m,1.0/3.0));
            int k=ceil((double)(b*b-1)/4.0);
            phase.push_back(Phase(m, b, k, pos));
            m=ceil((double)m/(double)b)+k-1;
            pos+=k;
        }
        reverse(phase.begin(), phase.end());
        if(pos==Nglob-2 && phase.size()<8)
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

int lastU, lastV;

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
    if(i<N-2){
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

        int cells = blockU * actual.b + blockV;
        if(cells!=0){
            int card = i + (cells-1) / 4;
            int num = ((cells-1) % 4)+1;
            delayed = {card, num};
        }

        phases.pop_back();

    }

    if(i == delayed.first){
        return delayed.second;
    }
    if(i==N-2){
        int p1 = candP[0], p2 = candP[1];
        int q1 = candQ[0], q2 = candQ[1];        
        vector<ii> cand = {
            ii(p1, q1), ii(p1, q2),
            ii(p2, q1), ii(p2,q2),
            ii(p1, i), ii(p2, i),
            ii(i, q1), ii(i, q2)
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
        int r1,r2,r3;
        int p1 = candP[0], p2 = candP[1];
        int q1 = candQ[0], q2 = candQ[1]; 
        if(previous == 0){
            r3=p1; r2=q1; r1=q2;
        }
        if(previous == 1) {
            r3=p2; r2=q1; r1=q2;
        }
        if(previous == 2) {
            r3=N-2; r2=p1; r1=p2;
        }
        if(previous == 3){
            r3=N-2; r2=q1; r1=q2;
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

    bool read = 0;
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

        int blockSize=ceil((double)phase.m/(double)phase.b);
        int blockU = cells/phase.b, blockV = cells%phase.b;

        candP = sliceCandidates(candP, blockU, blockSize);
        candQ = sliceCandidates(candQ, blockV, blockSize);

        for(int i=pos;i<pos+phase.k-1;i++){
            candP.push_back(i);
            candQ.push_back(i);
        }
        pos=pos+phase.k-1;

        phases.pop_back();
    }

    int p1 = candP[0], p2 = candP[1];
    int q1 = candQ[0], q2 = candQ[1]; 
    int r1,r2,r3;
    
    if(S[N-2] == 0){
        r3=p1; r2=q1; r1=q2;
    }
    if(S[N-2] == 1) {
        r3=p2; r2=q1; r1=q2;
    }
    if(S[N-2] == 2) {
        r3=N-2; r2=p1; r1=p2;
    }
    if(S[N-2] == 3){
        r3=N-2; r2=q1; r1=q2;
    }

    if(S[N-1] == 0) return {r1,r3};
    if(S[N-1] == 1) return {r2,r3};
    if(S[N-1] == 2) return {r1,N-1};
    if(S[N-1] == 3) return {r2,N-1};
    if(S[N-1] == 4) return {r3,N-1};
    
}

