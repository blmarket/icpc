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

map<long long, int> M;

class ColorfulCoins 
{
public:
    int minQueries(vector<long long> values) 
    {		
        M.clear();
        for(int i=0;i+1<size(values);i++) {
            long long dim = values[i+1] / values[i];
            M[dim] += 1;
        }

        for(auto it : M) {
            cout << it.first << " " << it.second << " - ";
        }
        cout << endl;

        int ret = 1;
        int acc = 1;

        for(auto it : M) {
            acc += it.second;

            long long pow = 1;
            for(int i=0;;i++) {
                pow *= it.first;
                if(i+1 > ret) ret = i+1;
                if(pow >= acc) {
                    break;
                }
            }
        }
        return ret;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long Arr0[] = {1}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, minQueries(Arg0)); }
	void test_case_1() { long Arr0[] = {1, 3}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, minQueries(Arg0)); }
	void test_case_2() { long Arr0[] = {1, 2, 4}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, minQueries(Arg0)); }
	void test_case_3() { long Arr0[] = {1, 2, 4, 8, 16}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(3, Arg1, minQueries(Arg0)); }
	void test_case_4() { long Arr0[] = {1, 2, 6, 30, 90, 270, 810, 2430, 7290, 29160, 87480, 262440, 787320, 3149280,
  9447840, 28343520, 56687040, 170061120, 510183360, 1530550080, 3061100160,
  9183300480, 27549901440, 82649704320, 247949112960, 1239745564800, 3719236694400,
  14876946777600, 44630840332800, 223154201664000, 669462604992000, 2008387814976000,
  6025163444928000, 12050326889856000, 24100653779712000, 72301961339136000,
  289207845356544000, 867623536069632000}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(4, Arg1, minQueries(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    ColorfulCoins ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
