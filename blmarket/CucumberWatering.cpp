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

vector<int> x;
vector<int> xs;
vector<int> idxs;
vector<int> move;
int n;

long long go2(int pos, long long mask)
{
    int near[55];
    int last = -1;
    for(int i=0;i<n;i++)
    {
        if(mask & (1LL << i))
            last = i;
        if(last != -1)
            near[i] = xs[i] - xs[last];
        else
            near[i] = -1;
    }

    last = -1;
    for(int i=n-1;i>=0;i--)
    {
        if(mask & (1LL << i))
            last = i;
        if(last != -1)
        {
            int tmp = xs[last] - xs[i];
            if(near[i] == -1 || near[i] > tmp) near[i] = tmp;
        }
    }

    cout << "nears : ";
    for(int i=0;i<n;i++) cout << near[i] << " ";
    cout << endl;

    long long ret = 0;
    for(int i=0;i+1<size(idxs);i++)
    {
        int p1 = xs[idxs[i]];
        int p2 = xs[idxs[i+1]];
        int dist = abs(p2-p1);
        if(dist > near[idxs[i]] + near[idxs[i+1]])
        {
            dist = near[idxs[i]] + near[idxs[i+1]];
        }
        ret += dist;
    }
    return ret;
}

long long go(int pos, long long mask, int life)
{
    cout << pos << " " << mask << " " << life << endl;
    if(pos == n) return go2(0, mask);
    long long ret = - 1;
    if(n-pos == life) return go(pos+1, (mask << 1) | 1, life-1);
    ret = go(pos+1, mask<<1, life);
    if(life) ret = min(ret, go(pos+1, (mask<<1) | 1, life-1));
    return ret;
}

class CucumberWatering 
{
public:
	long long theMin(vector <int> _x, int K) 
	{
            x = _x;
            n = size(x);
            if(K > size(x)) K = size(x);
            xs = x;
            sort(xs.begin(), xs.end());
            for(int i=0;i<size(x);i++)
            {
                for(int j=0;j<size(xs);j++)
                    if(x[i] == xs[j]) { idxs.pb(j); break; }
            }

            if(K < 2)
            {
                long long ret = 0;
                for(int i=0;i+1<size(x);i++)
                    ret += abs(x[i+1] - x[i]);
                return ret;
            }

            return go(0, 0, K);
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
	___test.run_test(-1);
}
// END CUT HERE
