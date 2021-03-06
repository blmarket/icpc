#include <iostream>
#include <cstring>
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

string ss;
string t[305];

int dd[305][2][305];
int dsum[305][2];

class FlippingBitsDiv1 
{
public:
    int getmin(vector <string> S, int M) 
    {		
        ss.clear();
        for(int i=0;i<size(S);i++) ss += S[i];

        for(int i=0;i<M;i++) {
            t[i].clear();
            for(int j=i;j<size(ss);j+=M) {
                t[i] += ss[j];
            }
        }

        memset(dd, 0, sizeof(dd));
        int l = size(t[0]);

        for(int i=1;i<l;i++) {
            for(int j=0;j<M;j++) {
                if(t[j].size() >= i) break;
                int cc;
                // assume nonflip


                // assume flip

            }
        }
        return 0;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"00111000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2; verify_case(0, Arg2, getmin(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"101100001101"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 2; verify_case(1, Arg2, getmin(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"11111111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 0; verify_case(2, Arg2, getmin(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"1101001000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; int Arg2 = 1; verify_case(3, Arg2, getmin(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"1","10","11","100","101","110"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 4; verify_case(4, Arg2, getmin(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"1001011000101010001111111110111011011100110001001"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 16; verify_case(5, Arg2, getmin(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    FlippingBitsDiv1 ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
