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

/**
 * Problem: 500
 * Test Case: 49
 * Succeeded: No
 * Execution Time: 0 ms
 * Args:
 * {{"33 45 13 37 37 31 18 28 18 29 24 40 33 29 4 16 33", "30 37 26 43 36 22 28 30 18 18 10 44 20 41 29 44 16", "20 41 25 24 14 20 24 25 30 32 32 41 36 27 29 30 29", "4", "6 36 45 30 37 20 10 27 20 37 41 20 14 41 41 27 6", "22 27 34 29 20 25 34 29 22 32 8 3 24 31 45 20 10", "41 17 38 17 31 15 19 13 33 10 37 41 3 16 19 40 17", "43 43 43 31 43 31 25 31 25 25 43 39 25 31 31 39 39", "28 40 3 37 30 42 27 20 30 18 45 14 34 18 11 32 42", "8 28 34 39 36 43 39 45 25 44 28 34 19 36 19 41 45", "11", "15 4 11 33 45 14 31 4 20 14 44 44 10 43 6 36 21", "28 22 44 44 31 14 36 3 20 34 25 39 30 43 41 43 29", "32 34 44 34 41 44 39 28 27 27 34 25 32 27 30 25 41", "27 43 14 4 26 45 19 18 37 29 34 45 16 39 29 4 31", "19 39 6 30 32 8 26 8 37 6 13 22 4 28 26 44 29", "31 23 34 29 29 23 41 5 37 37 41 19 32 24 25 3 24", "20 32 27 28 40 26 25 34 14 44 31 43 28 3 4 40 45", "31 39 39 43 43 25 31 8 8 25 43 39 8 25 39 39 8", "28 31 22 30 25 30 39 34 28 31 30 44 8 43 22 19 39", "21", "8 19 31 31 43 25 28 25 43 25 34 19 43 32 44 43 28", "36 29 43 19 13 24 41 26 26 37 18 30 8 27 27 29 26", "24", "25", "26", "22 22 8 32 28 30 44 8 22 19 22 20 20 32 39 19 25", "28", "29", "32 25 25 43 22 39 19 39 43 43 44 43 43 19 8 44 19", "31", "19 8 19 43 44 25 44 43 8 44 8 28 39 28 43 44 34", "8 31 34 16 28 41 3 18 37 44 21 23 39 10 27 25 8", "31 8 44 25 28 43 25 19 31 44 31 31 43 43 31 19 25", "11 15 18 20 30 13 2 26 17 36 39 39 3 20 43 19 2", "8 32 34 14 29 22 29 29 44 44 25 19 27 43 4 29 29", "27 39 19 27 8 27 34 34 25 32 31 22 39 8 34 20 43", "38", "25 25 25 31 25 25 25 31 25 25 31 31 25 31 25 31 31", "3 14 37 13 29 24 14 16 19 14 39 16 31 36 32 4 6", "22 25 22 39 19 30 27 32 31 19 25 34 34 37 20 19 19", "21 20 10 20 41 8 23 4 18 39 37 30 41 5 43 18 21", "25 39 39 25 25 31 25 39 39 39 25 39 39 39 25 25 39", "44", "34 29 29 36 19 24 28 25 22 31 36 37 20 19 36 8 41"}}
 *
 * Expected:
 * 516208987
 *
 * Received:
 * The code execution time exceeded the 2.000 second time limit.
 */

const int mod = 1000000007;
vector<int> links[55];
bool reach[55][55];
int memo[55];

bool chkinf(int a) {
    if(memo[a] != -1) return memo[a];
    if(reach[a][a]) {
        if(links[a].size() > 1) return memo[a] = 1;
        int tmp = links[a][0];
        while(tmp != a) {
            if(links[tmp].size() > 1) return memo[a] = 1;
            tmp = links[tmp][0];
        }
        return memo[a] = 0;
    }

    for(int i=0;i<size(links[a]);i++) {
        if(chkinf(links[a][i])) return memo[a] = 1;
    }
    return memo[a] = 0;
}

int getc(int a) {
    if(reach[a][a]) return 1;
    if(memo[a] != -1) return memo[a];
    int ret = 0;
    for(int i=0;i<size(links[a]);i++) {
        ret += getc(links[a][i]);
        if(ret >= mod) ret -= mod;
    }
    return memo[a] = ret;
}

class MonsterFarm 
{
public:
    int numMonsters(vector <string> tra) 
    {
        int n = size(tra);
        memset(reach, 0, sizeof(reach));
        for(int i=0;i<n;i++) {
            istringstream sin(tra[i]);
            int tmp;
            links[i].clear();
            while(sin >> tmp) {
                links[i].pb(tmp-1);
                reach[i][tmp-1] = true;
            }
        }

        for(int k=0;k<n;k++) {
            for(int i=0;i<n;i++) if(reach[i][k]) {
                for(int j=0;j<n;j++) if(reach[k][j]) reach[i][j] = true;
            }
        }

        memset(memo, -1, sizeof(memo));
        if(chkinf(0)) return -1;
        memset(memo, -1, sizeof(memo));
        return getc(0);
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, numMonsters(Arg0)); }
	void test_case_1() { string Arr0[] = {"1 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(1, Arg1, numMonsters(Arg0)); }
	void test_case_2() { string Arr0[] = {"2", "3", "1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, numMonsters(Arg0)); }
	void test_case_3() { string Arr0[] = {"1", "3 4", "2", "2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(3, Arg1, numMonsters(Arg0)); }
	void test_case_4() { string Arr0[] = {"2 2", "3", "4 4 4", "5", "6", "7 7 7 7", "7"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 24; verify_case(4, Arg1, numMonsters(Arg0)); }
	void test_case_5() { string Arr0[] = {"2 3","5 7","2 4","5","6","4","7"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(5, Arg1, numMonsters(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    MonsterFarm ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
