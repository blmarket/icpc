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

class TeamContest 
{
public:
    int worstRank(vector <int> str) 
    {
        int my[3] = { str[0], str[1], str[2] };
        sort(my, my+3);
        int mypow = my[0] + my[2];

        vector<int> V;
        for(int i=3;i<size(str);i++) {
            V.pb(str[i]);
        }
        sort(V.begin(), V.end());
        int ret = 1;
        while(size(V)) {
            if(V[0] + V.back() > mypow) {
                ret++;
                V.pop_back();
                swap(V[0], V.back());
                V.pop_back();
                swap(V[1], V.back());
                V.pop_back();
                sort(V.begin(), V.end());
            } else {
                for(int i=3;i<size(V);i++) {
                    V[i-3] = V[i];
                }
                V.resize(size(V) - 3);
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
	void test_case_0() { int Arr0[] = {5, 7, 3, 5, 7, 3, 5, 7, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, worstRank(Arg0)); }
	void test_case_1() { int Arr0[] = {5, 7, 3}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, worstRank(Arg0)); }
	void test_case_2() { int Arr0[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, worstRank(Arg0)); }
	void test_case_3() { int Arr0[] = {3,9,4,6,2,6,1,6,9,1,4,1,3,8,5}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(3, Arg1, worstRank(Arg0)); }
	void test_case_4() { int Arr0[] = {53,47,88,79,99,75,28,54,65,14,22,13,11,31,43}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(4, Arg1, worstRank(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    TeamContest ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
