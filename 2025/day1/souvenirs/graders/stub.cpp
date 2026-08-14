#include "souvenirs.h"
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
  return int(std::size(c));
}

using LL = long long;

template <class T>
constexpr T div_ceil(T a, T b) {
  return (a + b - 1) / b;
}

int get_vi_bit(const vector<int>& v, int i) {
  const int& x = v[i / 32];
  int j = i % 32;
  return (x >> j) & 1;
}

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

void write_ll(LL x) {
  if (1 != fwrite(&x, sizeof(x), 1, fout)) {
    fprintf(stderr, "Could not write ll to fout\n");
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

LL read_ll() {
  LL x;
  if (1 != fread(&x, sizeof(x), 1, fin)) {
    fprintf(stderr, "Could not read ll from fin\n");
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

void read_int_vector(vector<int>& v) {
  read_int_array(v.data(), sz(v));
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

using Index = int;
using Compressed = int;
using Count = int;
using Money = LL;

#define read_index read_int
#define read_money read_ll
#define write_index write_int
#define write_money write_ll

Index N;

constexpr Compressed compressed_len(Index len) {
  return div_ceil(len, 32);
}

vector<Index> read_indices() {
  vector<Compressed> X_f(compressed_len(N), 0);
  read_int_vector(X_f);
  vector<Index> X;
  rep(i, N) if (get_vi_bit(X_f, i))
      X.push_back(i);
  return X;
}

} // namespace

pair<vector<Index>, Money> transaction(Money M) {
  write_secret(G2M_CODE__OK_NEW_TRANSACTION);
  write_money(M);
  out_flush();

  read_secret();
  vector<Index> L = read_indices();
  Money R = read_money();
  return make_pair(L, R);
}

int main() {
  signal(SIGPIPE, SIG_IGN);
  atexit(check_exit_protocol);
  at_quick_exit(check_exit_protocol);

  read_secret();
  N = read_index();
  Money P0 = read_money();

  buy_souvenirs(N, P0);

  write_secret(G2M_CODE__OK_END_OF_TRANSACTIONS);
  out_flush();
  authorized_exit(0);
}
