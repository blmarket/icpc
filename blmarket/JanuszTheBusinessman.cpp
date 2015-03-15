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
 * Problem: 250
 * Test Case: 6
 * Succeeded: No
 * Execution Time: 3 ms
 * Peak memory used: 11.602MB
 * Args:
 * {{1, 2, 3, 4, 5, 6, 7}, {2, 3, 365, 5, 6, 7, 8}}
 *
 * Expected:
 * 2
 *
 * Received:
 * 3
 *
 * Answer checking result:
 * Returned value must exactly match the expected one.
 */
vector<PII> V;
int memo[55];

int go(int a) {
    if(memo[a] != -1) return memo[a];
    int ret = -1;
    int myd = V[a].first;
    for(int i=a;i<size(V);i++) {
        if(V[i].second <= myd) {
            // check this candidate
            int j = a;
            while(j < size(V) && V[i].second <= V[j].first) {
                j++;
                int tmp = go(j) + 1;
                if(ret == -1 || ret > tmp) ret = tmp;
            }
        }
    }
    return memo[a] = ret;
}

class JanuszTheBusinessman 
{
public:
    int makeGuestsReturn(vector <int> arrivals, vector <int> departures) 
    {		
        memset(memo, -1, sizeof(memo));
        for(int i=0;i<size(arrivals);i++) {
            V.pb(mp(departures[i], arrivals[i]));
        }

        sort(V.begin(), V.end());
        memo[size(V)] = 0;
        return go(0);
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2, 10, 6}	; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {6, 11, 9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(0, Arg2, makeGuestsReturn(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {2, 10, 23, 34, 45, 123, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {25, 12, 40, 50, 48, 187, 365}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(1, Arg2, makeGuestsReturn(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {8, 12, 20, 30, 54, 54, 68, 75}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {13, 31, 30, 53, 55, 70, 80, 76}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(2, Arg2, makeGuestsReturn(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {124, 328, 135, 234, 347, 124, 39, 99, 116, 148}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {237, 335, 146, 246, 353, 213, 197, 215, 334, 223}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(3, Arg2, makeGuestsReturn(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {154, 1, 340, 111, 92, 237, 170, 113, 241, 91, 228, 134, 191, 86, 59, 115, 277, 328, 12, 6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {159, 4, 341, 118, 101, 244, 177, 123, 244, 96, 231, 136, 193, 95, 64, 118, 282, 330, 17, 13}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 14; verify_case(4, Arg2, makeGuestsReturn(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    JanuszTheBusinessman ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
