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
typedef long long LL;

template<typename T> int size(const T &a) { return a.size(); }

const LL mod = 1000000007LL;
int pow2[2000];

LL cnt(int X,int Y,int sx,int sy) {
    if(X <= sx && Y <= sy) {
        
    }
}

class LitPanels 
{
public:
    int countPatterns(int X, int Y, int sx, int sy) 
    {
        pow2[0] = 1;
        for(int i=1;i<2000;i++) {
            pow2[i] = (pow2[i-1] * 2) % mod;
        }
        LL ret = 0;
        for(int i=1;i<=X;i++) {
            for(int j=1;j<=Y;j++) {
                LL tmp = cnt(i,j,sx,sy);
                ret += tmp * (X-i+1) * (Y-i+1);
                ret %= mod;
            }
        }
        return (ret + 1) % mod;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 1; int Arg3 = 1; int Arg4 = 11; verify_case(0, Arg4, countPatterns(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 3; int Arg2 = 1; int Arg3 = 2; int Arg4 = 40; verify_case(1, Arg4, countPatterns(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 4; int Arg2 = 3; int Arg3 = 2; int Arg4 = 14096; verify_case(2, Arg4, countPatterns(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 40; int Arg1 = 39; int Arg2 = 5; int Arg3 = 8; int Arg4 = 877713074; verify_case(3, Arg4, countPatterns(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    LitPanels ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
