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

int go(int a, int b) {
    cerr << a << " " << b << endl;
    if(b == 1) {
        if(a == 1) return 0;
        return -1;
    }
    if(a == 1) {
        return b-1;
    }
    int p = (a+1) / 2;
    int tmp = go(p, b-1);
    if(tmp == -1) return -1;
    return p + tmp;
}

class WellTimedSearch 
{
public:
    double getProbability(int N, int A, int B) 
    {
        cerr << go(300, 7) << endl;
        return 0;
        int maxx = 0;
        for(int i=1;i<=N;i++) {
            int t1 = go(i, A);
            if(t1 == -1) break;
            int cur = i;
            int sum = i;
            for(int j=A;j<B;j++) {
                cur *= 2;
                sum += cur;
                if(sum + t1 >= N) {
                    sum = N - t1;
                    break;
                }
            }
            if(sum + t1 >= N) sum = N - t1;
            cerr << i << " " << sum << endl;
            if(sum > maxx) maxx = sum;
        }
        return (double)maxx / N;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 2; double Arg3 = 0.6666666666666666; verify_case(0, Arg3, getProbability(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 3; double Arg3 = 0.3333333333333333; verify_case(1, Arg3, getProbability(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 123456; int Arg1 = 1; int Arg2 = 20; double Arg3 = 1.0; verify_case(2, Arg3, getProbability(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 5; int Arg1 = 3; int Arg2 = 4; double Arg3 = 0.6; verify_case(3, Arg3, getProbability(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    WellTimedSearch ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
