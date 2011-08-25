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

inline void setmin(int &a,int b) { if(a>b) a=b; }

vector<int> points;
int myp;
int dp[55][205][15];

const int BASE = 101;

class TheSoccerDivOne 
{
public:
    int find(vector <int> points_) 
    {		
        points = points_;
        myp = points[0] + 12;

        for(int i=0;i<205;i++) for(int j=0;j<15;j++) dp[0][i][j] = 1000;
        dp[0][BASE+4][0] = 0;

        for(int i=1;i<size(points);i++) for(int a=0;a<205;a++) for(int b=0;b<15;b++)
        {
            int &r = dp[i][a][b];
            r = 1000;

            for(int j=0;j<4;j++)
            {
                for(int k=0;j+k<4;k++) if(b+k<105)// num of draw
                {
                    int l = 4-j-k; // num of lose
                    if(a+l-j < 0 || a+l-j >= 205) continue;
                    int newscore = points[i] + l * 3 + k;

                    for(int m=b-k;m<=b+k;m+=2)
                    {
                        if(m < 0 || m >= 15) continue;
                        int &prev = dp[i-1][a+l-j][m];

                        setmin(r, prev + (newscore > myp ? 1 : 0));
                    }
                    //int &prev = dp[i-1][a+j-l];
                }
            }

            if(r < 1000)
            {
                cerr << i << " " << a << " " << b << " = " << r << endl;
            }
        }

        return dp[size(points)-1][BASE][0]+1;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {5, 17}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, find(Arg0)); }
	void test_case_1() { int Arr0[] = {5, 18, 21, 19}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(1, Arg1, find(Arg0)); }
	void test_case_2() { int Arr0[] = {4, 1, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, find(Arg0)); }
	void test_case_3() { int Arr0[] = {4, 16, 16, 16}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(3, Arg1, find(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    TheSoccerDivOne ___test; 
    ___test.run_test(3);
} 
// END CUT HERE
