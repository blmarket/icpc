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

map<string, int> makeit(const vector<string> &in)
{
    int n = size(in[0]);
    map<string, int> ret;
    for(int i=0;i<n;i++)
    {
        string tmp;
        for(int j=0;j<size(in);j++)
        {
            tmp += in[j][i];
        }
        ret[tmp]++;
    }
    return ret;
}

class SwitchesAndLamps 
{
public:
	int theMin(vector <string> switches, vector <string> lamps) 
	{
            map<string, int> m1 = makeit(switches);
            map<string, int> m2 = makeit(lamps);
            if(m1 != m2) return -1;
            int maxx = 0;
            foreach(it, m1)
            {
                maxx = max(maxx, it->second);
            }

            int ret = 0;
            while(maxx > 1)
            {
                ret++;
                maxx = (maxx + 1) / 2;
            }
            return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"NYNN", "NNYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NNNY", "NNYN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(0, Arg2, theMin(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"YYN", "YNY", "YYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"YNY", "NYY", "YNY"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(1, Arg2, theMin(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"NYYYNYNNYYYNYNNNNY", "NYYYNYNNYYYNYNNNNY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"YYYNNNYNNYNYNYNYNY", "YYYNNNYNNYNYYNNYNY"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(2, Arg2, theMin(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"YYNNN", "NNYYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NYNNY", "NNNYY"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(3, Arg2, theMin(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"YNNYNNYNYY", "NYNNYNYNYN", "YNYNYYYYYN", "NNYYNYNYNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NYYNYNNYNY", "NYYYNNYNNN", "YYYYNYNNYY", "YNNNNYNYYN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(4, Arg2, theMin(Arg0, Arg1)); }

// END CUT HERE

};



// BEGIN CUT HERE 
int main() {
	SwitchesAndLamps ___test;
	___test.run_test(-1);
}
// END CUT HERE
