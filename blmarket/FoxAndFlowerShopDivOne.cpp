#include <iostream>
#include <cstring>
#include <cstdio>
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

vector<string> flowers;
int N,M;
int sums[35][35][35][35];
int cnts[35][35][35][35];
int maxDiff;

int step(int U, int L, int D, int R, int cDiff) {
    int ret = -1;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            for(int k=i+1;k<=N;k++) {
                for(int l=j+1;l<=M;l++) {
                    if(k <= U || D <= i || l <= L || R <= j) {
                        int tmp1 = cDiff + sums[i][j][k][l];
                        if(abs(tmp1) <= maxDiff) {
                            if(ret < cnts[i][j][k][l]) ret = cnts[i][j][k][l];
                        }
                    }
                }
            }
        }
    }
    return ret;
}

class FoxAndFlowerShopDivOne 
{
public:
    int theMaxFlowers(vector <string> flowers_, int maxDiff_) 
    {		
        flowers = flowers_;
        maxDiff = maxDiff_;
        N = flowers.size();
        M = flowers[0].size();

        memset(cnts, 0, sizeof(cnts));

        for(int i=0;i<N;i++) {
            for(int j=0;j<M;j++) {
                sums[i][j][i+1][j+1] = (flowers[i][j] == 'L' ? 1 : (flowers[i][j] == 'P' ? -1 : 0));
                cnts[i][j][i+1][j+1] = sums[i][j][i+1][j+1] == 0 ? 0 : 1;
            }
            for(int j=0;j<M;j++) {
                for(int k=j+1;k<M;k++) {
                    sums[i][j][i+1][k+1] = sums[i][j][i+1][k] + sums[i][k][i+1][k+1];
                    cnts[i][j][i+1][k+1] = cnts[i][j][i+1][k] + cnts[i][k][i+1][k+1];
                }
            }
        }
        for(int i=0;i<N;i++) {
            for(int j=i+1;j<N;j++) {
                for(int k=0;k<M;k++) {
                    for(int l=k+1;l<=M;l++) {
                        sums[i][k][j+1][l] = sums[i][k][j][l] + sums[j][k][j+1][l];
                        cnts[i][k][j+1][l] = cnts[i][k][j][l] + cnts[j][k][j+1][l];
                    }
                }
            }
        }

        int ret = -1;
        for(int i=0;i<N;i++) {
            for(int j=0;j<M;j++) {
                for(int k=i+1;k<=N;k++) {
                    for(int l=j+1;l<=M;l++) {
                        int tmp = step(i,j,k,l,sums[i][j][k][l]);
                        if(tmp != -1) {
                            if(ret < tmp + cnts[i][j][k][l]) {
                                ret = tmp + cnts[i][j][k][l];
                            }
                        }
                        // printf("%d %d %d %d = %d %d\n",i,j,k,l,sums[i][j][k][l], cnts[i][j][k][l]);
                    }
                }
            }
        }

        return ret;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"LLL",
 "PPP",
 "LLL"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 7; verify_case(0, Arg2, theMaxFlowers(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"LLL",
 "PPP",
 "LLL"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 6; verify_case(1, Arg2, theMaxFlowers(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"...",
 "...",
 "..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 0; verify_case(2, Arg2, theMaxFlowers(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"LLPL.LPP",
 "PLPPPPLL",
 "L.P.PLLL",
 "LPL.PP.L",
 ".LLL.P.L",
 "PPLP..PL"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 38; verify_case(3, Arg2, theMaxFlowers(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"LLLLLLLLLL",
 "LLLLLLLLLL",
 "LLLLLLLLLL",
 "LLLLLLLLLL",
 "LLLLLLLLLL"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = -1; verify_case(4, Arg2, theMaxFlowers(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"LLLP..LLP.PLL.LL..LP",
 "L.PL.L.LLLL.LPLLPLP.",
 "PLL.LL.LLL..PL...L..",
 ".LPPP.PPPLLLLPLP..PP",
 "LP.P.PPL.L...P.L.LLL",
 "L..LPLPP.PP...PPPL..",
 "PP.PLLL.LL...LP..LP.",
 "PL...P.PPPL..PLP.L..",
 "P.PPPLPLP.LL.L.LLLPL",
 "PLLPLLP.LLL.P..P.LPL",
 "..LLLPLPPPLP.P.LP.LL",
 "..LP..L..LLPPP.LL.LP",
 "LPLL.PLLPPLP...LL..P",
 "LL.....PLL.PLL.P....",
 "LLL...LPPPPL.PL...PP",
 ".PLPLLLLP.LPP...L...",
 "LL...L.LL.LLLPLPPPP.",
 "PLPLLLL..LP.LLPLLLL.",
 "PP.PLL..L..LLLPPL..P",
 ".LLPL.P.PP.P.L.PLPLL"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; int Arg2 = 208; verify_case(5, Arg2, theMaxFlowers(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    FoxAndFlowerShopDivOne ___test; 
    ___test.run_test(4); 
} 
// END CUT HERE
