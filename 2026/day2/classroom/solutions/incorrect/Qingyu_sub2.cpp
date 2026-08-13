#include "classroom.h"
#include <cassert> 
std::vector<std::vector<int>> process_step(int N, int M, int R, std::vector<int> T, std::vector<std::vector<int>> A) {
    if (A[0].empty() && A[1].empty()) {
        if (T.empty()) return A;
        int x = T[0];
        A[!x] = { x, R };
        return A;
    }
    if (A[0].empty() || A[1].empty()) {
        int o = (A[0].empty() ? 0 : 1);
        if (T.empty()) {
            if (A[!o][0] >= 32) {
                A[!o][0] -= 32;
                A[o] = { !A[!o][0], R - 1 };
            }            
            return A;
        }
        else {
            if (T[0] == !o) {
                A[o] = {T[0], R};
            }
            else {
                A[!o][0] += 32;
            }
        }
    }
    return A;
}

std::vector<int> determine_steps(int N, int M, std::vector<std::vector<int>> A) {
    std::vector<int> ret(N, -1);
    if (A[0].empty() && A[1].empty()) return ret;
    if (A[0].empty() || A[1].empty()) {
        int o = (A[0].empty() ? 0 : 1);
        if (A[!o][0] >= 32) {
            A[!o][0] -= 32;
            ret[A[!o][0]] = A[!o][1];
            ret[!A[!o][0]] = M - 1;
        }
        else {
            ret[A[!o][0]] = A[!o][1];
        }
    }
    else {
        ret[A[0][0]] = A[0][1];
        ret[A[1][0]] = A[1][1];
    }
    return ret;
}
