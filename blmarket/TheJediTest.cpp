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

vector<int> V;
int K;

map<PII, int> memo;

int go(int a, int b) {
    if(a+1 == size(V)) {
        return (V[a]+b+K-1) / K;
    }
    PII key = mp(a,b);
    if(memo.count(key)) return memo[key];

    int ret = -1;
    int value = 0;

    for(int i=0;;i+=K) {
        int elasp = V[a] + b - i;
        if(elasp > V[a]) continue;
        if(-elasp > V[a+1]) {
            int tmp = go(a+1, -V[a+1]);
            if(tmp == -1) break;
            tmp += i / K;
            if(ret == -1 || ret > tmp) {
                ret = tmp;
                value = -V[a+1];
            }
            break;
        }
        int tmp = go(a+1, elasp);
        if(tmp == -1) continue;
        tmp += i / K;
        if(ret == -1 || ret > tmp) {
            ret = tmp;
            value = elasp;
        }
    }
    if(a == 6 && b == 160) {
        cout << ret << " : " << value << endl;
    }
    return memo[key] = ret;
}

class TheJediTest 
{
public:
    int minimumSupervisors(vector <int> V_, int K_) 
    {		
        V = V_; K = K_;
        memo.clear();
        int ret = 0;
        /*
        for(int i=0;i<size(V);i++) {
            ret += V[i] / K;
            V[i] %= K;
        }
        */
        ret += go(0, 0);
        return ret;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = 
            {309,616,935,451,600,249,519,556,798,303,224,8,844,609,989,702,195,485,93,343}
            ; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; int Arg2 = 99; verify_case(0, Arg2, minimumSupervisors(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1, 1, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 2; verify_case(1, Arg2, minimumSupervisors(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {0, 0, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12345; int Arg2 = 0; verify_case(2, Arg2, minimumSupervisors(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {15, 0, 13, 4, 29, 6, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; int Arg2 = 10; verify_case(3, Arg2, minimumSupervisors(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {1284912, 1009228, 9289247, 2157, 2518, 52781, 2, 2818, 68}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 114; int Arg2 = 102138; verify_case(4, Arg2, minimumSupervisors(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    TheJediTest ___test; 
    ___test.run_test(0); 
} 
// END CUT HERE
