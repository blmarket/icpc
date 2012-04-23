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

string a,b,c,S,F;
const int mod = 1000000007;

string getleft(int k, int len)
{
    if(len <= 0) return "";
    if(k == 0) return S;
    string tmp = a + getleft(k-1, len-size(a));
    if(size(tmp) >= len) return tmp;
    tmp += b;
    if(size(tmp) >= len) return tmp;
    tmp += getleft(k-1, len - size(tmp));
    if(size(tmp) >= len) return tmp;
    tmp += c;
    return tmp;
}

string getright(int k, int len)
{
    if(len <= 0) return "";
    if(k == 0) return S;
    string tmp = getright(k-1, len - size(c)) + c;
    if(size(tmp) >= len) return tmp;
    tmp = b + tmp;
    if(size(tmp) >= len) return tmp;
    tmp = getleft(k-1, len - size(tmp)) + tmp;
    if(size(tmp) >= len) return tmp;
    tmp = a + tmp;
    return tmp;
}

int fuck(const string &base, const string &t, int s, int e)
{
    int ret = 0;
    for(int i=s;i<e;i++)
    {
        if(i + size(t) > size(base)) break;
        if(base.substr(i, size(t)) == t) ret++;
    }
    return ret;
}

int count(int k, int prevcount)
{
    //cout << k << " " << F << endl;
    if(k == 0)
    {
        int ret = 0;
        int len = size(S) - size(F) + 1;
        for(int i=0;i<len;i++)
        {
            if(S.substr(i, size(F)) == F) ret++;
        }
        return ret;
    }

    int ret = prevcount;
    ret *= 2;
    ret %= mod;

    string left = getleft(k-1, 50);
    string right = getright(k-1, 50);

    string s1 = a + left + b + left + c;
    ret += fuck(s1, F, max(0, size(a)-size(F)+1), size(a));
    string s2 = right + b + left + c;
    ret += fuck(s2, F, max(0, size(right) - size(F) + 1), size(right) + size(b));
    string s3 = right + c;
    ret += fuck(s3, F, max(0, size(right) - size(F) + 1), size(right));
    ret %= mod;

    return ret;
}

class AkariDaisukiDiv1 
{
public:
	int countF(string Waai, string Akari, string Daisuki, string S_, string F_, int k) 
	{
            S = S_;
            a = Waai;
            b = Akari;
            c = Daisuki;
            F = F_;

            int ret = -1, prev = -1;
            for(int i=0;i<=k;i++)
            {
                if((i%10000) == 0)
                    cout << i << endl;
                ret = count(i, prev);
                prev = ret;
            }
            return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "a"; string Arg1 = "b"; string Arg2 = "c"; string Arg3 = "x"; string Arg4 = "axb"; int Arg5 = 2; int Arg6 = 2; verify_case(0, Arg6, countF(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_1() { string Arg0 = "a"; string Arg1 = "b"; string Arg2 = "c"; string Arg3 = "x"; string Arg4 = "abcdefghij"; int Arg5 = 1; int Arg6 = 0; verify_case(1, Arg6, countF(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_2() { string Arg0 = "a"; string Arg1 = "a"; string Arg2 = "a"; string Arg3 = "b"; string Arg4 = "aba"; int Arg5 = 1; int Arg6 = 2; verify_case(2, Arg6, countF(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_3() { string Arg0 = "a"; string Arg1 = "b"; string Arg2 = "c"; string Arg3 = "d"; string Arg4 = "baadbdcbadbdccccbaaaadbdcbadbdccbaadbdcba"; int Arg5 = 58; int Arg6 = 191690599; verify_case(3, Arg6, countF(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_4() { string Arg0 = "a"; string Arg1 = "x"; string Arg2 = "y"; string Arg3 = "b"; string Arg4 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab"; int Arg5 = 49; int Arg6 = 1; verify_case(4, Arg6, countF(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_5() { string Arg0 = "waai"; string Arg1 = "akari"; string Arg2 = "daisuki"; string Arg3 = "usushio"; string Arg4 = "id"; int Arg5 = 10000000; int Arg6 = 127859200; verify_case(5, Arg6, countF(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_6() { string Arg0 = "vfsebgjfyfgerkqlr"; string Arg1 = "ezbiwls"; string Arg2 = "kjerx"; string Arg3 = "jbmjvaawoxycfndukrjfg"; string Arg4 = "bgjfyfgerkqlrvfsebgjfyfgerkqlrvfsebgjfyfgerkqlrvfs"; int Arg5 = 1575724; int Arg6 = 483599313; verify_case(6, Arg6, countF(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }

// END CUT HERE

};



// BEGIN CUT HERE 
int main() {
	AkariDaisukiDiv1 ___test;
	___test.run_test(-1);
}
// END CUT HERE
