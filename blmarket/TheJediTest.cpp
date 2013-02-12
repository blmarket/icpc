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

class TheJediTest 
{
public:
    int minimumSupervisors(vector <int> st, int K) 
    {
        int ret = 0;
        int n = size(st);
        st.pb(0);
        st.pb(0);
        for(int i=0;i<n;i++) {
            int others = st[i+1] + st[i+2];
            int ssum = st[i] + others;
            int tmp = ssum % K;

            if(tmp > others) {
                ret += (ssum / K) + 1;
                st[i+1] = st[i+2] = 0;
                continue;
            }

            if(st[i+2] >= tmp) {
                ret += (ssum / K);
                st[i+1] = 0;
                st[i+2] = tmp;
                continue;
            }

            tmp -= st[i+2];
            ret += (ssum / K);
            st[i+1] = tmp;
        }
        return ret;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3, 6, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 3; verify_case(0, Arg2, minimumSupervisors(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1, 1, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 2; verify_case(1, Arg2, minimumSupervisors(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {0, 0, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12345; int Arg2 = 0; verify_case(2, Arg2, minimumSupervisors(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {15, 0, 13, 4, 29, 6, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; int Arg2 = 10; verify_case(3, Arg2, minimumSupervisors(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {1284912, 1009228, 9289247, 2157, 2518, 52781, 2, 2818, 68}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 114; int Arg2 = 102138; verify_case(4, Arg2, minimumSupervisors(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    TheJediTest ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
