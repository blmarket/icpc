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

const LL mod = 1000000007LL;
int pow2[2000];

LL small(int X, int Y) {
    if(X>Y) swap(X,Y);
    if(X == 1) {
        if(Y == 1) return 1;
        return pow2[Y-2];
    }

    LL ret = 0;

    for(int a=0;a<2;a++) for(int b=0;b<2;b++) for(int c=0;c<2;c++) for(int d=0;d<2;d++) {
        bool hasu = a || b;
        bool hasl = a || c;
        bool hasr = b || d;
        bool hasd = c || d;
        LL cntu = pow2[Y-2] - !hasu;
        LL cntl = pow2[X-2] - !hasl;
        LL cntr = pow2[X-2] - !hasr;
        LL cntd = pow2[Y-2] - !hasd;

        LL t1 = (cntu * cntl) % mod;
        LL t2 = (cntr * cntd) % mod;
        ret += (t1*t2);
        ret %= mod;
    }
    LL inner = pow2[(X-2)*(Y-2)];
    ret = ((ret * inner) % mod);
    if(ret < 0) ret += mod;
    return ret;
}

LL thin(int X, int Y, int sy) {
    if(Y <= sy * 2) {
        return small(X,Y);
    }
    return small(X, 2*sy);
}

LL diagonal(int X, int Y, int sx, int sy) {
    LL ret = 0;
    for(int a=0;a<2;a++) for(int b=0;b<2;b++) {
        LL cnt1 = ((pow2[sy-1] - !a) * (pow2[sx-1] - !a)) % mod;
        LL cnt2 = ((pow2[sy-1] - !b) * (pow2[sx-1] - !b)) % mod;
        ret += (cnt1 * cnt2);
        ret %= mod;
    }
    int intersec = 0;
    if(X < 2*sx && Y < 2 * sy) {
        intersec = (2*sx - X) * (2*sy-Y);
    }
    cout << 2*(sx-1)*(sy-1)-intersec << endl;
    LL inner = pow2[2*(sx-1)*(sy-1) - intersec];
    ret = (ret * inner) % mod;
    if(ret < 0) ret += mod;
    return ret;
}

LL cross(int X, int Y, int sx, int sy) {
    if(X >= 2*sx || Y >= 2*sy) return 0;
    LL cnt1 = sqr(pow2[2*sx-X]-1) % mod;
    LL cnt2 = sqr(pow2[2*sy-Y]-1) % mod;
    LL inner = pow2[(X-2) * (Y-2) - 4 * (X-1-sx) * (Y-1-sy)];
    LL ret = (cnt1 * cnt2) % mod;
    ret = (ret * inner) % mod;
    if(ret < 0) ret += mod;
    return ret;
}

LL cnt(int X,int Y,int sx,int sy) {
    if(X <= sx && Y <= sy) {
        return small(X,Y);
    }
    if(X <= sx) {
        return thin(X, Y, sy);
    }
    if(Y <= sy) {
        return thin(Y, X, sx);
    }
    LL ret = (2 * diagonal(X,Y,sx,sy) - cross(X,Y,sx,sy)) % mod;
    if(ret < 0) ret += mod;
    return ret;
}

class LitPanels 
{
public:
    int countPatterns(int X, int Y, int sx, int sy) 
    {
        pow2[0] = 1;
        for(int i=1;i<2000;i++) {
            pow2[i] = (pow2[i-1] * 2) % mod;
        }
        LL ret = 0;
        for(int i=1;i<=X;i++) {
            for(int j=1;j<=Y;j++) {
                LL tmp = cnt(i,j,sx,sy);
                tmp *= (X-i+1);
                tmp %= mod;
                tmp *= (Y-j+1);
                tmp %= mod;

                ret += tmp;
                ret %= mod;
                //cout << i << " " << j << " = " << tmp << " " << (X-i+1) * (Y-j+1) << " " << tmp * (X-i+1) * (Y-j+1) << " " << ret << endl;
            }
        }
        return (ret + 1) % mod;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 1; int Arg3 = 1; int Arg4 = 11; verify_case(0, Arg4, countPatterns(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 3; int Arg2 = 1; int Arg3 = 2; int Arg4 = 40; verify_case(1, Arg4, countPatterns(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 4; int Arg2 = 3; int Arg3 = 2; int Arg4 = 14096; verify_case(2, Arg4, countPatterns(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 40; int Arg1 = 39; int Arg2 = 5; int Arg3 = 8; int Arg4 = 877713074; verify_case(3, Arg4, countPatterns(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    LitPanels ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
