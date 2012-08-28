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
void setmax(int &a, int b) { if(a<b) a=b; }

vector<string> flowers;
int N,M;
int sums[35][35];
int cnts[35][35];
int maxDiff;

int get(int arr[][35], int u, int l, int d, int r) {
    return arr[d][r] - arr[u][r] - arr[d][l] + arr[u][l];
}

int getSum(int u,int l,int d,int r) {
    return get(sums,u,l,d,r);
}

int getCnt(int u,int l, int d, int r) {
    return get(cnts, u, l, d, r);
}

int res1[2000];
int res2[2000];

int go(int res[], int L, int R) {
    memset(res, -1, sizeof(res1));
    for(int i=0;i<N;i++) {
        for(int j=i;j<N;j++) {
            for(int k=L;k<R;k++) {
                for(int l=k;l<R;l++) {
                    int sum = getSum(i,k,j+1,l+1);
                    int cnt = getCnt(i,k,j+1,l+1);
                    setmax(res[1000 + sum], cnt);
                }
            }
        }
    }
}

int calc() {
    int ret = -1;
    for(int i=0;i<2000;i++) if(res1[i] != -1) {
        for(int j=-maxDiff;j<=maxDiff;j++) {
            int dst = 2000 + j - i;
            if(res2[dst] == -1) continue;

            if(ret < res1[i] + res2[dst]) {
                ret = res1[i] + res2[dst];
            }
        }
    }
    return ret;
}

int build() {
    int ret = -1;
    for(int j=1;j<M;j++) {
        go(res1, 0, j);
        go(res2, j, M);

        int tmp = calc();
        if(ret < tmp) ret = tmp;
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

        for(int i=0;i<N;i++) {
            for(int j=0;j<M;j++) {
                int tmp = 0;
                if(flowers[i][j] == 'L') tmp=1; else if(flowers[i][j] == 'P') tmp = -1;
                sums[i+1][j+1] = sums[i+1][j] + sums[i][j+1] - sums[i][j] + tmp;
                cnts[i+1][j+1] = cnts[i+1][j] + cnts[i][j+1] - cnts[i][j] + abs(tmp);
            }
        }

        int tmp = build();
        for(int i=0;i<=30;i++) {
            for(int j=0;j<i;j++) {
                swap(sums[i][j], sums[j][i]);
                swap(cnts[i][j], cnts[j][i]);
            }
        }
        swap(N,M);
        int tmp2 = build();

        return max(tmp, tmp2);
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
    ___test.run_test(5); 
} 
// END CUT HERE
