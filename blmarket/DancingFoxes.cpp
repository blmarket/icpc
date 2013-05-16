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

int N;
vector<string> data;
int memo[55][55];

int go(int a, int b) {
    if(data[a][b] == 'Y') return 1;
    if(memo[a][b] != -1) return memo[a][b];
    memo[a][b] = -2;

    int ret = -2;
    for(int i=0;i<N;i++) if(i!=a && i!=b) {
        int tmp1 = go(a,i);
        int tmp2 = go(i,b);
        if(tmp1 == -2 || tmp2 == -2) continue;
        if(ret < 0 || ret > max(tmp1,tmp2) + 1) {
            ret = max(tmp1,tmp2) + 1;
        }
    }

    return memo[a][b] = ret;
}

class DancingFoxes 
{
public:
    int minimalDays(vector <string> friendship) 
    {
        memset(memo, -1, sizeof(memo));
        data = friendship;
        N = size(data);
        int tmp = go(0,1);
        if(tmp == -2) return -1;
        return tmp;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"NNY",
 "NNY",
 "YYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, minimalDays(Arg0)); }
	void test_case_1() { string Arr0[] = {"NNNNN",
 "NNYYY",
 "NYNYY",
 "NYYNY",
 "NYYYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(1, Arg1, minimalDays(Arg0)); }
	void test_case_2() { string Arr0[] = {"NNYYNN",
 "NNNNYY",
 "YNNNYN",
 "YNNNNY",
 "NYYNNN",
 "NYNYNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, minimalDays(Arg0)); }
	void test_case_3() { string Arr0[] = {"NNYNNNNYN",
 "NNNNYNYNN",
 "YNNYNYNNN",
 "NNYNYNYYN",
 "NYNYNNNNY",
 "NNYNNNYNN",
 "NYNYNYNNN",
 "YNNYNNNNY",
 "NNNNYNNYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(3, Arg1, minimalDays(Arg0)); }
	void test_case_4() { string Arr0[] = {"NY",
 "YN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(4, Arg1, minimalDays(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    DancingFoxes ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
