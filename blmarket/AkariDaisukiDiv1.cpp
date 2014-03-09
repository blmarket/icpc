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

const int mod = 1000000007;

int pow2(int a) {
    long long ret = 1;
    int tt = 2;
    while(a) {
        if(a & 1) ret = (ret * tt) % mod;
        tt = (tt * 2) % mod;
        a /= 2;
    }
    return ret;
}

class AkariDaisukiDiv1 
{
public:
    int countF(string Waai, string Akari, string Daisuki, string S, string F, int k) 
    {
        auto build = [&](string x) -> string {
            return Waai + x + Akari + x + Daisuki;
        };

        auto cnt = [&](string x) -> int {
            int nn = size(x) - size(F) + 1;
            int ret = 0;
            for(int i=0;i<nn;i++) {
                if(x.substr(i, size(F)) == F) ret++;
            }
            return ret;
        };

        string c = S;
        while(size(c) < 1000 && k) {
            c = build(c);
            k--;
        }

        if(k == 0) {
            cout << c << endl;
            return cnt(c);
        }

        string bs = c.substr(0, 50);
        string es = c.substr(size(c) - 50);
        long long cc = cnt(c);

        int tmp;
        for(int i=0;i<55;i++) {
            cc = (cc * 2) % mod;

            string bbs = Waai + bs.substr(0, size(F) - 1);
            string m1 = es.substr(size(es) - size(F) + 1) + Akari;
            string m2 = Akari + bs.substr(0, size(F) - 1);
            string ees = es.substr(size(es) - size(F) + 1) + Daisuki;
            tmp = cnt(bbs) + cnt(m1) + cnt(m2) + cnt(ees);
            cc += tmp;
            cc %= mod;

            k--;
            cout << k << " " << cc << " " << tmp << endl;
            if(k == 0) return cc;

            bs = (Waai + bs).substr(0, 50);
            es = (es + Daisuki);
            es = es.substr(size(es) - 50);
        }

        int p2 = pow2(k);
        cout << pow2(1) << " " << pow2(2) << " " << pow2(3) << endl;
        cout << p2 << endl;
        cc += tmp;
        cc = (cc * p2) % mod;
        cc -= tmp;
        if(cc < 0) cc += mod;
        return cc;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "a"; string Arg1 = "b"; string Arg2 = "c"; string Arg3 = "x"; string Arg4 = "axb"; int Arg5 = 2; int Arg6 = 2; verify_case(0, Arg6, countF(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_1() { string Arg0 = "a"; string Arg1 = "b"; string Arg2 = "c"; string Arg3 = "x"; string Arg4 = "abcdefghij"; int Arg5 = 1; int Arg6 = 0; verify_case(1, Arg6, countF(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_2() { string Arg0 = "a"; string Arg1 = "a"; string Arg2 = "a"; string Arg3 = "b"; string Arg4 = "aba"; int Arg5 = 2; int Arg6 = 4; verify_case(2, Arg6, countF(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_3() { string Arg0 = "a"; string Arg1 = "b"; string Arg2 = "c"; string Arg3 = "d"; string Arg4 = "baadbdcbadbdccccbaaaadbdcbadbdccbaadbdcba"; int Arg5 = 58; int Arg6 = 191690599; verify_case(3, Arg6, countF(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_4() { string Arg0 = "a"; string Arg1 = "x"; string Arg2 = "y"; string Arg3 = "b"; string Arg4 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab"; int Arg5 = 49; int Arg6 = 1; verify_case(4, Arg6, countF(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_5() { string Arg0 = "waai"; string Arg1 = "akari"; string Arg2 = "daisuki"; string Arg3 = "usushio"; string Arg4 = "id"; int Arg5 = 10000000; int Arg6 = 127859200; verify_case(5, Arg6, countF(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_6() { string Arg0 = "vfsebgjfyfgerkqlr"; string Arg1 = "ezbiwls"; string Arg2 = "kjerx"; string Arg3 = "jbmjvaawoxycfndukrjfg"; string Arg4 = "bgjfyfgerkqlrvfsebgjfyfgerkqlrvfsebgjfyfgerkqlrvfs"; int Arg5 = 1575724; int Arg6 = 483599313; verify_case(6, Arg6, countF(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    AkariDaisukiDiv1 ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
