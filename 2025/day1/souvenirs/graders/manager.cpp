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

const int secret_g2m = 0x729B3F30;
const int secret_m2g = 0x35397FC0;
const int code_mask = 0x0000000F;

const int M2G_CODE__OK = 0;
const int M2G_CODE__DIE = 1;

const int G2M_CODE__OK_NEW_TRANSACTION = 0;
const int G2M_CODE__OK_END_OF_TRANSACTIONS = 1;
const int G2M_CODE__PV_CALL_EXIT = 13;
const int G2M_CODE__TAMPER_M2G = 14;
const int G2M_CODE__SILENT = 15;

int fifo_idx = 0;

enum class ActionMode {
  ok_new_transaction,
  ok_end_of_transactions,
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
  case G2M_CODE__OK_NEW_TRANSACTION:
    ok_action_mode = ActionMode::ok_new_transaction;
    return;
  case G2M_CODE__OK_END_OF_TRANSACTIONS:
    ok_action_mode = ActionMode::ok_end_of_transactions;
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
using Compressed = int;
using Count = int;
using Money = LL;

#define read_index read_int
#define read_money read_ll
#define write_index write_int
#define write_money write_ll

const bool log_details = false;

const Count TRANSACTIONS_CNT_LIMIT = 5'000;

Index N;

constexpr Compressed compressed_len(Index len) {
  return div_ceil(len, 32);
}

void write_indices(const vector<Index>& X) {
  vector<Compressed> X_f(compressed_len(N), 0);
  for (Index idx : X)
    set_vi_bit(X_f, idx, 1);
  write_int_vector(X_f);
}

int main(int argc, char** argv) {
  registerManager("souvenirs", 1, argc, argv);

  N = inf.readInt();
  vector<Money> P(N);
  rep(i, N)
      P[i] = inf.readLong();
  fclose(stdin);

  log_var(N);
  log_printf("P:\n");
  log_array(P);

  write_secret();
  write_index(N);
  write_money(P[0]);
  out_flush();

  Count transactions_cnt = 0;
  vector<Count> bought(N, 0);

  while (true) {
    log_printf("Checking for new transaction...\n");
    read_secret();
    if (ok_action_mode != ActionMode::ok_new_transaction)
      break;
    log_printf("Received a new transaction\n");

    const Money M = read_money();
    log_var(M);

    if (++transactions_cnt > TRANSACTIONS_CNT_LIMIT)
      die_too_many_calls("Used too many transactions");
    if (M >= P[0])
      die_invalid_argument(format("M (%lld) >= P[0] (%lld)", M, P[0]));
    if (M < P[N - 1])
      die_invalid_argument(format("M (%lld) < P[N-1] (%lld)", M, P[N - 1]));

    vector<Index> L;
    Money R = M;
    rep(idx, N) if (P[idx] <= R) {
      L.push_back(idx);
      R -= P[idx];
    }

    if (log_details) {
      log_printf("L:\n");
      log_array(L);
    } else {
      log_printf("L size=%d\n", sz(L));
    }
    log_var(R);

    ensuref(0 <= R, "negative value of R=%lld", R);
    if (L.empty())
      quitf(_wa, "Nothing is bought with M=%lld", M);
    ensuref(0 <= L[0], "negative index L[%d]=%d", 0, L[0]);
    rep(i, sz(L)) {
      ensuref(L[i] < N, "too large index L[%d]=%d", i, L[i]);
      ensuref(i == 0 || L[i - 1] < L[i], "L is not increasing, L[%d]=%d, L[%d]=%d", i - 1, L[i - 1], i, L[i]);
    }

    for (Index idx : L)
      bought[idx]++;

    log_printf("Sending transaction results...\n");
    write_secret();
    write_indices(L);
    write_money(R);
    out_flush();
    log_printf("Transaction results sent.\n");
  }

  ensuref(ok_action_mode == ActionMode::ok_end_of_transactions, "Expected action code ok_end_of_transactions");
  log_printf("No more transactions.\n");

  // Final checking
  rep(idx, N) if (bought[idx] != idx)
      quitf(_wa, "Item %d is bought %d times, expected %d", idx, bought[idx], idx);
  quitf(_ok, "Finished successfully with %d transaction(s)", transactions_cnt);
}
