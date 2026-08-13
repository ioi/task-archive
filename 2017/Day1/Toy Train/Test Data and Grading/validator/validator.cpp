#include "testlib.h"
#include <set>
using namespace std;
const int max_n = 5000;
const int max_m = 20000;

int main()
{
	registerValidation();
	string secret = inf.readLine();
	ensuref(secret == "3d2051c242fe2ae63792f9868123a5eb", "Secret not found!");
	int n = inf.readInt(1, max_n, "n");
	inf.readSpace();
	int m = inf.readInt(n, max_m, "m");
	inf.readEoln();

	for(int i = 0; i < n; i++) {
		if (i > 0) inf.readSpace();
		inf.readInt(0, 1, "d_" + to_string(i));
	}
	inf.readEoln();

	int well_cnt = 0;
	for(int i = 0; i < n; i++) {
		if (i > 0) inf.readSpace();
		well_cnt += inf.readInt(0, 1, "w_" + to_string(i));
	}
	inf.readEoln();
	ensuref(well_cnt > 0, "At least one of the junctions must contain a well");

    set <pair <int, int>> edges;
	set <int> edge_heads;
	for (int i = 0; i < m; i++) {
		int u = inf.readInt(0, n - 1, "u_" + to_string(i));
		inf.readSpace();
		int v = inf.readInt(0, n - 1, "v_" + to_string(i));
		ensuref(edges.count(make_pair(u, v)) == 0, "The given graph cannot contain multiple edges");
        edges.insert(make_pair(u, v));
		edge_heads.insert(u);
		inf.readEoln();
	}
	ensuref((int)edge_heads.size() == n, "Every junction must have an exiting road");
    inf.readEof();
	return 0;
}
