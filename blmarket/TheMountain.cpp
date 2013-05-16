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

int base[202][202];
int data[202][202];
bool check[202][202];
int N,M;

int A,B;

void setmax(int &a, int b) {
    if(a == -1) return;
    if(b == -1 || a < b) a=b;
}

int fill(int a, int b) {
    if(a < 0 || a >= N || b < 0 || b >= M) return 0;

    if(check[a][b]) return data[a][b];
    check[a][b] = true;

    int ret = 0;
    if(a <= A) setmax(ret, fill(a-1,b));
    if(a >= A) setmax(ret, fill(a+1,b));
    if(b <= B) setmax(ret, fill(a,b-1));
    if(b >= B) setmax(ret, fill(a,b+1));

    if(ret == -1) return -1;

    ret++;
    if(data[a][b] == -1) return data[a][b] = ret;

    if(data[a][b] < ret) return -1;

    return data[a][b];
}

int go(int a, int b) {
    A = a; B = b;
    memcpy(data, base, sizeof(data));

    if(fill(a,b) == -1) return -1;

    /*
    cout << a << "," << b << " = " << endl;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) cout << data[i][j] << " ";
        cout << endl;
    }
    cout << endl;
    */

    int ret = 0;
    for(int i=0;i<N;i++) for(int j=0;j<M;j++) ret += data[i][j];
    return ret;
}

void clean(int a, int b) {
    for(int i=0;i<N;i++) for(int j=0;j<M;j++) if(abs(i-a) < 2 || abs(j-b) < 2) {
        check[i][j] = false;
    }
}

class TheMountain 
{
public:
    int minSum(int n, int m, vector <int> rowIndex, vector <int> columnIndex, vector <int> element) 
    {		
        memset(base, -1, sizeof(base));
        for(int i=0;i<size(rowIndex);i++) {
            base[rowIndex[i]][columnIndex[i]] = element[i];
        }

        N = n; M = m;
        memset(check, 0, sizeof(check));

        int ret = -1;
        for(int i=0;i<N;i++) { 
            for(int j=0;j<M;j++) {
                clean(i,j);
                int tmp = go(i,j);
                if(tmp == -1) continue;
                if(ret == -1 || ret > tmp) ret = tmp;
            }
        }
        return ret;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 3; int Arr2[] = {0, 0, 0, 1, 1, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0, 1, 2, 0, 1, 2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {4, 6, 9, 1, 3, 6}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 29; verify_case(0, Arg5, minSum(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 3; int Arr2[] = {1, 0, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2, 2, 0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {5, 7, 6}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 40; verify_case(1, Arg5, minSum(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 3; int Arr2[] = {0, 0, 2, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0, 2, 2, 0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {1, 1, 1, 1}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 15; verify_case(2, Arg5, minSum(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 2; int Arg1 = 2; int Arr2[] = {0, 0, 1, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0, 1, 1, 0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {5, 8, 5, 8}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = -1; verify_case(3, Arg5, minSum(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 1; int Arg1 = 3; int Arr2[] = {0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {1}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = -1; verify_case(4, Arg5, minSum(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_5() { int Arg0 = 123; int Arg1 = 45; int Arr2[] = {2, 3, 5, 7, 11}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {13, 17, 19, 23, 29}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {100, 200, 300, 400, 500}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 367047; verify_case(5, Arg5, minSum(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_6() { int Arg0 = 200; int Arg1 = 200; int Arr2[] = {5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {8}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {666}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 5737554; verify_case(6, Arg5, minSum(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_7() { int Arg0 = 10; int Arg1 = 10; int Arr2[] = {0, 8, 7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {3, 1, 9}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {5, 4, 7}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 593; verify_case(7, Arg5, minSum(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    TheMountain ___test; 
    ___test.run_test(6); 
} 
// END CUT HERE
