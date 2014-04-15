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

/**
 * Problem: 500
 * Test Case: 6
 * Succeeded: No
 * Execution Time: 23 ms
 * Args:
 * {{1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824, 2147483648, 4294967296, 8589934592, 17179869184, 34359738368, 68719476736, 137438953472, 274877906944, 549755813888, 1099511627776, 2199023255552, 4398046511104, 8796093022208, 17592186044416, 35184372088832, 70368744177664, 140737488355328, 281474976710656, 562949953421312, 1125899906842624, 2251799813685248, 4503599627370496, 9007199254740992, 18014398509481984, 36028797018963968, 72057594037927936, 144115188075855872, 288230376151711744, 576460752303423488}}
 *
 * Expected:
 * 6
 *
 * Received:
 * 7
 *
 * Answer checking result:
 * Returned value must exactly match the expected one.
 */

map<long long, int> M;

int know(int num, long long ng) {
    if(num == 1) return 0;
    int gs = (num + ng - 1) / ng;
    int ret = know(gs, ng) + 1;
    cout << "known " << ng << " " << num << " = " << ret << endl;
    return ret;
}

int unkn(int num, long long ng) {
    if(num == 0) return 0;
    if(num == 1) return 1;
    int gs = (num + ng - 1) / ng;
    int ret = 0;
    if(num % ng == 0) {
        ret = unkn(gs, ng) + 1;
    } else {
        ret = max(know(gs, ng), unkn(gs-1, ng)) + 1;
    }
    cout << "unkn  " << ng << " " << num << " = " << ret << endl;
}

class ColorfulCoins 
{
public:
    int minQueries(vector<long long> values) 
    {		
        M.clear();
        sort(values.begin(), values.end());
        for(int i=0;i+1<size(values);i++) {
            long long dim = values[i+1] / values[i];
            M[dim] += 1;
        }

        int ret = 1;
        for(auto &a : M) {
            int tmp = unkn(a.second, a.first);
            cout << a.first << " " << a.second << " = " << tmp << endl;
            ret = max(ret, tmp);
        }
        return ret;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long Arr0[] = {1}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, minQueries(Arg0)); }
	void test_case_1() { long Arr0[] = {1, 3}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, minQueries(Arg0)); }
	void test_case_2() { long Arr0[] = {1, 2, 4}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, minQueries(Arg0)); }
	void test_case_3() { long Arr0[] = {1, 2, 4, 8, 16}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(3, Arg1, minQueries(Arg0)); }
	void test_case_4() { long Arr0[] = {1, 2, 6, 30, 90, 270, 810, 2430, 7290, 29160, 87480, 262440, 787320, 3149280,
  9447840, 28343520, 56687040, 170061120, 510183360, 1530550080, 3061100160,
  9183300480, 27549901440, 82649704320, 247949112960, 1239745564800, 3719236694400,
  14876946777600, 44630840332800, 223154201664000, 669462604992000, 2008387814976000,
  6025163444928000, 12050326889856000, 24100653779712000, 72301961339136000,
  289207845356544000, 867623536069632000}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(4, Arg1, minQueries(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    ColorfulCoins ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
