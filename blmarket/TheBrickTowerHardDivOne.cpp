#include <iostream>
#include <cstring>
#include <iterator>
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

int stmap[4][4][4][4];
int curst = 0;

int tstate[4];

int * exstate(int *arr) {
    map<int, int> m;
    for(int i=0;i<4;i++) {
        if(m.count(arr[i]) == 0)
            m[arr[i]] = m.size();
        tstate[i] = m[arr[i]];
    }
    return tstate;
}

int getstate(int *arr) {
    int &ret = stmap[arr[0]][arr[1]][arr[2]][arr[3]];
    if(ret == -1) {
        ret = curst++;
    }
    return ret;
}

void gen(int *arr, int pos) {
    if(pos == 8) {
        int s1 = getstate(arr);
        int s2 = getstate(exstate(arr + 4));
        cout << s1 << " -> " << s2 << endl;
        return;
    }
    arr[pos] = -1;
    int ee = *max_element(arr, arr+pos) + 1;
    for(int i=0;i<=ee;i++) {
        arr[pos] = i;
        gen(arr, pos+1);
    }
}

class TheBrickTowerHardDivOne 
{
public:
    int find(int C, int K, long long H) 
    {
        memset(stmap, -1, sizeof(stmap));
        curst = 0;
        int arr[8];
        gen(arr, 0);
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 0; long long Arg2 = 2LL; int Arg3 = 4; verify_case(0, Arg3, find(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 7; long long Arg2 = 19LL; int Arg3 = 1; verify_case(1, Arg3, find(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 3; long long Arg2 = 1LL; int Arg3 = 14; verify_case(2, Arg3, find(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 7; long long Arg2 = 47LL; int Arg3 = 1008981254; verify_case(3, Arg3, find(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    TheBrickTowerHardDivOne ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
