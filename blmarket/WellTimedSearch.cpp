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

int firstN = -1;

long double go(int N, int A, int B) {
    if(N == 0) return 0;
    long double px = 1.0 / N;
    if(B == 1) return px;
    if(A == 1) {
        long double p1 = (long double)(N / 2) / N;
        if(N % 2 == 1) {
            return px + 2 * p1 * go(N/2, 1, B-1);
        } else {
            long double p2 = (long double)(N-N/2-1) / N;
            return px + p1 * go(N/2, 1, B-1) + p2 * go(N-1-N/2, 1, B-1);
        }
    }

    double prob = 1.0;
    while(true) {
        int tmp = 1;
        bool onemore = false;
        double prob = 1 - px;
        for(int i=0;i<A-1;i++) {
            tmp *= 2;
            if(tmp >= N) {
                prob = prob * (N-1) / N;
                cerr << prob << endl;
                N--; A--; B--;
                onemore = true;
                break;
            }
        }
        if(!onemore) break;
    }
    cout << prob << endl;
    if(prob < 1.0) return prob * go(N, A, B);

    long double ret = 0;
    int md = 0;
    for(int i=0;i<=(N/2);i++) {
        long double p1 = (long double)i / N;
        long double p2 = (long double)(N-1-i) / N;
        long double tmp = p1 * go(i, A-1, B-1) + p2 * go(N-1-i, A-1, B-1);
        if(N == firstN) cout << N << " " << A << " " << B << " = " << tmp << "(" << i << ")" << endl;
        if(ret < tmp) { 
            ret = tmp;
            md = i;
        } else break;
    }
    if(N == firstN) cout << N << " " << A << " " << B << " = " << ret << "(" << md << ")" << endl;
    return prob * ret;
}

class WellTimedSearch 
{
public:
    long double getProbability(int N, int A, int B) 
    {
        firstN = N;
        return go(N, A, B);
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long double &Expected, const long double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 2; long double Arg3 = 0.6666666666666666; verify_case(0, Arg3, getProbability(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 3; long double Arg3 = 0.3333333333333333; verify_case(1, Arg3, getProbability(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 123456; int Arg1 = 1; int Arg2 = 20; long double Arg3 = 1.0; verify_case(2, Arg3, getProbability(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 5; int Arg1 = 3; int Arg2 = 4; long double Arg3 = 0.6; verify_case(3, Arg3, getProbability(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    WellTimedSearch ___test; 
    ___test.run_test(1); 
} 
// END CUT HERE
