// .... .... .....!
// ...... ......!
// .... ....... ..... ..!
// ...... ... ... .... ... .... .....!
// ... .. ... .... ...?

#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define fer(i, x, n) for (int i = (int)(x), _n = (int)(n); i < _n; i++)
#define rof(i, n, x) for (int i = (int)(n), _x = (int)(x); i-- > _x; )
#define sz(x) (int((x).size()))
#define pb push_back
#define all(X) (X).begin(),(X).end()
#define X first
#define Y second
//#define endl '\n'

template<class P, class Q> inline void smin(P &a, Q b) { if (b < a) a = b; }
template<class P, class Q> inline void smax(P &a, Q b) { if (a < b) a = b; }

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int inside_edge_prob = 50;
const int connect_to_next_group_prob = 18;
const int loop_prob = 35;

const int try_limit = 20000;

const int maxn = 10000 + 100;

enum Owner { APOSH = 0, TIR = 1 };

vector<int> make_arr(int k, int sum, int st = 1) {
	if(st) sum -= k; // one
	ensuref(sum >= 0, "make_arr is used incorrectly!");
	vector<int> v(k, 0);
	if(k == 0) { assert(sum == 0); if(st) rep(i, k) v[i]++; return v; }
	v.back() = sum;
	rep(i, k-1) v[i] = rnd.next(0, sum);
	sort(all(v));
	rof(i, k, 1) v[i] -= v[i-1];
	if(st) rep(i, k) v[i]++; // one
	return v;
}

vector<int> get_some(int k, int n) {
	vector<int> v(k);
	rep(i, k) v[i] = rnd.next(n - k + 1);
	sort(all(v));
	rep(i, k) v[i] += i;
	return v;
}

int logrand(int n) {
	int res = (int)exp(rnd.next(log(n)));
	smax(res, 1); smin(res, n);
	return res;
}

int owner[maxn], color[maxn];
int red_prob, blue_prob;

int red_cnt[maxn]; // not all entries used.

vector<pii> make_red(int start, int cnt, int next_cnt) {
	red_cnt[start] = logrand(cnt);
	fer(i, start, start + red_cnt[start]) color[i] = 1;

	vector<pii> e;
	fer(i, start, start + cnt) {
		owner[i] = (rnd.next(100) < (color[i] ? red_prob : blue_prob) ? TIR : APOSH);
		if(color[i] == 1) {
			if(start == i || rnd.next(100) < connect_to_next_group_prob)
				e.pb({i, rnd.next(start + cnt, start + cnt + next_cnt - 1)});
			else
				e.pb({i, rnd.next(start, i - 1)}); // cbm
			if(owner[i] == APOSH)
				e.pb({i, rnd.next(i, start + cnt - 1)}); // cbn, cbm
		} else {
			if(owner[i] == TIR) {
				e.pb({i, rnd.next(start, i - 1)}); // cbm
				if(rnd.next(10) == 0) // modify prob later
					e.pb({i, rnd.next(i, start + cnt - 1)}); // cbm
			} else {
				e.pb({i, rnd.next(start, i - 1)}); // cbm
			}
		}
	}

	return e;
}

vector<pii> make_blue(int start, int cnt, int next_cnt) {
	vector<pii> e;
	fer(i, start, start + cnt) {
		owner[i] = ((i == start || rnd.next(100) < (color[i] ? red_prob : blue_prob)) ? TIR : APOSH);
		if(color[i] == 0 && blue_prob == 0) owner[i] = APOSH; // it stops the layers connection, handle with care!
		if(owner[i] == TIR) {
			if(next_cnt > 0 && (i == start || rnd.next(100) < connect_to_next_group_prob)) {
				e.pb({i, rnd.next(start + cnt, start + cnt + next_cnt - 1)});
				e.pb({i, rnd.next(start, start + cnt - 1)});
			} else {
				if(start < i)
					e.pb({i, rnd.next(start, i - 1)}); // cbm
				else
					e.pb({i, i});
			}
		} else
			e.pb({i, rnd.next(start, max(start, i - 1))}); // cbm
	}

	return e;
}

vector<pii> make_win_set(int win_cnt, int reds = -1) {
	if(win_cnt == 0) return vector<pii>();

	int win_reds = (reds == -1 ? logrand(win_cnt) : reds);
	rep(i, win_reds) color[i] = 1;

	vector<pii> e;
	rep(i, win_cnt) {
		owner[i] = (rnd.next(100) < (color[i] ? red_prob : blue_prob) ? TIR : APOSH);
		if(color[i] == 1)
			e.pb({i, rnd.next(win_cnt)}); // cbm
		else
			e.pb({i, rnd.next(i)}); // cbm
		if(owner[i] == TIR)
			e.pb({i, rnd.next(i, win_cnt - 1)}); // cbn, cbm
	}

	return e;
}

