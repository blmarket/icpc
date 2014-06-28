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

/**
Problem: 500
Test Case: 76
Succeeded: No
Execution Time: 0 ms
Peak memory used: 11.613MB
Args:
{{-72, -8}, {36, 18, 12, 30, 30}, 49}

Expected:
{-9}

Received:
{}

Answer checking result:
Returned value must exactly match the expected one.
 *
 */

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;

template<typename T> int size(const T &a) { return a.size(); }

long long mod1 = 100000007;
long long mod2 = 104395301;
long long mod3 = 104395303;

vector<int> a;
bool go(int t, long long M) {
    long long sum = 0;
    long long now = 1;
    for(int i=0;i<size(a);i++) {
        sum = sum + (now * a[i]);
        sum %= M;
        now = (now * t) % M;
    }
    return sum == 0;
}

bool chk(int t) {
    return go(t, mod1) && go(t, mod2) && go(t, mod3);
}

class SolvePolynomial 
{
public:
    vector <int> integerRoots(vector <int> X, vector <int> Y, int n) 
    {
        a.resize(n+1);
        for(int i=0;i<=n;i++) {
            int p = (i % size(X));
            int q = (i + Y[i % size(Y)]) % size(X);
            a[i] = X[p];
            X[p] = X[q];
            X[q] = a[i];
        }

        set<int> ret;
        while(a[0] == 0) {
            ret.insert(0);
            a.erase(a.begin(), a.begin()+1);
        }

        for(int i=0;i<size(a);i++) cout << a[i] << " ";
        cout << endl;

        int aa = abs(a[0]);
        for(int i=1;i*i <= aa;i++) {
            if( (a[0] % i) != 0) continue;
            bool tmp = chk(i);
            if(tmp) ret.insert(i);
            tmp = chk(-i);
            if(tmp) ret.insert(-i);
            if(chk(a[0] / i)) ret.insert(a[0]/i);
            if(chk(-a[0]/i)) ret.insert(-a[0]/i);
        }
        if(chk(a[0])) ret.insert(a[0]);
        if(chk(-a[0])) ret.insert(-a[0]);

        return vector<int>(ret.begin(), ret.end());
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {-4, 2, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arr3[] = {-2, 1 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(0, Arg3, integerRoots(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {1, 2, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 0, 0, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arr3[] = {-1 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(1, Arg3, integerRoots(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {1, 4, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arr3[] = { }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(2, Arg3, integerRoots(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {-15, -10, 2, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arr3[] = {3 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(3, Arg3, integerRoots(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {735134400, 1383, 4121, 18875, 10463, 
 13512, 19603, 28679, 13483, 9509, 1701,
 13383, 24425, 7923, 7978, 21702, 30989,
 20676, 18547, 28130, 10944}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {34,23,6,5,3,5,4,34,37,5,6,21,17,9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10000; int Arr3[] = { }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(4, Arg3, integerRoots(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    SolvePolynomial ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
