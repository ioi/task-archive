#include "migrations.h"
#include <csignal>
#include <cstdlib>
#include <cstdio>
#include <string>

using namespace std;


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


void write_secret(int g2m_code = G2M_CODE__OK) {
	write_int(secret_g2m | g2m_code);
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

// grader logic

NORETURN void run_encoder() {
	for (int N; read_secret(), (N = read_int()) != -1;) {
		int i = read_int();
		int P = read_int();

		int S = send_message(N, i, P);

		write_secret();
		write_int(S);
		out_flush();
	}
	die(G2M_CODE__SILENT);
}

NORETURN void run_decoder() {
	read_secret();
	int N = read_int();
	vector<int> S(N, 0);
	read_int_array(S.data(), N);

	auto [U, V] = longest_path(S);

	write_secret();
	write_int(U);
	write_int(V);
	out_flush();

	die(G2M_CODE__SILENT);
}

} // namespace

int main(int argc, char **argv) {
	signal(SIGPIPE, SIG_IGN);
	atexit(check_exit_protocol);
	at_quick_exit(check_exit_protocol);

	if(argc < 2) {
		fprintf(stderr, "invalid args\n");
		authorized_exit(1);
	}

	string grader_id = argv[1];
	if (grader_id == "0")
		run_encoder();

	if (grader_id == "1")
		run_decoder();

	fprintf(stderr, "invalid grader id: '%s'\n", grader_id.c_str());
	authorized_exit(1);
}
