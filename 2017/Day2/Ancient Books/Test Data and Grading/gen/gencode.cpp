#include <iostream>
#include <cstdlib>
#include <numeric>
#include "testlib.h"
using namespace std;
const string input_secret = "f58fb993-f209-43d7-9391-c46c61f180b9";
const int MAX = 1000000;
int p[MAX];
void build(int l, int r)
{
	if (l > r)
		return;
	int mid = rnd.next(l, r);
	if (rnd.next(0, 1))
	{
		p[l] = mid;
		p[mid] = l;
		build(l + 1, mid - 1);
		build(mid + 1, r);
	}
	else
	{
		p[r] = mid;
		p[mid] = r;
		build(mid + 1, r - 1);
		build(l, mid - 1);
	}
}
void childish(int l, int r, int pr)
{
	if (l > r)
		return;
	if (l == r)
	{
		p[l] = l;
		return;
	}
	vector<int> v, ids;
	v.push_back(l);
	ids.push_back(l);
	for (int i = l + 1; i < r; i++)
		if (rnd.next(1, pr) == 1)
		{
			v.push_back(i);
			ids.push_back(i);
		}
	v.push_back(r);
	ids.push_back(r);
	shuffle(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
		p[ids[i]] = v[i];
	for (int i = 0; i + 1 < ids.size(); i++)
		childish(ids[i] + 1, ids[i + 1] - 1, pr);
}
int cone(int l, int r, int sz)
{
	if (r - l <= 0)
		return l;
	p[l] = r - 1;
	p[r - 1] = l;
	l++, r--;
	if (r - l <= 0)
		return l;
	if (r - l < 10)
	{
		for (int i = l; i < r; i++)
			p[i] = i;
		shuffle(p + l, p + r);
		return rnd.next(l, r - 1);
	}
	int lc = 1;
	int rc = rnd.next(2, 5);
	if (rnd.next(0, 1))
		swap(lc, rc);
	sz = min(sz, (r - l) / (lc + rc));
	for (int i = l; i < l + sz * lc; i += sz)
	{
		iota(p + i, p + i + sz, i);
		shuffle(p + i, p + i + sz);
	}
	for (int i = r; i > r - sz * rc; i -= sz)
	{
		iota(p + i - sz, p + i, i - sz);
		shuffle(p + i - sz, p + i);
	}
	return cone(l + lc * sz, r - sz * rc, sz);
}
int main(int argc, char *argv[]) 
{
	registerGen(argc, argv, 1);
	string type = string(argv[1]);
	int n = atoi(argv[2]);
	int s = atoi(argv[3]);
	if (type == "random")
	{
		for (int i = 0; i < n; i++)
			p[i] = i;
		shuffle(p, p + n);
	}
	if (type == "sorted")
	{
		for (int i = 0; i < n; i++)
			p[i] = i;
	}
	if (type == "bucket")
	{
		for (int i = 0; i < n; i++)
			p[i] = i;
		int pr = atoi(argv[4]);
		int last = 0;
		for (int i = 1; i <= n; i++)
			if (i == n || rnd.next(1, pr) == 1)
			{
				shuffle(p + last, p + i);
				last = i;
			}
	}
	if (type == "normal")
	{
		build(0, n - 1);
	}
	if (type == "childish")
	{
		childish(0, n - 1, atoi(argv[4]));
	}
	if (type == "cone")
	{
		int sz = atoi(argv[4]);
		s = cone(0, n, sz);
	}
	if (type == "long_path")
	{
		for (int i = 0; i < n; i++)
			p[i] = i;
		reverse(p, p + n);
		int x = n / 6;
		int s = n / 2 - x;
		int e = n / 2 + x;
		reverse(p + s, p + e);
		for (int i = s; i < e; i += 2)
			swap(p[i], p[i + 1]);
	}
	cout << input_secret << "\n";
	cout << n << " " << s << "\n";
	for (int i = 0; i < n; i++)
	{
		cout << p[i];
		if (i + 1 < n)
			cout << " ";
		else
			cout << "\n";
	}
	return 0;
}
