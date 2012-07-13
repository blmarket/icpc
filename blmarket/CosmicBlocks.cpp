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

vector<int> b;
int n;

vector<LL> flow[70][70];

void fillflow(int a,int s)
{
    cout << a << " " << s << endl;
    flow[a][s].clear();
    vector<int> tmp;
    for(int i=0;i<(1<<n);i++) {
        if((s&i) == i) {
            tmp.pb(i);
        }
    }
    int pp = 1;
    int cnt = 0;
    for(int i=0;i<n;i++) if(a & (1<<i)) pp *= size(tmp), cnt++;

    for(int i=0;i<pp;i++) {
        int tmp2 = i;
        LL tmp4 = 0;
        for(int j=n-1;j>=0;j--) if(a & (1<<j)) {
            tmp4 <<= 6;
            int tmp3 = (tmp2 % size(tmp));
            tmp4 |= tmp[tmp3];
        }
        flow[a][s].pb(tmp4);
    }
    cout << size(flow[a][s]) << endl;
}

class CosmicBlocks 
{
public:
    int getNumOrders(vector <int> blockTypes, int minWays, int maxWays) 
    {		
        b = blockTypes;
        n = size(b);
        for(int i=1;i<(1<<n);i++) for(int j=1;j<(1<<n);j++) if((i & j) == 0) {
            fillflow(i,j);
        }
        return 0;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2,2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 1; int Arg3 = 6; verify_case(0, Arg3, getNumOrders(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {1,1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 720; int Arg2 = 720; int Arg3 = 1; verify_case(1, Arg3, getNumOrders(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2; int Arg3 = 3; verify_case(2, Arg3, getNumOrders(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2; int Arg3 = 2; verify_case(3, Arg3, getNumOrders(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 1; int Arg3 = 1; verify_case(4, Arg3, getNumOrders(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arr0[] = {1,2,4,8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 30; int Arg3 = 27; verify_case(5, Arg3, getNumOrders(Arg0, Arg1, Arg2)); }
	void test_case_6() { int Arr0[] = {1,2,3,4,5,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 720; int Arg3 = 4445; verify_case(6, Arg3, getNumOrders(Arg0, Arg1, Arg2)); }
	void test_case_7() { int Arr0[] = {7500,1000,7500,1000,7500}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; int Arg2 = 88; int Arg3 = 448; verify_case(7, Arg3, getNumOrders(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    CosmicBlocks ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
