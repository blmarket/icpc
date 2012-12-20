#include <iostream>
#include <queue>
#include <cstring>
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
int nums[1000005];
int cnts[1000005];
int ltr[1000005];
int n;

map<int, int> M;

class TheDivisionGame 
{
public:
    long long countWinningIntervals(int L, int R) 
    {
        primes.clear();
        primes.pb(2);
        for(int i=3;i<40000;i+=2) {
            bool fail = false;
            for(int j=0;j<size(primes);j++) {
                if(primes[j] * primes[j] > i) break;
                if((i % primes[j]) == 0) { fail=true; break; }
            }
            if(!fail) primes.pb(i);
        }
        cout << size(primes) << endl;
        
        for(int i=L;i<=R;i++) {
            nums[i-L] = i;
        }
        n = R-L+1;

        memset(cnts, 0, sizeof(cnts));
        for(int i=0;i<size(primes);i++) {
            long long p = primes[i];

            while(true) {
                long long s = -(L % p); if(s<0) s+=p;
                if(s > n) break;
                for(int j=s;j<=n;j+=p) {
                    nums[j] /= primes[i];
                    cnts[j]++;
                }
                p *= primes[i];
            }
        }

        for(int i=0;i<n;i++) if(nums[i] > 1) cnts[i]++;

        for(int i=0;i<n;i++) {
            cout << cnts[i] << " ";
        }
        cout << endl;

        memset(cnts, 0, sizeof(cnts));
        for(int i=0;i<n;i++) {
            if((i % 10000) == 0) cout << i << " " << nums[i] << endl;
            cnts[i] = 0;
            for(int j=0;j<size(primes);j++) {
                while((nums[i] % primes[j]) == 0) {
                    nums[i] /= primes[j];
                    cnts[i]++;
                }
            }
            if(nums[i] > 1) cnts[i]++;
        }

        for(int i=0;i<n;i++) {
            cout << cnts[i] << " ";
        }
        cout << endl;

        M.clear();
        ltr[0] = 0;
        M[0] = 1;
        for(int i=1;i<=n;i++) {
            ltr[i] = ltr[i-1] ^ cnts[i-1];
            M[ltr[i]] += 1;
        }

        long long losecount = 0;
        foreach(it, M) {
            losecount += ((long long)it->second * (it->second - 1)) / 2;
        }
        long long totalcount = (long long)n * (n+1) / 2;

        cout << totalcount << " " << losecount << endl;

        return totalcount - losecount;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 9; int Arg1 = 10; long long Arg2 = 2LL; verify_case(0, Arg2, countWinningIntervals(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 5; long long Arg2 = 9LL; verify_case(1, Arg2, countWinningIntervals(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 6; long long Arg2 = 13LL; verify_case(2, Arg2, countWinningIntervals(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 2; int Arg1 = 100; long long Arg2 = 4345LL; verify_case(3, Arg2, countWinningIntervals(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 12566125; int Arg1 = 12567777; long long Arg2 = 1313432LL; verify_case(4, Arg2, countWinningIntervals(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    TheDivisionGame ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
