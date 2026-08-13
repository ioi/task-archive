
#include "classroom.h"
#include <cassert> 

constexpr int B = 63;

std::vector<int> encode_int(int value) {
    assert(0 <= value);
    if (value == 0) return {};
    if (value <= 64) return {value - 1};
    value -= 64;
    assert(value < 64 * 64);
    return { value / 64, value % 64 };
}

int decode_int(std::vector<int> vec) {
    assert(vec.size() <= 2);
    if (vec.size() == 0) return 0;
    else if (vec.size() == 1) return vec[0] + 1;
    else return 64 + vec[0] * 64 + vec[1] % 64;
}

struct data_t {
    int pos, t;
    bool finalized;
    bool special;

    data_t() : pos(-1), t(-1), finalized(false), special(false) {

    }

    data_t(int pos, int t) : pos(pos), t(t) {
        finalized = special = false;
    }

    data_t(int pos, int t, bool finalized) : pos(pos), t(t), finalized(finalized) {
        special = false;
    }

    void set_pos(int i, int R) {
        pos = i;
        t = R % 4;
        finalized = special = false;
    }

    void set_finalized(int pos, int t) {
        this->pos = pos;
        this->t = t;
        finalized = true;
        special = false;
    }

    void set_special(int pos) {
        this->pos = pos;
        this->t = -1;
        special = true;
        finalized = false;
    }

    int encode_to_value() {
        if (pos == -1) {
            return 0;
        }
        int base = 1;
        if (finalized) {
            return base + t * B + pos;
        }
        base += (B - 1) * B;
        if (!special) {
            return base + t * B + pos;
        }
        base += 4 * B;

        return base + pos;
    }

    void decode_from_value(int value) {
        pos = -1;
        t = -1;
        finalized = special = false;
        if (value == 0) {
            return;
        }
        value -= 1;
        if (value < (B - 1) * B) {
            t = value / B;
            pos = value % B;
            finalized = true;
            return;
        }
        value -= (B - 1) * B;
        if (value < 4 * B) {
            t = value / B;
            pos = value % B;
            finalized = false;
            return;
        }
        value -= 4 * B;
        special = true;
        pos = value;
    }

    void decode(std::vector<int> vec) {
        decode_from_value(decode_int(vec));
    }
    std::vector<int> encode() {
        return encode_int(encode_to_value());
    }
};

std::vector<data_t> work(int N, int M, int R, std::vector<int> T, std::vector<data_t> data) {
    std::vector<int> has(N), perm(N, -1);
    for (int x : T) has[x] = true;
    int current = R % 4, last = (R - 1 + 4) % 4;
    std::vector<data_t> ret = data;
    for (int i = 0; i < N; ++i) {
        if (data[i].pos != -1 && !has[i]) {
            perm[data[i].pos] = i;
        }
    }
    for (int i = 0; i < N; ++i) {
        if (has[i]) continue;

        bool alive_last_round = false;
        int finalized_pos = -1;

        for (int j = 0; j < N; ++j) {
            if (data[j].pos == i) {
                if (!data[j].finalized && data[j].t == last) {
                    // good candidate
                    alive_last_round = true;
                }
                else if (data[j].finalized) {
                    finalized_pos = j;
                }
            }
        }
        if (finalized_pos != -1) {
            ret[i] = data[finalized_pos];
        }
        else if (alive_last_round) {
            ret[i] = data_t(i, current);
        }
        else {
            ret[i] = data_t(i, R - 1, true); // died at last round
        }
    }

    auto extract_cycle = [&](int x) {
        std::vector<int> ret = {x};
        while (perm[x] != -1) {
            x = perm[x];
            ret.push_back(x);
        }
        return ret;
    };
    return ret;
}

std::vector<data_t> decode(std::vector<std::vector<int>> A) {
    std::vector<data_t> raw(A.size());
    for (int i = 0; i < raw.size(); ++i) {
        raw[i].decode(A[i]);
    }
    return raw;
}

std::vector<std::vector<int>> process_step(int N, int M, int R, std::vector<int> T, std::vector<std::vector<int>> A) {
    std::vector<int> has(N);
    auto raw = decode(A);    
    for (int x : T) has[x] = true;

    if (R == 0) {
        for (int i = 0; i < N; ++i) {
            if (has[i]) continue;
            raw[i].set_pos(i, R);
        }
    }
    else {
        raw = work(N, M, R, T, raw);
    }
    for (int i = 0; i < N; ++i) {
        A[i] = raw[i].encode();
    }
    return A;
}

std::vector<int> determine_steps(int N, int M, std::vector<std::vector<int>> A) {
    auto raw = work(N, M, M, {}, decode(A));
    std::vector<int> ret(N, -1);
    for (int i = 0; i < N; ++i) {
        if (raw[i].finalized && raw[i].t < M) {
            ret[i] = raw[i].t;
        }
    }
    return ret;
    
}