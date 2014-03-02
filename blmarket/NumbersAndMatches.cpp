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

const int nums[10][7] = { { 1,1,1,0,1,1,1 }, {0,0,1,0,0,1,1}, {1,0,1,1,1,0,1}, {1,0,1,1,0,1,1}, {0,1,1,1,0,1,0}, {1,1,0,1,0,1,1}, {1,1,0,1,1,1,1}, {1,0,1,0,0,1,0}, {1,1,1,1,1,1,1}, {1,1,1,1,0,1,1} };
int nmove[10][10];
int ndiff[10][10];

string num;
int memo[20][130][220];

long long go(int pos, int life, int remain) {
    if(life < 0) return 0;
    if(pos == size(num)) {
        return remain == 110;
    }

    if(memo[pos][life][remain] != -1) return memo[pos][life][remain];

    long long ret = 0;
    int sp = num[pos] - '0';
    for(int i=0;i<10;i++) {
        ret += go(pos+1, life - nmove[sp][i], remain + ndiff[sp][i]);
    }
    return memo[pos][life][remain] = ret;
}

class NumbersAndMatches 
{
public:
    long long differentNumbers(long long N, int K) 
    {		
        memset(memo, -1, sizeof(memo));

        ostringstream ost;
        ost << N;
        num = ost.str();

        for(int i=0;i<10;i++) {
            for(int j=0;j<10;j++) {
                int nadd = 0;
                int nrem = 0;
                for(int k=0;k<7;k++) {
                    nadd += nums[j][k] && !nums[i][k];
                    nrem += !nums[j][k] && nums[i][k];
                }
                nmove[i][j] = nadd + nrem;
                ndiff[i][j] = nadd - nrem;
            }
        }

        for(int i=0;i<10;i++) {
            for(int j=0;j<10;j++) cout << ndiff[i][j] << " ";
            cout << endl;
        }

        return go(0, K, 110);
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 10LL; int Arg1 = 1; long long Arg2 = 4LL; verify_case(0, Arg2, differentNumbers(Arg0, Arg1)); }
	void test_case_1() { long long Arg0 = 23LL; int Arg1 = 1; long long Arg2 = 4LL; verify_case(1, Arg2, differentNumbers(Arg0, Arg1)); }
	void test_case_2() { long long Arg0 = 66LL; int Arg1 = 2; long long Arg2 = 15LL; verify_case(2, Arg2, differentNumbers(Arg0, Arg1)); }
	void test_case_3() { long long Arg0 = 888888888LL; int Arg1 = 100; long long Arg2 = 1LL; verify_case(3, Arg2, differentNumbers(Arg0, Arg1)); }
	void test_case_4() { long long Arg0 = 444444444444444444LL; int Arg1 = 2; long long Arg2 = 1LL; verify_case(4, Arg2, differentNumbers(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    NumbersAndMatches ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
