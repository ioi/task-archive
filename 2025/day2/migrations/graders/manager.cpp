#include "testlib.h"
#include <csignal>
#include <random>
#include <vector>
#include <algorithm>

using namespace std;


/******************************** Begin testlib-related material ********************************/

inline FILE* openFile(const char* name, const char* mode) {
	FILE* file = fopen(name, mode);
	if (!file)
		quitf(_fail, "Could not open file '%s' with mode '%s'.", name, mode);
	closeOnHalt(file);
	return file;
}


vector<FILE*> mgr2sol, sol2mgr;
FILE* log_file = nullptr;

void nullifyFile(int idx) {
	mgr2sol[idx] = sol2mgr[idx] = nullptr;
}

#ifdef __GNUC__
__attribute__ ((format (printf, 1, 2)))
#endif
void log_printf(const char* fmt, ...) {
	if (log_file) {
		FMT_TO_RESULT(fmt, fmt, message);
		fprintf(log_file, "%s", message.c_str());
		fflush(log_file);
	}
}

void registerManager(std::string probName, int num_processes, int argc, char* argv[]) {
	setName("manager for problem %s", probName.c_str());
	__testlib_ensuresPreconditions();
	testlibMode = _checker;
	random_t::version = 1; // Random generator version
	__testlib_set_binary(stdin);
	ouf.mode = _output;

	{//Keep alive on broken pipes
		//signal(SIGPIPE, SIG_IGN);
		struct sigaction sa;
		sa.sa_handler = SIG_IGN;
		sigaction(SIGPIPE, &sa, NULL);
	}

	int required_args = 1 + 2 * num_processes;
	if (argc < required_args || required_args+1 < argc) {
		string usage = format("'%s'", argv[0]);
		for (int i = 0; i < num_processes; i++)
			usage += format(" sol%d-to-mgr mgr-to-sol%d", i, i);
		usage += " [mgr_log] < input-file";
		quitf(_fail,
			"Manager for problem %s:\n"
			"Invalid number of arguments: %d\n"
			"Usage: %s",
			probName.c_str(), argc-1, usage.c_str());
	}

	inf.init(stdin, _input);
	closeOnHalt(stdout);
	closeOnHalt(stderr);

	mgr2sol.resize(num_processes);
	sol2mgr.resize(num_processes);
	for (int i = 0; i < num_processes; i++) {
		mgr2sol[i] = openFile(argv[1 + 2*i + 1], "a");
		sol2mgr[i] = openFile(argv[1 + 2*i + 0], "r");
	}

	if (argc > required_args) {
		log_file = openFile(argv[required_args], "w");
	} else {
		log_file = nullptr;
	}
}
/********************************* End testlib-related material *********************************/

// grader/manager protocol

const int secret_g2m = 0x852CA190;
const int secret_m2g = 0xD248E6C0;
const int code_mask  = 0x0000000F;

const int M2G_CODE__OK = 0;
const int M2G_CODE__DIE = 1;

const int G2M_CODE__OK = 0;
const int G2M_CODE__PV_CALL_EXIT = 13;
const int G2M_CODE__PV_TAMPER_M2G = 14;
const int G2M_CODE__SILENT = 15;


int fifo_idx = 0;

void out_flush() {
	fflush(mgr2sol[fifo_idx]);
}

void write_int(int x) {
	FILE* fout = mgr2sol[fifo_idx];
	if (1 != fwrite(&x, sizeof(x), 1, fout)) {
		nullifyFile(fifo_idx);
		log_printf("Could not write int to mgr2sol[%d]\n", fifo_idx);
	}
}

void write_int_array(const int* arr, int len) {
	FILE* fout = mgr2sol[fifo_idx];
	if (int ret = fwrite(arr, sizeof(int), len, fout); len != ret) {
		nullifyFile(fifo_idx);
		log_printf("Could not write int array of size %d to mgr2sol[%d], fwrite returned %d\n", len, fifo_idx, ret);
	}
}

void write_int_vector(const vector<int>& v) {
	write_int_array(v.data(), v.size());
}

void write_secret(int m2g_code = M2G_CODE__OK) {
	write_int(secret_m2g | m2g_code);
}

#ifdef __GNUC__
__attribute__ ((format (printf, 2, 3)))
#endif
NORETURN void die(TResult result, const char* format, ...) {
	FMT_TO_RESULT(format, format, message);
	log_printf("Dying with message '%s'\n", message.c_str());
	for (int i = 0; i < (int)mgr2sol.size(); ++i)
		if(mgr2sol[i] != nullptr) {
			fifo_idx = i;
			log_printf("Sending secret with code DIE to mgr2sol[%d]\n", fifo_idx);
			write_secret(M2G_CODE__DIE);
			out_flush();
		}
	log_printf("Quitting with result code %d\n", int(result));
	quit(result, message);
}

