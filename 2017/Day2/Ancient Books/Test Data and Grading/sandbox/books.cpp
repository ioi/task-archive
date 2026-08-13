#include <iostream>
#include <vector>
using namespace std;
const int MAX = 1000005;
int le[MAX], ri[MAX], pos[MAX];
int mark[MAX];
int val(int x)
{
	return (x > 0 ? x : -x);
}
void go(int &l, int &r, int nl, int nr)
{
	while (nl < l || r < nr)
		if (nl != l)
		{
			l--;
			nl = min(nl, le[l]);
			nr = max(nr, ri[l]);
		}
		else
		{
			r++;
			nl = min(nl, le[r]);
			nr = max(nr, ri[r]);
		}
}
int dist(int s, int t)
{
	if (s == t)
		return 0;
	int ns = s;
	if (t < s)
	{
		while (s >= ns)
		{
			ns = min(ns, le[s]);
			s--;
			if (ns <= t)
				return 0;
		}
	}
	else
	{
		while (s <= ns)
		{
			ns = max(ns, ri[s]);
			s++;
			if (ns >= t)
				return 0;
		}
	}
	return dist(s, t) + 2;
}
long long minimum_walk(vector<int> p, int s)
{
	int n = p.size();
	long long ans = 0;
	for (int i = 0; i < n; i++)
		ans += val(i - p[i]);
	for (int i = 0; i < n; i++)
		le[i] = ri[i] = i;
	for (int i = 0; i < n; i++)
		pos[p[i]] = i;
	for (int i = 0; i < n; i++)
		if (!mark[i])
		{
			int v = i;
			while (mark[v] < 2)
			{
				le[v] = min(le[v], le[p[v]]);
				ri[v] = max(ri[v], ri[p[v]]);
				mark[v]++;
				v = pos[v];
			}
		}
	int gl = 0;
	while (gl < s && p[gl] == gl)
		gl++;
	int gr = n - 1;
	while (gr > s && p[gr] == gr)
		gr--;
	int l = s + 1, r = s;
	go(l, r, s, s);
	bool done = false;
	while (gl < l || r < gr)
	{
		int nl = l, nr = r;
		if (!done)
		{
			while (nl >= 0 && ri[nl] <= r)
				nl--;
		}
		if (nl == -1)
			done = true;
		if (done)
		{
			nl = l;
			if (l <= gl)
			{
				nr++;
				ans += 2;
			}
			else
			{
				nl--;
				ans += 2;
			}
		}
		else
		{
			while (l <= le[nr])
				nr++;
			ans += min(dist(l - 1, nl), dist(r + 1, nr)) + 2;
		}
		go(l, r, nl, nr);
	}
	return ans;
}
