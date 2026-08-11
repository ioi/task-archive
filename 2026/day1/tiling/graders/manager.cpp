#include "testlib.h"
#include <cstdio>
#include <csignal>
#include <string>

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
__attribute__((format(printf, 1, 2)))
#endif
void
log_printf(const char* fmt, ...) {
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

  { // Keep alive on broken pipes
    // signal(SIGPIPE, SIG_IGN);
    struct sigaction sa;
    sa.sa_handler = SIG_IGN;
    sigaction(SIGPIPE, &sa, NULL);
  }

  int required_args = 1 + 2 * num_processes;
  if (argc < required_args || required_args + 1 < argc) {
    string usage = format("'%s'", argv[0]);
    for (int i = 0; i < num_processes; i++)
      usage += format(" sol%d-to-mgr mgr-to-sol%d", i, i);
    usage += " [mgr_log] < input-file";
    quitf(_fail,
          "Manager for problem %s:\n"
          "Invalid number of arguments: %d\n"
          "Usage: %s",
          probName.c_str(), argc - 1, usage.c_str());
  }

  inf.init(stdin, _input);
  closeOnHalt(stdout);
  closeOnHalt(stderr);

  mgr2sol.resize(num_processes);
  sol2mgr.resize(num_processes);
  for (int i = 0; i < num_processes; i++) {
    mgr2sol[i] = openFile(argv[1 + 2 * i + 1], "a");
    sol2mgr[i] = openFile(argv[1 + 2 * i + 0], "r");
  }

  if (argc > required_args) {
    log_file = openFile(argv[required_args], "w");
  } else {
    log_file = nullptr;
  }
}
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

void set_vi_bit(vector<int>& v, int i, int b) {
  int& x = v[i / 32];
  int j = i % 32;
  if (b == 1)
    x |= (1 << j);
  else
    x &= ~(1 << j);
}

#define log_var(var_name) log_printf("%s = %s\n", #var_name, toString(var_name).c_str());

template <class C>
void log_array(const C& c, string delim = " ", string ending = "\n") {
  string d = "";
  for (const auto& x : c) {
    log_printf("%s%s", d.c_str(), toString(x).c_str());
    d = delim;
  }
  log_printf("%s", ending.c_str());
}

// grader/manager protocol

const int secret_g2m = 0xE1E91A00;
const int secret_m2g = 0x1115CC00;
const int code_mask = 0x0000000F;

const int M2G_CODE__OK = 0;
const int M2G_CODE__DIE = 1;

const int G2M_CODE__OK_BEGIN_PLACEMENTS = 0;
const int G2M_CODE__OK_NEW_PLACEMENT = 1;
const int G2M_CODE__OK_END_OF_PLACEMENTS = 2;
const int G2M_CODE__PV_CALL_EXIT = 13;
const int G2M_CODE__TAMPER_M2G = 14;
const int G2M_CODE__SILENT = 15;

int fifo_idx = 0;

enum class ActionMode {
  ok_begin_placements,
  ok_new_placement,
  ok_give_up,
  ok_end_of_placements,
} ok_action_mode;

void out_flush() {
  fflush(mgr2sol[fifo_idx]);
}

void write_int(int x) {
  if (1 != fwrite(&x, sizeof(x), 1, mgr2sol[fifo_idx])) {
    nullifyFile(fifo_idx);
    // add logging here
  }
}

void write_ll(LL x) {
  if (1 != fwrite(&x, sizeof(x), 1, mgr2sol[fifo_idx])) {
    nullifyFile(fifo_idx);
    // add logging here
  }
}

void write_int_vector(const vector<int>& arr) {
  int len = (int)sz(arr);
  if (len != (int)fwrite(arr.data(), sizeof(int), len, mgr2sol[fifo_idx])) {
    nullifyFile(fifo_idx);
    // add logging here
  }
}

void write_secret(int m2g_code = M2G_CODE__OK) {
  write_int(secret_m2g | m2g_code);
}

#ifdef __GNUC__
__attribute__((format(printf, 2, 3)))
#endif
NORETURN void
die(TResult result, const char* format, ...) {
  FMT_TO_RESULT(format, format, message);
  log_printf("Dying with message '%s'\n", message.c_str());
  rep(i, sz(mgr2sol)) if (mgr2sol[i] != nullptr) {
    fifo_idx = i;
    log_printf("Sending secret with code DIE to mgr2sol[%d]\n", fifo_idx);
    write_secret(M2G_CODE__DIE);
    out_flush();
  }
  log_printf("Quitting with result code %d\n", int(result));
  quit(result, message);
}

NORETURN void die_invalid_argument(const string& msg) {
  RESULT_MESSAGE_WRONG += ": Invalid argument";
  die(_wa, "%s", msg.c_str());
}

NORETURN void die_too_many_calls(const string& msg) {
  RESULT_MESSAGE_WRONG += ": Too many calls";
  die(_wa, "%s", msg.c_str());
}

