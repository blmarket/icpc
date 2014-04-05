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

const int mod = 1000000007;

void addmod(int &a, int b) {
    a += b;
    if(a >= mod) a -= mod;
}

int memo[2][55][55];

class AlternativePiles 
{
public:
    int count(string C, int M) 
    {		
        memset(memo, 0, sizeof(memo));
        memo[0][0][0] = 1;

        for(int i=0;i<size(C);i++) {
            int cur = i %2;
            int nex = !cur;
            if(C[i] == 'B') {
                memcpy(memo[nex], memo[cur], sizeof(memo[0]));
                continue;
            }

            memset(memo[nex], 0, sizeof(memo[nex]));

            for(int j=0;j<=M;j++) {
                for(int k=0;k<M;k++) if(memo[cur][j][k]) {
                    int cc = memo[cur][j][k];
                    if(C[i] != 'G' && j < M) {
                        addmod(memo[nex][j+1][(k+1)%M], cc);
                    }
                    if(C[i] != 'R' && j > 0) {
                        addmod(memo[nex][j-1][k], cc);
                    }
                }
            }
        }

        int cur = size(C) % 2;
        
        return memo[cur][0][0];
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "WRGWWRGW"; int Arg1 = 2; int Arg2 = 3; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "RRGG"; int Arg1 = 1; int Arg2 = 0; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "BBBB"; int Arg1 = 5; int Arg2 = 1; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW"; int Arg1 = 50; int Arg2 = 265470435; verify_case(3, Arg2, count(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "WRWRGWWGWWWRWBWRWGWWRWBWWRGWBWGRGWWGWGRWGRWBRWBW"; int Arg1 = 7; int Arg2 = 7400348; verify_case(4, Arg2, count(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    AlternativePiles ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
