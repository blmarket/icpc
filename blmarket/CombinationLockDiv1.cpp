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

int d[2505];
int n;

int dp[2][2][2505];

class CombinationLockDiv1 
{
public:
    int minimumMoves(vector <string> P, vector <string> Q) 
    {		
        string pp,qq;
        for(int i=0;i<size(P);i++) pp += P[i];
        for(int i=0;i<size(Q);i++) qq += Q[i];

        n = size(pp);
        for(int i=0;i<n;i++) d[i] = (pp[i] - qq[i] + 10) % 10;

        memset(dp, -1, sizeof(dp));

        dp[0][0][0] = d[0];
        dp[0][1][0] = 10-d[0];

        int lm = min(d[0], 10-d[0]);
        cout << lm << endl;

        for(int i=1;i<n;i++) {
            int cur = i%2;
            int prev = !cur;

            memset(dp[cur], -1, sizeof(dp[cur]));

            dp[cur][0][0] = lm + d[i];
            dp[cur][1][0] = lm + (10-d[i]);

            lm = min(dp[cur][0][0], dp[cur][1][0]);

            for(int j=0;j<2;j++) {
                int pi, ci;
                if(j == 0) {
                    pi = d[i-1];
                    ci = d[i];
                } else {
                    pi = 10 - d[i-1];
                    ci = 10 - d[i];
                }

                for(int k=0;k<2500;k++) {
                    int cii = ci + 10 * k;
                    for(int l=max(0, k-1);l<=k+1;l++) if(dp[prev][j][l] != -1) {
                        int pii = pi + 10 * l;
                        int tmp = dp[prev][j][l] + max(0, cii - pii);
                        if(dp[cur][j][k] == -1 || dp[cur][j][k] > tmp) dp[cur][j][k] = tmp;
                    }
                    lm = min(lm, dp[cur][j][k]);
                }
            }
        }
        return lm;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"123"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"112"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(0, Arg2, minimumMoves(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"7"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(1, Arg2, minimumMoves(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"6","07"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"","60","7"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(2, Arg2, minimumMoves(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"1234"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"4567"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(3, Arg2, minimumMoves(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"020"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"909"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(4, Arg2, minimumMoves(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"4423232218340"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"6290421476245"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 18; verify_case(5, Arg2, minimumMoves(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    CombinationLockDiv1 ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
