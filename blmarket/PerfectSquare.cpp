#include <iostream>
#include <queue>
#include <set>
#include <sstream>
#include <algorithm>
#include <map>
#include <vector>

#define mp make_pair
#define pb push_back
#define eb emplace_back
#define sqr(x) ((x)*(x))
#define foreach(it,c) for(typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;

template<typename T> int size(const T &a) { return a.size(); }

int xx[22][22];
VI primes;

void xxor(set<int> &a, set<int> b) {
    for(auto it : b) {
        auto jt = a.find(it);
        if(jt == a.end()) {
            a.insert(it);
        } else {
            a.erase(jt);
        }
    }
}

set<int> ryze(int a) {
    set<int> ret;
    for(int i=0;i<size(primes);i++) {
        int cnt = 0;
        while((a % primes[i]) == 0) {
            cnt++;
            a /= primes[i];
        }
        if(cnt&1) ret.insert(primes[i]);
    }
    if(a > 1) ret.insert(a);
    return ret;
}

class PerfectSquare 
{
public:
    int ways(vector <int> x) 
    {		
        int n;
        for(n=1;n*n < size(x);n++);
        for(int i=0;i<size(x);i++) xx[i/n][i%n] = x[i];

        primes.clear();
        primes.pb(2);
        for(int i=3;i<100000;i+=2) {
            bool fail = false;
            for(int j=0;j<size(primes);j++) {
                if(primes[j]*primes[j] > i) break;
                if(i % primes[j] == 0) { fail = true; break; }
            }
            if(!fail) primes.pb(i);
        }

        set<int> diag;
        for(int i=0;i<n;i++) {
            auto tmp = ryze(xx[i][i]);
            xxor(diag, tmp);
        }

        vector<set<int> > vs;
        for(int i=0;i+1<n;i++) {
            for(int j=0;j+1<n;j++) {
                auto t1 = ryze(xx[i][j]);
                auto t2 = ryze(xx[i][j+1]);
                auto t3 = ryze(xx[i+1][j]);
                auto t4 = ryze(xx[i+1][j+1]);
                xxor(t1, t2);
                xxor(t1, t3);
                xxor(t1, t4);
                vs.eb(t1);
            }
        }

        int c0 = 0;
        for(int i=0;i<size(vs);i++) {
            if(vs[i].size() == 0) {
                c0++;
            } else {
                int fs = *(vs[i].begin());
                for(int j=i+1;j<size(vs);j++) {
                    if(vs[j].count(fs)) {
                        xxor(vs[j], vs[i]);
                    }
                }
                if(diag.count(fs)) xxor(diag, vs[i]);
            }
        }
        if(diag.size()) return 0;
        long long ret = 1;
        for(int i=0;i<c0;i++) {
            ret = (ret * 2) % 1000000007LL;
        }
        return ret;
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
