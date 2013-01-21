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

int cnt[90000];

class TheSquareRootDilemma 
{
public:
    int countPairs(int N, int M) 
    {
        memset(cnt, 0, sizeof(cnt));
        int ret = 0;
        vector<int> sqrs;
        for(int i=1;i*i<=77777;i++) {
            sqrs.pb(i*i);
        }

        for(int i=1;i<=100;i++) {
            int tmp = i;
            for(int j=1;j<size(sqrs);j++) {
                if(tmp < sqrs[j]) break;
                while((tmp % sqrs[j]) == 0) {
                    tmp /= sqrs[j];
                }
            }
            cout << i << " = " << tmp << endl;

            for(int j=0;j<size(sqrs);j++) {
                int tmp2 = tmp * sqrs[j];
                if(tmp2 > M) break;
                cout << i << " " << tmp2 << endl;
                ret++;
            }
        }

        if(false) {
            int ret2 = 0;
            for(int i=1;i<=N;i++) {
                for(int j=1;j<=M;j++) {
                    int tmp = i*j;
                    for(int k=0;k<size(sqrs);k++) {
                        if(tmp == sqrs[k]) {
                            cout << i << " " << j << endl;
                            ret2++;
                            break;
                        }
                    }
                }
            }
            cout << ret2 << endl;
        }

        return ret;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 2; verify_case(0, Arg2, countPairs(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 1; int Arg2 = 3; verify_case(1, Arg2, countPairs(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 8; int Arg2 = 5; verify_case(2, Arg2, countPairs(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 100; int Arg1 = 100; int Arg2 = 310; verify_case(3, Arg2, countPairs(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    TheSquareRootDilemma ___test; 
    ___test.run_test(3); 
} 
// END CUT HERE
