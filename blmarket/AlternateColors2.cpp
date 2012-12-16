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

long long H(int a, int b) {
    long long ret = 1;
    b--;
    a += b;
    for(int i=0;i<b;i++) {
        ret *= (a - i);
        ret /= (i+1);
    }
    return ret;
}

class AlternateColors2 
{
public:
    long long countWays(int n, int k) 
    {		
        n--; k--;
        if(k == 0) return H(n, 3);

        long long ret = 0;
        int o2 = k / 3;
        for(int i=o2;i>=0;i--) {
            int rest = k - (i*3);
            if(rest == 0) { // special case
                int avail = n - (i*3);
                ret += H(avail, 3);
                continue;
            }

            cerr << rest << endl;
            int o1 = rest / 2;
            if((rest % 2) == 0) {
                int avail = n - (i*3) - rest;
                ret += 2 * H(avail, 2);
                o1--;
            } 

            for(int j=o1;j>0;j--) {
                ret += 2;
            }
            ret++;
        }
        return ret;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; long long Arg2 = 1LL; verify_case(0, Arg2, countWays(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 3; long long Arg2 = 3LL; verify_case(1, Arg2, countWays(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 6; int Arg1 = 4; long long Arg2 = 9LL; verify_case(2, Arg2, countWays(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 6; int Arg1 = 1; long long Arg2 = 21LL; verify_case(3, Arg2, countWays(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 1000; int Arg1 = 2; long long Arg2 = 1LL; verify_case(4, Arg2, countWays(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 100000; int Arg1 = 100000; long long Arg2 = 1666700000LL; verify_case(5, Arg2, countWays(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    AlternateColors2 ___test; 
    ___test.run_test(1); 
} 
// END CUT HERE
