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

void add(int &a, int b) {
    a += b;
    if(a >= mod) a -= mod;
}

class WinterAndSnowmen 
{
public:
    int getNumber(int N, int M) 
    {
        long long ret = 0;
        int mm = max(N, M);
        for(int i=0;i<=11;i++) {
            int cur[2048][4], nex[2048][4];
            memset(cur, 0, sizeof(cur));
            cur[0][0] = 1;
            for(int j=1;j<=mm;j++) {
                // cout << i << " " << j << endl;
                memset(nex, 0, sizeof(nex));
                for(int a=0;a<2048;a++) for(int b=0;b<4;b++) if(cur[a][b]) {
                    // cout << a << " " << b << " = " << cur[a][b] << endl;
                    if(j <= N) {
                        int nb = b;
                        if(j & (1<<i)) nb ^= 1;
                        add(nex[a ^ j][nb], cur[a][b]);
                    }
                    if(j <= M) {
                        int nb = b;
                        if(j & (1<<i)) nb ^= 2;
                        add(nex[a ^ j][nb], cur[a][b]);
                    }
                }
                for(int a=0;a<2048;a++) for(int b=0;b<4;b++) add(cur[a][b], nex[a][b]);
            }
            for(int a=0;a<2048;a++) {
                if((a >> i) == 1) ret += cur[a][2];
            }
        }
        return ret % mod;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 4; verify_case(0, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 1; verify_case(1, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 5; int Arg2 = 74; verify_case(2, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 7; int Arg1 = 4; int Arg2 = 216; verify_case(3, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 47; int Arg1 = 74; int Arg2 = 962557390; verify_case(4, Arg2, getNumber(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    WinterAndSnowmen ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
