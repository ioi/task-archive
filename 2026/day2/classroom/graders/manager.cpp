#include "testlib.h"

#include <algorithm>
#include <chrono>
#include <climits>
#include <cstddef>
#include <csignal>
#include <cstdio>
#include <random>
#include <string>
#include <vector>

using namespace std;

/******************************** Begin testlib-related material ********************************/

inline FILE* openFile(const char* name, const char* mode) {
	FILE* file = fopen(name, mode);
	if (!file) {
		quitf(_fail, "Could not open file '%s' with mode '%s'.", name, mode);
	}
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

int registerManager(string probName, int argc, char* argv[]) {
	setName("manager for problem %s", probName.c_str());
	__testlib_ensuresPreconditions();
	testlibMode = _checker;
	random_t::version = 1;
	__testlib_set_binary(stdin);
	ouf.mode = _output;

	{
		struct sigaction sa;
		sa.sa_handler = SIG_IGN;
		sigaction(SIGPIPE, &sa, NULL);
	}

	// int expected_argc = 2 + 2 * num_processes;
	// int expected_argc = 1 + 2 * num_processes;
	// if (argc != expected_argc) {
	// 	string usage = format("'%s'", argv[0]);
	// 	for (int i = 0; i < num_processes; i++) {
	// 		usage += format(" sol%d-to-mgr mgr-to-sol%d", i, i);
	// 	}
	// 	usage += " mgr_log < input-file";
	// 	quitf(
	// 		_fail,
	// 		"Manager for problem %s:\n"
	// 		"Invalid number of arguments: %d\n"
	// 		"Usage: %s",
	// 		probName.c_str(),
	// 		argc - 1,
	// 		usage.c_str()
	// 	);
	// }

	inf.init(stdin, _input);
	closeOnHalt(stdout);
	closeOnHalt(stderr);

	int num_processes = (argc - 1) / 2;
	mgr2sol.resize(num_processes);
	sol2mgr.resize(num_processes);
	for (int i = 0; i < num_processes; i++) {
		mgr2sol[i] = openFile(argv[1 + 2 * i + 1], "a");
		sol2mgr[i] = openFile(argv[1 + 2 * i + 0], "r");
	}

	// log_file = openFile(argv[1 + 2 * num_processes], "w");

	return num_processes;
}

/********************************* End testlib-related material *********************************/

// grader/manager protocol

const int secret_g2m = 0x4B93A7C0;
const int secret_m2g = 0xD03D8520;
const int code_mask  = 0x0000000F;

const int M2G_CODE__OK = 0;
const int M2G_CODE__DIE = 1;

const int G2M_CODE__OK = 0;
const int G2M_CODE__PV_CALL_EXIT = 13;
const int G2M_CODE__PV_TAMPER_M2G = 14;
const int G2M_CODE__SILENT = 15;

const int CALL_EXIT = -1;
const int CALL_PROCESS_STEP = 1;
const int CALL_DETERMINE_STEPS = 2;

const int MAX_SERIALIZED_INTS = 20000000;

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

void read_int_array(int* arr, int len) {
	if (len == 0) {
		return;
	}
	FILE* fin = sol2mgr[fifo_idx];
	if (fread(arr, sizeof(int), len, fin) != (size_t)len) {
		nullifyFile(fifo_idx);
		die_rte("manual RTE, cannot read int array from grader");
	}
}

void read_secret() {
	int secret = read_int();
	if ((secret & ~code_mask) != secret_g2m) {
		die(_pv, "Possible tampering with sol2mgr[%d]", fifo_idx);
	}
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

void write_vector(const vector<int>& values) {
	write_int(values.size());
	write_int_array(values.data(), (int)values.size());
}

void write_vector(const vector<vector<int>>& matrix) {
	write_int(matrix.size());
	for (const vector<int>& row : matrix) {
		write_vector(row);
	}
}

vector<int> read_vector_with_limit(int max_len, const string& what) {
	int len = read_int();
	if (len < 0 || len > max_len) {
		die_invalid_action(format("%s has invalid length %d", what.c_str(), len));
	}

	vector<int> values(len);
	read_int_array(values.data(), len);
	return values;
}

vector<vector<int>> read_matrix_with_rows(int expected_rows, const string& what) {
	int rows = read_int();
	if (rows != expected_rows) {
		die_invalid_action(format(
			"%s has invalid row count %d, expected %d",
			what.c_str(),
			rows,
			expected_rows
		));
	}

	vector<vector<int>> matrix(rows);
	int remaining = MAX_SERIALIZED_INTS;
	for (int i = 0; i < rows; ++i) {
		string row_name = format("%s[%d]", what.c_str(), i);
		matrix[i] = read_vector_with_limit(remaining, row_name);
		remaining -= (int)matrix[i].size();
	}
	return matrix;
}

void shutdown_processes() {
	for (int i = 0; i < (int)mgr2sol.size(); ++i) {
		if (mgr2sol[i] != nullptr) {
			fifo_idx = i;
			write_secret();
			write_int(CALL_EXIT);
			out_flush();
			nullifyFile(i);
		}
	}
}

struct InputData {
	int N;
	int M;
	vector<int> Q;
	vector<int> P;
};

InputData read_input() {
	int N = inf.readInt();
	int M = inf.readInt();

	vector<int> Q(N);
	for (int i = 0; i < N; ++i) {
		Q[i] = inf.readInt();
	}

	vector<int> P(N);
	for (int i = 0; i < N; ++i) {
		P[i] = inf.readInt();
	}

	return InputData{N, M, Q, P};
}

vector<vector<int>> call_process_step(
	int process,
	int N,
	int M,
	int R,
	const vector<int>& T,
	const vector<vector<int>>& A
) {
	fifo_idx = process;
	log_printf("Calling process_step for R=%d on process #%d\n", R, process + 1);

	write_secret();
	write_int(CALL_PROCESS_STEP);
	write_int(N);
	write_int(M);
	write_int(R);
	write_vector(T);
	write_vector(A);
	out_flush();

	read_secret();
	return read_matrix_with_rows(N, "process_step return value");
}

vector<int> call_determine_steps(int process, int N, int M, const vector<vector<int>>& A) {
	fifo_idx = process;
	log_printf("Calling determine_steps on process #%d\n", process + 1);

	write_secret();
	write_int(CALL_DETERMINE_STEPS);
	write_int(N);
	write_int(M);
	write_vector(A);
	out_flush();

	read_secret();
	return read_vector_with_limit(N, "determine_steps return value");
}

template <typename... Args>
void wrong_answer(const char *fmt, Args... args) {
    shutdown_processes();
	if constexpr (sizeof...(args) == 0) {
		quit(_wa, fmt);
	} else {
    	quitf(_wa, fmt, args...);
	}
}

template <typename... Args>
void ok(const char *fmt, Args... args) {
    shutdown_processes();
    quitf(_ok, fmt, args...);
}

template <typename... Args>
void partial(double p, const char *fmt, Args... args) {
    shutdown_processes();
    quitp(p, fmt, args...);
}

int main(int argc, char** argv) {
	const int NUM_PROCESSES = registerManager("classroom", argc, argv);
	const int SEND_PROCESS_COUNT = NUM_PROCESSES - 1;
	const int FIND_PROCESS = 0;  // Zero-based process index; this is public process #9.
	bool ENABLE_SHUFFLE = true;

	int T = inf.readInt();
	vector<InputData> inputs;
	vector<vector<vector<int>>> As(T);
	vector<int> orders, Rs(T);

	int M = 0;
	for (int t = 0; t < T; ++t) {
		InputData input = read_input();
		inputs.push_back(input);
		As[t] = vector<vector<int>>(input.N);
		M = max(M, input.M);
		for (int i = 0; i < input.M; ++i) {
			orders.push_back(t);
		}
	}

	mt19937 rng(42); // fixed seed for shuffle
	ENABLE_SHUFFLE = (SEND_PROCESS_COUNT < M);

	if (ENABLE_SHUFFLE) {
		shuffle(orders.begin(), orders.end(), rng);
	}
	int C = 0;
	
	int process = 0;
	for (int t_id : orders) {
		int R = Rs[t_id]; ++Rs[t_id];
		const auto &input = inputs[t_id];
		auto &A = As[t_id];
		vector<int> T;
		for (int i = 0; i < input.N; ++i) {
			if (input.Q[i] == R) {
				T.push_back(i);
			}
		}

		if (ENABLE_SHUFFLE) {
			process = rng() % NUM_PROCESSES;
		} else {
			process = (process + 1) % NUM_PROCESSES;
		}
		while (process == FIND_PROCESS) {
			if (ENABLE_SHUFFLE) {
				process = rng() % NUM_PROCESSES;
			} else {
				process = (process + 1) % NUM_PROCESSES;
			}
		}

		vector<vector<int>> B = call_process_step(process, input.N, input.M, R, T, A);

		for (int i = 0; i < input.N; ++i) {
			if (input.Q[i] == R && A[i] != B[i]) {
				wrong_answer("Invalid element in the returned array");
			}
			if (B[i].size() > 63) {
				wrong_answer("The length of a returned array exceeds 63");
			}
			for (int j = 0; j < (int)B[i].size(); ++j) {
				if (B[i][j] < 0 || B[i][j] > 63) {
					wrong_answer("Invalid element in the returned array");
				}
			}
			C = max(C, (int)B[i].size());
		}
		for (int i = 0; i < input.N; ++i) {
			A[input.P[i]] = B[i];
		}
	}
	for (int t_id = 0; t_id < T; ++t_id) {
		const auto &input = inputs[t_id];
		auto &A = As[t_id];
		vector<int> D = call_determine_steps(FIND_PROCESS, input.N, input.M, A);
		if ((int)D.size() != input.N) {
			wrong_answer("determine_steps returned an array with invalid size");
		}

		for (int i = 0; i < input.N; ++i) {
			if (D[i] != input.Q[i]) {
				wrong_answer(
					"Wrong Answer: D[%d] = %d, expected %d",
					i,
					D[i],
					input.Q[i]
				);
			}
		}
	}

	auto get_points = [&](int C) -> double {
		if (C <= 2) return 1.0;
		if (C <= 3) return 0.75;
		if (C <= 4) return 0.55;
		if (C <= 13) return 0.50 - 0.03 * (C - 5);
		if (C <= 63) return 0.19 * (64 - C) / (64 - 14) + 0.04;
		return 0.0;
	};
	if (C <= 2) {
		ok("Correct, C = %d", C);
	}
	partial(get_points(C), "Correct, C = %d", C);
	return 0;
}
