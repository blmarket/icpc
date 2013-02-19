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

map<pair<int, PII>, int> memo;

int go(int a, int b, int c) {
    if(a < 0) return 99999;
    if(b < 0) return 99999;
    if(c < 0) return 99999;
    cout << a << " " << b << " " << c << endl;
    if(a == 0 && c == 0) return 1;
    if(b == 0 && c == 0) return -1;

    pair<int, PII> key = mp(c, mp(a,b));
    if(memo.count(key)) return memo[key];

    int t1 = go(b, a-1, c);
    int t2 = go(b-1, a, c);
    int t3 = go(b, a, c-1);

    int minn = min(t3, min(t1,t2));
    if(minn < 0) {
        return memo[key] = -minn + 1;
    }
    if(minn == 0) {
        return memo[key] = 0;
    }
    return memo[key] = -minn - 1;
}

class DoorsGame 
{
public:
    int determineOutcome(string doors, int trophy) 
    {		
        string left = doors.substr(0, trophy);
        string right = doors.substr(trophy);

        set<char> S1, S2;
        for(int i=0;i<size(left);i++) S1.insert(left[i]);
        for(int i=0;i<size(right);i++) S2.insert(right[i]);

        int common = 0;
        foreach(it, S1) {
            if(S2.count(*it)) {
                common++;
            }
        }

        return go(size(S1) - common, size(S2) - common, common);
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "ABCD"; int Arg1 = 2; int Arg2 = 3; verify_case(0, Arg2, determineOutcome(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "ABCC"; int Arg1 = 2; int Arg2 = -2; verify_case(1, Arg2, determineOutcome(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "ABABAB"; int Arg1 = 3; int Arg2 = 0; verify_case(2, Arg2, determineOutcome(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "ABAPDCAA"; int Arg1 = 5; int Arg2 = -4; verify_case(3, Arg2, determineOutcome(Arg0, Arg1)); }

	void test_case_4() { string Arg0 = "MOCFDCE"; int Arg1 = 3; int Arg2 = 5; verify_case(4, Arg2, determineOutcome(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "ABCCDE"; int Arg1 = 3; int Arg2 = 0; verify_case(5, Arg2, determineOutcome(Arg0, Arg1)); }
	void test_case_6() { string Arg0 = "ABCCD"; int Arg1 = 3; int Arg2 = 0; verify_case(6, Arg2, determineOutcome(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    DoorsGame ___test; 
    ___test.run_test(2); 
} 
// END CUT HERE
