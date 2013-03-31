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

char findmax(string s) {
    char maxc = s[0];
    for(int i=1;i<size(s);i++) {
        if(s[i] > maxc) maxc = s[i];
    }
    return maxc;
}

int count(string s, string t, char c, int &lastidx, string &s1, string &t1) {
    int ret = 0;
    int cnt2 = 0;

    for(int i=0;i<size(s);i++) if(s[i] == c) {
        lastidx = i;
        if(t[i] == c) cnt2++;
    }

    for(int i=0;i<=cnt2;i++) {
        int cur = 0, cnt = 0;
        string s2 = "", t2 = "";

        for(int j=0;j<size(s);j++) if(s[j] == c) {
            if(cur > 0 && t[j] != c) continue;
            if(t[j] == c && cur) cur--;

            s2 += s[j]; 
            t2 += t[j];
            cnt++;
        }
        if(cnt + i > ret) {
            ret = cnt + i;
            s1 = s2; t1 = t2;
        }
    }

    return ret;
}

class TheLargestString 
{
public:
    string find(string s, string t) 
    {
        if(size(s) == 0) return "";
        char maxc = findmax(s);

        char maxt = -1;
        for(int i=0;i<size(s);i++) {
            if(s[i] == maxc) {
                if(t[i] > maxt) maxt = t[i];
            }
        }
        if(maxt > maxc) return string("") + maxc + maxt;

        int lastidx;
        string s1, t1;
        cout << count(s, t, maxc, lastidx, s1, t1) << endl;
        s = s.substr(lastidx + 1); t = t.substr(lastidx + 1);

        while(size(s)) {
            maxc = findmax(s);
            if(maxc < t1[0]) return s1 + t1;

            for(int i=0;i<size(s);i++) {
                if(s[i] == maxc) {
                    s1 += s[i];
                    t1 += t[i];
                    lastidx = i;
                }
            }
            s = s.substr(lastidx + 1);
            t = t.substr(lastidx + 1);
        }
        return s1 + t1;
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
