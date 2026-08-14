#include <bits/stdc++.h>

using namespace std;
const int c=400005;
int n, t[c];
vector<int> kis[c], sum[c], dif[c];
bool check(int a, int b, int c) {
    vector<int> p={b-a, c-b, c-a}, q={t[a], t[b], t[c]};
    sort(p.begin(), p.end()), sort(q.begin(), q.end());
    return (p==q);
}
long long brute() {
    long long ans=0;
    for (int i=1; i<=n; i++) {
        for (int j=i+1; j<=n; j++) {
            for (int k=j+1; k<=n; k++) {
                ans+=check(i, j, k);
            }
        }
    }
    return ans;
}
long long count_triples(std::vector<int> H) {
    n=H.size();

    for (int i=0; i<n; i++) {
        t[i+1]=H[i];
    }

    long long ans=0;

    for (int i=1; i<=n; i++) {
        sum[i+t[i]].push_back(i);
        dif[i-t[i]+n].push_back(i);
    }

    for (int i=1; i<=2*n; i++) {
        reverse(sum[i].begin(), sum[i].end());
    }

    for (int pos=1; pos<=n; pos++) {
        int ert=t[pos];
        if (pos>ert) {
            int bal=pos-ert;
            int jobb=bal+t[bal];
            if (jobb<=n && jobb-pos==t[jobb]) {
                ans++;
            }
            jobb=pos+t[bal];
            if (jobb<=n && jobb-bal==t[jobb]) {
                ans++;
            }
        }
        if (pos+ert<=n) {
            int jobb=pos+ert;
            int bal=jobb-t[jobb];
            if (bal>0 && pos-bal==t[bal] && t[bal]!=ert) {
                ans++;
            }
            bal=pos-t[jobb];
            if (bal>0 && jobb-bal==t[bal] && t[jobb]!=ert) {
                ans++;
            }
        }

        if (pos+ert<=n) {
            kis[pos+ert].push_back(pos);
        }
        for (auto x:kis[pos]) {
            if (x+ert<=n && t[x+ert]==x+ert-pos && 2*t[x+ert]!=ert) { // 121 csak egyszer
                ans++;
            }
        }

        int ossz=pos+ert, kul=pos-ert+n;

        if (sum[ossz].size()<dif[kul].size()) {
            for (auto x:sum[ossz]) {
                if (x<=pos) break;
                if (x-ert>0 && t[x-ert]==x-pos) {
                    ans++;
                }
            }
        } else {
            for (auto x:dif[kul]) {
                if (x>=pos) break;
                if (x+ert<=n && t[x+ert]==pos-x) {
                    ans++;
                }
            }
        }
    }


    return ans;
}
int l=18;
std::vector<int> construct_range(int M, int K) {
    vector<int> ans;
    for (int i=0; i<l; i++) {
        int kezd=i%(l/2+1)*l;
        for (int j=kezd+l; j>kezd; j--) {
            ans.push_back(j);
        }
    }
    for (auto x:ans) {
        cout << x << " ";
    }
    cerr << "\n";
    cerr << count_triples(ans) << "\n";
    return ans;
}


/*
int main()  {
    int N;
    cin >> N;
    vector<int> H;
    for (int i=0; i<N; i++) {
        int x;
        cin >> x;
        H.push_back(x);
    }
    cout << count_triples(H) << "\n";
}
*/
/*
7
4 1 4 3 2 6 1
*/
