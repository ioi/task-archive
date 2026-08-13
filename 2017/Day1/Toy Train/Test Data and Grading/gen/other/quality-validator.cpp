#include <iostream>
#include <vector>
#include <cstring>
#include <set>
#include <algorithm>

using namespace std;

const int max_n = 10000;
const bool ALICE = true;
const bool BOB = false;

int layers;

int n, m;
vector <int> a[max_n], b[max_n];
bool owners[max_n];
int rem[max_n];

set <int> fill_followers(set <int> sources, bool player) {
	memset (rem, 0, sizeof rem);
	set <int> res;
	vector <int> queue;
	for (int i = 0; i < n; i++) {
		rem[i] = (int)a[i].size();
		if (owners[i] == player) rem[i] = min(rem[i], 1);
		for (auto adj : a[i]) if (sources.count(adj) > 0) rem[i] = max(0, rem[i] - 1);
		if (rem[i] == 0) queue.push_back(i);
	}

	for (int i = 0; i < (int)queue.size(); i++) {
		int k = queue[i];
		res.insert(k);
		for (auto adj : b[k]) if (rem[adj] > 0 && sources.count(k) == 0) {
			rem[adj] = max(0, rem[adj] - 1);
			if (rem[adj] == 0) queue.push_back(adj);
		}
	}

	return res;
}

vector<int> who_wins(vector<int> d, vector<int> w, vector<int> u, vector<int> v) {
	n = (int)d.size();
	for (int i = 0; i < (int)u.size(); i++)
		a[u[i]].push_back(v[i]),
		b[v[i]].push_back(u[i]);
	for (int i = 0; i < n; i++)
		owners[i] = d[i];

	set <int> sources;
	for (int i = 0; i < n; i++) if (w[i] == 1) sources.insert(i);
	int k = (int)sources.size();

	for (int i = 0; i < k; i++) {
		set <int> alice = fill_followers(sources, ALICE), not_alice;
		for (int j = 0; j < n; j++)
			if (alice.count(j) == 0)
				not_alice.insert(j);

		set <int> bob = fill_followers(not_alice, BOB);
		layers++;
		int prev = (int)sources.size();
		for (auto x : bob) sources.erase(x);
		if (prev == (int)sources.size())
			break;
	}
	set <int> alice = fill_followers(sources, ALICE);

	vector <int> res(n, BOB);
	for (auto x : alice) res[x] = ALICE;
	return res;
}

int mark[max_n], tc = 1;
vector <int> topol;
set <int> not_source, not_sink;

void dfs(int v, vector<int> *graph, bool is_topol=false) {
    mark[v] = tc;
    for (auto u : graph[v])
        if (mark[u] == 1-is_topol)
            dfs(u, graph, is_topol);
    if (is_topol)
        topol.push_back(v);
}

void scc() {
	for (int i = 0; i < n; i++) if (mark[i] == 0) dfs(i, a, true);
	reverse(topol.begin(), topol.end());

    for (auto x : topol) if (mark[x] == 1) {
		tc++;
        dfs(x, b);
    }

	for (int v = 0; v < n; v++)
		for (auto u : a[v]) if (mark[u] != mark[v])
			not_source.insert(mark[v]),
			not_sink.insert(mark[u]);
}

int main()
{
  string secret; cin >> secret;
  cin >> n >> m;

  vector<int> d(n), w(n), u(m), v(m);

  for (int i = 0; i < n; i++) {
    cin >> d[i];
  }

  for (int i = 0; i < n; i++) {
    cin >> w[i];
  }

  for (int i = 0; i < m; i++) {
    cin >> u[i] >> v[i];
  }

  vector<int> r = who_wins(d, w, u, v);

  scc();

  cout << "layers: " << layers << " ";
  cout << "tir: " << count(r.begin(), r.end(), ALICE) << " ";
  cout << "aposh: " << count(r.begin(), r.end(), BOB) << " ";
  cout << "scc: " << tc-1 << " ";
  cout << "sources: " << tc-1 - (int)not_source.size() << " ";
  cout << "sinks: " << tc-1 - (int)not_sink.size() << endl;

  return 0;
}
