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

int state[2][900000];
int pow;

class AmoebaCode 
{
public:
    int find(string code, int K) 
    {
        memset(state[0], -1, sizeof(state[0]));
        pow = 1;
        for(int i=0;i<K;i++) pow *= K;

        for(int i=0;i<size(code);i++)
        {
            int cur = (i%2);
            int next = !cur;
            memset(state[next], 0, sizeof(state[0]));
            for(int j=1;j<=K;j++) if(code[i] == '0' || code[i]-'0' == j)
            {
                cerr << "processing " << j << endl;
                for(int k=0;k<pow;k++)
                {
                    int tmp = k;
                    int cstate = state[cur][k];
                    if(cstate == -1) cstate = K+1;
                    int ptr = (k*K+(j-1))%pow;
                    int &nstate = state[next][(k * K + (j-1)) % pow];
                    if(nstate > cstate) continue;
                    for(int l=0;l<K;l++)
                    {
                        int dgt = (tmp % K) + 1;
                        if(dgt == j)
                        {
                            nstate = max(nstate, min(cstate, l+1));
                        }
                        tmp /= K;
                    }

                    cerr << next << "," << ptr << " = " << nstate << endl;
                }
            }
        }

        int cur = size(code) % 2;
        int ret = K+1;
        for(int i=0;i<pow;i++)
            ret = min(ret, state[cur][i]);
        return ret;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "01"; int Arg1 = 1; int Arg2 = 1; verify_case(0, Arg2, find(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "1001"; int Arg1 = 2; int Arg2 = 1; verify_case(1, Arg2, find(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "1010"; int Arg1 = 2; int Arg2 = 2; verify_case(2, Arg2, find(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "01001"; int Arg1 = 3; int Arg2 = 3; verify_case(3, Arg2, find(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "10012031001"; int Arg1 = 3; int Arg2 = 2; verify_case(4, Arg2, find(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    AmoebaCode ___test; 
    ___test.run_test(1); 
} 
// END CUT HERE