NORETURN void die_invalid_action(const string &msg) {
	//RESULT_MESSAGE_WRONG += ": Invalid action";
	die(_wa, "%s", msg.c_str());
}

NORETURN void die_too_many_messages(const string &msg) {
	//RESULT_MESSAGE_WRONG += ": Too many messages";
	die(_wa, "%s", msg.c_str());
}

NORETURN void die_rte(const string &msg) {
	RESULT_MESSAGE_WRONG = "Runtime Error";
	die(_wa, "%s", msg.c_str());
}

int read_int() {
	FILE* fin = sol2mgr[fifo_idx];
	int x;
	if (1 != fread(&x, sizeof(x), 1, fin)) {
		nullifyFile(fifo_idx);
		die_rte("manual RTE, cant read int from grader");
//		die(_fail, "Could not read int from sol2mgr[%d]", fifo_idx);
	}
	return x;
}


void read_secret() {
	int secret = read_int();
	if((secret & ~code_mask) != secret_g2m)
		die(_pv, "Possible tampering with sol2mgr[%d]", fifo_idx);
	int g2m_code = secret & code_mask;
	switch (g2m_code) {
		case G2M_CODE__OK:
			return;
		case G2M_CODE__SILENT:
			die(_fail, "Unexpected g2m_code SILENT from sol2mgr[%d]", fifo_idx);
		case G2M_CODE__PV_TAMPER_M2G:
			die(_pv, "Possible tampering with mgr2sol[%d]", fifo_idx);
		case G2M_CODE__PV_CALL_EXIT:
			die(_pv, "Solution[%d] called exit()", fifo_idx);
		default:
			die(_fail, "Unknown g2m_code %d from sol2mgr[%d]", g2m_code, fifo_idx);
	}
}


const int MESSAGE_CNT_LIMIT = 50;
const int MIN_ACTION = 0, MAX_ACTION = 20000;
int Z = 0, M = 0;

struct TestCase {
	int type;
	int N;
	vector<int> P;
	string strat = "";
	int U = 0, V = 0, mU = 0, seed = 0;

	int get_diameter() const;
	int get_distance(int U, int V) const;

