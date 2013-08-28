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

map<pair<string, int>, int> memo;

string convert(const string &a, char b, char c, int &cost) {
    string ret = a;
    cost = 0;
    for(int i=0;i<size(a);i++) {
        if(a[i] == b) {
            cost++;
            ret[i] = c;
        }
    }
    return ret;
}

// {"aaabbbcxyyopqrorrqoxyxcbaaddd"}

int go(const string &S, int pos) {
    pair<string, int> key = mp(S, pos);
    if(memo.count(key)) return memo[key];

    int bpos = size(S) - 1 - pos;
    if(pos >= bpos) return 0;

    if(S[pos] == S[bpos]) return go(S, pos+1);
    int t1, t2, t3, t4;
    t1 = go(convert(S, S[pos], S[bpos], t2), pos+1);
    t3 = go(convert(S, S[bpos], S[pos], t4), pos+1);

    int ret = min(t1+t2, t3+t4);
    cout << S << " " << pos << " = " << ret << endl;
    return memo[key] = ret;
}

class GooseTattarrattatDiv1 
{
public:
    int getmin(string S) 
    {		
        if(size(S) <= 1) return 0;
        return go(S, 0);
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "geese"; int Arg1 = 2; verify_case(0, Arg1, getmin(Arg0)); }
	void test_case_1() { string Arg0 = "tattarrattat"; int Arg1 = 0; verify_case(1, Arg1, getmin(Arg0)); }
	void test_case_2() { string Arg0 = "xyyzzzxxx"; int Arg1 = 2; verify_case(2, Arg1, getmin(Arg0)); }
	void test_case_3() { string Arg0 = "xrepayuyubctwtykrauccnquqfuqvccuaakylwlcjuyhyammag"; int Arg1 = 11; verify_case(3, Arg1, getmin(Arg0)); }
	void test_case_4() { string Arg0 = "abaabb"; int Arg1 = 3; verify_case(4, Arg1, getmin(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    GooseTattarrattatDiv1 ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
