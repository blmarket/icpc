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

const long long mod = 1000000007LL;

long long cnt[2][100000];

class Nine 
{
public:
    int count(int N, vector <int> d) 
    {
        memset(cnt, 0, sizeof(cnt));
        cnt[0][0] = 1;
        for(int i=0;i<size(d);i++) {
            int cur = (i%2);
            int nex = !cur;
            memset(cnt[nex], 0, sizeof(cnt[0]));
            int v[5];
            for(int j=0;j<100000;j++) if(cnt[i][j]) {
                int jj = j;
                cout << i << " ";
                for(int k=0;k<N;k++) {
                    v[k] = (jj % 9);
                    cout << v[k] << ",";
                    jj /= 9;
                }
                cout << " = " << cnt[i][j] << endl;

                for(int k=0;k<10;k++) {
                    for(int a=0;a<N;a++) if(d[i] & (1<<a)) {
                        v[a] = (v[a] + k) % 9;
                    }
                    int kk = 0;
                    for(int a=N-1;a>=0;a--) {
                        kk *= 9;
                        kk += v[a];
                    }
                    // cout << kk << endl;
                    cnt[nex][kk] = (cnt[nex][kk] + cnt[i][j]) % mod;
                    for(int a=0;a<N;a++) if(d[i] & (1<<a)) {
                        v[a] = (v[a] + 9 - k) % 9;
                    }
                }

            }
        }
        int cc = size(d) % 2;
        return cnt[cc][0];
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arr1[] = {1,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arr1[] = {1,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 16; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1; int Arr1[] = {0,0,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 200; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 5; int Arr1[] = {1,3,5,8,24,22,25,21,30,2,4,0,6,7,9,11,14,13,12,15,18,17,16,19,26,29,31,28,27,10,20,23}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 450877328; verify_case(3, Arg2, count(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 5; int Arr1[] = {31,31,31,31,31}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 11112; verify_case(4, Arg2, count(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    Nine ___test; 
    ___test.run_test(0); 
} 
// END CUT HERE
