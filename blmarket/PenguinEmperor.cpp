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
const int mod = 1000000007LL;
const long long mod2 = (long long)mod * mod;

struct matrix {
    int a[351][351];

    matrix() { clear(); }
    void clear() { memset(a, 0, sizeof(a)); }
};

void matmulx(matrix &src, int move, matrix &dst) {
    dst.clear();
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            dst.a[i][(j + move) % N] += src.a[i][j];
            if(dst.a[i][(j + move) % N] >= mod) dst.a[i][(j + move) % N] -= mod;
            if(move * 2 == N) continue;
            dst.a[i][(j + N - move) % N] += src.a[i][j];
            if(dst.a[i][(j + N - move) % N] >= mod) dst.a[i][(j + N - move) % N] -= mod;
        }
    }
}

void build(matrix &mat, int a) {
    mat.clear();
    for(int i=0;i<N;i++) {
        mat.a[i][(i+a) % N] = 1;
        mat.a[i][(i-a+N) % N] = 1;
    }
}

matrix t1,t2,t3;

class PenguinEmperor 
{
public:
    int countJourneys(int numCities, long long daysPassed) 
    {		
        N = numCities;
        long long tmp = daysPassed % numCities;

        build(t1, 1);
        matrix *cur = &t1, *next = &t2, *buff = &t3;
        for(int i=2;i<=tmp;i++) {
            matmulx(*cur, i, *next);
            swap(next, cur);
        }
        return cur->a[0][0];
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; long long Arg1 = 2LL; int Arg2 = 2; verify_case(0, Arg2, countJourneys(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 4; long long Arg1 = 3LL; int Arg2 = 2; verify_case(1, Arg2, countJourneys(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 5; long long Arg1 = 36LL; int Arg2 = 107374182; verify_case(2, Arg2, countJourneys(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 300; long long Arg1 = 751LL; int Arg2 = 413521250; verify_case(3, Arg2, countJourneys(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 300; long long Arg1 = 750LL; int Arg2 = 0; verify_case(4, Arg2, countJourneys(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 350; long long Arg1 = 1000000000000000000LL; int Arg2 = 667009739; verify_case(5, Arg2, countJourneys(Arg0, Arg1)); }
	void test_case_6() { int Arg0 = 5; long long Arg1 = 7LL; int Arg2 = 12; verify_case(6, Arg2, countJourneys(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    PenguinEmperor ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
