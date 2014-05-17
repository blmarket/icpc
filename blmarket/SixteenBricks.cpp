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

class SixteenBricks 
{
public:
    int maximumSurface(vector <int> height) 
    {		
        sort(height.rbegin(), height.rend());
        int arr[6][6];
        memset(arr, 0, sizeof(arr));
        arr[2][2] = height[0];
        arr[3][3] = height[1];
        arr[1][3] = height[2];
        arr[2][4] = height[3];
        arr[2][3] = height[15];
        arr[3][2] = height[14];
        arr[1][2] = height[13];
        arr[2][1] = height[12];
        int jj = 4;
        int kk = 11;

        for(int i=0;i<4;i++) {
            for(int j=0;j<4;j++) {
                if(arr[i][j] == 0) {
                    if((i&1) == (j&1)) {
                        arr[i+1][j+1] = height[jj++];
                    } else {
                        arr[i+1][j+1] = height[kk--];
                    }
                }
            }
        }


        int ret = 16;
        for(int i=0;i<5;i++) {
            for(int j=0;j<5;j++) {
                ret += abs(arr[i][j+1] - arr[i][j]);
                ret += abs(arr[i+1][j] - arr[i][j]);
            }
        }

        return ret;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 32; verify_case(0, Arg1, maximumSurface(Arg0)); }
	void test_case_1() { int Arr0[] = {1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 64; verify_case(1, Arg1, maximumSurface(Arg0)); }
	void test_case_2() { int Arr0[] = {77, 78, 58, 34, 30, 20, 8, 71, 37, 74, 21, 45, 39, 16, 4, 59}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1798; verify_case(2, Arg1, maximumSurface(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    SixteenBricks ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
