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

const int secret_g2m = 0x3C3CABA0;
const int secret_m2g = 0xA1B2C3D0;
const int code_mask = 0x0000000F;

const int M2G_CODE__OK = 0;
const int M2G_CODE__DIE = 1;

const int G2M_CODE__OK_NEW_PLACEMENT = 0;
const int G2M_CODE__OK_END_OF_PLACEMENTS = 1;
const int G2M_CODE__PV_CALL_EXIT = 13;
const int G2M_CODE__TAMPER_M2G = 14;
const int G2M_CODE__SILENT = 15;

int fifo_idx = 0;

enum class ActionMode {
    ok_new_PLACEMENT,
    ok_end_of_PLACEMENTs,
} ok_action_mode;

bool is_dying = false;

#ifdef __GNUC__
__attribute__((format(printf, 2, 3)))
#endif
NORETURN void die(TResult result, const char* format, ...);

void out_flush() {
    if (mgr2sol[fifo_idx] != nullptr)
        fflush(mgr2sol[fifo_idx]);
}

void write_int(int x) {
    if (mgr2sol[fifo_idx] == nullptr || 1 != fwrite(&x, sizeof(x), 1, mgr2sol[fifo_idx])) {
        nullifyFile(fifo_idx);
        if (!is_dying)
            die(_unexpected_eof, "Could not write int to mgr2sol[%d]", fifo_idx);
        return;
    }
}

void write_ll(LL x) {
    if (mgr2sol[fifo_idx] == nullptr || 1 != fwrite(&x, sizeof(x), 1, mgr2sol[fifo_idx])) {
        nullifyFile(fifo_idx);
        if (!is_dying)
            die(_unexpected_eof, "Could not write ll to mgr2sol[%d]", fifo_idx);
        return;
    }
}

void write_int_vector(const vector<int>& arr) {
    int len = (int)sz(arr);
    if (mgr2sol[fifo_idx] == nullptr ||
        len != (int)fwrite(arr.data(), sizeof(int), len, mgr2sol[fifo_idx])) {
        nullifyFile(fifo_idx);
        if (!is_dying)
            die(_unexpected_eof, "Could not write int vector to mgr2sol[%d]", fifo_idx);
        return;
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
    if (!is_dying) {
        is_dying = true;
        rep(i, sz(mgr2sol)) if (mgr2sol[i] != nullptr) {
            fifo_idx = i;
            log_printf("Sending secret with code DIE to mgr2sol[%d]\n", fifo_idx);
            write_secret(M2G_CODE__DIE);
            out_flush();
        }
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
        die(_unexpected_eof, "Could not read int from sol2mgr[%d]", fifo_idx);
    }
    return x;
}

LL read_ll() {
    LL x;
    if (1 != fread(&x, sizeof(x), 1, sol2mgr[fifo_idx])) {
        nullifyFile(fifo_idx);
        die(_unexpected_eof, "Could not read ll from sol2mgr[%d]", fifo_idx);
    }
    return x;
}

void read_int_array(int* arr, int len) {
    if (len != (int)fread(arr, sizeof(*arr), len, sol2mgr[fifo_idx])) {
        nullifyFile(fifo_idx);
        die(_unexpected_eof, "Could not read int array from sol2mgr[%d]", fifo_idx);
    }
}

void read_secret() {
    int secret = read_int();
    if ((secret & ~code_mask) != secret_g2m)
        die(_pv, "Possible tampering with sol2mgr[%d]", fifo_idx);
    int g2m_code = secret & code_mask;
    switch (g2m_code) {
    case G2M_CODE__OK_NEW_PLACEMENT:
        ok_action_mode = ActionMode::ok_new_PLACEMENT;
        return;
    case G2M_CODE__OK_END_OF_PLACEMENTS:
        ok_action_mode = ActionMode::ok_end_of_PLACEMENTs;
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


int N, K, M;

int main(int argc, char** argv) {
    registerManager("partition", 2, argc, argv);
    const int MAXN = 100'000;
    const int MAXK = 100'000;
    const int MAXM = 1'000'000'000;

    N = inf.readInt(3, MAXN, "N");
    K = inf.readInt(2, MAXK, "K");
    M = inf.readInt(1, MAXM, "M");
    ensure(K <= N);

    vector<int> A(N);
    for (int i = 0; i < N; ++i)
        A[i] = inf.readInt(1, M, "A[i]");
    fclose(stdin);

    fifo_idx = 0;
    write_secret();
    write_int(N);
    write_int(K);
    write_int(M);
    for (int i = 0; i < N; ++i)
        write_int(A[i]);
    out_flush();

    read_secret();
    int S = read_int();
    if (S < 0 || S > K - 1)
        die(_wa, "add_numbers returned an array of length %d", S);
    vector<int> C(S);
    for (int i = 0; i < S; ++i)
        C[i] = read_int();

    for (int i = 0; i < S; ++i) {
        if (C[i] < 1 || C[i] > M)
            die(_wa, "add_numbers returned C[%d]=%d, which is not in [1, %d]", i, C[i], M);
    }

    vector<int> B = A;
    for (int i = 0; i < S; ++i)
        B.push_back(C[i]);

    sort(B.begin(), B.end());

    fifo_idx = 1;
    write_secret();
    write_int(sz(B));
    for (int i = 0; i < sz(B); ++i)
        write_int(B[i]);
    write_int(K);
    out_flush();

    read_secret();
    int P_len = read_int();
    if (P_len != sz(B))
        die(_wa, "find_partition returned an array of length %d", P_len);
    vector<int> P(P_len);
    for (int i = 0; i < P_len; ++i)
        P[i] = read_int();

    if (P_len != sz(B))
        die(_wa, "find_partition returned %d group indices, expected %d", P_len, sz(B));

    vector<LL> sums(K, 0);
    for (int i = 0; i < sz(B); ++i) {
        if (P[i] < 0 || P[i] >= K)
            die(_wa, "find_partition returned P[%d]=%d, which is not in [0, %d]", i, P[i], K - 1);
        sums[P[i]] += B[i];
    }
    for (int i = 0; i < K; ++i) {
        if (sums[i] != sums[0])
            die(_wa, "Group %d has sum %lld, but group 0 has sum %lld", i, sums[i], sums[0]);
    }

    quitf(_ok, "N = %d, K = %d, S = %d, group sum = %lld", N, K, S, sums[0]);
}