struct Solver {
	vector<int> radj[maxn];
	int deg[maxn], need[maxn];

	void dfs(int u, vector<int> &w) {
		for(int v: radj[u]) {
			need[v]--;
			if(!w[v] && need[v] == 0) dfs(v, w); // only dfs through non-well vertices
		}
	}

	vector<int> who_wins(vector<int> d, vector<int> w, const set<pii> &es) {
		int n = sz(d);
		rep(i, n) deg[i] = 0, radj[i].clear();
		for(pii p: es) radj[p.Y].pb(p.X), deg[p.X]++;
		vector<int> r(n, 1);
		for(bool cng = true; !(cng = !cng); ) {
			rep(i, n) need[i] = (d[i] ? 1 : deg[i]); // d only matters here
			rep(i, n) if(w[i] && r[i]) dfs(i, w); // dfs from yet-has-a-chance-to-win wells
			rep(i, n) if(w[i] && r[i] && need[i] > 0) r[i] = false, cng = true; // and see if they had no chance
		}
		rep(i, n) r[i] &= (need[i] <= 0); // look, more fopdoodles
		return r;
	}
};

int n;

void converge(int n, int goal, const set<pii> &es, bool can_change = false) {
	const int change_limit = 25;
	Solver S;
	int cng = 0, prv = -1;
	for(int i = 0; i < try_limit && cng < change_limit; i++) {
		vector<int> tmp = S.who_wins(vector<int>(owner, owner + n), vector<int>(color, color + n), es);
		if(count(all(tmp), 1) > goal) {
			int u = rnd.next(n);
			while(!((can_change && owner[u] == 1) || color[u] == 1)) u = rnd.next(n);
			if(can_change && owner[u] == 1) owner[u] = 0;
			else color[u] = 0;
			if(prv == 1) cng++;
			prv = 0;
		} else {
			int u = rnd.next(n);
			while(!((can_change && owner[u] == 0) || color[u] == 0)) u = rnd.next(n);
			if(can_change && owner[u] == 0) owner[u] = 1;
			else color[u] = 1;
			if(prv == 0) cng++;
			prv = 1;
		}
	}
}

