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

const int dx[] = {-1,0,0,1};
const int dy[] = {0,-1,1,0};
const long long mod = 1000000007LL;

vector<int> x,y;
int n,m;

int pari(int a, int b) {
    int ret = (a+b) % 2;
    ret = (ret+2)%2;
    return ret;
}

int gather(int a, int b) {
    for(int i=0;i<n;i++) {
        int dx = abs(a - x[i]) + abs(b - y[i]);
        int elasp = m - dx;
        cout << elasp << " ";
    }
    cout << endl;
    return 1;
}

class WolfPack 
{
public:
    int calc(vector <int> x_, vector <int> y_, int m_) 
    {
        x=x_; y=y_; m=m_; n = size(x);

        int parity = (x[0] + y[0]) % 2;
        parity = (parity + 2) % 2;
        for(int i=1;i<size(x);i++) {
            if(pari(x[i], y[i]) != parity) return 0;
        }

        int stx = (x[0] - m + y[0]);
        int sty = (x[0] - m - y[0]);
        int sex = stx + m * 2;
        int sey = sty + m * 2;

        for(int i=1;i<n;i++) {
            int tx = (x[i] - m + y[i]);
            int ty = (x[i] - m - y[i]);
            int ex = tx + m * 2;
            int ey = ty + m * 2;

            if(stx > tx) {
                swap(stx, tx);
                swap(sex, ex);
            }

            if(sty > ty) {
                swap(sty, ty);
                swap(sex, ey);
            }

            if(sex < tx) return 0;
            if(sex < ty) return 0;
            stx = tx;
            sex = min(sex, ex);
            sty = ty;
            sey = min(sey, ey);
        }

        long long ret = 0;
        for(int i=stx;i<=sex;i+=2) {
            for(int j=sty;j<=sey;j+=2) {
                ret += gather((i+j)/2, (i-j)/2);
                ret %= mod;
            }
        }

        return ret;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 1; verify_case(0, Arg3, calc(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 0; verify_case(1, Arg3, calc(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {0,2,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 4; verify_case(2, Arg3, calc(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {7,8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {8,7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 2; verify_case(3, Arg3, calc(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {-2,-2,-2,0,0,0,2,2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-2,0,2,-2,0,2,-2,0,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1000; int Arg3 = 387540818; verify_case(4, Arg3, calc(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    WolfPack ___test; 
    ___test.run_test(4); 
} 
// END CUT HERE
