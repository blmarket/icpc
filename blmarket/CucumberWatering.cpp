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

typedef map<pair<int,int>, long long> memo_t;
memo_t memo;
vector<int> xs,x;

long long solve(int prev, int life)
{
    memo_t::iterator iter = memo.find(mp(prev, life));
    if(iter != memo.end()) return iter->second;

    if(life == 0)
    {
        long long ret = 0;
        for(int i=0;i+1<size(x);i++)
        {
            int p1 = x[i];
            int p2 = x[i+1];
            if(p1 > p2) swap(p1, p2);
            if(p2 <= xs[prev]) continue;
            if(p1 >= xs[prev]) 
            {
                ret += p2-p1;
                continue;
            }
            ret += p2 - xs[prev];
        }
        cout << prev << " " << life << " = " << ret << endl;
        return memo[mp(prev, life)] = ret;
    }

    long long ret = -1;
    for(int i=prev+1;i<=size(xs) - life;i++)
    {
        long long tmp = solve(i, life-1);
        cout << "::" << prev << " " << life << " " << i << " = " << tmp << endl;
        for(int j=0;j+1<size(x);j++)
        {
            int p1 = x[j];
            int p2 = x[j+1];
            if(p1 > p2) swap(p1,p2);
            if(p2 <= xs[prev]) continue;
            if(p1 >= xs[i]) continue;
            if(p2 >= xs[i])
            {
                cout << "::::" << p1 << " " << p2 << " =a " << xs[i] - p1 << endl;
                tmp += min(xs[i] - p1, p1 - xs[prev]);
                continue;
            }
            if(p1 <= xs[prev])
            {
                cout << "::::" << p1 << " " << p2 << " =b " << p2 - xs[prev] << endl;
                tmp += min(p2 - xs[prev], xs[i] - p2);
                continue;
            }
            cout << "::::" << p1 << " " << p2 << endl;
            int c1 = p2 - p1;
            int c2 = (p1 - xs[prev]) + (xs[i] - p2);
            cout << "::::" << c1 << " " << c2 << endl;
            tmp += min(c1,c2);
        }
        if(ret < 0 || ret > tmp) ret = tmp;
    }

    cout << prev << " " << life << " = " << ret << endl;
    return memo[mp(prev,life)] = ret;
}

class CucumberWatering 
{
public:
	long long theMin(vector <int> x_, int K) 
	{
            x = xs = x_;
            sort(xs.begin(), xs.end());

            if(K >= size(xs)) return 0;
            if(K == 0) K = 1;

            solve(-1,K);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0, 6, 8, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; long long Arg2 = 6LL; verify_case(0, Arg2, theMin(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {-1000000000, 1000000000, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; long long Arg2 = 3000000000LL; verify_case(1, Arg2, theMin(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {58, 2012}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 50; long long Arg2 = 0LL; verify_case(2, Arg2, theMin(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {9, -3, 14, 6, 5, -9, 32, 7, -5, 26, 2, 11}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; long long Arg2 = 58LL; verify_case(3, Arg2, theMin(Arg0, Arg1)); }

// END CUT HERE

};



// BEGIN CUT HERE 
int main() {
	CucumberWatering ___test;
	___test.run_test(0);
}
// END CUT HERE