int main(int argc, char **argv) {
	ios_base::sync_with_stdio(false); cin.tie(0);
	registerGen(argc, argv, 0);

	string test_type = string(argv[1]);
	int n = atoi(argv[2]);
	int k = atoi(argv[3]);
	int m = atoi(argv[4]);
	int win_cnt = atoi(argv[5]);
	red_prob = atoi(argv[6]);
	blue_prob = (argc <= 7 ? red_prob : atoi(argv[7]));

	vector<pii> e;
	set<pii> es;

	if(test_type == "general") {
		ensuref(m >= n && n - win_cnt - 2 * k >= 0, "(n - win_cnt - 2 * k >= 0)"); // ok!

		rep(i, n) color[i] = 0;

		e = make_win_set(win_cnt);

		vector<int> cnt = make_arr(2 * k, n - win_cnt);
		vector<int> starts(2 * k);

		int pos = win_cnt;
		rep(i, k) {
			vector<pii> tmp;

			starts[2 * i] = pos;
			tmp = make_red(starts[2 * i], cnt[2 * i], cnt[2 * i + 1]);
			copy(all(tmp), back_inserter(e));
			pos += cnt[2 * i];

			starts[2 * i + 1] = pos;
			tmp = make_blue(starts[2 * i + 1], cnt[2 * i + 1], i + 1 == k ? 0 : cnt[2 * i + 2]);
			copy(all(tmp), back_inserter(e));
			pos += cnt[2 * i + 1];
		}
		starts.pb(pos);

		if(win_cnt > 0 && k > 0)
			e.pb({win_cnt - 1, win_cnt});

		es = set<pii>(all(e)); // bye vector, hello set!

		for(int i = 0; i < try_limit && sz(es) < m; i++) {
			int u = rnd.next(n), v = -1;
			int gid = upper_bound(all(starts), u) - starts.begin() - 1;

			if(gid == -1) { // win set
				if(rnd.next(100) < inside_edge_prob) {
					if(owner[u] == TIR)
						v = rnd.next(win_cnt);
					else
						v = (u == 0 ? -1 : rnd.next(u));
				} else {
					if(owner[u] == TIR)
						v = rnd.next(win_cnt, n - 1);
				}
			} else if(gid % 2 == 0) { // red-blue set, it's not the last group
				if(rnd.next(100) < inside_edge_prob) {
					if(color[u] == 1) {
						if(owner[u] == TIR)
							v = rnd.next(starts[gid + 1], starts[gid + 2] - 1);
						else
							v = rnd.next(starts[gid], starts[gid + 1] - 1);
					} else {
						if(owner[u] == TIR)
							v = rnd.next(starts[gid], starts[gid + 1] - 1);
						else
							v = rnd.next(starts[gid], starts[gid] + red_cnt[starts[gid]] - 1);
					}
				} else {
					if(owner[u] == TIR)
						v = rnd.next(starts[gid + 1], n - 1);
					else
						v = (starts[gid] > 0 ? rnd.next(starts[gid]) : -1);
				}
			} else { // blue set
				if(rnd.next(100) < inside_edge_prob) {
					if(owner[u] == TIR)
						v = rnd.next(starts[gid], starts[gid + 1] - 1);
					else
						v = (starts[gid] < u ? rnd.next(starts[gid], u - 1) : -1);
				} else {
					if(owner[u] == TIR)
						v = (starts[gid + 1] < n ? rnd.next(starts[gid + 1], n - 1) : -1);
					else
						v = rnd.next(starts[gid]);
				}
			}

			if(v != -1) es.insert({u, v});
		}
	} else if(test_type == "single") { // n -1 m win_cnt rp bp
		if(win_cnt > 0) {
			vector<pii> tmp = make_win_set(win_cnt, 1);
			es = set<pii>(all(tmp));
		} else {
			rep(i, n) color[i] = 0;
			color[0] = 1;
		}

		fer(i, win_cnt, n) owner[i] = (rnd.next(100) < (color[i] ? red_prob : blue_prob) ? TIR : APOSH);

		fer(i, win_cnt, n) {
			int v = rnd.next(win_cnt, n - 1);
			es.insert({i, v});
		}


		for(int i = 0; i < try_limit && sz(es) < m; i++) {
			int u = (win_cnt ? rnd.next(n) : rnd.next(1, n - 1)), v = -1;

			if(u < win_cnt) { // win set
				if(rnd.next(100) < inside_edge_prob) {
					if(owner[u] == TIR)
						v = rnd.next(win_cnt);
					else
						v = (u == 0 ? -1 : rnd.next(u));
				} else {
					if(owner[u] == TIR && win_cnt < n)
						v = rnd.next(win_cnt, n - 1);
				}
			} else {
				v = rnd.next(n);
			}

			if(v != -1) es.insert({u, v});
		}

	} else if(test_type == "hespec") { // n -1 -1 -1 -1 -1
		rep(i, n) owner[i] = TIR;
		rep(i, n) color[i] = (i % 2 ? 0 : 1);
		rep(i, n) {
			if((i | 1) < n) es.insert({i, i | 1});
			if((i | 1) + 1 < n) es.insert({i, (i | 1) + 1});
		}
	} else if(test_type == "schange") { // n k m -1 rp bp
		rep(i, n) color[i] = rnd.next(2);
		rep(i, n) owner[i] = (rnd.next(100) < (color[i] ? red_prob : blue_prob) ? TIR : APOSH);

		rep(i, n) {
			int v = rnd.next(n);
			es.insert({i, v});
		}
		rep(i, m - n) {
			int u = rnd.next(n), v = rnd.next(n);
			es.insert({u, v});
		}

		converge(n, k, es, red_prob % 100 && blue_prob % 100);
	} else if(test_type == "path") { // n k -1 -1 rp bp
		rep(i, n) color[i] = rnd.next(2);
		rep(i, n) owner[i] = (rnd.next(100) < (color[i] ? red_prob : blue_prob) ? TIR : APOSH);

		vector<int> cnts = make_arr(k, n);
		int pos = 0;
		rep(i, k) {
			fer(j, pos, pos + cnts[i] - 1) {
				es.insert({j, j + 1});
				if(rnd.next(100) < loop_prob) es.insert({j, j});
			}
			es.insert({pos + cnts[i] - 1, pos + cnts[i] - 1});
			pos += cnts[i];
		}
	} else if(test_type == "hcc") { // n k m left_kcnt rp (-1)
		int left_kcnt = win_cnt; // noch noch noch!

		rep(i, n) color[i] = 0;
		rep(i, n) owner[i] = (rnd.next(100) < red_prob ? TIR : APOSH);

		vector<int> cnts = make_arr(k, n);
		vector<int> starts(k + 1, 0);

		int bomb_cnt = logrand(max(1, left_kcnt / 2)); // owner == alice ? have red : blue cycle
		vector<int> is_bomb(k, 0);
		rep(i, bomb_cnt) is_bomb[rnd.next(left_kcnt)] = 1;

		int pos = 0;
		rep(i, k) {
			starts[i] = pos;
			int len = rnd.next(1, cnts[i]);

			fer(j, pos, pos + len - 1) es.insert({j, j + 1});
			es.insert({pos + len - 1, pos});

			if(red_prob == 0 && (!is_bomb[i] || rnd.next(2))) // if it's bob bomb, add a red in every arc/cycle
				color[rnd.next(pos, pos + len - 1)] = 1;

			int end = pos + len;
			while(end < pos + cnts[i]) {
				len = rnd.next(1, pos + cnts[i] - end);
				fer(j, end + 1, end + len) es.insert({j - 1, j});
				es.insert({rnd.next(pos, end), end});
				es.insert({end + len - 1, rnd.next(pos, end)});

				if(red_prob == 0 && (!is_bomb[i] || rnd.next(2))) // same here
					color[rnd.next(end, end + len - 1)] = 1;

				end += len;
			}

			if(red_prob == 100 && is_bomb[i]) // if it's alice bomb, add a red somewhere
				color[rnd.next(pos, pos + cnts[i] - 1)] = 1;

			pos += cnts[i];
		}
		starts[k] = pos;

		ensuref(m >= sz(es), "there is not enough edges in hcc type");
		vector<int> outdeg = make_arr(k - 1, m - sz(es), 0);

		rep(i, k-1) {
			vector<int> outs = get_some(logrand(k - i - 1), k - i - 1);

			rep(z, outdeg[i]) {
				int u = rnd.next(starts[i], starts[i + 1] - 1);
				int g = outs[rnd.next(sz(outs))] + i + 1;
				int v = rnd.next(starts[g], starts[g + 1] - 1);
				es.insert({u, v});
			}
		}

	} else if(test_type == "scc") { // n k m -1 rp bp
		rep(i, n) color[i] = rnd.next(2);
		rep(i, n) owner[i] = (rnd.next(100) < (color[i] ? red_prob : blue_prob) ? TIR : APOSH);

		vector<int> cnts = make_arr(k, n);
		vector<int> starts(k + 1, 0);

		int pos = 0;
		rep(i, k) {
			starts[i] = pos;
			int len = rnd.next(1, cnts[i]);

			fer(j, pos, pos + len - 1) es.insert({j, j + 1});
			es.insert({pos + len - 1, pos});

			int end = pos + len;
			while(end < pos + cnts[i]) {
				len = rnd.next(1, pos + cnts[i] - end);
				fer(j, end + 1, end + len) es.insert({j - 1, j});
				es.insert({rnd.next(pos, end), end});
				es.insert({end + len - 1, rnd.next(pos, end)});
				end += len;
			}
			pos += cnts[i];
		}
		starts[k] = pos;

		for(int i = 0; i < try_limit && sz(es) < m; i++) {
			if(rnd.next(100) < inside_edge_prob) {
				int g = rnd.next(k);
				int u = rnd.next(starts[g], starts[g + 1] - 1);
				int v = rnd.next(starts[g], starts[g + 1] - 1);
				es.insert({u, v});
			} else {
				int g1 = rnd.next(k);
				int g2 = rnd.next(k);
				if(g1 > g2) swap(g1, g2);
				int u = rnd.next(starts[g1], starts[g1 + 1] - 1);
				int v = rnd.next(starts[g2], starts[g2 + 1] - 1);
				es.insert({u, v});
			}
		}
	} else
		ensuref(0, "invalid test_type argument");

// es ready!

	vector<int> perm(n);
	iota(all(perm), 0);

	if(test_type != "path")
		shuffle(all(perm));

	vector<int> rperm(n);
	rep(i, n) rperm[perm[i]] = i;

	e.clear(); for(pii p: es) e.pb(p); // bye set, hi vector!

	shuffle(all(e));

	cout << "3d2051c242fe2ae63792f9868123a5eb" << endl;
	cout << n << ' ' << sz(e) << endl;

	rep(i, n) cout << (i ? " " : "") << owner[rperm[i]];
	cout << endl;

	rep(i, n) cout << (i ? " " : "") << color[rperm[i]];
	cout << endl;

	rep(i, sz(e)) cout << perm[e[i].X] << ' ' << perm[e[i].Y] << endl;

	return 0;
}
