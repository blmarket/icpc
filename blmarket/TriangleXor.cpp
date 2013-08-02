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

class TriangleXor 
{
public:
    int theArea(int W) 
    {
        double ret = 0;
        double area = 0;
        for(int i=1;i<=W;i++) {
            double xpos = (double)W * i / (W + i);
            double px = (double)W * (i-1) / (W + i - 1);
            if((i%2) == 1) {
                cout << xpos << " " << px << endl;
                area += (double)(xpos-px) / 2;
            }
        }

        cout << area << endl;

        int nc = W-1;
        for(int i=1;;i++) {
            if(nc <= 0) break;
            double y1 = (double)i / (W + i);
            double y0 = (double)(i-1) / (W + i-1);
            double xspace = W / (W+(i+1)/2);
            cout << y1 << " " << y0 << " " << nc << " " << xspace << endl;
            ret += (y1-y0) / 2 * nc * W / (W + (i+1)/2);
            if((i%2) == 0) nc -= 2;
        }

        if((W%2)==0) {
            ret += (double)W / 4;
        }
        ret += area * 2;
        cout << area << " " << ret << endl;
        return ret;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 0; verify_case(0, Arg1, theArea(Arg0)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 1; verify_case(1, Arg1, theArea(Arg0)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 1; verify_case(2, Arg1, theArea(Arg0)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 2; verify_case(3, Arg1, theArea(Arg0)); }
	void test_case_4() { int Arg0 = 5; int Arg1 = 2; verify_case(4, Arg1, theArea(Arg0)); }
	void test_case_5() { int Arg0 = 12345; int Arg1 = 4629; verify_case(5, Arg1, theArea(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    TriangleXor ___test; 
    ___test.run_test(4); 
} 
// END CUT HERE
