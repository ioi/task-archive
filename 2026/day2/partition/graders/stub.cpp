#include "partition.h"

#include <csignal>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

namespace {

/******************************** Begin testlib-related material ********************************/
#ifdef _MSC_VER
#define NORETURN __declspec(noreturn)
#elif defined __GNUC__
#define NORETURN __attribute__((noreturn))
#else
#define NORETURN
#endif
/********************************* End testlib-related material *********************************/

// grader/manager protocol

const int secret_g2m = 0x3C3CABA0;
const int secret_m2g = 0xA1B2C3D0;
const int code_mask = 0x0000000F;

const int M2G_CODE__OK = 0;

const int G2M_CODE__OK_NEW_PLACEMENT = 0;
const int G2M_CODE__OK_END_OF_PLACEMENTS = 1;
const int G2M_CODE__PV_CALL_EXIT = 13;
const int G2M_CODE__TAMPER_M2G = 14;
const int G2M_CODE__SILENT = 15;

const int ENCODER = 0;
const int DECODER = 1;
const int PROCESS_COUNT = 2;

bool exit_allowed = false;

NORETURN void authorized_exit(int exit_code) {
  exit_allowed = true;
  exit(exit_code);
}

FILE* fin = stdin;
FILE* fout = stdout;

void out_flush() {
  fflush(fout);
}

void write_int(int x) {
  if (1 != fwrite(&x, sizeof(x), 1, fout)) {
    fprintf(stderr, "Could not write int to fout\n");
    authorized_exit(3);
  }
}

void write_secret(int g2m_code) {
  write_int(secret_g2m | g2m_code);
}

NORETURN void die(int g2m_code) {
  if (g2m_code == G2M_CODE__OK_NEW_PLACEMENT || g2m_code == G2M_CODE__OK_END_OF_PLACEMENTS) {
    fprintf(stderr, "Shall not die with code OK\n");
    authorized_exit(5);
  }
  fprintf(stderr, "Dying with code %d\n", g2m_code);
  if (g2m_code != G2M_CODE__SILENT)
    write_secret(g2m_code);
  fclose(fin);
  fclose(fout);
  authorized_exit(0);
}

int read_int() {
  int x;
  if (1 != fread(&x, sizeof(x), 1, fin)) {
    fprintf(stderr, "Could not read int from fin\n");
    authorized_exit(3);
  }
  return x;
}

void read_secret() {
  int secret = read_int();
  if ((secret & ~code_mask) != secret_m2g)
    die(G2M_CODE__TAMPER_M2G);
  int m2g_code = secret & code_mask;
  if (m2g_code != M2G_CODE__OK)
    die(G2M_CODE__SILENT);
}

void check_exit_protocol() {
  if (!exit_allowed)
    die(G2M_CODE__PV_CALL_EXIT);
}

// problem logic

void run_encoder() {
  read_secret();
  int N = read_int();
  int K = read_int();
  int M = read_int();
  std::vector<int> A(N);
  for (int i = 0; i < N; ++i)
    A[i] = read_int();

  std::vector<int> C = add_numbers(A, K, M);

  write_secret(G2M_CODE__OK_NEW_PLACEMENT);
  write_int((int)C.size());
  for (int i = 0; i < (int)C.size(); ++i)
    write_int(C[i]);
  out_flush();
}

void run_decoder() {
  read_secret();
  int L = read_int();
  std::vector<int> B(L);
  for (int i = 0; i < L; ++i)
    B[i] = read_int();
  int K = read_int();

  std::vector<int> P = find_partition(B, K);

  write_secret(G2M_CODE__OK_NEW_PLACEMENT);
  write_int((int)P.size());
  for (int i = 0; i < (int)P.size(); ++i)
    write_int(P[i]);
  out_flush();
}

} // namespace

int parse_nonnegative_integer(const char* text) {
	char* end = nullptr;
	long value = std::strtol(text, &end, 10);
	if (text[0] == '\0' || *end != '\0' || value < 0 || value > INT_MAX) {
		return -1;
	}
	return (int)value;
}

int parse_process_id(const char* process_arg) {
	int process_id = parse_nonnegative_integer(process_arg);
	if (process_id < 0 || process_id >= PROCESS_COUNT) {
		std::exit(1);
	}
	return process_id;
}

int main(int argc, char** argv) {
	signal(SIGPIPE, SIG_IGN);
	atexit(check_exit_protocol);
	at_quick_exit(check_exit_protocol);

	if(argc < 2) {
		fprintf(stderr, "invalid args\n");
		authorized_exit(1);
	}
  
	int process_id = parse_process_id(argv[1]);
	if (process_id == ENCODER) {
		run_encoder();
	} else {
		run_decoder();
	}
	exit_allowed = true;
	return 0;
}
