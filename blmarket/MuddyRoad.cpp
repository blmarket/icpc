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

double memo[55];
VI road;

double go(int a) 
{
		if(a >= size(road) - 2) return 0;
		if(memo[a] >= -0.1) return memo[a];

		double prob = (double)road[a+1] / 100;
		double ret = prob * (go(a+2) + (double)road[a+2] / 100) + (1-prob) * go(a+1);
		return memo[a] = ret;
}

class MuddyRoad 
{
public:
    double getExpectedValue(vector <int> road_) 
    {		
				road = road_;
				for(int i=0;i<size(road);i++) memo[i] = -1;
				return go(0);
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0, 60, 60, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.36; verify_case(0, Arg1, getExpectedValue(Arg0)); }
	void test_case_1() { int Arr0[] = {0, 50, 50, 50, 50, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.5625; verify_case(1, Arg1, getExpectedValue(Arg0)); }
	void test_case_2() { int Arr0[] = {0, 0, 100, 100, 100, 100, 100, 100, 0, 0, 100, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 3.0; verify_case(2, Arg1, getExpectedValue(Arg0)); }
	void test_case_3() { int Arr0[] = {0, 12, 34, 56, 78, 91, 23, 45, 67, 89, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 1.7352539420031923; verify_case(3, Arg1, getExpectedValue(Arg0)); }
	void test_case_4() { int Arr0[] = {0, 50, 50, 100, 50, 100, 50, 50, 100, 66, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 2.288125; verify_case(4, Arg1, getExpectedValue(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    MuddyRoad ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
