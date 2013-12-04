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

vector<int> primes;

class BigFatInteger 
{
public:
    int minOperations(int A, int B) 
    {
        VI qs;
        for(int i=2;i*i <= A;i++) {
            bool fail = false;
            for(int j=0;j<size(primes);j++) {
                if((i%primes[j]) == 0) {
                    fail = true;
                    break;
                }
            }
            if(fail) continue;
            primes.pb(i);
            int cnt = 0;
            while((A%i) == 0) {
                cnt++;
                A /= i;
            }
            if(cnt == 0) continue;
            qs.pb(cnt);
        }
        if(A != 0) qs.pb(1);
        sort(qs.rbegin(), qs.rend());

        int cc = qs[0] - 1;
        int ret = 1;
        int cut = 1;
        while(cc) {
            if(cc >= cut) {
                cc -= cut;
                cut *= 2;
                ret++;
            } else {
                return ret + 1;
            }
        }
        return ret;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 6; int Arg1 = 1; int Arg2 = 2; verify_case(0, Arg2, minOperations(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 162; int Arg1 = 1; int Arg2 = 4; verify_case(1, Arg2, minOperations(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 999983; int Arg1 = 9; int Arg2 = 5; verify_case(2, Arg2, minOperations(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 360; int Arg1 = 8; int Arg2 = 8; verify_case(3, Arg2, minOperations(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    BigFatInteger ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
