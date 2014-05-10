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

set<int> vv[22][22];
vector<int> primes;

void ryze(int a, set<int> &ret) {
    ret.clear();
    for(int i=0;i<size(primes);i++) {
        int cnt = 0;
        while((a % primes[i]) == 0) {
            a /= primes[i];
            cnt++;
        }
        if(cnt&1) {
            ret.insert(primes[i]);
        }
    }
    if(a) ret.insert(a);
}

void xxor(set<int> &a, const set<int> &b) {
    for(int it : b) {
        auto jt = a.find(it);
        if(jt != a.end()) a.erase(jt); else a.insert(it);
    }
}

class PerfectSquare 
{
public:
    int ways(vector <int> x) 
    {
        int n;
        for(n=1;n*n < size(x);n++);

        primes.pb(2);
        for(int i=3;i<100005;i+=2) {
            bool divi = false;
            for(int j=0;j<size(primes);j++) {
                if(primes[j] * primes[j] > i) break;
                if((i % primes[j]) == 0) {
                    divi = true; break;
                }
            }
            if(!divi) primes.pb(i);
        }

        for(int i=0;i<size(x);i++) {
            ryze(x[i], vv[i/n][i%n]);
        }

        set<int> base;
        for(int i=0;i<n;i++) {
            xxor(base, vv[i][i]);
        }

        vector<set<int> > vc;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                for(int k=i+1;k<n;k++) {
                    for(int l=j+1;l<n;l++) {
                        set<int> tmp = vv[i][j];
                        xxor(tmp, vv[k][j]);
                        xxor(tmp, vv[i][l]);
                        xxor(tmp, vv[k][l]);
                        vc.pb(tmp);
                    }
                }
            }
        }

        for(auto it : base) {
            cout << it << " ";
        }
        cout << endl;

        for(int i=0;i<size(vc);i++) {
            for(auto it : vc[i]) {
                cout << it << " ";
            }
            cout << endl;
        }

        return 0;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 1,
 1, 2}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, ways(Arg0)); }
	void test_case_1() { int Arr0[] = {620, 620,
 620, 620}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, ways(Arg0)); }
	void test_case_2() { int Arr0[] = {1, 2, 3,
 4, 5, 6,
 7, 8, 9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, ways(Arg0)); }
	void test_case_3() { int Arr0[] = {2, 2, 2, 2, 2,
 2, 2, 2, 2, 2,
 2, 2, 2, 2, 2,
 2, 2, 2, 2, 2,
 2, 2, 2, 2, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(3, Arg1, ways(Arg0)); }
	void test_case_4() { int Arr0[] = {2, 3, 4, 5,
 6, 7, 8, 9,
 10,11,12,13,
 14,15,16,17}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(4, Arg1, ways(Arg0)); }
	void test_case_5() { int Arr0[] = {9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,
 9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,
 9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,
 9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,
 9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,
 9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,
 9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,
 9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,
 9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,
 9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690,9699690}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 993282280; verify_case(5, Arg1, ways(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    PerfectSquare ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
