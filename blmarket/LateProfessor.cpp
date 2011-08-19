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

class LateProfessor 
{
public:
    double getProbability(int waitTime, int walkTime, int lateTime, int bestArrival, int worstArrival) 
    {
        int accum = 0;
        int cur = 0;

        while(cur < worstArrival + lateTime)
        {
            int next = cur + waitTime;
            if(next > bestArrival)
            {
                cout 
                << max(cur-lateTime, bestArrival) 
                << " - " 
                << min(next, worstArrival) 
                << endl;
                accum += min(next, worstArrival) - max(cur - lateTime, bestArrival);
            }
            cur = next + walkTime;
        }

        cout << accum << " " << endl;

        return (double)accum / (worstArrival - bestArrival);
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 20; int Arg1 = 30; int Arg2 = 10; int Arg3 = 0; int Arg4 = 50; double Arg5 = 0.4; verify_case(0, Arg5, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 20; int Arg1 = 30; int Arg2 = 10; int Arg3 = 30; int Arg4 = 100; double Arg5 = 0.42857142857142855; verify_case(1, Arg5, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 20; int Arg1 = 40; int Arg2 = 50; int Arg3 = 0; int Arg4 = 300; double Arg5 = 0.0; verify_case(2, Arg5, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 101; int Arg1 = 230; int Arg2 = 10; int Arg3 = 654; int Arg4 = 17890; double Arg5 = 0.6637270828498492; verify_case(3, Arg5, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 20; int Arg1 = 30; int Arg2 = 10; int Arg3 = 90; int Arg4 = 90; double Arg5 = 1.0; verify_case(4, Arg5, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_5() { int Arg0 = 1000; int Arg1 = 600; int Arg2 = 1; int Arg3 = 17000; int Arg4 = 17000; double Arg5 = 0.0; verify_case(5, Arg5, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    LateProfessor ___test; 
    ___test.run_test(0); 
} 
// END CUT HERE
