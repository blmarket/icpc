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
typedef long long LL;

template<typename T> int size(const T &a) { return a.size(); }

int N;
vector<string> S;
int cnts[55][30];

bool go(int a, LL life, int cards) {
    if(life == 0) return true;
    if(cards == 0) return false;

    for(int i=0;i<26;i++) if(cards & (1<<i)) {
        if(cnts[a][i] == 0) continue;
        bool good = true;
        for(int j=0;j<N;j++) if(life & (1LL << j)) {
            if(cnts[j][i] > cnts[a][i]) {
                good = false;
                break;
            }
        }
        if(good) {
            cout << a << " " << i << endl;
            LL newlife = 0;
            for(int j=0;j<N;j++) if(life & (1LL << j)) {
                if(cnts[j][i] == cnts[a][i]) {
                    newlife |= (1LL << j);
                }
            }
            return go(a, newlife, cards ^ (1<<i));
        }
    }
    return false;
}

bool check(int a) {
    int cards = (1<<26)-1;
    long long life = (1LL << size(S)) - 1;

    life ^= (1LL << a);

    return go(a, life, cards);
}

class StringGame 
{
public:
    vector <int> getWinningStrings(vector <string> S_) 
    {
        S = S_; N = size(S);
        memset(cnts, 0, sizeof(cnts));
        for(int i=0;i<size(S);i++) {
            for(int j=0;j<size(S[i]);j++) {
                cnts[i][S[i][j] - 'a']++;
            }
        }
        vector<int> ret;
        for(int i=0;i<size(S);i++) {
            if(check(i)) ret.pb(i);
        }
        return ret;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"a", "b", "c", "d"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1, 2, 3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getWinningStrings(Arg0)); }
	void test_case_1() { string Arr0[] = {"aabbcc", "aaabbb", "aaaccc"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getWinningStrings(Arg0)); }
	void test_case_2() { string Arr0[] = {"ab", "ba"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getWinningStrings(Arg0)); }
	void test_case_3() { string Arr0[] = {"xaocxsss", "oooxsoas", "xaooosss", "xaocssss", "coxaosxx"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 3, 4 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, getWinningStrings(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    StringGame ___test; 
    ___test.run_test(0); 
} 
// END CUT HERE
