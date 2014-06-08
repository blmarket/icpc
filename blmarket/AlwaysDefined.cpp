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

/*
 * Problem: 900
 * Test Case: 74
 * Succeeded: No
 * Execution Time: 0 ms
 * Peak memory used: 0.000MB
 * Args:
 * {52654107011850814, 744472477227325439, 2028}
 *
 * Expected:
 * 2819463395911898
 *
 * Received:
 * The code execution time exceeded the 2.000 second time limit.
 *
 * Answer checking result:
 * null
 */

map<pair<long long, int>, long long> memo;

int W;
vector<int> nr[3005];

long long go2(long long maxk, int r) {
    if(r == 1) return maxk+1;
    auto key = mp(maxk, r);
    auto it = memo.find(key);
    if(it != memo.end()) return it->second;
    long long ret = 0;
    // k W + r
    for(auto it : nr[r]) {
        if(maxk - it < 0) break;
        long long maxw = (maxk - it) / r;
        int nr = (it * W + r) / r;
        ret += go2(maxw, nr);
    }
    // cout << maxk << " " << r << " = " << ret << endl;
    return memo[key] = ret;
}

long long go(long long A) {
    long long ret = 0;
    for(int i=1;i<W;i++) {
        if(A < i) break;
        long long k = (A-i) / W;
        ret += go2(k, i);
    }
    return ret;
}

class AlwaysDefined 
{
public:
    long long countIntegers(long long L, long long R, int W_) 
    {
        memo.clear();
        W = W_;
        for(int i=1;i<W;i++) {
            nr[i].clear();
            for(int j=0;j<i;j++) {
                if((j*W+i) % i) continue;
                nr[i].pb(j);
            }
            for(int j=0;j<size(nr[i]);j++) {
                cout << nr[i][j] << " ";
            }
            cout << endl;
        }
        return go(R) - go(L-1);
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 10LL; long long Arg1 = 10LL; int Arg2 = 4; long long Arg3 = 1LL; verify_case(0, Arg3, countIntegers(Arg0, Arg1, Arg2)); }
	void test_case_1() { long long Arg0 = 1LL; long long Arg1 = 99LL; int Arg2 = 2; long long Arg3 = 50LL; verify_case(1, Arg3, countIntegers(Arg0, Arg1, Arg2)); }
	void test_case_2() { long long Arg0 = 1282LL; long long Arg1 = 1410LL; int Arg2 = 10; long long Arg3 = 42LL; verify_case(2, Arg3, countIntegers(Arg0, Arg1, Arg2)); }
	void test_case_3() { long long Arg0 = 29195807LL; long long Arg1 = 273209804877LL; int Arg2 = 42; long long Arg3 = 31415926535LL; verify_case(3, Arg3, countIntegers(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    AlwaysDefined ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