int read_int() {
  int x;
  if (1 != fread(&x, sizeof(x), 1, sol2mgr[fifo_idx])) {
    nullifyFile(fifo_idx);
    die(_fail, "Could not read int from sol2mgr[%d]", fifo_idx);
  }
  return x;
}

LL read_ll() {
  LL x;
  if (1 != fread(&x, sizeof(x), 1, sol2mgr[fifo_idx])) {
    nullifyFile(fifo_idx);
    die(_fail, "Could not read ll from sol2mgr[%d]", fifo_idx);
  }
  return x;
}

void read_int_array(int* arr, int len) {
  if (len != (int)fread(arr, sizeof(*arr), len, sol2mgr[fifo_idx])) {
    nullifyFile(fifo_idx);
    die(_fail, "Could not read int array from sol2mgr[%d]", fifo_idx);
  }
}

void read_secret() {
  int secret = read_int();
  if ((secret & ~code_mask) != secret_g2m)
    die(_pv, "Possible tampering with sol2mgr[%d]", fifo_idx);
  int g2m_code = secret & code_mask;
  switch (g2m_code) {
  case G2M_CODE__OK_BEGIN_PLACEMENTS:
    ok_action_mode = ActionMode::ok_begin_placements;
    return;
  case G2M_CODE__OK_NEW_PLACEMENT:
    ok_action_mode = ActionMode::ok_new_placement;
    return;
  case G2M_CODE__OK_END_OF_PLACEMENTS:
    ok_action_mode = ActionMode::ok_end_of_placements;
    return;
  case G2M_CODE__SILENT:
    die(_fail, "Unexpected g2m_code SILENT from sol2mgr[%d]", fifo_idx);
  case G2M_CODE__TAMPER_M2G:
    die(_pv, "Possible tampering with mgr2sol[%d]", fifo_idx);
  case G2M_CODE__PV_CALL_EXIT:
    die(_pv, "Solution[%d] called exit()", fifo_idx);
  default:
    die(_fail, "Unknown g2m_code %d from sol2mgr[%d]", g2m_code, fifo_idx);
  }
}

// problem logic

using Index = int;

#define read_index read_int
#define write_index write_int

const int MINN = 1, MAXN = 100;

int main(int argc, char** argv) {
  registerManager("tiling", 1, argc, argv);
  int N = inf.readInt(MINN, MAXN);
  int M = inf.readInt(MINN, MAXN);
  const int total = N * M;
  vector<array<int, 4>> tiles(total);
  rep(k, total) {
    rep(t, 4) tiles[k][t] = inf.readInt(0, 1);
    ensuref(tiles[k][0] + tiles[k][1] + tiles[k][2] + tiles[k][3] <= 3, "Tile %d has all black squares", k);
  }
  fclose(stdin);

  log_var(N);
  log_var(M);

  vector<vector<char>> val(2 * N, vector<char>(2 * M, 0)); 
  vector<vector<char>> occupied(N, vector<char>(M, 0));

  auto place_square = [&](int i, int j, int k) -> bool {
    val[i][j] = tiles[k][0];
    val[i][j + 1] = tiles[k][1];
    val[i + 1][j] = tiles[k][2];
    val[i + 1][j + 1] = tiles[k][3];
    for (int dr = -1; dr <= 1; dr++)
      for (int dc = -1; dc <= 1; dc++) {
        int sr = i + dr, sc = j + dc;
        if (sr < 0 || sc < 0 || sr + 1 > 2 * N - 1 || sc + 1 > 2 * M - 1)
          continue;
        if (val[sr][sc] && val[sr][sc + 1] && val[sr + 1][sc] && val[sr + 1][sc + 1])
          return false;
      }
    return true;
  };

  write_secret();
  write_int(N);
  write_int(M);
  out_flush();

  read_secret();
  if (ok_action_mode != ActionMode::ok_begin_placements)
    die(_pv, "Expected ok_begin_placements but got %d", int(ok_action_mode));

  for (int step = 0; step < total; ++step) {
    write_secret();
    rep(t, 4) write_int(tiles[step][t]);
    out_flush();

    read_secret();

    if (ok_action_mode != ActionMode::ok_new_placement)
      die(_pv, "Expected ok_new_placement but got %d", int(ok_action_mode));

    const int i = read_int();
    const int j = read_int();

    if (i < 0 || i > 2 * N - 2 || i % 2 != 0) {
      die(_wa, "i (%d) is invalid", i);
    }
    if (j < 0 || j > 2 * M - 2 || j % 2 != 0) {
      die(_wa, "j (%d) is invalid", j);
    }
    if (occupied[i / 2][j / 2])
      die(_wa, "Position (%d, %d) already occupied", i, j);
    if (!place_square(i, j, step))
      die(_wa, "Placement at (%d, %d) creates a 2x2 black square", i, j);

    occupied[i / 2][j / 2] = 1;
  }

  read_secret();
  if (ok_action_mode != ActionMode::ok_end_of_placements)
    die(_pv, "Expected ok_end_of_placements but got %d", int(ok_action_mode));
  
  quitf(_ok, "Correct solution with %d placement(s)", total);

}
