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

bool susan[1000];

class SumAndProductPuzzle 
{
public:
    long long getSum(int A, int B) 
    {
        susan[2] = true; // 2 = 1+1, determined.
        susan[3] = true; // 3 = 1+2, determined.
        susan[4] = true; // 4 = 1+3 or 2+2, product = 3 or 4, determined.
        susan[5] = true; // 5 = 1+4, 2+3, product 4 or 6

        for(int i=6;i<10;i++) {
            for(int j=1;j<i;j++) {
                int k = i-j;
                if(k < j) break;
                long long product = (long long)j * k;
                cout << product << " ";
            }
            cout << endl;
        }
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 30; int Arg1 = 33; long long Arg2 = 33LL; verify_case(0, Arg2, getSum(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 8; int Arg1 = 11; long long Arg2 = 19LL; verify_case(1, Arg2, getSum(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 40; int Arg1 = 43; long long Arg2 = 0LL; verify_case(2, Arg2, getSum(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 47; int Arg1 = 74; long long Arg2 = 168LL; verify_case(3, Arg2, getSum(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 1; int Arg1 = 2; long long Arg2 = 0LL; verify_case(4, Arg2, getSum(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    SumAndProductPuzzle ___test; 
    ___test.run_test(0); 
} 
// END CUT HERE
