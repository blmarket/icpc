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

#define MOD 1000000007

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;
typedef long long LL;

template<typename T> int size(const T &a) { return a.size(); }

LL calc(const vector<int> &arr)
{
    LL ret = 0;
    for(int i=0;i<size(arr);i++)
        ret += i * arr[i];

    return ret;
}

class RowsOrdering 
{
public:
    int order(vector <string> rows) 
    {		
        vector<LL> ret;
        for(int i=0;i<size(rows[0]);i++)
        {
            map<char, int> M;
            for(int j=0;j<size(rows);j++)
                M[rows[j][i]] += 1;

            vector<int> tmp;
            foreach(it, M)
                tmp.pb(it->second);
            sort(tmp.rbegin(), tmp.rend());

            ret[i] = calc(tmp);
        }

        cout << size(ret) << endl;

        sort(ret.begin(), ret.end());
        LL rr = size(rows);
        for(int i=0;i<size(ret);i++)
        {
            rr = ((rr * 50) + ret[i]) % MOD;
        }
        return rr;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"bb", "cb", "ca"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 54; verify_case(0, Arg1, order(Arg0)); }
	void test_case_1() { string Arr0[] = {"abcd", "ABCD"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 127553; verify_case(1, Arg1, order(Arg0)); }
	void test_case_2() { string Arr0[] = {"Example", "Problem"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 943877448; verify_case(2, Arg1, order(Arg0)); }
	void test_case_3() { string Arr0[] = {"a", "b", "c", "d", "e", "f", "g"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 28; verify_case(3, Arg1, order(Arg0)); }
	void test_case_4() { string Arr0[] = {"a", "a"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(4, Arg1, order(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    RowsOrdering ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
