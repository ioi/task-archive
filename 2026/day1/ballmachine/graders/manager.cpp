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
    return int(c.size());
}

using LL = long long;

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
        log_printf("Could not write int into mgr2sol[%d]", fifo_idx); 
        // add logging here
    }
}

void write_ll(LL x) {
    if (1 != fwrite(&x, sizeof(x), 1, mgr2sol[fifo_idx])) {
        nullifyFile(fifo_idx);
        log_printf("Could not write LL into mgr2sol[%d]", fifo_idx); 
        // add logging here
    }
}

void write_int_vector(const vector<int>& arr) {
    int len = (int)sz(arr);
    if (len != (int)fwrite(arr.data(), sizeof(int), len, mgr2sol[fifo_idx])) {
        nullifyFile(fifo_idx);
        log_printf("Could not write int vector into mgr2sol[%d]", fifo_idx); 
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

NORETURN void die_too_much_resources(const string& msg) {
    RESULT_MESSAGE_WRONG += ": Too many resources used";
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

// new communication functions

void write_int_dyn_vector(const vector<int>& vec) {
	write_int( (int)vec.size() );
	write_int_vector( vec ); 
}

vector<int> read_int_dyn_vector() {
	int len = read_int(); 

	vector<int> vec(len); 

	read_int_array(vec.data(), sz(vec)); 

	return vec; 
}

/*

void write_pair_vector(const vector<pair<int, int>>& vec) {
	write_int( (int)vec.size() ); 

	int len = (int)sz(vec);
	if (len != (int)fwrite(vec.data(), sizeof(pair<int, int>), len, mgr2sol[fifo_idx])) {
		nullifyFile(fifo_idx);
        log_printf("Could not write pair vector into mgr2sol[%d]", fifo_idx); 
		// add logging here
	}
}

vector<pair<int, int>> read_pair_vector() {
	int len = read_int(); 

	vector< pair<int, int> > vec(len); 

	if (len > 0 && len != (int)fread(vec.data(), sizeof(pair<int, int>), len, sol2mgr[fifo_idx])) {
		nullifyFile(fifo_idx); 
		die(_fail, "Could not read pair<int, int> vector from sol2mgr[%d]", fifo_idx);
	}

	return vec; 
}

*/

template <typename... Args>
void wrong_answer(const char *fmt, Args... args) {
    if constexpr (sizeof...(args) == 0)
        quit(_wa, fmt);
    else
        quitf(_wa, fmt, args...);
}

template <typename... Args>
void ok(const char *fmt, Args... args) {
    quitf(_ok, fmt, args...);
}

template <typename... Args>
void partial(double p, const char *fmt, Args... args) {
    quitp(p, fmt, args...);
}

// problem logic

enum class ActionType {
    INSERT, 
    COLLECT,
	RETURN, 
}; 

ActionType read_action_type() {
    int action_type_code = read_int();

	switch (action_type_code) {
		case 0: 
			return ActionType::INSERT; 
		case 1: 
			return ActionType::COLLECT; 
		case 2: 
			return ActionType::RETURN; 
		default :
			die(_fail, "Unknown action_type_code %d from sol2mgr[%d] \nCode must be in range [0, 1]", action_type_code, fifo_idx); 
	}
}

#define read_node read_int
#define read_ball read_int
#define write_dfs_order write_int_dyn_vector

using Node = int; 
using Ball = int; 
const int MAXV = 1000;
const int INSERT_CALL_LIMIT = 500'000;

struct State {
    int type; 
    int n, m;
    int jump_dim; 
    int K, Q;
    int INSERT_CALL_COUNT;

    vector<Node> par;
    vector<Ball> ball;
    vector<vector<Node>> children;
    vector<vector<Node>> bin_jump;
    vector<int> TIE_P; 
	vector< int > result_par; 

    State(int type, int N, int M, vector<Node> par_): type(type), n(N), m(M), K(0), Q(0), INSERT_CALL_COUNT(0), par(par_) {
        ensuref(sz(par) == n, "Array par must have size N"); 
        par[n - 1] = n - 1;
        
		result_par = {}; 
        children.resize(n); 
        ball.resize(n, -1); 
        
        for (int i = 0; i < n - 1; i ++) {
            children[par[i]].push_back(i); 
        }

        jump_dim = __lg(n) + 1;

        bin_jump.resize(jump_dim, std::vector<int>(n, 0)); 
        for (int i = 0; i < n; i++) {
            bin_jump[0][i] = par[i];
        }

        for (int j = 1; j < jump_dim; j++) {
            for (int i = 0; i < n; i++) {
                bin_jump[j][i] = bin_jump[j - 1][bin_jump[j - 1][i]];
            }
        }

        TIE_P.resize(n);
        for (int i = 0; i < n; i++) TIE_P[i] = i;
    }

    bool insert(Node x, Ball y) {
        INSERT_CALL_COUNT++;

        if (INSERT_CALL_COUNT > INSERT_CALL_LIMIT) {
            die_too_many_calls(string("Can not make more than %d 'insert' calls", INSERT_CALL_LIMIT));
        }

        if (!(0 <= x && x < m)) {
            die_invalid_argument(string("Leaf argument must be in range [0, m)")); 
        }

        if (!(0 <= y && y <= MAXV)) {
            die_invalid_argument(string("Value on the ball must be in range [0, MAXV]")); 
        }

        K = max(K, y);

        for (int j = jump_dim - 1; j >= 0; j--) {
            if (ball[ bin_jump[j][x] ] == -1) {
                x = bin_jump[j][x];
            }
        }

        if (ball[x] == -1) {
            ball[x] = y;

            return true;
        } else {
            return false; 
        }
    }

    bool tie_break(Node x, Node y) {
        return TIE_P[x] < TIE_P[y]; 
    }

    vector<Ball> collect() {
        vector<Ball> order; 
        shuffle(TIE_P.begin(), TIE_P.end());

        function<void(Node)> dfs = [&](Node u) {
            order.push_back(ball[u]);
            sort(children[u].begin(), children[u].end(), [&](Node x, Node y) {
                if (ball[x] != ball[y]) {
                    return ball[x] < ball[y];
                } else {
                    return tie_break(x, y); 
                }
            });

            for(auto x : children[u]) {
                if (ball[x] != -1) {
                    dfs(x);
                }
            }
        }; 

        if (ball[n - 1] != -1) {
            dfs(n - 1);
        }

        for (int i = 0; i < n; i++) {
            ball[i] = -1;
        }

        Q++;

        return order;
    }

	void check() {
        if ((int)result_par.size() != n - 1)
            wrong_answer("Incorrect tree size");

        result_par.push_back(n - 1); 
        for (int i = 0; i < n; i++) {
            if (!(m <= result_par[i] && result_par[i] < n)) {
                wrong_answer("Incorrect return format"); 
            }
        }

		std::vector<int> f(n, -1), g(n, -1);
		for (int i = 0; i < m; i++) {
			int u = i, v = i;
			while (f[v] == -1) {
				if (g[u] != -1)
                    wrong_answer("Trees do not match"); 
                f[v] = u, g[u] = v;
				u = result_par[u];
				v = par[v];
			}
            if (v != g[u] || u != f[v])
                wrong_answer("Trees do not match");
		}
	}
}; 

State read_test_case() {
    const int MAXN = 1000;
    const int MAXM = 200;

    int type = inf.readInt(0, 4, "t");

    int N = inf.readInt(2, MAXN, "N");
    int M = inf.readInt(1, min(MAXM, N - 1), "M");

    vector<Node> par(N);
    par[N - 1] = N - 1;
    for (int i = 0; i < N - 1; i ++) {
        par[i] = inf.readInt(M, N - 1, "par[i]");
    }

    fclose(stdin); 

    return State(type, N, M, par); 
}


/*
SUBTASK0 : 0
SUBTASK1 : 5
SUBTASK2 : 10
SUBTASK3 : 25
    [46, 1000] : 13
    [0, 45] : 25
SUBTASK4 : 60
    [201, 1000] : 7
    [72, 200] : 47 - S/5
    [45, 71] : 104 - S
    [0, 44] : 60
*/

const bool log_details = false;
#define MAXS 1000
#define SUBTASK3_MAXM   45

#define SUBTASK4_MAXM   200
#define SUBTASK4_MID    71
#define SUBTASK4_OPT    44

double calculate_score_subtask4(int S) {
    double res = 0.0; 
    
    if (S <= SUBTASK4_OPT) {
        res = 60;
    } else if (S <= SUBTASK4_MID) {
        res = 104 - S; 
    } else if (S <= SUBTASK4_MAXM) {
        res = 47 - (S / 5.0); 
    } else if (S <= MAXS) {
        res = 7.0; 
    } else {
        res = 0.0;
    }

    res = res / 60.0; 
    return res;
}

double calculate_score_subtask3(int S) {
    if (S <= SUBTASK3_MAXM) {
        return 1.0;
    } else if (S <= MAXS) {
        return 13.0 / 25.0; 
    } else {
        return 0.0;
    }
}

int main(int argc, char** argv) {
	registerManager("ballmachine", 1, argc, argv);

	State test_state = read_test_case(); 

	log_var(test_state.n);
	log_var(test_state.m); 
	log_printf("par:\n");
	log_array(test_state.par);

	write_secret();
	write_int(test_state.m);
	out_flush();

	while (true) {
		log_printf("Checking for new actions...\n");
		read_secret();
		if (ok_action_mode != ActionMode::ok_new_transaction)
		break;
		log_printf("Received a new action request \n");

		ActionType action_type = read_action_type(); 

		switch (action_type) {
			case ActionType::INSERT: {
				Node x = read_node(); 
				Ball y = read_ball(); 
				log_printf("Performed : Insert %d %d\n", x, y); 

				bool result = test_state.insert(x, y); 
				log_printf("Insert result : %s\n", (result ? "true" : "false")); 

				if (test_state.K + test_state.Q > MAXS) {
					die_too_much_resources(string("K + Q > MAXS")); 
				}

				log_printf("Sending action results...\n"); 
				write_secret(); 
				write_int( (result ? 1 : 0) ); 

				break; 
			}
			case  ActionType::COLLECT: {
				log_printf("Performed : Collect\n"); 

				vector<Ball> order = test_state.collect();

                log_printf("dfs order size = %d\n", sz(order)); 
                if (log_details) {
                    log_printf("dfs order: \n"); 
                    log_array(order); 
                }

				if (test_state.K + test_state.Q > MAXS) {
					die_too_much_resources(string("K + Q > MAXS")); 
				}

				log_printf("Sending action results...\n"); 
				write_secret(); 
				write_dfs_order(order);

				break; 
			}
			case ActionType::RETURN: {
				log_printf("Performed : Return\n"); 

				std::vector< int > result_par = read_int_dyn_vector();

				test_state.result_par = result_par; 

                write_secret(); 
                log_printf("Received the tree of the solution\n"); 

				// ok_action_mode = ActionMode::ok_end_of_transactions; 
				break; 
			}
			default :
				die(_fail, "Unknown ActionType"); 
		}; 
		out_flush();
		log_printf("Transaction results sent.\n");

		// if (ok_action_mode == ActionMode::ok_end_of_transactions) {
		// 	break; 
		// }
	}

	ensuref(ok_action_mode == ActionMode::ok_end_of_transactions, "Expected action code ok_end_of_transactions");
	log_printf("No more transactions.\n");

    for (int i = 0; i < test_state.n; i++) {
        if (test_state.ball[i] != -1) {
            wrong_answer("The ballmachine nust be empty after the procedures are finished!"); 
        }
    }

	// checks the result 
	test_state.check(); 

	// Finishing

    int S = test_state.K + test_state.Q; 
    double SCORE = 0.0;

    switch (test_state.type) {
        case 0:  {
            if (S <= MAXS) {
                SCORE = 1.0; 
            }
            break;
        }
        case 1:  {
            if (S <= MAXS) {
                SCORE = 1.0;
            }
            break;
        }
        case 2: {
            if (S <= MAXS) {
                SCORE = 1.0;
            }
            break;
        }
        case 3: {
            SCORE = calculate_score_subtask3(S); 
            break;
        }
        case 4: {
            SCORE = calculate_score_subtask4(S); 
            break;
        }
        default: {
        }
    }

    // quitf(_ok, "Correct, S = %d", S); 

    if (SCORE == 1.0) {
        ok("Correct, S = %d", S); 
    }
    
    partial(SCORE, "Partially_Correct S = %d", S);
    
	// quitf(_ok, "Finished successfully with K + Q = %d + %d = S = %d", test_state.K, test_state.Q, test_state.K + test_state.Q);
}
