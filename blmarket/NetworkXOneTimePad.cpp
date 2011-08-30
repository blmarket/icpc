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
typedef long long LL;

template<typename T> int size(const T &a) { return a.size(); }

vector<LL> plain, cip;

void enc(const vector<string> &plaintexts, vector<LL> &plain)
{
    for(int i=0;i<size(plaintexts);i++)
    {
        LL tmp = 0;
        for(int j=0;j<size(plaintexts[i]);j++)
            if(plaintexts[i][j] == '1') tmp |= (1LL << j);
        plain.pb(tmp);
    }
}

bool check(LL key)
{
    for(int i=0;i<size(cip);i++)
    {
        LL kk = cip[i] ^ key;
        int idx = lower_bound(plain.begin(),plain.end(),kk) - plain.begin();
        if(idx == size(plain)) return false;
        if(plain[idx] != kk) return false;
    }
    return true;
}

class NetworkXOneTimePad 
{
public:
    int crack(vector <string> plaintexts, vector <string> ciphertexts) 
    {	
        plain.clear(); cip.clear();
        enc(plaintexts, plain);
        enc(ciphertexts, cip);
        sort(plain.begin(), plain.end());

        if(cip.size() == 1) return plain.size();

        vector<LL> css;

        for(int i=0;i<size(cip);i++)
        {
            for(int j=i+1;j<size(cip);j++)
            {
                LL xxx = cip[i] ^ cip[j];
                for(int k=0;k<size(plain);k++)
                {
                    LL yyy = xxx ^ plain[k];
                    int idx = lower_bound(plain.begin(), plain.end(), yyy) - plain.begin();
                    if(idx == plain.size()) continue;
                    if(plain[idx] != yyy) continue;
                    LL k1 = cip[i] ^ plain[k];
                    if(check(k1)) css.pb(k1);
                    k1 = cip[i] ^ yyy;
                    if(check(k1)) css.pb(k1);
                }
            }
        }
        sort(css.begin(), css.end());
        return unique(css.begin(),css.end()) - css.begin();
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"110", "001"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"101", "010"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(0, Arg2, crack(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"00", "01", "10", "11"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"00", "01", "10", "11"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(1, Arg2, crack(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"01", "10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"00"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(2, Arg2, crack(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"000", "111", "010", "101", "110", "001"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"011", "100"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; verify_case(3, Arg2, crack(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    NetworkXOneTimePad ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
