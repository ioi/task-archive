#include "ballmachine.h"
#include <string>
#include <cstdio>
#include <cstdlib>
#include <csignal>

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

// utils

#define rep(i, n) for (int i = 0, i##__n = (int)(n); i < i##__n; ++i)

template <class C>
int sz(const C& c) {
	return int(c.size());
}

using LL = long long;

// grader/manager protocol

const int secret_g2m = 0x729B3F30;
const int secret_m2g = 0x35397FC0;
const int code_mask = 0x0000000F;
const int M2G_CODE__OK = 0;

const int G2M_CODE__OK_NEW_TRANSACTION = 0;
const int G2M_CODE__OK_END_OF_TRANSACTIONS = 1;
const int G2M_CODE__PV_CALL_EXIT = 13;
const int G2M_CODE__TAMPER_M2G = 14;
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

void write_secret(int g2m_code) {
	write_int(secret_g2m | g2m_code);
}

NORETURN void die(int g2m_code) {
	if (g2m_code == G2M_CODE__OK_NEW_TRANSACTION || g2m_code == G2M_CODE__OK_END_OF_TRANSACTIONS) {
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

void read_int_array(int* arr, int len) {
	if (len != (int)fread(arr, sizeof(*arr), len, fin)) {
		fprintf(stderr, "Could not read int array from fin\n");
		authorized_exit(3);
	}
}

void read_secret() {
	int secret = read_int();

	if ((secret & ~code_mask) != secret_m2g){
		die(G2M_CODE__TAMPER_M2G);
	}
	int m2g_code = secret & code_mask;
	if (m2g_code != M2G_CODE__OK){
		die(G2M_CODE__SILENT);
	}
}

void check_exit_protocol() {
	if (!exit_allowed)
		die(G2M_CODE__PV_CALL_EXIT);
}


// new communication functions

void write_int_vector( const vector<int>& vec ) {
	if (sz(vec) != (int)fwrite(vec.data(), sizeof(int), sz(vec), fout)) {
		fprintf(stderr, "Could not write vector of ints into fout\n"); 
		authorized_exit(3); 
	}
}

vector<int> read_int_dyn_vector() {
	int len = read_int(); 

	vector<int> vec(len); 

	read_int_array(vec.data(), sz(vec)); 

	return vec; 
}

void write_int_dyn_vector(const vector<int>& vec) {
	write_int( (int)vec.size() );
	write_int_vector( vec ); 
}

/*

void write_pair_vector(const vector<pair<int, int>>& vec) {
	write_int( (int)vec.size() ); 

	int len = (int)sz(vec);
	if (len != (int)fwrite(vec.data(), sizeof(pair<int, int>), len, fout)) {
		fprintf(stderr, "Could not write vector of pairs into fout\n"); 
		authorized_exit(3); 
	}
}

void write_ll(LL x) {
  if (1 != fwrite(&x, sizeof(x), 1, fout)) {
    fprintf(stderr, "Could not write ll to fout\n");
    authorized_exit(3);
  }
}

LL read_ll() {
  LL x;
  if (1 != fread(&x, sizeof(x), 1, fin)) {
    fprintf(stderr, "Could not read ll from fin\n");
    authorized_exit(3);
  }
  return x;
}

void read_int_vector(vector<int>& v) {
  read_int_array(v.data(), sz(v));
}

vector<pair<int, int>> read_pair_vector() {
	int len = read_int(); 

	vector< pair<int, int> > vec(len); 

	if (len > 0 && len != (int)fread(vec.data(), sizeof(pair<int, int>), len, fin)) {
		fprintf(stderr, "Could not read vector of pairs from fin\n"); 
		authorized_exit(3); 
	}

	return vec; 
}

*/

// program logic

enum class ActionType {
    INSERT, 	// 0
    COLLECT, 	// 1
	RETURN, 	// 2
}; 
#define ACTION_INSERT 	0
#define ACTION_COLLECT  1
#define ACTION_RETURN 	2

#define write_node 			write_int
#define write_ball 			write_int
#define read_dfs_order 		read_int_dyn_vector


void return_results(std::vector< int > result) {
	write_secret(G2M_CODE__OK_NEW_TRANSACTION);
	write_int(ACTION_RETURN); 
	write_int_dyn_vector(result); 

	out_flush(); 

	read_secret(); 
}


}

bool insert(int x, int y) {
	write_secret(G2M_CODE__OK_NEW_TRANSACTION); 
	write_int(ACTION_INSERT); 
	write_node(x); 
	write_ball(y); 

	out_flush(); 

	read_secret(); 
	switch (read_int()) {
		case 0 : 
			return false; 
			break;
		case 1 : 
			return true; 
			break;
		default: 
			die(G2M_CODE__TAMPER_M2G); 
	}; 
}

std::vector<int> collect() {
	write_secret(G2M_CODE__OK_NEW_TRANSACTION); 
	write_int(ACTION_COLLECT); 

	out_flush(); 

	read_secret(); 
	std::vector<int> ord = read_int_dyn_vector(); 
	return ord; 
}

int main() {
	signal(SIGPIPE, SIG_IGN);
	atexit(check_exit_protocol);
	at_quick_exit(check_exit_protocol);


	read_secret(); 
	int M = read_int(); 

	std::vector< int > result = find_structure(M);

	return_results(result); 

	write_secret(G2M_CODE__OK_END_OF_TRANSACTIONS); 
	out_flush(); 
	authorized_exit(0); 

	return 0;
}
