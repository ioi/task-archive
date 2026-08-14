#include "testlib.h"
#include <string>
#include <vector>
#include <set>
#include <map>

const std::string input_secret  = "jB7KRtelfNrzhva6IhSoGAcDptqeBHJr";
const std::string output_secret = "qOpG8GoYprN2GHwBEAOkfIfpiiFWanMx";
const std::string extra_secret  = "nxz3K1mLpvlEac8SbN9hu4cFQ2jnBxG9";

bool goodTriple(int i, int j, int k, const std::vector<int>& H) {
	if (i == j || i == k || j == k)
        quitf(_fail, "checker failed to count triples\n");
	std::vector<int> A{H[i], H[j], H[k]};
	std::vector<int> B{abs(i - j), abs(i - k), abs(j - k)};
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	return A == B;
}

int countTriples(std::vector<int> H) {
    int N = H.size();
	std::set<std::set<int>> triples;
	auto considerPair = [&](int i, int j) {
		for (int id : {i, j}) {
			for (int dist : {H[i], H[j]}) {
				for (int k : {id - dist, id + dist}) {
					if (0 <= k && k < N && k != i && k != j) {
						if (goodTriple(i, j, k, H)) {
							triples.insert(std::set<int>{i, j, k});
						}
					}
				}
			}
		}
	};
	
	for (int i = 0; i < N; i++) {
		for (int j : {i - H[i], i + H[i]}) {
			if (0 <= j && j < N) {
				considerPair(i, j);
			}
		}
	}
	
	int answer = triples.size();
	auto considerTriple = [&](int i, int j, int k) {
		if (0 <= i && i < j && j < k && k < N && H[i] == k - j && H[j] == k - i && H[k] == j - i) {
			if (H[k] == j - i && H[i] != H[k]) {
				answer++;
			}
		}
	};
	
	std::map<int, std::vector<int>> diag1, diag2;
	for (int i = 0; i < N; i++) {
		diag1[i + H[i]].push_back(i);
		diag2[i - H[i]].push_back(i);
	}
	for (int j = 0; j < N; j++) {
		std::vector<int>& x = diag1[j + H[j]];
		std::vector<int>& y = diag2[j - H[j]];
		if (x.size() < y.size()) {
			for (int k : x) {
				int i = k - H[j];
				considerTriple(i, j, k);
			}
		}
		else {
			for (int i : y) {
				if (i < j) {
					int k = i + H[j];
					considerTriple(i, j, k);
				}
			}
		}
	}
	return answer;
}

void checkPart1() {
    readBothSecrets(output_secret);
    readBothGraderResults();
    
    compareRemainingLines(1);
}

void checkPart2() {
    int M = inf.readInt();
    inf.readSpace();

    int K = inf.readInt();
    inf.readEoln();

	int N = 0;
	std::string token = ouf.readToken();
	if (token == output_secret) {
		ouf.readSecret(extra_secret, _pv,
        	"Possible tampering with the output",
        	"Early termination of the solution (possibly calling exit)");
		N = ouf.readInt(3, M, "N");
	}
	else {
		try {
        	N = std::stoi(token);
    	} catch (const std::invalid_argument& e) {
			quitf(_wa, "N is not a number");
		} catch (const std::out_of_range& e) {
			quitf(_wa, "N is out of integer range");
    	}
		if (N < 3 || N > M)
			quitf(_wa, "N = %d is out of integer range", N);
	}
    
    std::vector<int> H;
    while (!ouf.seekEof() && (int)H.size() < N) {
        int h = ouf.readInt(1, N - 1, "Hi");
        H.push_back(h);
    }

    if (!ouf.seekEof() || (int)H.size() != N) {
        quitf(_wa, "length of H does not match N");
    }

    int T = countTriples(H);

    if (T >= K)
        quitf(_ok, "T = %d, K = %d\n", T, K);
    else
        quitp(1.0 * T / K, "T = %d, K = %d\n", T, K);
}

int main(int , char *argv[]) {
    registerChecker("triples", 4, argv);

    inf.readToken(input_secret);
    inf.readEoln();

    int part = inf.readInt();
    inf.readEoln();

    if (part == 1) {
        checkPart1();
    }
    else {
        checkPart2();
    }
}
