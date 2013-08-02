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

VI L;
int memo[30][30][30];

int go(int pos, int used, int now) {
    if(memo[pos][used][now] != -1) return memo[pos][used][now];
    if(pos == size(L)) return memo[pos][used][now] = 0;
    // now: current using window.
    int usable = 26-used;
    if(usable < 26 && L[pos] > usable) return memo[pos][used][now] = -2; // unable to finish it.
    int nnow = max(now, L[pos]);

    int ret = -2;

    for(int i=0;i<=L[pos];i++) { // end them here.
        int stretch = max(now - i, 0);
        int begins = max(nnow - i - stretch, 0);
        int ends = min(i, now);

        int tmp = go(pos+1, used + i, nnow - i);
        cout << tmp << endl;
        if(tmp >= 0) {
            tmp += begins * (begins + 1) / 2;
            tmp += ends * (ends + 1) / 2;
            tmp += stretch * L[pos];
            if(ret == -1 || ret > tmp) {
                cout << pos << " " << used << " " << now << " : " << i << " = " << tmp << endl;
                ret = tmp;
            }
        }
    }

    cout << pos << " " << used << " " << now << " = " << ret << endl;
    return memo[pos][used][now] = ret;
}

class StringWeight 
{
public:
    int getMinimum(vector <int> L_)
    {
        memset(memo, -1, sizeof(memo));
        L = L_;
        return go(0, 0, 0);
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(0, Arg1, getMinimum(Arg0)); }
	void test_case_1() { int Arr0[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, getMinimum(Arg0)); }
	void test_case_2() { int Arr0[] = {26, 2, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(2, Arg1, getMinimum(Arg0)); }
	void test_case_3() { int Arr0[] = {25, 25, 25, 25}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1826; verify_case(3, Arg1, getMinimum(Arg0)); }
	void test_case_4() { int Arr0[] = {14, 6, 30, 2, 5, 61}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1229; verify_case(4, Arg1, getMinimum(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    StringWeight ___test; 
    ___test.run_test(1); 
} 
// END CUT HERE
