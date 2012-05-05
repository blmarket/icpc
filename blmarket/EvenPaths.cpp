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
typedef long long LL;

template<typename T> int size(const T &a) { return a.size(); }

int n;
bool data[55][55];
bool haveway[55][55];
bool rooms[55];

pair<LL, LL> memo[55][55];
bool hasmemo[55][55];

pair<LL, LL> go(int s,int e)
{
    if(s==e) return mp(1,0);
    if(hasmemo[s][e])
        return memo[s][e];

    pair<LL, LL> ret(0,0);
    for(int i=0;i<n;i++) if(data[s][i])
    {
        bool fail = false;
        for(int j=0;j<n;j++) if(data[s][j] && hasway[i][j])
        {
            fail=true; break;
        }
    }
}

class EvenPaths 
{
public:
    long long theCount(vector <string> maze, string rooms_) 
    {
        memset(rooms, 0, sizeof(rooms));
        memset(hasmemo, 0, sizeof(hasmemo));
        n = size(maze);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                haveway[i][j] = data[i][j] = (maze[i][j] == 'Y');
            }
        }

        for(int k=0;k<n;k++) for(int i=0;i<n;i++) if(haveway[i][k]) for(int j=0;j<n;j++) if(haveway[k][j])
            haveway[i][j] = true;

        return go(0,1).second;
    }
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"NYY", "NNN", "NYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "--?"; long long Arg2 = 1LL; verify_case(0, Arg2, theCount(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"NYYNN", "NNNNY", "NYNNN", "YNNNN", "NNNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "--???"; long long Arg2 = 4LL; verify_case(1, Arg2, theCount(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"NNNNN", "NNYYN", "YNNNY", "NNNNN", "NNNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "--???"; long long Arg2 = 8LL; verify_case(2, Arg2, theCount(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"NNYNYNNY", "NNNNNNNN", "NNNNNYYY", "NYNNNNNN", "NNNNNNNN", "NYNYNNNN", "NYNNYNNN", "NNNYYNYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "----???-"; long long Arg2 = 4LL; verify_case(3, Arg2, theCount(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"NYNNNNYYYYYYYNYNYNNN",
"NNNNNNNNNNNNNNNNNNNN",
"NNNNYNYYNYNNNNYNYNYN",
"NNNNNNNNNNNNNNNNYYNN",
"NNNYNNNNNNYYNNYYNNNY",
"NYNNYNYYYYNYNYNYYYNN",
"NNNYYNNNYNYYNNYNYYNY",
"NNNYNNYNYNYNYNYYYYYN",
"NYNYYNNNNNNYYNNYYNNN",
"NNNNNNNNNNYNYNNNYYNN",
"NYNNNNNNNNNYNNNNYNNY",
"NNNNNNNNNNNNNNNNNNNN",
"NNNYNNNNNNNNNNYNNYNN",
"NNNYYNYNNYNNNNNYYYNN",
"NNNNNNNNNNNNNNNNNYNN",
"NYNYNNNNNNNNNNYNNNNN",
"NNNNNNNNNNNNNNNNNNNN",
"NYNNNNNNNNNNNNNNNNNN",
"NYNNNNNNNYNYYNNYYYNN",
"NYNNNNNNNNNNYNYNYYNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "---??-??--??--?-?---"; long long Arg2 = 136LL; verify_case(4, Arg2, theCount(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"NNYNNNNYNYYYNYNNYYNYNNYYNYNNNYYYNNNNYNNNYYNNNNYNNY",
"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
"NNNYNNNNNYNNNYNNYNNYNNYYYNYNYNNYYYNYNYYNYYNNNNYNNN",
"NNNNNNNNNYNNNNYNNNNNNNNYNNNNYNNNNNNNNNNYNNNNNNNNYN",
"NYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
"NYNNYNNNNNNNNNYNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNYNNN",
"NNNYYNNYNNYNNYNYNNNYYNYYNNNNYNNNYNNNNNYYNYNYYNNYYN",
"NYNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNYN",
"NYNYYNNYNYNYNNNNNNNNNNNNNNNNNYNNNNNNNNNYNNNNNYYNNN",
"NNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNYNNYN",
"NYNNYNNYNYNNNNYNNNNNNYNNNNNNNNNNNNNNNNNNNYNNNNNNNN",
"NYNNNNNYNNNNNNNNNNNYNNNYNNNNYNNNNNNNNNNNNNNNNNYNNN",
"NYNNNYNYNYNNNNNNNNYYNYYNNNNYNNNNNNYNNYYNNNNNYNYNYN",
"NNNNYYNNNNNNNNYNNYNYYYNYNNNNNNNYNNYNNNNNYNNNNNNYNN",
"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYN",
"NYNYNYNNNYYNNNYNNNNNYYYNYNNNNYNNNNNNNYNYNYNNNYYNYN",
"NNNNYYNYYYYYNNYNNYNYYNNNNNYNYYNNYNYNNYYYNYYYNNNNYN",
"NNNNNNNNYNNYNNNNNNNNNNNNNNNNYYNNYNYNNNNYNNNNNYNYNN",
"NNNYNYNYYYYYNNNNNNNNYNYNYNNNYNYNYNYNNNNNYYYNYNNYYN",
"NYNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYN",
"NNNYYYNYNYNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNYNNN",
"NNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNYN",
"NNNNNYNNYYYNNNYNNNNYNNNNNNNNNYNNYNYNNYNYNNNNNNNYNN",
"NYNNYNNNNNNNNNYNNNNYNYNNNNNNNNNNNNNNNNNNNYNNNYYNNN",
"NNNNNYNYYYNNNNYNNYNNNNNNNNNNNYNYNNNNNNNNNNNNNYYYNN",
"NNNNYYNYYYYNYNNNYYNYNYYNNNYYNYNNYNNYNYYNYYNYYNYYNY",
"NYNNNNNNNYYNNNNNNNNNNNNYNNNNYYNNNNYNNNYNNYNNNYNNYN",
"NNNYNYNYNYNNNNNNNNNYNYYNNNYNNYNYYNNNNNNNYNNNNYNNYN",
"NYNNNYNNNYNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNYNNN",
"NYNYNNNYNYYNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNYNNNYYNNN",
"NYNNNNNNYNNNNYYYNYNYNNNNNNNNYYNNNNNNNNNNNNNNNYYNNN",
"NNNYYNNNNNYYNNYNNNNNNYNYNNNNYYNNNNYNNNNYNNNNNNYNNN",
"NYNYNYNNNNNYNNNNNNNYNNNNNNNNNNNNNNNNNYYNNYNNNYNNYN",
"NYNNNNNNNYYNNNNYYYNNNNYNYNYNYNNYYNNYNYNNNNNNNNNNYN",
"NNNNYNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNYNNYN",
"NYNYYNNYNYNNNNNYNNNYNYNNYNNNNNNNYNNNNNYNNYNYNNNNNN",
"NYNNNNNNYNNNNYYNNNYNNYYNNYYYYYNNNYNNNNNYNYYNNNNNNY",
"NYNNNYNNNYYNNNNNNNNNNNNYNNNNNNNNNNYNNNNNNNNNNNYNNN",
"NNNNNYNNYYNYNNNNNNNNNYNYNNNNYNNNNNNNNNNNNYNNNNNNNN",
"NNNNNYNYNNYNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNYNNNNNNNN",
"NNNNYNNNYNNNNNNYNNNYNYNYYNNNNYNNNNNNNNNNNYNNNYYNNN",
"NNNNYNNYNYNNNNYNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNYYNYN",
"NYNNYYNNYNNNNNNNNNNYYYNNNNNNNNNNNNNNNNNNNNNYNNNNNN",
"NNNYYNNYYNNNNNYYNNNYNNNNYNYNNNNNNNNNNNNYNNNNNYNNNN",
"NNNNNYNYYNYNNNNNYNNYYYYNYNYYYYYNYNYYNNNNYNNNNYYYYN",
"NNNNNNNYNNNNNNYNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNYN",
"NYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYN",
"NNNYYNNNYYNYNNNNNNNNNYNNNNNNYNNNNNYNNNNNNYNNNNYNNN",
"NYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
"NYNNNNYYYNYYYYNYNNNNNNNNNNNYNYNNNNNNNNNYNYNYNNNNYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "---??--??-????-??????--?????-?-?-??--?-??--??????-"; long long Arg2 = 2165839872LL; verify_case(5, Arg2, theCount(Arg0, Arg1)); }

// END CUT HERE

};



// BEGIN CUT HERE 
int main() {
	EvenPaths ___test;
	___test.run_test(-1);
}
// END CUT HERE
