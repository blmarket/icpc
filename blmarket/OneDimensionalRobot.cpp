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

string cmds;
int minA, minB;
int rr[5005][5005];
bool chk[5005][5005];

int go(int a, int b, bool &left, bool &right) {
    left = right = false;
    int ret = 0;
    for(int i=0;i<size(cmds);i++) {
        if(cmds[i] == 'R') {
            ret++;
            if(ret > b) {
                ret = b;
                right = true;
            }
        } else {
            ret--;
            if(ret < -a) {
                ret = -a;
                left = true;
            }
        }
    }
    return ret;
}

class OneDimensionalRobot 
{
public:
    long long theSum(vector <string> commands1, vector <string> commands2, int minA_, int maxA, int minB_, int maxB) 
    {		
        minA = minA_;
        minB = minB_;
        cmds.clear();
        for(int i=0;i<size(commands1);i++) cmds += commands1[i];
        for(int i=0;i<size(commands2);i++) cmds += commands2[i];

        memset(chk, 0, sizeof(chk));

        bool left, right;
        for(int i=minA;i<=maxA;i++) {
            rr[i][minB] = go(i, minB, left, right);
            chk[i][minB] = true;

            if(left && right) {
                for(int j=0;i-j >= minA;j++) {
                    rr[i-j][minB+j] = rr[i][minB] + j;
                    chk[i-j][minB+j] = true;
                }
            } 
        }

        for(int i=minA;i<=maxA;i++) {
            for(int j=minB;j<=maxB;j++) {
                if(chk[i][j] == false) {
                    rr[i][j] = go(i,j, left, right);
                    chk[i][j] = true;
                    if(!right) {
                        for(int k=j+1;k<=maxB;k++) {
                            rr[i][k] = rr[i][j];
                            chk[i][k] = true;
                        }                            
                    }
                    if(!left) {
                        for(int k=i+1;k<=maxA;k++) {
                            rr[k][j] = rr[i][j];
                            chk[k][j] = true;
                        }
                    }
                }
            }
        }

        long long ret = 0;
        for(int i=minA;i<=maxA;i++) {
            for(int j=minB;j<=maxB;j++) ret += rr[i][j];
        }
        return ret;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"RRLRLLRRLL"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 2; int Arg4 = 1; int Arg5 = 1; long long Arg6 = -1LL; verify_case(0, Arg6, theSum(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_1() { string Arr0[] = {"RLRRLRLLRRLLLRLRLLRL"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 3; int Arg4 = 1; int Arg5 = 2; long long Arg6 = -9LL; verify_case(1, Arg6, theSum(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_2() { string Arr0[] = {"RLRRLRRRLLLLLRLRRLLLLRRRRLLRLLRLRRRLLRRLRLLRLLRRRL", "LRLRLRLLRLLLRRLLRLRRLLLRLLRLLRLLLLRRRLLRLRRRLLRRRR"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arg3 = 5; int Arg4 = 2; int Arg5 = 4; long long Arg6 = 17LL; verify_case(2, Arg6, theSum(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_3() { string Arr0[] = {"LRRRRLLLRLRLLLRRLLLRRRLLLLLLRLLRLRRLLRLLLLLRRLLLLR",
 "RLLLLRRRLRLLRLRRLRLRRLLRRLRRRRLLLRRLLRRLRRRLLRLRLL",
 "RLRRRLLLRLRRLRLLLRLLLLRRRLLRLRRLRRRRRLRLLLLLRLLRLR",
 "LLRLRRRLRLLLRLLRRLRLRLRLRRRLLRRRLRRRLRLRLRRLLRLRLR",
 "LRRRRRLLLRLLRRLLRRRRLLLLRRRRLRRRLLLRRLLRRRRRRLLRLR",
 "LRLLRLRLLLLRLLLRLLRRRRLRRLLLLRRRLRRLRLRRLLLRLRLRLR"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 34; int Arg4 = 1; int Arg5 = 34; long long Arg6 = -1417089LL; verify_case(3, Arg6, theSum(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_4() { string Arr0[] = {"LRRRRRLRRRLLLRLLLLRLRLLLRLLRLLRRLRRLRRLLRLLLRLLLLL",
 "RRRLRLRRLLLRLLRRRRLLLRLRLRRLLLRLRRLLRLRLRLLLRLRLLR",
 "RLLLLLRLRRLLLRRRLLRLRLLRRLLLLRRLRLRLRRRLRRLRRLLRLL",
 "RRLRLRLRLLLLRRRRLLLRLLRLLLLRLLLRLLLRLRLRLRRRLRRRRR",
 "LRRLRLLRLLRRLRRLLRLRLRRLRRLLLLLLLRRRLRLLRRRRRRLRRR",
 "RLRLLLRLRLLRRLRLLLLLRLRRLRLLLRRRLRLRLRLLLRLRLLLRRL",
 "LRLRRLRRLLLRRLLLRRLRRRLLLLLLLLLLLLLRLLLRLLLRLLLRLL",
 "LLLRLRRRRLRRLLRLRLLLRLLLRRLRRLRLRRLLLLRRLRRRLLLRLR",
 "RLRLLRRRRRLLLRLRRLRLLRLRLLLRLLLRRLRLRLRRRLRRLLRRRL",
 "RLLLLRRRLRRLRRRLRRRLRLLRRRLLLRRLRLLLLLLLLRLLRLLRRL",
 "RRLLLRRLRLLRLLLRRRLRRLLLRLLRLRRRLRRRRRLRRRRRLRLLLR",
 "LLLLRLRLRLLLLRLLRRLLLRLLLRLLLLRLRRRLRRRLRLRLRLRLRR",
 "LLLLRLRLRLRLRLLLRLLRLLRLLLLLLLRRLRRRLRRLLLLLRLLLLL",
 "RRLLRLLLRRLRLLLLRRRRLLLLRLLRLLLLLRLLLLRRLRLLRLRLLR",
 "LRRLLLLRLLRRLRRRRRLLRLLLRLRLLLLLRLLRRLLLLLLRLRLLLR",
 "LRLLRRLLLRLRLLLLRLLRRLLLRLLLRLRLRRLRRRLLLLRRRLRLLL",
 "LLLRRLRLLLLRLRRLRLRLRRRRLLLLLLLRLLLRRLRRLLLLRLLLLR",
 "RRLRLLLRLRRLRRRLRLLRRLLLLLRLRLRRLRLLLLLLLLLRRLRRLL",
 "LRRLLLLRLLLRRRLLLRLLRRLLLRRLLLRRLLLRRLLRLRRRLLRLLL",
 "LRRRRLLRRLLLLLRLLLRLRRLLRLLLLLLLRRRLLLRLLLLLLLRLRR",
 "LLRRRLRLRLLRLRRLRLRRLLRLLLLLLRRLLRLRLRLLLLRLRLRRRR",
 "RRLRLLLLLRLRRLLLLLRLLLRLLLRLLRLLLLLRLLLRRLRRLLLLRR",
 "RLLLRLLLLLLLLLRRRLLLRRRLRRLRRRLLLRLRLLRLLLRLLRRRRL",
 "LRLLLRRRLRLRRLLRLLRLRRLRLRLLLLRLLLRLLLLRRRRLRLRLRR",
 "RLRRLLLLLRRLRLRLRRRLLLRLRRRLRLRLRLLRRLLLLRRLLRRRLL",
 "RLLRRLRRLRLRLRLLLLLLRLLLLRRLLRLRLRRLLRLRRLLRLRLLLR",
 "LRLLLLRLRLLLRLRLLRLLRRLLRLLLLLRRLRLRRLLLRLLLLLLRLL",
 "LRLRLRLLLLLLRRLLLRLLRLRLRRRRLLLLLRLLLLRLLRRLRLLLLL",
 "LLRLRRLLLRLLLRRLRLLRLRLLLLLLRLLRLRLRRLRLRLLLRRLLLR",
 "LLLLLLLLRRLLLLRLRRRLRRLLRRLRLLLLRLLRLRRLLLLLRRLLLL",
 "RRLLLLRRRRLLLLLRRLLLRLRLRRLLLLLLLRLRRRLRLLRLLLLLRL",
 "RLLRRLRRLRRLRLLRLLLRLRRRLRRLLLLLRRRLLRRLRLRLLRLLRL",
 "LRLRLLLRLLLRLRRRRRLRLRRLRLRLLLRRLRLLRLRLLLLRLLLLLR",
 "LLLLRRRRLLLRLLRRLLLLLRRLLLRLRRRLRLRLRRLLRLRRLLRLLL",
 "RLLRLLLRRLRRRRLLRLRRRRRLRLLRLLLLRRLLRLLLLRRLRLLLRL",
 "LRRLLLLRRLLRLLLLLRRLRLRRLRLLRRRRRLRLLLRLLRLRRLLLRR",
 "LLRRLLRLLRRLRRLRLRLLLRRRRLLLRLLRRLLLLRRLRLLRLLLLRR",
 "LRLLRRRRLLRLRLLLLLLLLLRLLRLLLRLRLRRRLLLLRRRRLRLLLR",
 "RRLLLLLLLLRRLLRRRLLRLLLLRLLLLLRLRLLLLRLRRRRRLRLLRL",
 "RRRLLRRLLLLLRRRLLLLLLLRLLLRRLLRLRRLLLRLRLLLLRLRLLL",
 "LLRRRRLRLRRRRRLRRRRRRRLLLLLLLLLLRRRRLLLRLRLLLLRRLL",
 "RLLLLRLLLRRLRRLRRLLRRLLLLLRLLRRRRRRLLLLRLLLLLRRLLL",
 "RLRLLRRRLLLLLRRRLLLRRLLLLLRRLLRRLRRRRLRRLLRRRLLLRL",
 "LLLRLLRLRRLLRRRLRRRLLLRLLLLLLRRLLRRRLLRRRRLRLLLRRL",
 "RLLLRLLRLLRLRLRLRLRRLLLLLLLRLRRLLRLRLRRRLLLRLLRRLR",
 "LLRLRLRLRLLLRRLLLRRLRRLLLLRRLLRLLLRLLRRLLRRRLRRLRL",
 "RRLRLRRLRRRLLLRRRLRRRLLLLLLLLLRRRRLRRLRRRLRLRRLRRL",
 "LLLRRLRLLRLRLLLRRLRRLLRLLLLRRLRRLRRLLLLRLLRLRLRRLL",
 "RLRLLLLLLRLRRLLRRRLLLRRLLRRLRLRRLLLRLLLLLRLRRLRLRR",
 "LLLLRRRRRLLLRLLRLRRLLRRRLRLLRLLLRLLLLRLRRRRLRRLLLL"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"LLLLRRRLRLLLRRLRLRRLRLLLLLLLRRLRLRRLLRRLLRLRRRRLRL",
 "LLLRRLLRLRLLRLLLRLLLLRLLLLLRLLLLRRLRLRLRRLLLRRLLLL",
 "RRLLLRRRLRLLRLRLLRLLLRLLLRLLLLLLLRLLLLLLLLLRLLRLLR",
 "LLRLLRRRLLRLLRLRLRRLRLLLLLLLRLLLRRLRLLLLLLLLLLRRRL",
 "LLRRRRLLRLLLRRLLLLLLRLLLRRLLLRLRRRRLLLRRLLRLRLRLLL",
 "LLLRLLLRLLLLRLLLLLRRLLLRRLLLRLRRRRLLLRRLLLLLLLRLRL",
 "RLRRLRRRRRLRLRLLLRLRRRRLLRLRLLLLLLLLLLRRLLLLRRRLLL",
 "RRRLRLLRRRLLRRLLRLLLRLRLRRRLLRLLLLRLLRRRRLRRLLLRLL",
 "RLLRLLRLLLLLLRLLLRLLLLLRRRLRLRRRLLRRLRRRLLRRRRLLLR",
 "RRLRRRLLRLLLLRLRRLRLLLLLRLRRRLLLLLLRLLRLLRLLLRLLLL",
 "LLLRLLLRRLRLLLLLLLLRLLLLLLLLLRRLLLRLLRLLRLLLLLRLRR",
 "LRRRLLRRRRLRRLRLLRRRLLLLRRLRRLRRLRLLLLLLRLRRLLLRLL",
 "RLLLRRRRLLRLRLLRLLLRLLLRLLRRRLLRLLRRLLLLLLLRRRRRRL",
 "LLRRRLRLLRRRLRLLLRLRLLLLLRRLLRLLRLLLRLRLRLLRLLRLRR",
 "LLRLRRRRLLRRLLLRRLLRLLLLLLLRRLRLRLLRRLLLLRRRLLRRLR",
 "LRLLRLLRLLRLLLLLRLLRLLRLLRLRLLRLLLRLRLRLLLLLRLLLRR",
 "LRRRLRLLRLLRLLRRRLRRLRLLLRLRLLLLLLLLLRLRLRRRRRLRLL",
 "LLLLLLRLRLLLLRRRLRLLRRRRLRLRLLLLLRRLRRLLRRLLLRLLRL",
 "LRLRLLLLLLRLLLLLLLLLRLLLRLLRLLRLRRRRLRRRRLRLRLLLLL",
 "RLLLLLLRLRLLRRLRLLRLLRLLRLRLRRRLLRRLRLRLRRLLRRLRLR",
 "LRRRLRLLRLLLLLRLRLRLLLRLLLLLLRRLRLLLRLRLLRLLLLLRRL",
 "LRLLLRRLRLLLRLRRLLRLRLLLLLLRLLLLRRRLLLLRRRRLLRRRRL",
 "LRRLRLRLRRRRRRLRLLLRRRLLLRLLRRLLRLLRRLLRLLLRRRRLRL",
 "LLRLLRLRLRLLLRRLLLRLRLLLRLRRRLRLRLLLRRLLLRLRRLRLLR",
 "RRLLLLLLLLLLRRRLLLRRLLLLLRRLLLLRLRRLRLRLLLLLRRLLRL",
 "LRRRLLRLLLRRRLLLLRLRLLRRLLLRRRRRLLLLRRRLLLRRRLLLRL",
 "LRRLLLRLLRRLLLRLLRLRLRRLLLLRRRLLRLLLRLRLLRLLRLLLLL",
 "LRLLRRLLLLLLRRRLLRLLLLLLLLRRRLLLRLLRRRRLLLLLLLRLLL",
 "LLLRLLRRLLRLLRLRLLRRRLLLLLLRRLLLLLLLLLLLRLLLLLLRLR",
 "LLLLLRRRRLLLLLRRRRLLRLRRLLLLLLLLRRLLLRRRLRRLLRLRRL",
 "RLRLRLRRLLRLLRRRRLLRLLLLLRLRLLRLLLLLRLRRRRRLRRRLRR",
 "RLRRLRRRLLRLLRLRLRLLLLRLRLLLRLRRRLLLRRLLRRLLRLRRLL",
 "RLLLRRRRRLLLLLLLLLRRLRRLLLRLLLRLLLLRRLRLLLLLRLLLRR",
 "LLLRRRLLLLLLLLLRRLRLRLLLLRLLRLRRLLRRRLRRRRLRRRLLLL",
 "LRRLLLLLRLRLRLLRRRRLLLLRLRRLLRRRRLRLRLRRRRRRLRLLRL",
 "RRRLLRLLRLLRLRRLRRLLLLLRRLLLRLLRRLLLLRRRLRLRLRRLRL",
 "LRLRLLRLLRRRRLLRRRLLLLRRLRLLLLLLRRRLLRRLLLLLLRRRLL",
 "RRRRRLRLRLLRLLLRLRLRLLLLRLLLLRLRLLRLLRLLRLLRRRLLRL",
 "RLRRRLLLRLRLRRLLRLLLLLLLLLLRRLRRLRLLRRLRRLLRLRLLLL",
 "RRLRLRLRRLLLLLLRRLLLRRLRLLLLLLLLLLRLRLLLRLLRRLLLLR",
 "RLLLRLRRLLRLLRRRRLLRLLRLRLLLRLRLRRLLLLRLRLLRRRLLLL",
 "RLRLLRLLRRRLLLLRLLLRLLRLRRLLLLRRLRRRLRRRLLRLRRRRLR",
 "LLRLRLRLLRLRRRRRRLLLLLLLRLLLRLRLRLLRRRLRRLLLRLLRRL",
 "RLLRLLRRLRRLLLRLLRLLLLRRLLRLRRRLRRLRRLLRRRRRLLRLRL",
 "LRRLLLLLLLLLLRLLLLLRRLLLRRRRLRLRRLLLRRRRRRLRRRLRLL",
 "RRRLRLLLLLLLLRRLLRLRLRLRLLLLLRRLLRLLLLLRLLRRLLLRLL",
 "RLLLLRLRLLLLLRRLLLLRRLLRRLLLLLLRLLRLRLRLLRLLLLRLRR",
 "LLLRLRLRRRLRLLLRRLLLRLRLLRLRLLLLLLLLLRRLRLLLLRRRLR",
 "LRLRLLLLLRRLLRLRLLRLLLLRRLRRRLRRLRRRRLLLRRRLLRRLLL",
 "LRLLRRLRRLLLLRLLLLLLLLLLRLLLLLRRRLRLLLLLLLRLLRLLRR"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 5000; int Arg4 = 1; int Arg5 = 5000; long long Arg6 = -19478907170LL; verify_case(4, Arg6, theSum(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    OneDimensionalRobot ___test; 
    ___test.run_test(3); 
} 
// END CUT HERE