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

vector<int> child[105];
int P;

bool try_flow(vector<vector<bool> > &flow, vector<int> &back, vector<bool> &visit, int a) {
    if(visit[a]) return false;
    visit[a] = true;
    for(int i=0;i<size(flow[a]);i++) if(flow[a][i]) {
        if(back[i] == -1 || try_flow(flow, back, visit, back[i])) {
            back[i] = a;
            return true;
        }
    }
    return false;
}

bool go(int a, double s, double e) {
    if((int)(s+1e-6) == (int)(e-1e-6)) return true;

    int nc = child[a].size();

    if(nc <= 1) return false;

    vector<vector<bool> > bb(nc, vector<bool>(nc, false));

    for(int i=0;i<nc;i++) {
        double m1 = (s * (nc - i) + e * i) / nc;
        double m2 = (s * (nc-1-i) + e * (i+1)) / nc;

        for(int j=0;j<nc;j++) {
            bb[i][j] = go(child[a][j], m1, m2);
        }
    }

    vector<int> bf(nc, -1);
    for(int i=0;i<nc;i++) {
        vector<bool> visit = vector<bool>(nc, false);
        if(!try_flow(bb, bf, visit, i)) return false;
    }

    // cout << a << " : " << s << " " << e << " : ";
    // for(int i=0;i<size(bf);i++) cout << bf[i] << "-" << i << " ";
    // cout << endl;
    return true;
}

class LotteryTree 
{
public:
    string isFairTree(vector <int> tree, int P_) 
    {		
        P = P_;
        for(int i=0;i<105;i++) child[i].clear();
        for(int i=0;i<size(tree);i++) {
            child[tree[i]].pb(i + 1);
        }

        if(go(0, 0.0, P)) return "YES"; else return "NO";
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); if ((Case == -1) || (Case == 8)) test_case_8(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; string Arg2 = "YES"; verify_case(0, Arg2, isFairTree(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {0, 0, 0, 1, 1, 2, 2, 3, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; string Arg2 = "YES"; verify_case(1, Arg2, isFairTree(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {0, 0, 1, 1, 2, 2, 4, 4, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; string Arg2 = "NO"; verify_case(2, Arg2, isFairTree(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {0, 0, 1, 1, 1, 3, 3, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; string Arg2 = "NO"; verify_case(3, Arg2, isFairTree(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {0, 0, 0, 3, 0, 0, 3, 6, 3, 1, 0, 2, 0, 4, 6, 15, 1, 15, 11, 11, 1, 4, 11, 2, 11, 2, 6}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; string Arg2 = "YES"; verify_case(4, Arg2, isFairTree(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {0, 1, 2, 3, 1, 1, 4, 4, 0, 1, 6, 9, 1, 12, 9, 2, 4, 8, 6, 13, 8, 5, 11, 12, 17, 
 19, 13, 9, 3, 24, 30, 29, 28, 28, 11, 27, 2, 26, 6, 14, 8, 26, 15, 25, 33, 38, 
 1, 24, 15, 43, 3, 39, 26, 8, 13, 50, 28, 8, 6, 27, 8, 38, 27, 50, 17, 50, 25, 
 40, 7, 29, 22, 40, 2, 24, 22, 30, 33, 40, 19, 14, 26, 39, 5, 43, 7, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; string Arg2 = "NO"; verify_case(5, Arg2, isFairTree(Arg0, Arg1)); }
	void test_case_6() { int Arr0[] = {0, 1, 0, 0, 4, 0, 2, 2, 0, 2, 6, 1, 3, 6, 5, 9, 11, 13, 1, 10, 14, 4, 7, 21,
 16, 8, 25, 4, 5, 22, 25, 14, 12, 11, 12, 26, 21, 8, 2, 38, 3, 5, 4, 38, 27, 
 35, 38, 30, 38, 9, 16, 36, 6, 10, 7, 27, 30, 33, 17, 26, 17, 10, 35, 10, 38,
 41, 15, 9, 3, 27, 8, 15, 38, 22, 41, 33, 33, 36, 30, 13, 18, 22, 18}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; string Arg2 = "YES"; verify_case(6, Arg2, isFairTree(Arg0, Arg1)); }
	void test_case_7() { int Arr0[] = {0, 0, 2, 3, 4, 3, 2, 1, 8, 6, 8, 8, 2, 7, 14, 2, 8, 1, 11, 11, 12, 16, 12, 
 19, 20, 13, 7, 12, 26, 11, 18, 19, 18, 20, 4, 9, 1, 1, 6, 16, 1, 35, 27, 24,
 37, 30, 36, 41, 32, 36, 8, 2, 6, 14, 41, 1, 35, 6, 30, 16, 12, 2, 35, 25, 50,
 13, 1, 24, 8, 32, 26, 50, 9, 19, 9, 20, 26, 27, 6, 12, 25, 9, 37, 37, 9} ; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; string Arg2 = "NO"; verify_case(7, Arg2, isFairTree(Arg0, Arg1)); }
	void test_case_8() { int Arr0[] = {0, 0, 1, 0, 2, 3, 0, 0, 8, 5, 7, 5, 2, 12, 12, 14, 14, 13, 8, 2, 1, 7, 18,
 16, 8, 24, 18, 2, 24, 3, 11, 5, 24, 4, 34, 6, 31, 13, 38, 19, 4, 3, 22, 3,
 11, 12, 21, 34, 41, 8, 19, 4, 13, 29, 33, 8, 14, 50, 18, 45, 16, 50, 44, 50,
 38, 5, 43, 31, 29, 7, 6, 45, 38, 4, 19, 41, 50, 21, 44, 41, 43, 22, 33, 6, 8}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; string Arg2 = "YES"; verify_case(8, Arg2, isFairTree(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    LotteryTree ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
