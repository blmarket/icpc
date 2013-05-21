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
double pp[55][55][55];
double nex[55][55][55];
long long combi[55][55];

void addone(double a, double b, double c) {
    memset(nex, 0, sizeof(nex));
    nex[0][0][0] = 1.0;
    for(int i=0;i<=N;i++) {
        for(int j=0;i+j<=N;j++) {
            for(int k=0;i+j+k<=N;k++) {
                int tot = i+j+k;
                if(tot == 0) continue;

                nex[i][j][k] = pp[i][j][k] * (N-tot) / N;
                if(i) {
                    nex[i][j][k] += pp[i-1][j][k] * tot / N * a;
                }
                if(j) {
                    nex[i][j][k] += pp[i][j-1][k] * tot / N * b;
                }
                if(k) {
                    nex[i][j][k] += pp[i][j][k-1] * tot / N * c;
                }
            }
        }
    }

    if(N == 3) {
        cout << "aaa ";
        cout << pp[2][0][0] << " " << pp[1][1][0] << endl;
    }

    memcpy(pp, nex, sizeof(pp));
}

double norm(int a,int b,int c) {
    int sum = a+b+c;
    if(sum == 0) return 1.0;
    return pp[a][b][c] / combi[sum][a] / combi[b+c][b];
}

double go(int a,int b,int c) {
    if(pp[a][b][c] < 1e-6) return 0.0;
    int sum = a+b+c;
    if(sum == N) return 0;
    if(nex[a][b][c] >= 0) return nex[a][b][c];

    double p1 = norm(a+1,b,c) / norm(a,b,c);
    double p2 = norm(a,b+1,c) / norm(a,b,c);
    double p3 = norm(a,b,c+1) / norm(a,b,c);

    double ex1 = go(a+1,b,c), ex2 = go(a,b+1,c), ex3 = go(a,b,c+1);

    double r1 = p1 + 3 * p3 + ex1;
    double r2 = p2 + 3 * p1 + ex2;
    double r3 = p3 + 3 * p2 + ex3;

    nex[a][b][c] = max(max(r1,r2),r3);
    cout << a << "," << b << "," << c << " = " << p1 << " " << p2 << " " << p3 << " " << nex[a][b][c] << endl;
    return nex[a][b][c];
}

class RockPaperScissors 
{
public:
    double bestScore(vector <int> rockProb, vector <int> paperProb, vector <int> scissorsProb) 
    {
        for(int i=0;i<55;i++) {
            combi[i][0] = combi[i][i] = 1;
            for(int j=1;j<i;j++) {
                combi[i][j] = combi[i-1][j-1] + combi[i-1][j];
            }
        }

        memset(pp, 0, sizeof(pp));
        pp[0][0][0] = 1.0;

        N = 0;
        for(int i=0;i<size(rockProb);i++) {
            N++;
            addone((double)rockProb[i]/300.0, (double)paperProb[i] / 300.0, (double)scissorsProb[i] / 300.0);
        }
        cout << pp[0][0][0] << endl;
        cout << pp[1][0][0] << " " << pp[0][1][0] << " " << pp[0][0][1] << endl;
        cout << pp[2][0][0] << " : " << pp[3][0][0] << " " << pp[2][1][0] << " " << pp[2][0][1] << endl;

        for(int i=0;i<55;i++) for(int j=0;j<55;j++) for(int k=0;k<55;k++) nex[i][j][k] = -1.0;

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
    ___test.run_test(2); 
} 
// END CUT HERE
