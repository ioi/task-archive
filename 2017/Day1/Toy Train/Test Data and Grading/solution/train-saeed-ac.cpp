#include "train.h"

#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

const int MAXN = 5000+10;

const int B = 0;
const int A = 1;

bool mark[MAXN], checked[MAXN];
int need[MAXN], f[MAXN]; 
vector<int> adj[MAXN], bak[MAXN];

vector<int> who_wins(vector<int> a, vector<int> r, vector<int> u, vector<int> v){
	for (int i = 0; i < (int)u.size(); i++) {
		adj[u[i]].push_back(v[i]);
		bak[v[i]].push_back(u[i]);
	}
	int n = (int)a.size();
	for (int i = 0; i < n; i++)
		f[i] = A;
	while (true) {
		for (int i = 0; i < n; i++) if (f[i] != B) {
			mark[i] = false;
			checked[i] = false;
			need[i] = a[i] == A ? 1 : (int)adj[i].size();
		}
		queue<int> q;
		for (int i = 0; i < n; i++) if (r[i] && f[i] == A)
			q.push(i);
		while (!q.empty()){
			int front = q.front();
			q.pop();
			if (checked[front] == true)
				continue;
			checked[front] = true;
			for (int i = 0; i < (int)bak[front].size(); i++) {
				int temp = bak[front][i];
				--need[temp];
				if (need[temp] == 0 && mark[temp] == false && f[temp] == A) {
					q.push(temp);
					mark[temp] = true;
				}
			}
		}
		bool flag = false;
		for (int i = 0; i < n; i++) if (f[i] == A && mark[i] == false) {
			f[i] = B;
			flag = true;
		}
		if (!flag)
			break;
	}
	vector<int> res;
	for (int i = 0; i < n; i++)
		res.push_back(f[i]);
	return res;
}
