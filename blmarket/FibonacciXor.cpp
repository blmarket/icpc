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

long long fbs[100];

void print(long long a) {
    for(int i=79;i>=0;i--) {
        if(fbs[i] <= a) {
            cout << 1;
            a -= fbs[i];
        } else {
            cout << 0;
        }
    }
}

map<long long, long long> memo;

long long F(long long x) {
    if(x == 1) return 1;
    if(x == 2) return 2;
    if(x == 3) return 4;

    if(memo.count(x)) return memo[x];

    int pos = lower_bound(fbs, fbs + 79, x) - fbs;

    cout << x << " " << pos << endl;
    if(fbs[pos] == x) {
        long long ret = 0;
        int tt = fbs[pos-2];
        if(tt & 1) {
            ret = (1LL << (pos-1));
        }

        ret ^= F(fbs[pos-1]) ^ F(fbs[pos-2]);
        return memo[x] = ret;
    } else {
        int cnt = (x - fbs[pos]);
        long long ret = 0;
        if(cnt & 1) {
            ret = (1LL << pos);
        }
        ret ^= F(fbs[pos]) ^ F(x - fbs[pos]);
        return memo[x] = ret;
    }
}

class FibonacciXor 
{
public:
    int find(long long A, long long B) 
    {		
        fbs[0] = 1;
        fbs[1] = 2;
        for(int i=2;i<80;i++) {
            fbs[i] = fbs[i-2] + fbs[i-1];
        }

        long long tmp = F(B+1) ^ F(A+1);
        return (tmp % 1000000007);
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 1LL; long long Arg1 = 2LL; int Arg2 = 3; verify_case(0, Arg2, find(Arg0, Arg1)); }
	void test_case_1() { long long Arg0 = 3LL; long long Arg1 = 10LL; int Arg2 = 25; verify_case(1, Arg2, find(Arg0, Arg1)); }
	void test_case_2() { long long Arg0 = 1LL; long long Arg1 = 1000000000000000LL; int Arg2 = 780431495; verify_case(2, Arg2, find(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    FibonacciXor ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
