#include <iostream>
#include <queue>
#include <set>
#include <sstream>
#include <algorithm>
#include <map>
#include <vector>

#define mp make_pair
#define pb push_back
#define sqr(x) ((x)*(x))
#define foreach(it,c) for(typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;

template<typename T> int size(const T &a) { return a.size(); }

const long long mod = 1000000007LL;

long long combi[1505][1505];
long long a[55][55];
long long b[55][55];

class KingdomAndCities 
{
public:
    int howMany(int N, int M, int K) 
    {
        for(int i=0;i<=25*49;i++) {
            combi[i][0] = combi[i][i] = 1;
            for(int j=1;j<i;j++) {
                combi[i][j] = (combi[i-1][j-1] + combi[i-1][j]) % mod;
            }
        }

        if(N < 2) return 0;

        for(int i=1;i<=N;i++) {
            for(int j=0;j<=K;j++) {
                a[i][j] = combi[combi[i][2]][j];
            }
        }

        for(int i=1;i<=N;i++) {
            for(int j=0;j<=K;j++) {
                b[i][j] = a[i][j];
                for(int k=1;k<i;k++) {
                    for(int l=0;l<=j;l++) {
                        b[i][j] -= ((((b[k][l] * combi[N-1][k-1]) % mod) * a[N-k][K-l]) % mod);
                        b[i][j] %= mod;
                    }
                }
                b[i][j] = (b[i][j] + mod + mod) % mod;
            }
        }

        a[0][0] = b[0][0] = a[1][0] = b[1][0] = 1;

        if(M == 0) return b[N][K];
        if(M == 1) {
            if(K < 2) return 0;
            K -= 2; N--;
            long long ret = (b[N][K] * combi[N][2]) % mod;
            for(int i=0;i<=N-1;i++) {
                for(int j=0;j<=K;j++) {
                    ret += ((((b[i+1][j] * combi[N][i+1]) % mod) * b[N-1-i][K-j]) % mod);
                    ret %= mod;
                }
            }
            return ret;
        }
        if(N == 2) { // 2-link case.
            return K==2?1:0;
        }

        // no links.
        N -= 2; K -= 4;
        /// one big block
        long long ret = ((((b[N][K] * combi[N][2]) % mod) * combi[N][2]) % mod);
        /// two blocks
        for(int i=0;i<=N-1;i++) {
            for(int j=0;j<=K;j++) {
                long long tmp = ((((b[i+1][j] * combi[N][i+1]) % mod) * b[N-1-i][K-j]) % mod);
                // 0 links, 1 links
                tmp *= (i+1) * (N-1-i) * (i+1) * (N-1-i);
                tmp %= mod;
                // 0 links, 1 not
                // 0 not, 1 links
                tmp *= (i+1) * (N-1-i) * (combi[i+1][2] + combi[N-1-i][2]) * 2;
                tmp %= mod;

                ret += tmp;
                ret %= mod;
            }
        }
        /// three blocks
        for(int i=0;i<=N-1;i++) { // size of block 1
            for(int j=0;j<=K;j++) {
                long long tmp1 = (b[i+1][j] * combi[N][i+1]) % mod;
                for(int k=0;k<N-1-i-1;k++) {
                    for(int l=0;l<=K-j;l++) {
                        long long tmp2 = (b[k+1][l] * combi[N-i-1][k+1]) % mod;
                        tmp2 *= tmp1;
                        tmp2 %= mod;
                        int elasp = N-i-k-2;
                        tmp2 *= b[N-i-k-2][K-j-l];
                        tmp2 %= mod;

                        long long tmp3 = 0;
                        // 0 : 2-3, 1 : 1-2
                        // 0 : 1-2, 1 : 2-3
                        // tmp3 += (i+1) * (k+1) * elasp * 2 * (i+1+k+1+elasp);
                        tmp3 = (i+1) * (k+1) * elasp * 2 * N;

                        tmp2 *= tmp3;
                        tmp2 %= mod;

                        ret += tmp2;
                        ret %= mod;
                    }
                }
            }
        }

        // 1 link.
        K++;
        cout << N << " " << K << endl;
        ret += ((((b[N][K] * N) % mod) * N) % mod);
        for(int i=0;i<=N-1;i++) {
            for(int j=0;j<=K;j++) {
                long long tmp = ((((b[i+1][j] * combi[N-1][i]) % mod) * b[N-1-i][K-j]) % mod);
                cout << tmp << endl;
                // 0 links, 1 links
                tmp *= (i+1) * (N-1-i) * 2;
                tmp %= mod;
                ret += tmp;
                ret %= mod;
            }
        }

        ret %= mod;
        return ret;
    }

    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arg0 = 4; int Arg1 = 2; int Arg2 = 3; int Arg3 = 1; verify_case(0, Arg3, howMany(Arg0, Arg1, Arg2)); }
    void test_case_1() { int Arg0 = 4; int Arg1 = 1; int Arg2 = 4; int Arg3 = 9; verify_case(1, Arg3, howMany(Arg0, Arg1, Arg2)); }
    void test_case_2() { int Arg0 = 5; int Arg1 = 2; int Arg2 = 11; int Arg3 = 0; verify_case(2, Arg3, howMany(Arg0, Arg1, Arg2)); }
    void test_case_3() { int Arg0 = 5; int Arg1 = 0; int Arg2 = 8; int Arg3 = 45; verify_case(3, Arg3, howMany(Arg0, Arg1, Arg2)); }
    void test_case_4() { int Arg0 = 10; int Arg1 = 2; int Arg2 = 20; int Arg3 = 150810825; verify_case(4, Arg3, howMany(Arg0, Arg1, Arg2)); }

    // END CUT HERE

};



// BEGIN CUT HERE 
int main() {
	KingdomAndCities ___test;
	___test.run_test(0);
}
// END CUT HERE
