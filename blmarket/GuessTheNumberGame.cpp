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

class GuessTheNumberGame 
{
public:
    int possibleClues(int n) 
    {		
				primes.pb(2);
				for(int i=3;i<=n;i+=2) {
						bool fail = false;
						for(int j=0;j<size(primes);j++) {
								if(primes[j] * primes[j] > i) break;
								if(i % (primes[j]) == 0) {
										fail=true; break;
								}
						}
						if(!fail) primes.pb(i);
				}

				long long ret = 1;
				for(int i=0;i<size(primes);i++) {
						int cnt = 1;
						int tmp = n;
						while(tmp > primes[i]) {
								cnt++; tmp /= primes[i];
						}
						ret *= cnt;
						ret %= 1000000007LL;
				}
				return ret;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 12; verify_case(0, Arg1, possibleClues(Arg0)); }
	void test_case_1() { int Arg0 = 16; int Arg1 = 240; verify_case(1, Arg1, possibleClues(Arg0)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 1; verify_case(2, Arg1, possibleClues(Arg0)); }
	void test_case_3() { int Arg0 = 1000000; int Arg1 = 677298706; verify_case(3, Arg1, possibleClues(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    GuessTheNumberGame ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
