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
double pp[55][55][55][55];

void addone(int aa, int bb, int cc) {
    N++;
    pp[N][0][0][0] = 1.0;

    for(int i=0;i<=N;i++) {
        for(int j=0;i+j<=N;j++) {
            for(int k=0;i+j+k<=N;k++) {
                int sum = i+j+k;
                if(sum == 0) continue;
                pp[N][i][j][k] = pp[N-1][i][j][k] / N * (N - sum);
                if(i) pp[N][i][j][k] += pp[N-1][i-1][j][k] * i / N * aa / 300.0;
                if(j) pp[N][i][j][k] += pp[N-1][i][j-1][k] * j / N * bb / 300.0;
                if(k) pp[N][i][j][k] += pp[N-1][i][j][k-1] * k / N * cc / 300.0;
            }
        }
    }
}

class RockPaperScissors 
{
public:
    double bestScore(vector <int> rockProb, vector <int> paperProb, vector <int> scissorsProb) 
    {
        memset(pp, 0, sizeof(pp));
        N = 0;
        pp[0][0][0][0] = 1.0;
        for(int i=0;i<size(rockProb);i++) {
            addone(rockProb[i], paperProb[i], scissorsProb[i]);
        }
        cout << pp[1][1][0][0] << " " << pp[1][0][1][0] << " " << pp[1][0][0][1] << endl;
        return 0;
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
    ___test.run_test(0); 
} 
// END CUT HERE
