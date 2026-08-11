#include "tiling.h"
#include <cstdio>
#include <cstdlib>
#include <csignal>
#include <utility>

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


const int secret_g2m = 0xE1E91A00;
const int secret_m2g = 0x1115CC00;
const int code_mask = 0x0000000F;

const int M2G_CODE__OK = 0;

const int G2M_CODE__OK_BEGIN_PLACEMENTS = 0;
const int G2M_CODE__OK_NEW_PLACEMENT = 1;
const int G2M_CODE__OK_END_OF_PLACEMENTS = 2;
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

} // namespace

int main() {
  signal(SIGPIPE, SIG_IGN);
  atexit(check_exit_protocol);
  at_quick_exit(check_exit_protocol);

  read_secret();
  const int n = read_int();
  const int m = read_int();
  const int total = n * m;

  init(n, m);

  write_secret(G2M_CODE__OK_BEGIN_PLACEMENTS);
  out_flush();

  for (int k = 0; k < total; k++) {
    read_secret();
    int tl = read_int(), tr = read_int(), bl = read_int(), br = read_int();

    pair<int, int> placement = receive_block(tl, tr, bl, br);

    write_secret(G2M_CODE__OK_NEW_PLACEMENT);
    write_int(placement.first);
    write_int(placement.second);
    out_flush();
  }
  
  write_secret(G2M_CODE__OK_END_OF_PLACEMENTS);
  out_flush();
  authorized_exit(0);
}
