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
double cur[55][55][55], nex[55][55][55];
double memo[55][55][55];

void addone(int aa, int bb, int cc) {
    N++;
    memset(nex, 0, sizeof(nex));
    nex[0][0][0] = 1.0;

    for(int i=0;i<=N;i++) {
        for(int j=0;i+j<=N;j++) {
            for(int k=0;i+j+k<=N;k++) {
                int sum = i+j+k;
                if(sum == 0) continue;
                nex[i][j][k] = cur[i][j][k] / N * (N - sum);
                if(i) nex[i][j][k] += cur[i-1][j][k] * i / N * aa / 300.0;
                if(j) nex[i][j][k] += cur[i][j-1][k] * j / N * bb / 300.0;
                if(k) nex[i][j][k] += cur[i][j][k-1] * k / N * cc / 300.0;
            }
        }
    }

    memcpy(cur, nex, sizeof(cur));
}

double go(int a,int b,int c) {
    if(memo[a][b][c] >= -1e-6) return memo[a][b][c];
    int sum = a+b+c;
    if(sum == N) return memo[a][b][c] = 0;

    if(cur[a][b][c] < 1e-6) return memo[a][b][c] = 0;

    double p1 = cur[a+1][b][c] / cur[a][b][c];
    double p2 = cur[a][b+1][c] / cur[a][b][c];
    double p3 = cur[a][b][c+1] / cur[a][b][c];

    double ex = go(a+1,b,c) * p1 + go(a,b+1,c) * p2 + go(a,b,c+1) * p3;

    double ex1 = p1 + p3 * 3;
    double ex2 = p2 + p1 * 3;
    double ex3 = p3 + p2 * 3;
    double mex = max(ex1,ex2);
    cout << p1 << " " << p2 << " " << p3 << " " << p1+p2+p3 << " " << mex << endl;

    mex = max(mex, ex3);

    return memo[a][b][c] = mex + ex;
}

class RockPaperScissors 
{
public:
    double bestScore(vector <int> rockProb, vector <int> paperProb, vector <int> scissorsProb) 
    {
        memset(cur, 0, sizeof(cur));
        N = 0;
        cur[0][0][0] = 1.0;
        for(int i=0;i<size(rockProb);i++) {
            addone(rockProb[i], paperProb[i], scissorsProb[i]);
        }

        for(int i=0;i<55;i++) for(int j=0;j<55;j++) for(int k=0;k<55;k++) memo[i][j][k] = -1;

        return go(0,0,0);
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {100, 100, 100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {100, 100, 100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {100, 100, 100}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 3.999999999999999; verify_case(0, Arg3, bestScore(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {300}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 3.0; verify_case(1, Arg3, bestScore(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {300, 0,   0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,   300, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,   0,   300}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 6.333333333333332; verify_case(2, Arg3, bestScore(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {100,  0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {200, 100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,   200}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 3.7222222222222223; verify_case(3, Arg3, bestScore(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {150,300,300,300,300,300,300,300,300,300,300,300,300,300
,300,300,300,300,300,300,300,300,300,300,300,300,300,300
,300,300,300,300,300,300,300,300,300,300,300,300,300,300
,300,300,300,300,300,300,300,300}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {150,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
,0,0,0,0,0,0,0,0,0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 149.00000000000003; verify_case(4, Arg3, bestScore(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    RockPaperScissors ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
