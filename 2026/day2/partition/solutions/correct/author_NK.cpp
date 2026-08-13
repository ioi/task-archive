// this solution is wrong
#include "partition.h"
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>
#include <assert.h>
using namespace std;
using ll = long long;

vector<int> add_numbers(vector<int> a, int k, int m) {
	ll low=0,high=(ll)1e18;
    sort(a.begin(),a.end());
    while(high-low>1){
        ll mid=(high+low)/2;
        int cnt=0;
        ll cur=0;
        for(ll i:a){
            while(cnt<k){
                ll x=mid/k;
                if(cnt<mid%k){x++;}
                if(cur+i>x){
                    cur=0;
                    cnt++;
                }else{
                    cur+=i;
                    break;
                }
            }
        }
        if(cnt<=k-1){
            high=mid;
        }else{
            low=mid;
        }
    }
    //cout<<high<<"\n";
    vector<vector<ll>> num(k);
    int cnt=0;
    ll cur=0;
    for(ll i:a){
        ll x=high/k;
        if(cnt<high%k){x++;}
        if(cur+i>x){
            cnt++;
            cur=0;
        }
        num[cnt].push_back(i);
        cur+=i;
    }
    ll max_v=high/k;
    if(high%k!=0){max_v++;}
    vector<int> res;
    for(int i=0;i<k;i++){
        ll s=accumulate(num[i].begin(),num[i].end(),(ll)0);
        ll v=max_v-s;
        if(v!=0){
            res.push_back(v);
        }
    }
    if(res.size()==k){
    	ll x=*min_element(res.begin(),res.end());
    	vector<int> res2;
    	for(int i:res){
    		if(i-x>0){
    			res2.push_back(i-x);
			}
		}
		res=res2;
	}
    return res;
}

vector<int> find_partition(vector<int> b, int k) {
	vector<pair<ll,int>> arr;
    for(int i=0;i<b.size();i++){
        arr.push_back(make_pair(b[i],i));
    }
    sort(arr.begin(),arr.end());
    vector<int> used(arr.size(),-1);
    ll total=accumulate(b.begin(),b.end(),(ll)0);
    for(int i=0;i<k;i++){
        ll s=0;
        for(int j=arr.size()-1;j>=0;j--){
            if(used[arr[j].second]==-1 and s+arr[j].first<=total/k){
                used[arr[j].second]=i;
                s+=arr[j].first;
            }
        }
    }
    return used;
}