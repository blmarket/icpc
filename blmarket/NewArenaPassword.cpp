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

class NewArenaPassword 
{
public:
    int minChange(string old, int K) 
    {
        int n = old.size(),ans=0,ans1=0,ans2=0,ans3=0;
        string old1=old,old2=old,old3=old;
        for(int i=K-1;i>=0;i--) if(old[i] != old[n-K+i]) { old[n-K+i] = old[i]; ans++; }
        for(int i=K-1;i>=0;i--) if(old2[i] != old2[n-K+i]) { old2[i] = old2[n-K+i]; ans2++; }
        for(int i=0;i<K;i++) if(old1[i] != old1[n-K+i]) { old1[i] = old1[n-K+i]; ans1++; }
        for(int i=0;i<K;i++) if(old3[i] != old3[n-K+i]) { old3[n-K+i] = old3[i]; ans3++; }

        cout << ans << " " << ans1 << " " << ans2 << " " << ans3 << endl;

        return min(min(ans, ans1), min(ans2, ans3));
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "topcoderopen"; int Arg1 = 5; int Arg2 = 3; verify_case(0, Arg2, minChange(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "puyopuyo"; int Arg1 = 4; int Arg2 = 0; verify_case(1, Arg2, minChange(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "loool"; int Arg1 = 3; int Arg2 = 1; verify_case(2, Arg2, minChange(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "arena"; int Arg1 = 5; int Arg2 = 0; verify_case(3, Arg2, minChange(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "bacbacbabacsbabacbabasbabacbabacbacbababcabaababcb"; int Arg1 = 49; int Arg2 = 30; verify_case(4, Arg2, minChange(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    NewArenaPassword ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
