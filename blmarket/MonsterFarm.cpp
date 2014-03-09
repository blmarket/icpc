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

/*
 * Problem: 500
 * Test Case: 2
 * Succeeded: No
 * Execution Time: 3 ms
 * Args:
 * {{"2 3", "1", "1"}}
 *
 * Expected:
 * -1
 *
 *  Received:
 *  2
 */

vector<int> links[55];
bool reach[55][55];

bool chkinf(int a) {
    cout << a << " " << reach[a][a] << endl;
    if(reach[a][a]) {
        if(links[a].size() > 1) return true;
        int tmp = links[a][0];
        while(tmp != a) {
            if(links[tmp].size() > 1) return true;
            tmp = links[tmp][0];
        }
        return false;
    }

    for(int i=0;i<size(links[a]);i++) {
        if(chkinf(links[a][i])) return true;
    }
    return false;
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
                reach[i][tmp] = true;
            }
        }

        for(int k=0;k<n;k++) {
            for(int i=0;i<n;i++) if(reach[i][k]) {
                for(int j=0;j<n;j++) if(reach[k][j]) reach[i][j] = true;
            }
        }

        if(chkinf(0)) return -1;
        return 0;
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
