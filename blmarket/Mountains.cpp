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

const int mod = 1000000009;

int N,W;
vector<int> heights;
vector<long long> masks;

int go(int a, const vector<int> &state) {
    int ret = 0;
    for(int i=0;i<W;i++) {
        if((masks[a] & (1LL << i)) == 0) continue;

        LL mask = 0;
        for(int j=0;j<W;j++) {
            int diff = abs(i-j);
            int hh = heights[a] - diff;
            if(hh > state[j]) mask |= (1LL << j);
        }

        if(mask != masks[a]) continue;
        vector<int> tmp = state;
        for(int j=0;j<W;j++) {
            int diff = abs(i-j);
            int hh = heights[a] - diff;
            if(hh > state[j]) tmp[j] = hh;
        }

        ret += go(a-1, tmp);
        ret %= mod;
    }
    return ret;
}

class Mountains 
{
public:
    int countPlacements(vector <int> heights_, vector <string> visi) 
    {
        heights = heights_;
        masks.clear();
        for(int i=0;i<size(visi);i++) {
            long long mask = 0;
            for(int j=0;j<size(visi[0]);j++) {
                if(visi[i][j] == 'X') {
                    mask |= (1LL << j);
                }
            }
            masks.pb(mask);
        }
        W = size(visi[0]);

        vector<int> state(W, 0);

        go(N-1, state);
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2, 3, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"------",
 "XXXX--",
 "---XXX"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(0, Arg2, countPlacements(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {4, 3, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"XXXXX--------",
 "----------XXX",
 "----XXXXXXX--"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(1, Arg2, countPlacements(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {13, 2, 3, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"XXXXXXXXX",
 "-XXX-----",
 "----XXXXX",
 "-----XXX-"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 9; verify_case(2, Arg2, countPlacements(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {8, 2, 9, 3, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"X------",
 "-------",
 "------X",
 "-------",
 "XXXXXXX"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 98; verify_case(3, Arg2, countPlacements(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {20, 20, 20, 20, 20, 20, 45, 50, 49, 50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"-------------------",
 "-------------------",
 "-------------------",
 "-------------------",
 "-------------------",
 "-------------------",
 "-------------------",
 "------------XXXXXXX",
 "XXXXXXX------------",
 "XXXXXXXXXXXXXXXXXXX"}
; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 973726691; verify_case(4, Arg2, countPlacements(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    Mountains ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
