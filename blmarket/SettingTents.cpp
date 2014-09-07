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

class SettingTents 
{
public:
    int countSites(int N, int M) 
    {		
        int ret = 0;
        for(int i=1;i<=N;i++) {
            for(int j=1;j<=M;j++) {
                ret += (N-i+1) * (M-j+1);
                int h = i * 2;
                int w = j * 2;
                if(h > N || j > M) continue;
                ret += (N-h+1) * (M-w+1);
            }
        }
        return ret;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 6; verify_case(0, Arg2, countSites(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 6; int Arg2 = 6; verify_case(1, Arg2, countSites(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 6; int Arg1 = 8; int Arg2 = 527; verify_case(2, Arg2, countSites(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    SettingTents ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
