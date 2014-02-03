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

string S;

double palins[5005][5005];

class PalindromicSubstringsDiv1 
{
public:
    double expectedPalindromes(vector <string> S1, vector <string> S2) 
    {		
        for(int i=0;i<size(S1);i++) S += S1[i];
        for(int i=0;i<size(S2);i++) S += S2[i];

        double ret = 0;

        for(int i=0;i<size(S);i++) {
            palins[i][i+1] = 1.0;
            ret += 1.0;
        }

        for(int i=0;i+1<size(S);i++) {
            if(S[i] == '?' || S[i+1] == '?') {
                palins[i][i+2] = 1.0 / 26;
            } else {
                if(S[i] == S[i+1]) {
                    palins[i][i+2] = 1.0;
                } else {
                    palins[i][i+2] = 0.0;
                }
            }
            ret += palins[i][i+2];
        }

        for(int i=3;i<=size(S);i++) {
            for(int j=0;j+i<=size(S);j++) {
                int k = j + i;
                double &tgt = palins[j][k];
                const double &pp = palins[j+1][k-1];
                if(S[j] == '?' || S[k-1] == '?') {
                    tgt += pp / 26;
                } else {
                    if(S[j] == S[k-1]) {
                        tgt = pp;
                    } else {
                        tgt = 0;
                    }
                }
                ret += tgt;
            }
        }

        return ret;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"a","a",""}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"a"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 6.0; verify_case(0, Arg2, expectedPalindromes(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"z??"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 3.115384615384615; verify_case(1, Arg2, expectedPalindromes(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"ab","c"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"??","a?"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 7.315088757396449; verify_case(2, Arg2, expectedPalindromes(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"?"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 1.0; verify_case(3, Arg2, expectedPalindromes(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"ab?def","?"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"f??a"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 12.545971779699588; verify_case(4, Arg2, expectedPalindromes(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    PalindromicSubstringsDiv1 ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
