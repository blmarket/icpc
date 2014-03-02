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

template<typename T> int size(const T &a) { return a.size(); }

const int mod = 1000000007;

int han[55];
bool visit[55];
int inv[55];
int n;
vector<int> ng;

int go(int a) {
    if(visit[a]) return 0;
    visit[a] = true;
    return go(han[a]) + 1;
}

long long gg(int pos, int place) {
    if(pos == size(ng)) return 1;
    long long nf = 1;
    long long bb = gg(pos+1, place - ng[pos]);

    long long ret = 0;

    for(int i=0;i<ng[pos];i++) {
        nf *= (place - i);
    }

    ret = (nf * bb) % mod;

    if(ng[pos] == 1) {
        return ret;
    }

    int tt = ng[pos];
    int nc = tt * (tt-1);

    ret *= (1 + ((long long)nc * inv[2]) % mod);
    ret %= mod;
    cout << pos << " " << place << " = " << ret << endl;
    return ret;
}

class TwoSidedCards 
{
public:
    int theCount(vector <int> taro, vector <int> hanako) 
    {
        inv[1] = 1;
        for(int i=2;i<55;i++) {
            inv[i] = ((long long)(mod / i + 1) * inv[i - (mod % i)]) % mod;
        }

        for(int i=0;i<size(taro);i++) {
            han[taro[i]] = hanako[i];
        }
        n = size(taro);

        memset(visit, 0, sizeof(visit));
        ng.clear();

        for(int i=1;i<=n;i++) if(!visit[i]) {
            int tmp = go(i);
            ng.pb(tmp);
        }

        long long nf = 1;
        for(int i=1;i<=n;i++) {
            nf = (nf * i) % mod;
        }

        return gg(0, n);
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 2, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 3, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 12; verify_case(0, Arg2, theCount(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1, 2, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; verify_case(1, Arg2, theCount(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(2, Arg2, theCount(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {5, 8, 1, 2, 3, 4, 6, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 3, 4, 5, 6, 7, 8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2177280; verify_case(3, Arg2, theCount(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {41, 22, 17, 36, 26, 15, 10, 23, 33, 48, 49, 9, 34, 6, 21, 2, 46, 16, 25, 3, 24, 13, 40, 37, 35,
50, 44, 42, 31, 12, 29, 7, 43, 18, 30, 19, 45, 32, 39, 14, 8, 27, 1, 5, 38, 11, 4, 20, 47, 28}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {19, 6, 23, 35, 17, 7, 50, 2, 33, 36, 12, 31, 46, 21, 30, 13, 47, 22, 44, 4, 25, 24, 3, 15, 20,
48, 10, 28, 26, 18, 5, 45, 49, 16, 40, 42, 43, 14, 1, 37, 29, 8, 41, 38, 9, 11, 34, 32, 39, 27}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 529165844; verify_case(4, Arg2, theCount(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    TwoSidedCards ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
