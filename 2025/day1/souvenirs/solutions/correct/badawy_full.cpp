#include <bits/stdc++.h>
#include "souvenirs.h"

using namespace std;

const int N=105;

struct payment{
    vector<int> items;
    long long price;
};

payment leading[N];
long long price[N];
int cnt_bought[N];
int know_leading;

pair<vector<int> , long long> add_leading(long long curp)
{
    auto ret=transaction(curp);
    sort(ret.first.begin(), ret.first.end());
    if(leading[ret.first[0]].price == 0) know_leading++;
    leading[ret.first[0]] = {ret.first, curp - ret.second};
    for(int i:ret.first) cnt_bought[i]++;
    return ret;
}

void calc_price(int i)
{
    long long me = leading[i].price;
    for(int j:leading[i].items) if(j!=i) me-=price[j];
    price[i] = me;
}

void buy_souvenirs(int n, long long P0)
{
    long long curp = P0 - 1;
    for(int i=0;i<n;i++) leading[i] = {vector<int>(), 0};
    while(true)
    {
        auto ret=add_leading(curp);
        curp -= ret.second;
        curp = curp/ret.first.size();
        if(ret.first.size() == 1) curp--; // In case of exactly one item bought
        if(ret.first[0] == n-1) break; 
    }
    while(know_leading < n-1) {
        int unknown = n-1;
        while(leading[unknown].price) {
            if(!price[unknown]) calc_price(unknown);
            unknown--;
        }   
        int known = unknown;
        while(leading[known].price == 0) known--;
        long long totp = leading[known].price;
        int totn = leading[known].items.size();
        for(int j:leading[known].items) {
            if(j > unknown) {
                if(!price[j]) calc_price(j);
                totn--;
                totp -= price[j];
            }
        }
        if(totn == 1) totp--;
        else totp/=totn;
        auto ret = add_leading(totp);
        int cnt_unknown = ret.first.size();
        long long tot = totp - ret.second;
        for(int i:ret.first)
        {
            if(price[i]) {
                tot-=price[i];
                cnt_unknown--;
            }
        }
        if(cnt_unknown == 1) {
            price[ret.first[0]] = tot;
        }
    }
    for(int i=n-1;i>=0;i--)
    {
        long long me = leading[i].price;
        for(int j:leading[i].items) if(j!=i) me-=price[j];
        price[i] = me;
        while(cnt_bought[i] < i) {
            transaction(price[i]);
            cnt_bought[i]++;
        }
    }
}