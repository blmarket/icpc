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
typedef long long LL;

template<typename T> int size(const T &a) { return a.size(); }

LL methods[2][55][2][2];
const LL mod = 1000000007LL;

vector<string> grid;
int n,m;

long long cnt(char L, char R) {
    memset(methods, 0, sizeof(methods));
    for(int i=0;i<n;i++) {
        int turn = (i % 2);
        memset(methods[turn], 0, sizeof(methods[0]));
        for(int j=0;j<=m;j++) {
            cout << i << " " << j << endl;
            bool fail = false;

            for(int k=0;k<j;k++) {
                if(grid[i][k] == R) {
                    fail = true;
                    break;
                }
            }
            if(fail) continue;
            for(int k=j;k<m;k++) {
                if(grid[i][k] == L) {
                    fail = true;
                    break;
                }
            }
            if(fail) continue;

            if(i == 0) {
                methods[turn][j][0][0] = 1;
                cout << methods[turn][j][0][0] << " " << methods[turn][j][0][1] << " " << methods[turn][j][1][0] << " " << methods[turn][j][1][1] << endl;
                continue;
            }

            for(int k=0;k<=m;k++) {
                if(k < j) { // left is expanding, right is shrinking
                    methods[turn][j][0][1] += (methods[1-turn][k][0][0] + methods[1-turn][k][0][1]) % mod;
                } else if(k > j) {
                    methods[turn][j][1][0] += (methods[1-turn][k][0][0] + methods[1-turn][k][1][0]) % mod;
                } else { // j == k
                    methods[turn][j][0][0] += methods[1-turn][k][0][0];
                    methods[turn][j][0][1] += methods[1-turn][k][0][1];
                    methods[turn][j][1][0] += methods[1-turn][k][1][0];
                    methods[turn][j][1][1] += methods[1-turn][k][1][1];
                }
            }

            cout << methods[turn][j][0][0] << " " << methods[turn][j][0][1] << " " << methods[turn][j][1][0] << " " << methods[turn][j][1][1] << endl;
        }
    }

    int turn = (n-1) % 2;
    long long ret = 0;
    for(int i=0;i<=m;i++) {
        ret += methods[turn][i][0][0];
        ret += methods[turn][i][0][1];
        ret += methods[turn][i][1][0];
        ret += methods[turn][i][1][1];
    }
    ret %= mod;
    return ret;
}

class TwoConvexShapes 
{
public:
    int countWays(vector <string> grid_) 
    {
        grid = grid_; n =size(grid); m = size(grid[0]);
        bool hasB = false, hasW = false;
        for(int i=0;i<size(grid);i++) for(int j=0;j<size(grid[i]);j++) {
            if(grid[i][j] == 'B') hasB = true;
            if(grid[i][j] == 'W') hasW = true;
        }
        long long ret = cnt('W', 'B') + cnt('B', 'W');
        if(hasB == false || hasW == false) {
            ret--;
        }
        if(hasB == false && hasW == false) {
            ret--;
        }
        return ((ret + mod) % mod);
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"??",
 "??"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 14; verify_case(0, Arg1, countWays(Arg0)); }
	void test_case_1() { string Arr0[] = {"B?",
 "??"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(1, Arg1, countWays(Arg0)); }
	void test_case_2() { string Arr0[] = {"WWB",
 "WWW",
 "WWW",
 "WWW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, countWays(Arg0)); }
	void test_case_3() { string Arr0[] = {"BBBBBB",
 "WWBBBB",
 "WBBBBB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(3, Arg1, countWays(Arg0)); }
	void test_case_4() { string Arr0[] = {"?BB?",
 "BBBB",
 "?BB?"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(4, Arg1, countWays(Arg0)); }
	void test_case_5() { string Arr0[] = {"?WWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
 "B?WWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
 "BB?WWWWWWWWWWWWWWWWWWWWWWWWWWWW",
 "BBB?WWWWWWWWWWWWWWWWWWWWWWWWWWW",
 "BBBB?WWWWWWWWWWWWWWWWWWWWWWWWWW",
 "BBBBB?WWWWWWWWWWWWWWWWWWWWWWWWW",
 "BBBBBB?WWWWWWWWWWWWWWWWWWWWWWWW",
 "BBBBBBB?WWWWWWWWWWWWWWWWWWWWWWW",
 "BBBBBBBB?WWWWWWWWWWWWWWWWWWWWWW",
 "BBBBBBBBB?WWWWWWWWWWWWWWWWWWWWW",
 "BBBBBBBBBB?WWWWWWWWWWWWWWWWWWWW",
 "BBBBBBBBBBB?WWWWWWWWWWWWWWWWWWW",
 "BBBBBBBBBBBB?WWWWWWWWWWWWWWWWWW",
 "BBBBBBBBBBBBB?WWWWWWWWWWWWWWWWW",
 "BBBBBBBBBBBBBB?WWWWWWWWWWWWWWWW",
 "BBBBBBBBBBBBBBB?WWWWWWWWWWWWWWW",
 "BBBBBBBBBBBBBBBB?WWWWWWWWWWWWWW",
 "BBBBBBBBBBBBBBBBB?WWWWWWWWWWWWW",
 "BBBBBBBBBBBBBBBBBB?WWWWWWWWWWWW",
 "BBBBBBBBBBBBBBBBBBB?WWWWWWWWWWW",
 "BBBBBBBBBBBBBBBBBBBB?WWWWWWWWWW",
 "BBBBBBBBBBBBBBBBBBBBB?WWWWWWWWW",
 "BBBBBBBBBBBBBBBBBBBBBB?WWWWWWWW",
 "BBBBBBBBBBBBBBBBBBBBBBB?WWWWWWW",
 "BBBBBBBBBBBBBBBBBBBBBBBB?WWWWWW",
 "BBBBBBBBBBBBBBBBBBBBBBBBB?WWWWW",
 "BBBBBBBBBBBBBBBBBBBBBBBBBB?WWWW",
 "BBBBBBBBBBBBBBBBBBBBBBBBBBB?WWW",
 "BBBBBBBBBBBBBBBBBBBBBBBBBBBB?WW",
 "BBBBBBBBBBBBBBBBBBBBBBBBBBBBB?W"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 73741817; verify_case(5, Arg1, countWays(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    TwoConvexShapes ___test; 
    ___test.run_test(0); 
} 
// END CUT HERE
