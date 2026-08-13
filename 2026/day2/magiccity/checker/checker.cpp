#include "testlib.h"

const std::string input_secret = "dDIZTjOnVjhIDrUsCub93axaXK54larl";
const std::string output_secret1 = "AWmSCSuAvEsx26UlX7YQwxi7mlumajPI";
const std::string output_secret2 = "vSsge5g7k6Z1q3r8X9y0p4b2nLhJtRPe";

const int MAXN = 2000;

int get_P(int N) {
	if (N == 1) {
		return 2;
	} else if (N == 2) {
		return 12;
	} else if (N == 3) {
		return 24;
	} else if (N == 4) {
		return 40;
	} else if (N == 5) {
		return 50;
	} else {
		return 12 * N;
	}
}

int main(int /*argc*/, char* argv[]) {
	registerChecker("magiccity", 4, argv);
	inf.readSecret(input_secret);
	int K = inf.readInt();
	inf.close();

	int N;
	std::string token = ouf.readToken();
	if (token == output_secret1) {
		ouf.readSecret(output_secret2);
		ouf.readGraderResult();
		N = ouf.readInt(1, MAXN, "N");
	}
	else {
		try {
			N = std::stoi(token);
		}
		catch (const std::exception&) {
			quitf(_wa, "Invalid value for N");
		}
		if (N < 1 || N > MAXN) {
			quitf(_wa, "Value of N=%d is out of range [1, %d]", N, MAXN);
		}
	}
	
	int M = ouf.readInt(0, K * N / 2, "M");
	std::vector<int> T = ouf.readInts(N, 0, 2 * K - 1, "T");
	std::vector<int> U(M), V(M), d(N);
	std::vector<std::vector<int>> adj(N);

	for (int i = 0; i < M; ++i) {
		int u = ouf.readInt(0, N - 1, "U");
		int v = ouf.readInt(0, N - 1, "V");
		if (u == v) {
			quitf(_wa, "Edge %d = (%d, %d) is a loop", i, u, v);
		}
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 0; i < N; ++i) {
		if ((int)adj[i].size() > K) {
			quitf(_wa, "The degree of vertex %d exceeds %d", i, K);
		}
	}

	std::vector<std::vector<std::vector<int>>> ok(2 * K, std::vector<std::vector<int>>(2 * K, std::vector<int>(2 * K, 0)));

	for (int x = 0; x < N; ++x) {
		for (int y : adj[x]) {
			for (int z : adj[y]) {
				ok[T[x]][T[y]][T[z]] = 1;
			}
		}
	}
	for (int t0 = 0; t0 < 2 * K; ++t0) {
		for (int t1 = 0; t1 < 2 * K; ++t1) {
			for (int t2 = 0; t2 < 2 * K; ++t2) {
				if (t0 != t1 && t1 != t2) {
					if (!ok[t0][t1][t2]) {
						quitf(_wa, "Tuple (%d, %d, %d) is not good", t0, t1, t2);
					}
				}
			}
		}
	}
	int P = get_P(K);
	auto get_points = [&](int N, int P) -> double {
		if (N <= P) {
			return 1.0;
		} else if (N <= 2 * P) {
			return 0.4 + 0.3 * (2 * P - N) / P;
		} else {
			return 0.1 + 0.3 * 2 * P / N;
		}
	};
	double pts = get_points(N, P);
	if (pts == 1.0) {
		quitf(_ok, "N = %d, P = %d", N, P);
	} else {
		quitp(get_points(N, P), "N = %d, P = %d", N, P);
	}
}
