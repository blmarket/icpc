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

class MagicalStringDiv1 
{
public:
    int getLongest(string S) 
    {		
        int ret = size(S);
        int c1 = 0;
        int maxx = 0; 
        for(int i=0;i<size(S);i++) {
            if(S[i] == '>') c1++;
            int c2 = 0;
            for(int j=i+1;j<size(S);j++) {
                if(S[j] == '<') c2++;
            }

            maxx = max(maxx, min(c1, c2));
        }
        return size(S) - maxx * 2;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "<><><<>"; int Arg1 = 4; verify_case(0, Arg1, getLongest(Arg0)); }
	void test_case_1() { string Arg0 = ">>><<<"; int Arg1 = 6; verify_case(1, Arg1, getLongest(Arg0)); }
	void test_case_2() { string Arg0 = "<<<>>>"; int Arg1 = 0; verify_case(2, Arg1, getLongest(Arg0)); }
	void test_case_3() { string Arg0 = "<<<<><>>><>>><>><>><>>><<<<>><>>>>><<>>>>><><<<<>>"; int Arg1 = 24; verify_case(3, Arg1, getLongest(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    MagicalStringDiv1 ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