	private:
	vector<vector<int>> get_adj() const;
	vector<int> bfs(int root) const;
};
vector<vector<int>> TestCase::get_adj() const {
	vector<vector<int>> adj(N, vector<int>());
	for (int i = 1; i < N; ++i) {
		int x = i, y = P[i];
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	return adj;
}
vector<int> TestCase::bfs(int root) const {
	vector<int> dist(N, N);
	dist[root] = 0;
	vector<int> q = {root};
	vector<vector<int>> adj = get_adj();
	for (int i = 0; i < (int)q.size(); ++i) {
		int x = q[i];
		for (int y : adj[x]) {
			if (dist[y] == N) {
				dist[y] = dist[x] + 1;
				q.push_back(y);
			}
		}
	}
	return dist;
}
int TestCase::get_distance(int U, int V) const {
	vector<int> dist = bfs(U);
	return dist[V];
}
int TestCase::get_diameter() const {
	vector<int> dist = bfs(0);
	int u = 0;
	for (int i = 1; i < N; ++i) {
		if (dist[i] > dist[u])
			u = i;
	}
	dist = bfs(u);
	return *max_element(dist.begin(), dist.end());
}

TestCase ReadTestCase() {
	int type = inf.readInt();
	if (type < 3) {
		int N = inf.readInt();
		vector<int> P(N, 0);
		for (int i = 1; i < N; ++i)
			P[i] = inf.readInt();
	
		fclose(stdin);
		return TestCase{
			.type = type,
			.N = N,
			.P = P
		};
	}
	else {
		string strat = inf.readToken();
		int seed = inf.readInt();
		rnd.setSeed(seed);

		vector<int> P = {0, 0, 1, 2, 3, 4, 0, 1, 2, 3, 4};
		int U = rnd.next(512,1023), V = rnd.next(512, 1023);
		while (U == V)
			V = rnd.next(512, 1023);
		int L = max(U, V);
		for (int i = 11; i <= L; ++i) {
			if (i == U)
				P.push_back(10);
			else if (i == V)
				P.push_back(5);
			else
				P.push_back(1);
		}
		return TestCase{
			.type = type,
			.N = 10000,
			.P = P,
			.strat = strat,
			.U = U, .V = V,
			.seed = seed
		};
	}
}

vector<int> RunEncoder(TestCase &test) {
	vector<int> S(test.N, 0);

	for(int i = 1; i < test.N; ++i) {
		write_secret();
		write_int(test.N);
		write_int(i);
		write_int(test.P[i]);
		out_flush();

		read_secret();
		S[i] = read_int();
		if (S[i] < MIN_ACTION || S[i] > MAX_ACTION)
			die_invalid_action("send_message returned an invalid action");
		if (S[i] > 0)
			++M;
		if (M > MESSAGE_CNT_LIMIT)
			die_too_many_messages("Sent too many messages");
		
		Z = max(Z, S[i]);

		if (test.type == 3 && i + 1 == (int)test.P.size()) {
			if (S[i] == 0)
				test.P.push_back(1);
			else {
				if (test.strat == "U") {
					test.P.push_back(test.U);
					test.U = i + 1;
				}
				else if (test.strat == "V") {
					test.P.push_back(test.V);
					test.V = i + 1;
				}
				else if (test.strat == "both") {
					if (rnd.next() < 0.5)
						swap(test.U, test.V);
					test.P.push_back(test.U);
					test.P.push_back(test.V);
					test.U = i + 1;
					test.V = i + 2;
				}
				else if (test.strat == "rand") {
					if (rnd.next() < 0.5)
						swap(test.U, test.V);
					test.P.push_back(test.U);
					test.U = i + 1;
				}
				else if (test.strat == "match") {
					if (rnd.next() < 0.5)
						swap(test.U, test.V);
					if (test.mU == 0) {
						test.mU = S[i];
						test.P.push_back(test.U);
						test.U = i + 1;
					}
					else {
						if (S[i] == test.mU) {
							test.P.push_back(test.U);
							test.U = i + 1;
						}
						else {
							test.P.push_back(test.V);
							test.V = i + 1;
						}
					}
				}
			}
		}
	}
	test.P.resize(test.N);

	write_secret();
	write_int(-1);
	out_flush();

	return S;
}

void RunDecoder(const vector<int> &S, const TestCase &test) {
	write_secret();
	write_int(S.size());
	write_int_vector(S);
	out_flush();

	read_secret();
	int U = read_int(), V = read_int();
	
	if (U < 0 || U >= test.N || V < 0 || V >= test.N) {
		quitf(_wa, "invalid index in (U, V) = (%d, %d)", U, V);
	}
	int diam = test.get_diameter(), dist = test.get_distance(U, V);
	if (diam != dist) {
		quitf(_wa, "distance of (U, V): %d; maximum distance: %d, U=%d ^ V=%d", dist, diam, U, V);
	}
}

int main(int argc, char **argv) {
	registerManager("migrations", 2, argc, argv);

	fifo_idx = 0; // Mode: Encoder
	TestCase test = ReadTestCase();
	vector<int> S = RunEncoder(test);
	nullifyFile(fifo_idx);

	fifo_idx = 1; // Mode: Decoder
	RunDecoder(S, test);
	nullifyFile(fifo_idx);

	// scoring
	if (test.type == 0) {
		quitf(_ok, "Used %d messages; max message: %d", M, Z);
	}
	else if (test.type == 1) {
		if (Z >= 9998)
			quitp(10.0 / 30.0, "Used %d messages; max message: %d", M, Z);
		else if (Z >= 102)
			quitp(16.0 / 30.0, "Used %d messages; max message: %d", M, Z);
		else if (Z >= 5)
			quitp(23.0 / 30.0, "Used %d messages; max message: %d", M, Z);
		else
			quitf(_ok, "Used %d messages; max message: %d", M, Z);
	}
	else if (test.type == 2 || test.type == 3) {
		if (Z >= 5)
			quitp(0.5 - (5.0 / 14.0) * log(0.2 * Z) / log(4000.0),
				  "Used %d messages; max message: %d", M, Z);
		else {
			if (M <= 8)
				quitf(_ok, "Used %d messages; max message: %d", M, Z);
			else {
				double decay = 0.5 * log2(1.0 * max(M, 8) / 8.0);
				quitp(max(4.0 / 7.0, 1.0 - (3.0 / 7.0) * decay),
					  "Used %d messages; max message: %d", M, Z);
			}
		}
	}

	die(_fail, "Reached an unreachable code!!!");

	return 0;
}
