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

vector<PII> links;

class BunnyExam 
{
public:
    double getExpected(int m, int k, vector <int> linkage) 
    {		
        if(m > 1 && k == 1) return -1;
        for(int i=0;i<size(linkage);i+=2)
        {
            if(linkage[i] > linkage[i+1])
                swap(linkage[i], linkage[i+1]);
            links.pb(mp(linkage[i], linkage[i+1]));
        }

        if(k == 2)
        {
            for(int i=0;i<size(links);i++)
            {
                if((links[i].first + links[i].second) % 2) return -1;
            }
        }

        for(int i=0;i<size(links);i++)
        {
            cout << links[i].first << " " << links[i].second << endl;
            if(links[i].second == links[i].first + 1) return -1;
        }

        return (double)m/k;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 2; int Arr2[] = { 1, 3 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 1.5; verify_case(0, Arg3, getExpected(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 2; int Arr2[] = { 1, 4 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = -1.0; verify_case(1, Arg3, getExpected(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 8; int Arr2[] = { }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 0.25; verify_case(2, Arg3, getExpected(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 1000000000; int Arg1 = 1; int Arr2[] = { 11, 13, 2010, 487 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = -1.0; verify_case(3, Arg3, getExpected(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 128; int Arg1 = 64; int Arr2[] = { 32, 16, 8, 4, 2, 1 }
; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = -1.0; verify_case(4, Arg3, getExpected(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 13; int Arg1 = 3; int Arr2[] = { 1, 3, 7, 9, 13, 10, 6, 2  }
; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 4.333333333333333; verify_case(5, Arg3, getExpected(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    BunnyExam ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
