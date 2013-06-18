#include <iostream>
#include <cstring>
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

vector<pair<int, int> > data;

pair<int, bool> go(int pos, int parent) {
    vector<int> childs;
    vector<int> states;
    for(int i=0;i<size(data);i++) {
        if(i+1 == pos || data[i].first == pos) {
            int oth = i+1+data[i].first-pos;
            if(oth == parent) continue;
            childs.pb(oth);
            states.pb(data[i].second);
        }
    }

    int ret = 0;
    bool have = false;
    for(int i=0;i<size(childs);i++) {
        pair<int, bool> key = go(childs[i], pos);
        if(states[i] == 3) {
            key.first += key.second;
            key.second = false;
        } else if(states[i] == 2) {
            key.second = true;
        }

        ret += key.first;
        ret += (have && key.second);
        have ^= key.second;
    }

    cout << pos << " : " << ret << " " << have << endl;

    return mp(ret, have);
}

class TurnOnLamps 
{
public:
    int minimize(vector <int> roads, string initState, string isImportant) 
    {
        data.clear();
        for(int i=0;i<size(roads);i++) {
            int state = (initState[i] == '1') + 2 * (isImportant[i] == '1');
            data.pb(mp(roads[i], state));
        }

        int N = size(data);
        return go(N, -1).first;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,0,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "0001"; string Arg2 = "0111"; int Arg3 = 1; verify_case(0, Arg3, minimize(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {0,0,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "0000"; string Arg2 = "0111"; int Arg3 = 2; verify_case(1, Arg3, minimize(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {0,0,1,1,4,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "000100"; string Arg2 = "111111"; int Arg3 = 2; verify_case(2, Arg3, minimize(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {0,0,1,1,4,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "100100"; string Arg2 = "011101"; int Arg3 = 2; verify_case(3, Arg3, minimize(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {0,0,2,2,3,1,6,3,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "010001110"; string Arg2 = "000110100"; int Arg3 = 1; verify_case(4, Arg3, minimize(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arr0[] = {0,0,1,2,4,4,6,1,2,5,2,8,8,3,6,4,14,7,18,14,11,7,1,12,7,5,18,23,0,14,11,10,2,2,6,1,30,11,9,12,5,35,25,11,23,17,14,45,15}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "0000000000010000000000000010000010100000000000000"; string Arg2 = "1010111111111011011111000110111111111111111110111"; int Arg3 = 14; verify_case(5, Arg3, minimize(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    TurnOnLamps ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
