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

    data_t(int _pos, int _t) : pos(_pos), t(_t) {
        finalized = special = false;
    }

    data_t(int _pos, int _t, bool _finalized) : pos(_pos), t(_t), finalized(_finalized) {
        special = false;
    }

    void set_pos(int i, int R) {
        pos = i;
        t = R % 3;
        finalized = special = false;
    }

    void set_finalized(int _pos, int _t) {
        this->pos = _pos;
        this->t = _t;
        finalized = true;
        special = false;
    }

    void set_special(int _pos) {
        this->pos = _pos;
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
        base += 3 * B;

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
        if (value < 3 * B) {
            t = value / B;
            pos = value % B;
            finalized = false;
            return;
        }
        value -= 3 * B;
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

std::vector<data_t> work(int N, int /*M*/, int R, std::vector<int> T, std::vector<data_t> data) {
    std::vector<int> has(N), perm(N, -1);
    for (int x : T) has[x] = true;
    int current = R % 3, last = (R - 1 + 3) % 3;
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
        std::vector<int> cyc = {x};
        while (perm[x] != -1) {
            x = perm[x];
            cyc.push_back(x);
        }
        return cyc;
    };

    for (int i : T) {
        for (int j : T) {
            if (data[j].pos == i && data[j].t == current) {
                auto cyc = extract_cycle(i);
                int sz = cyc.size();
                assert(sz >= 2);
                int x = cyc[sz - 1], y = cyc[sz - 2];
                ret[x].set_special(y);
                ret[y].set_special(i);
            }
        }
    }
    std::vector<int> pool(N, 0);
    for (int i = 0; i < N; ++i) {
        if (data[i].pos != -1 && !data[i].special) {
            pool[data[i].pos] = true;
        }
    }
    for (int i = 0; i < N; ++i) {
        if (data[i].special) {
            int pos = data[i].pos;
            if (pool[pos]) {
                ret[i].set_finalized(i, R - 2);
                ret[pos].set_finalized(pos, R - 1);
            } 
            else {
                ret[i].set_finalized(i, R - 1);
                ret[pos].set_finalized(pos, R - 3);
            }
        }
    }
    return ret;
}

std::vector<data_t> decode(std::vector<std::vector<int>> A) {
    std::vector<data_t> raw(A.size());
    for (int i = 0; i < (int)raw.size(); ++i) {
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
        if (raw[i].finalized) {
            ret[i] = raw[i].t;
        }
    }
    return ret;
}