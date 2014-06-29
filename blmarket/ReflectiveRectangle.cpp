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
typedef long long LL;

template<typename T> int size(const T &a) { return a.size(); }

long long mod = 1e9+7;
long long inv6 = (mod+1) / 6;

long long sumsq(long long n) {
     long long ret = n * (n+1);
     ret %= mod; ret *= (n*2+1); ret %= mod; ret *= inv6; ret %= mod;
     return ret;
}

class ReflectiveRectangle 
{
public:
    int findSum(int sideA, int sideB, int bounces) 
    {
        if(bounces % 2) return 0;
        long long n = bounces + 2;

        long long cur = 0;

        vector<int> fs;
        for(int i=2;i*i <= n;i ++) {
            if((n%i) == 0) {
                fs.pb(i);
                n /= i;
            }
            while((n%i) == 0) n /= i;
        }
        if(n > 1) fs.pb(n);

        n = bounces + 2;

        for(auto it : fs) cout << it << " ";
        cout << endl;

        int sz = size(fs);
        for(int i=0;i<(1LL<<sz);i++) {
            int base = 1;
            int cnt = 1;
            for(int j=0;j<sz;j++) if(i & (1<<j)) {
                cnt = -cnt;
                base *= fs[j];
            }
            long long tmp = (sumsq(n/base) * (base*base) % mod) % mod;
            cur = (cur + tmp * cnt + mod) % mod;
            cout << base << " " << tmp << " " << cnt << " " << cur << endl;
        }
        long long tmp = (LL)sideA * sideA + (LL)sideB * sideB;
        cout << tmp << endl;
        tmp %= mod;
        return (cur * tmp) % mod;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 4; int Arg2 = 0; int Arg3 = 25; verify_case(0, Arg3, findSum(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 2; int Arg3 = 180; verify_case(1, Arg3, findSum(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 13; int Arg1 = 17; int Arg2 = 1; int Arg3 = 0; verify_case(2, Arg3, findSum(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 59325; int Arg1 = 31785; int Arg2 = 262142; int Arg3 = 48032850; verify_case(3, Arg3, findSum(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 1000000; int Arg1 = 1000000; int Arg2 = 1000000000; int Arg3 = 145972110; verify_case(4, Arg3, findSum(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    ReflectiveRectangle ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
