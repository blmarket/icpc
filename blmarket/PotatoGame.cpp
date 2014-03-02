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

int memo[128];

class PotatoGame 
{
public:
    string theWinner(int n) 
    {		
        memo[0] = 0;
        memo[1] = 1;
        for(int i=2;i<128;i++) {
            if(memo[i-1] == 0) memo[i] = 1;
            else if(i>= 4 && memo[i-4] == 0) memo[i] = 1;
            else if(i>= 16 && memo[i-16] == 0) memo[i] = 1;
            else if(i>= 64 && memo[i-64] == 0) memo[i] = 1;
            cout << memo[i] << " ";
            if(i % 5 == 0) cout << endl;
        }
        return "Taro";
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; string Arg1 = "Taro"; verify_case(0, Arg1, theWinner(Arg0)); }
	void test_case_1() { int Arg0 = 2; string Arg1 = "Hanako"; verify_case(1, Arg1, theWinner(Arg0)); }
	void test_case_2() { int Arg0 = 3; string Arg1 = "Taro"; verify_case(2, Arg1, theWinner(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    PotatoGame ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
