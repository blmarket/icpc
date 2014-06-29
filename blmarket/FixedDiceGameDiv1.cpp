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

class FixedDiceGameDiv1 
{
public:
    double getExpectation(int a, int b, int c, int d) 
    {		
        double prob[2][350];
        memset(prob, 0, sizeof(prob));
        prob[0][0] = 1;
        for(int i=0;i<c;i++) {
            int cur = (i%2), nex = 1-cur;

            memset(prob[nex], 0, sizeof(prob[0]));
            for(int j=0;j<300;j++) {
                for(int k=1;k<=d;k++) {
                    prob[nex][j+k] += prob[0][j] / d;
                }
            }
        }
        if(c%2) memcpy(prob[0], prob[1], sizeof(prob[0]));

        int left = a;
        int right = a*b;

        prob[1][0] = 0;
        for(int i=1;i<300;i++) prob[1][i] = prob[1][i-1] + prob[0][i-1];

        for(int i=1;i<300;i++) cout << prob[1][i] << " ";
        cout << endl;

        double win = 0;
        for(int i=left;i<=right;i++) win += prob[1][i];

        cout << win << endl;
        if(win < 1e-5) return -1;

        double ret = 0;
        for(int i=left;i<=right;i++) {
            ret += i * prob[1][i] / win;
        }
        return ret;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 2; int Arg2 = 1; int Arg3 = 5; double Arg4 = 2.0; verify_case(0, Arg4, getExpectation(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 1; int Arg3 = 3; double Arg4 = 3.0; verify_case(1, Arg4, getExpectation(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 5; int Arg2 = 1; int Arg3 = 1; double Arg4 = 3.4999999999999996; verify_case(2, Arg4, getExpectation(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 2; int Arg1 = 6; int Arg2 = 50; int Arg3 = 30; double Arg4 = -1.0; verify_case(3, Arg4, getExpectation(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 50; int Arg1 = 11; int Arg2 = 50; int Arg3 = 50; double Arg4 = 369.8865999182022; verify_case(4, Arg4, getExpectation(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    FixedDiceGameDiv1 ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
