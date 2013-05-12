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

int maxd(int a, int b, int offset) {
    int t1 = __gcd(a, b);
    int t2 = offset % t1;
    int t3 = t1 - t2;
    return min(t2, t3);
}

class FruitTrees 
{
public:
    int maxDist(int apple, int kiwi, int grape) 
    {		
        int ret = -1;
        for(int i=0;i<2000;i++) {
            int tmp1 = maxd(apple, kiwi, i);
            for(int j=0;j<2000;j++) {
                int tmp2 = maxd(apple, grape, j);
                int tmp3 = maxd(kiwi, grape, i-j);
                tmp2 = min(tmp2, tmp3);
                int tmp = min(tmp2, tmp1);
                if(ret == -1 || ret < tmp) ret = tmp;
            }
        }
        return ret;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 5; int Arg2 = 8; int Arg3 = 0; verify_case(0, Arg3, maxDist(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 6; int Arg3 = 1; verify_case(1, Arg3, maxDist(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 40; int Arg1 = 30; int Arg2 = 20; int Arg3 = 5; verify_case(2, Arg3, maxDist(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 899; int Arg1 = 1073; int Arg2 = 1147; int Arg3 = 14; verify_case(3, Arg3, maxDist(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 2000; int Arg1 = 2000; int Arg2 = 2000; int Arg3 = 666; verify_case(4, Arg3, maxDist(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    FruitTrees ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
