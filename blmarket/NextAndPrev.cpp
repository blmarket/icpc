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

class NextAndPrev 
{
public:
    int getMinimum(int nextCost, int prevCost, string start, string goal) 
    {		
        map<char, char> mapping;
        for(int i=0;i<size(start);i++) {
            char &tmp = mapping[start[i]];
            if(tmp == 0) tmp = goal[i];
            if(tmp !=goal[i]) return -1;
        }

        char first = mapping.begin()->second;

        foreach(it, mapping) {
            map<char, char>::iterator jt = it;
            char next;
            if(++jt != mapping.end()) next = jt->second;
            else next = first;
            if(next < it->second) return -1;
        }

        foreach(it, mapping) {
            cout << it->first << " - " << it->second << endl;
        }
        return 0;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); if ((Case == -1) || (Case == 8)) test_case_8(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 8; string Arg2 = "aeaae"; string Arg3 = "bcbbc"; int Arg4 = 21; verify_case(0, Arg4, getMinimum(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 8; string Arg2 = "aeaae"; string Arg3 = "bccbc"; int Arg4 = -1; verify_case(1, Arg4, getMinimum(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 1; string Arg2 = "srm"; string Arg3 = "srm"; int Arg4 = 0; verify_case(2, Arg4, getMinimum(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 1000; int Arg1 = 39; string Arg2 = "a"; string Arg3 = "b"; int Arg4 = 975; verify_case(3, Arg4, getMinimum(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 123; int Arg1 = 456; string Arg2 = "pqrs"; string Arg3 = "abab"; int Arg4 = -1; verify_case(4, Arg4, getMinimum(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arg0 = 100; int Arg1 = 19; string Arg2 = "topcoder"; string Arg3 = "ssszsffs"; int Arg4 = 676; verify_case(5, Arg4, getMinimum(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_6() { int Arg0 = 1; int Arg1 = 1000; string Arg2 = "csk"; string Arg3 = "wog"; int Arg4 = 64; verify_case(6, Arg4, getMinimum(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_7() { int Arg0 = 7; int Arg1 = 6; string Arg2 = "qwerty"; string Arg3 = "jjjjjj"; int Arg4 = 125; verify_case(7, Arg4, getMinimum(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_8() { int Arg0 = 306; int Arg1 = 26; string Arg2 = "me"; string Arg3 = "ii"; int Arg4 = 572; verify_case(8, Arg4, getMinimum(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    NextAndPrev ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
