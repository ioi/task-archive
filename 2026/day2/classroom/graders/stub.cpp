#include "classroom.h"

#include <csignal>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <vector>

namespace {

/******************************** Begin testlib-related material ********************************/
#ifdef _MSC_VER
#   define NORETURN __declspec(noreturn)
#elif defined __GNUC__
#   define NORETURN __attribute__ ((noreturn))
#else
#   define NORETURN
#endif
/********************************* End testlib-related material *********************************/


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

const int FIND_PROCESS = 0;

FILE* fin = stdin;
FILE* fout = stdout;

bool exit_allowed = false;

NORETURN void authorized_exit(int exit_code) {
	exit_allowed = true;
	exit(exit_code);
}

void write_int(int x) {
	if (1 != fwrite(&x, sizeof(x), 1, fout)) {
		fprintf(stderr, "Could not write int to fout\n");
		authorized_exit(3);
	}
}

void write_secret(int g2m_code = G2M_CODE__OK) {
	write_int(secret_g2m | g2m_code);
}

void write_int_array(const int* arr, int len) {
	if (fwrite(arr, sizeof(int), len, fout) != (size_t)len) {
		fprintf(stderr, "Could not write ints to fout\n");
		authorized_exit(3);
	}
}

NORETURN void die(int g2m_code) {
	if(g2m_code == G2M_CODE__OK) {
		fprintf(stderr, "Shall not die with code OK\n");
		authorized_exit(5);
	}
	fprintf(stderr, "Dying with code %d\n", g2m_code);
	if(g2m_code != G2M_CODE__SILENT)
		write_secret(g2m_code);
	fclose(fin);
	fclose(fout);
	authorized_exit(0);
}

void out_flush() {
	if (fout == nullptr || fflush(fout) != 0) {
		fprintf(stderr, "Could not flush fout\n");
		authorized_exit(3);
	}
}

[[noreturn]] void finish_normally() {
	std::exit(0);
}

[[noreturn]] void report_tampering() {
	write_secret(G2M_CODE__PV_TAMPER_M2G);
	out_flush();
	finish_normally();
}


int read_int() {
	int x;
	if (1 != fread(&x, sizeof(x), 1, fin)) {
		fprintf(stderr, "Could not read int from fin\n");
		authorized_exit(3);
	}
	return x;
}

void read_int_array(int* arr, int len) {
	if (int ret = fread(arr, sizeof(int), len, fin); len != ret) {
		fprintf(stderr, "Could not read int array of size %d from fin, fread returned %d\n", len, ret);
		authorized_exit(3);
	}
}

void read_secret() {
	int secret = read_int();
	if((secret & ~code_mask) != secret_m2g)
		die(G2M_CODE__PV_TAMPER_M2G);
	int m2g_code = secret & code_mask;
	if(m2g_code != M2G_CODE__OK)
		die(G2M_CODE__SILENT);
}

void check_exit_protocol() {
  if (!exit_allowed)
    die(G2M_CODE__PV_CALL_EXIT);
}

std::vector<int> read_vector() {
	int len = read_int();
	if (len < 0) {
		finish_normally();
	}

	std::vector<int> values(len);
	read_int_array(values.data(), len);
	return values;
}

std::vector<std::vector<int>> read_matrix() {
	int rows = read_int();
	if (rows < 0) {
		finish_normally();
	}

	std::vector<std::vector<int>> matrix(rows);
	for (int i = 0; i < rows; ++i) {
		matrix[i] = read_vector();
	}
	return matrix;
}

void write_vector(const std::vector<int>& values) {
	write_int(values.size());
	write_int_array(values.data(), (int)values.size());
}

void write_vector(const std::vector<std::vector<int>>& matrix) {
	write_int(matrix.size());
	for (const std::vector<int>& row : matrix) {
		write_vector(row);
	}
}

void run_process_step() {
	int N = read_int();
	int M = read_int();
	int R = read_int();
	std::vector<int> T = read_vector();
	std::vector<std::vector<int>> A = read_matrix();

	std::vector<std::vector<int>> B = process_step(N, M, R, T, A);

	write_secret();
	write_vector(B);
	out_flush();
}

void run_determine_steps() {
	int N = read_int();
	int M = read_int();
	std::vector<std::vector<int>> A = read_matrix();

	std::vector<int> D = determine_steps(N, M, A);

	write_secret();
	write_vector(D);
	out_flush();
}

int parse_nonnegative_integer(const char* text) {
	char* end = nullptr;
	long value = std::strtol(text, &end, 10);
	if (text[0] == '\0' || *end != '\0' || value < 0 || value > INT_MAX) {
		return -1;
	}
	return (int)value;
}

void run_send_process() {
	while (true) {
		read_secret();
		int call_type = read_int();

		if (call_type == CALL_EXIT) {
			finish_normally();
		}
		if (call_type != CALL_PROCESS_STEP) {
			report_tampering();
		}
		run_process_step();
	}
}

void run_find_process() {
	while (true) {
		read_secret();
		int call_type = read_int();

		if (call_type == CALL_EXIT) {
			finish_normally();
		}
		if (call_type != CALL_DETERMINE_STEPS) {
			report_tampering();
		}
		run_determine_steps();
	}
}

}  // namespace

int main(int argc, char** argv) {
	signal(SIGPIPE, SIG_IGN);
	atexit(check_exit_protocol);
	at_quick_exit(check_exit_protocol);

	if(argc < 2) {
		fprintf(stderr, "invalid args\n");
		authorized_exit(1);
	}

	int process_id = parse_nonnegative_integer(argv[1]);
	if (process_id == FIND_PROCESS) {
		run_find_process();
	}
	run_send_process();
}
