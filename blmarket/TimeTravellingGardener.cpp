#include <iostream>
#include <cmath>
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

inline void setmax(int &a,int b) { if(a<b) a=b; }

vector<int> dista;
vector<int> height;

int ccw(PII a, PII b, PII c)
{
    double y = (double)(b.second - a.second) / (b.first - a.first) * (c.first - a.first) + a.second;
    if(y < -1e-6) return -1;
    cout << y << " " << c.second << endl;
    if(y > c.second + 1e-6) return -1;
    if(fabs(y-c.second) < 1e-6) return 0;
    return 1;
}

int check(const PII &a, const PII &b)
{
    int ret = 0;
    PII c;

    if(ccw(a,b,mp(0,0)) < 0) return 1;

    for(int i=0;i<size(height);i++)
    {
        c.second = height[i];
        if(ccw(a,b,c) == 0) ret++;

        if(i+1 < size(height))
            c.first += dista[i];
    }

    c.second = 0;
    if(ccw(a,b,c) < 0) return 1;
    return ret;
}

class TimeTravellingGardener 
{
public:
    int determineUsage(vector <int> dista_, vector <int> height_) 
    {
        dista = dista_;
        height = height_;
        int ret = 0;
        int n = size(height);
        int pos = 0;
        for(int i=0;i<n;i++) 
        {
            int h1 = height[i];
            int dist = dista[i];
            for(int j=i+1;j<n;j++)
            {
                int h2 = height[j];
                setmax(ret, check(mp(pos, h1), mp(pos+dist, h2)));
                dist += dista[j];
            }
            pos += dista[i];
        }

        return n - ret;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,3,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(0, Arg2, determineUsage(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {3,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3,1,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(1, Arg2, determineUsage(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4,4,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(2, Arg2, determineUsage(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {4,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {9,8,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(3, Arg2, determineUsage(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {476,465,260,484}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {39,13,8,72,80}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(4, Arg2, determineUsage(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {173,36,668,79,26,544}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {488,743,203,446,444,91,453}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(5, Arg2, determineUsage(Arg0, Arg1)); }
	void test_case_6() { int Arr0[] = {2,4,2,2,4,2,4,2,2,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,2,10,10,10,16,16,22,22,28,28}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; verify_case(6, Arg2, determineUsage(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    TimeTravellingGardener ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
