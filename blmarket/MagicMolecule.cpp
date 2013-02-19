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

int N, M;
vector<int> pow;
vector<string> bond;

struct state {
    state(int pos, LL dis, int pc) : pos(pos), dis(dis), pick_cnt(pc) {};

    int pos;
    LL dis;
    int pick_cnt;

    bool operator<(const state &rhs) const {
        if(pos != rhs.pos) return pos < rhs.pos;
        if(pick_cnt != rhs.pick_cnt) return pick_cnt < rhs.pick_cnt;
        return dis < rhs.dis;
    }
};

map<state, int> memo;

int go(int a, LL dis, int pc) {
    if(N-a + pc < M) return -1;
    if(a == N) {
        return 0;
    }
    if(dis & 1) {
        return go(a+1, dis >> 1, pc);
    }

    state key(a, dis, pc);
    if(memo.count(key)) return memo[key];

    int tmp1 = go(a+1, dis >> 1, pc);
    dis >>= 1;
    for(int i=a+1;i<N;i++) if(bond[a][i] == 'N') {
        int pp = i - a - 1;
        dis |= (1LL << pp);
    }
    int tmp2 = go(a+1, dis, pc + 1);
    if(tmp2 != -1) tmp2 += pow[a];

    return memo[key] = max(tmp1, tmp2);
}

class MagicMolecule 
{
public:
    int maxMagicPower(vector <int> magicPower, vector <string> magicBond) 
    {		
        pow = magicPower;
        bond = magicBond;
        memo.clear();
        N = size(pow);
        M = (N * 2 + 2) / 3;

        /*
        cout << M << endl;
        for(int i=0;i<N;i++) {
            cout << i << " : ";
            for(int j=0;j<N;j++) if(i != j) {
                if(bond[i][j] == 'N') {
                    cout << j << " ";
                }
            }
            cout << endl;
        }
        */

        return go(0, 0, 0);
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NYY","YNN","YNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(0, Arg2, maxMagicPower(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NNYY","NNYY","YYNN","YYNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(1, Arg2, maxMagicPower(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {86,15,100,93,53,50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NYYYYN","YNNNNY","YNNYYN","YNYNYN","YNYYNY","NYNNYN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 332; verify_case(2, Arg2, maxMagicPower(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {3969,9430,7242,8549,8190,8368,3704,9740,1691}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NYYYYYYYY","YNYYYYYYY","YYNYYYYYY","YYYNYYYYY","YYYYNYYYY","YYYYYNYYY","YYYYYYNNY","YYYYYYNNY","YYYYYYYYN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 57179; verify_case(3, Arg2, maxMagicPower(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    MagicMolecule ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
