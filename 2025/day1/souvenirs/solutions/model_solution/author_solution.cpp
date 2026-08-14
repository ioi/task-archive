//WARNING: not tested
#include<bits/stdc++.h>
#include "souvenirs.h"

using namespace std;

using ll = long long;

vector<int> counters;
vector<ll> lead_cost;
vector<vector<int>> lead_bought;

int buy_next_lead(int i) {
    ll S = lead_bought[i].size();
    ll P = lead_cost[i]/S;
    if (S == 1) P = P - 1;
    auto pt = transaction(P);
    for (int j : pt.first) counters[j]++;
    int l = pt.first[0];
    lead_cost[l] = P-pt.second; 
    lead_bought[l] = pt.first;
    return l;
}

void buy_souvenirs(int N, ll P_0) {
    N--;
    counters = vector<int>(N+1, 0);
    lead_cost = vector<ll>(N+1, -1);
    lead_bought = vector<vector<int>>(N+1);

    lead_cost[0] = P_0;
    lead_bought[0] = {0};

    int lead_index = 0;

    while (lead_index < N) {
        lead_index = buy_next_lead(lead_index);
    }

    int prices_index = N;

    while (prices_index > 0) {
        if (lead_cost[lead_index] != -1) {
            while ((int)lead_bought[lead_index].size() > 1 && lead_cost[lead_bought[lead_index].back()] != -1) {
                lead_cost[lead_index] -= lead_cost[lead_bought[lead_index].back()];
                lead_bought[lead_index].pop_back();
            }
            if (lead_index == prices_index) {
                prices_index--;
                lead_index--;
            }
            else {
                lead_index = buy_next_lead(lead_index);
            }
        }
        else lead_index--;
    }

    for (int i=0; i <= N; ++i) {
        for (int j=counters[i]; j < i; ++j) {
            transaction(lead_cost[i]);
        }
    }
}
