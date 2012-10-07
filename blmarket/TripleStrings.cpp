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

class TripleStrings 
{
public:
    int getMinimumOperations(string init, string goal) 
    {		
				for(int i=0;i<=size(init);i++) {
						if(init.substr(i) == goal.substr(0, size(init) - i)) {
								return i * 2;
						}
				}
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "ooxxox"; string Arg1 = "xoxoxo"; int Arg2 = 6; verify_case(0, Arg2, getMinimumOperations(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "oooxxoo"; string Arg1 = "oooxxoo"; int Arg2 = 0; verify_case(1, Arg2, getMinimumOperations(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "ox"; string Arg1 = "xo"; int Arg2 = 2; verify_case(2, Arg2, getMinimumOperations(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "ooxxooxx"; string Arg1 = "xxoxoxoo"; int Arg2 = 12; verify_case(3, Arg2, getMinimumOperations(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "oxxoxxoooxooooxxxoo"; string Arg1 = "oxooooxxxooooxoxxxo"; int Arg2 = 16; verify_case(4, Arg2, getMinimumOperations(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "xxxoxoxxooxooxoxooo"; string Arg1 = "oxxooxxooxxoxoxooxo"; int Arg2 = 36; verify_case(5, Arg2, getMinimumOperations(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    TripleStrings ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
