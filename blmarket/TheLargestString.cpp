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

string s,t;

pair<string, string> go(int spos) {
    if(spos >= size(s)) return mp("", "");
    for(int i=spos+1;i<size(s);i++) {
        if(s[i] > s[spos]) return go(i);
    }

    pair<string, string> tmp3 = mp(string(1, s[spos]), string(1, t[spos]));
    pair<string, string> tmp = go(spos + 1);
    pair<string, string> tmp2 = mp(s[spos] + tmp.first, t[spos] + tmp.second);

    if(tmp2.first + tmp2.second > tmp.first + tmp.second) {
        if(tmp3.first + tmp3.second > tmp2.first + tmp2.second) return tmp3;
        return tmp2;
    } else {
        if(tmp3.first + tmp3.second > tmp.first + tmp.second) return tmp3;
        return tmp;
    }
}

class TheLargestString 
{
public:
    string find(string s_, string t_) 
    {		
        s=s_;t=t_;

        go(0);

        string ret = "";
        for(int i=0;i<size(s);i++) {
            pair<string, string> tmp = go(i);
            string tmp2 = tmp.first + tmp.second;
            if(ret < tmp2) ret = tmp2;
        }
        return ret;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "ab"; string Arg1 = "zy"; string Arg2 = "by"; verify_case(0, Arg2, find(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "abacaba"; string Arg1 = "zzzaaaa"; string Arg2 = "cbaaaa"; verify_case(1, Arg2, find(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "x"; string Arg1 = "x"; string Arg2 = "xx"; verify_case(2, Arg2, find(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "abbabbabbababaaaabbababab"; string Arg1 = "bababbaabbbababbbbababaab"; string Arg2 = "bbbbbbbbbbbbbbbbbbaaab"; verify_case(3, Arg2, find(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    TheLargestString ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
