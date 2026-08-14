#include "testlib.h"

#include <string>
const std::string output_secret = "z0H2zDqz4usrRWQ5xeg9s2tOOGvlMue8";
const std::string input_secret = "ylQedwYNTcFgpd2Epe0kHFfnG4rqrt2X";

const long long oo = 1e15;
int readAns(InStream& stream, int N , int A, std::vector<int> &P , std::vector<int> &T) {
    std::vector<int> coupons;
    std::vector<bool> used(N, false);
    
    int cnt = stream.readInt(0, N, "Count of coupons bought");
    
    while (!stream.seekEof()) {
        int x = stream.readInt(0, N-1, "coupon");
        if(used[x]){
            stream.quitf(_wa, "coupon %d was used twice", x);
        }
        coupons.push_back(x);
        used[x] = true;
    }

    if(cnt != (int)coupons.size())
        quitf(_fail, "grader problem, sequence length doesn't match S: S= %d, seq_len = %d\n", cnt, (int)coupons.size());

    long long tokens = A;
    for(auto i : coupons){
        if(tokens - P[i] < 0){
            stream.quitf(_wa, "Invalid seqnuce of coupons tokens, Tokens became negative");
        }
        tokens = (tokens - P[i]) * T[i];
        tokens = std::min(tokens , oo);
    }
    return cnt;
}

int main(int argc, char *argv[])
{
    registerChecker("festival", argc, argv);
    readBothSecrets(output_secret);
    readBothGraderResults();
    
	inf.readToken(input_secret);
	inf.readEoln();

    int N = inf.readInt();
    int A = inf.readInt();

    std::vector<int> P(N) , T(N);
    for (int i = 0; i < N; i++) {
        P[i] = inf.readInt();
        T[i] = inf.readInt();
    }

    int jans = readAns(ans, N, A , P , T);
    int pans = readAns(ouf, N , A , P , T);
    
    if (jans > pans)
        quitf(_wa, "jury has the better answer: jans = %d, pans = %d\n", jans, pans);
    else if (jans == pans)
        quitf(_ok, "answer = %d\n", pans);
    else // (jans < pans)
        quitf(_fail, ":( participant has the better answer: jans = %d, pans = %d\n", jans, pans);
}
