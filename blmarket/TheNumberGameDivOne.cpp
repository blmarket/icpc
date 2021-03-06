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

class TheNumberGameDivOne 
{
public:
    string find(long long n) 
    {		
        primes.clear();
        primes.pb(2);
        for(int i=3;i<=100000;i+=2) {
            bool fail = false;
            for(int j=0;j<size(primes);j++) {
                if(primes[j] * primes[j] > i) break;
                if((i % primes[j]) == 0) {
                    fail = true;
                    break;
                }
            }
            if(!fail) {
                primes.pb(i);
            }
        }

        if(n % 2 == 1) {
            return "Brus";
        }

        int cnt = 0;
        while((n % 2) == 0){
            n /= 2;
            cnt++;
        }
        if(n != 1) return "John";
        if((cnt % 2) == 1) return "Brus";
        return "John";
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 6LL; string Arg1 = "John"; verify_case(0, Arg1, find(Arg0)); }
	void test_case_1() { long long Arg0 = 2LL; string Arg1 = "Brus"; verify_case(1, Arg1, find(Arg0)); }
	void test_case_2() { long long Arg0 = 747LL; string Arg1 = "Brus"; verify_case(2, Arg1, find(Arg0)); }
	void test_case_3() { long long Arg0 = 128LL; string Arg1 = "Brus"; verify_case(3, Arg1, find(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    TheNumberGameDivOne ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
