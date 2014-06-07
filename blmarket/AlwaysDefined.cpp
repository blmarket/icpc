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

long long go(long long R, int W) {
    long long ret = 0;
    long long n1 = (R-1+W) / W;
    ret += n1;

    for(int i=2;i<W;i++) {
        long long k = (R-i+W) / W;
        int t = i / __gcd(W, i);
        ret += (k / t);
    }
    return ret;
}

bool chk(long long x, int W) {
    if((x % W) == 0) return false;
    if((x % W) == 1) return true;
    int t = (x % W);
    if((x % t) != 0) return false;
    return chk(x/t, W);
}

class AlwaysDefined 
{
public:
    long long countIntegers(long long L, long long R, int W) 
    {		
        int cnt = 0;
        for(int i = L; i <= R; i++) if((i % W) == 2) {
            int x = i;
            if(chk(x, W)) {
                cout << i << " " << (i % W) << endl;
            }
        }
        // return go(R, W) - go(L - 1, W);
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
    ___test.run_test(2); 
} 
// END CUT HERE
