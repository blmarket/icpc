#include <iostream>
#include <cstring>
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

set<vector<int> > S;
int cur[20];
int n,m;

void go(int a,int b)
{
    cout << a << " " << b << endl;

    if(a >= n)
    {
        vector<int> V(cur, cur+n);
        sort(V.rbegin(), V.rend());
        if(V[0] == m)
            S.insert(V);
        return;
    }
    if(b >= n) 
    {
        return go(a+1,a+2);
    }
    if(a >= b) return go(a,b+1);

    cur[a] += 2;
    go(a,b+1);
    cur[a]--;
    cur[b]++;
    go(a,b+1);
    cur[a]--;
    cur[b]++;
    go(a,b+1);
    cur[b]-=2;
}

class TheBasketballDivOne 
{
public:
    int find(int n_, int m_) 
    {		
        n = n_; m = m_;
        memset(cur, 0, sizeof(cur));
        go(0,0);
        cout << "hello?" << endl;
        return S.size();
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 1; int Arg2 = 1; verify_case(0, Arg2, find(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 0; verify_case(1, Arg2, find(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 2; verify_case(2, Arg2, find(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 6; int Arg2 = 5; verify_case(3, Arg2, find(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    TheBasketballDivOne ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
