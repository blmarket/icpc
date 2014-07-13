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

vector<int> links[1050];
vector<int> V;
bool trace[1050];

const int SIZE = 1024;
struct FenwickTree {
    int tree[SIZE];

    void add(int a, int cnt = 1) {
        for(;a<=SIZE;a+=(a&-a)) tree[a] += cnt;
    }

    int range(int e) {
        int ret = 0;
        for(;e>0;e-=(e&-e)) ret += tree[e];
        return ret;
    }
};

FenwickTree t;

int go(int a, int K) {
    if(trace[a]) return -1;
    if(K == 0) return 0;
    trace[a] = true;
    t.add(V[a]);
    int ret = -1;

    for(auto it : links[a]) {
        int tmp = go(it, K-1);
        if(tmp == -1) continue;
        tmp += t.range(SIZE) - t.range(V[it]);
        if(ret == -1 || ret > tmp) ret = tmp;
    }

    trace[a] = false;
    t.add(V[a], -1);
    cout << a << " " << K << " " << V[a] << " = " << ret << endl;
    return ret;
}

class GraphInversions 
{
public:
    int getMinimumInversions(vector <int> A, vector <int> B, vector <int> V_, int K) 
    {
        V = V_;
        for(int i=0;i<size(A);i++) {
            links[A[i]].pb(B[i]);
            links[B[i]].pb(A[i]);
        }

        return go(2, K-1);

        int ret = -1;
        for(int i=0;i<size(V);i++) {
            int tmp = go(i, K-1);
            if(tmp == -1) continue;
            if(ret == -1 || ret > tmp) ret = tmp;
        }
        return ret;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {40,50,60}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; int Arg4 = 0; verify_case(0, Arg4, getMinimumInversions(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {0,1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {60,40,50,30}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; int Arg4 = 1; verify_case(1, Arg4, getMinimumInversions(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {0,1,2,3,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,0,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10,10,10,5,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 5; int Arg4 = 1; verify_case(2, Arg4, getMinimumInversions(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {0,1,2,3,0,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,0,4,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10,2,5,3,7,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 6; int Arg4 = -1; verify_case(3, Arg4, getMinimumInversions(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arr0[] = {5,7,7,5,5,7,6,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,0,2,0,1,4,7,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {15,10,5,30,22,10,5,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 6; int Arg4 = 3; verify_case(4, Arg4, getMinimumInversions(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    GraphInversions ___test; 
    ___test.run_test(0); 
} 
// END CUT HERE
