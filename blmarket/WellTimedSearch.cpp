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

class WellTimedSearch 
{
public:
    double calc(int N, int A, int B, int pos) {
        double ret = (A==1 ? 1.0/N : 0);

        double leftprob = (double)pos / N;
        double rightprob = (double)(N-1-pos) / N;

        double lres = getProbability(pos, max(1,A-1), B-1);
        double rres = getProbability(N-1-pos, max(1,A-1), B-1);

        ret += leftprob * lres + rightprob * rres;
        return ret;
    }

    double getProbability(int N, int A, int B) 
    {
        if(N == 0) return 1.0;
        if(B == 0) return 0;
        if(N == 1) {
            if(A == 1) return 1.0;
            return 0.0;
        }
        if(N == 2) {
            if(A == 2 || B == 1) return 0.5;
            return 1.0;
        }

        cout << N << " " << A << B << endl;
        if(A == 1) {
            return (1.0 / N) + getProbability(N/2, 1, B-1) * (N-1) / N;
        }

        double best = getProbability(N-1, A-1, B-1) * (N-1) / N;
        int s=1,e=(N+1)/2+1;
        while(e-s > 1) {
            int m1 = (s*2+e) / 3;
            int m2 = (s+e*2) / 3;

            double b1,b2;
            b1 = calc(N,A,B,m1);
            b2 = calc(N,A,B,m2);
            best = max(best, max(b1,b2));
            if(b1 < b2) {
                s = m1;
            } else {
                e = m2;
            }
        }

        return best;
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
