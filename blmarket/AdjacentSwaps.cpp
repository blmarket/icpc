#include <iostream>
#include <cstring>
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

const long long MOD = 1000000007LL;

template<typename T> int size(const T &a) { return a.size(); }

vector<int> p;
long long memo[55][55];

long long combi(int a, int b)
{
    long long ret = 1;
    for(int i=0;i<b;i++)
    {
        ret *= (a-i);
        ret /= (i+1);
    }
    return ret;
}

long long go(int left, int right)
{
    if(left+1 == right) return 1;
    long long &ret = memo[left][right];

    if(ret != -1) return ret;

    ret = 0;

    int n = right - left;

    for(int i=left;i+1<right;i++)
    {
        bool fail=false;
        int idx1, idx2;

        for(int j=left;j<=i;j++)
            if(p[j] > i+1) { fail = true; break; } else if(p[j] == i+1) { idx1 = j; }
        for(int j=i+1;j<right;j++)
            if(p[j] < i) { fail = true; break; } else if(p[j] == i) { idx2 = j; }

        if(!fail)
        {
            p[idx1]--;
            p[idx2]++;

            long long tmp1, tmp2;
            tmp1 = go(left, i+1);
            tmp2 = go(i+1, right);
            cerr << left << " " << right << " ==> " << i << " " << tmp1 << " " << tmp2 << endl;

            ret += tmp1 * combi(n-1, i-left) * tmp2;
            ret %= MOD;
            cerr << ret << endl;

            p[idx1]++;
            p[idx2]--;
        }
    }

    return ret;
}

class AdjacentSwaps 
{
public:
    int theCount(vector <int> p_) 
    {		
        memset(memo, -1, sizeof(memo));
        p = p_;
        return go(0, size(p));
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 2, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, theCount(Arg0)); }
	void test_case_1() { int Arr0[] = {0, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, theCount(Arg0)); }
	void test_case_2() { int Arr0[] = {2, 0, 3, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, theCount(Arg0)); }
	void test_case_3() { int Arr0[] = {1, 0, 3, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(3, Arg1, theCount(Arg0)); }
	void test_case_4() { int Arr0[] = {1, 3, 0, 5, 2, 7, 4, 8, 10, 6, 12, 9, 14, 11, 16, 13, 18, 15, 19, 17}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 716743312; verify_case(4, Arg1, theCount(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    AdjacentSwaps ___test; 
    ___test.run_test(1); 
} 
// END CUT HERE
