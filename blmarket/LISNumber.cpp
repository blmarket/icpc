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

int mod = 1000000007;
int dyna[2][1300];
int combi[1300][1300];

int h(int a, int b) {
    return combi[a+b-1][b];
}

class LISNumber 
{
public:
    int count(vector <int> cardsnum, int K) 
    {
        combi[0][0] = 1;
        for(int i=1;i<1300;i++) {
            combi[i][0] = combi[i][i] = 1;
            for(int j=1;j<i;j++) combi[i][j] = (combi[i-1][j-1] + combi[i-1][j]) % mod;
        }

        memset(dyna, 0, sizeof(dyna));
        dyna[0][0] = 1;

        int ret;
        for(int i=0;i<size(cardsnum);i++) {
            int it = *(cardsnum.rbegin() + i);
            int cur = i%2;
            int nex = 1-cur;

            memset(dyna[nex], 0, sizeof(dyna[nex]));
            cout << "turn " << i << endl;

            for(int j=0;j<=K;j++) {
                for(int k=j;k<=j+it;k++) {
                    if(k < it) continue;
                    int ng = k - j;
                    long long c1 = combi[j][it - ng];
                    long long c2 = h(j+1, k-j);
                    cout << j << " " << k << " : " << c1 << " " << c2 << " : " << dyna[cur][j] << " " << dyna[nex][k] << endl;
                    c1 = (c1 * c2) % mod;
                    long long sum = dyna[nex][k] + c1 * dyna[cur][j];
                    sum %= mod;
                    dyna[nex][k] = sum;
                }
            }
            for(int j=0;j<=20;j++) {
                cout << dyna[nex][j] << " ";
            }
            cout << endl;

            ret = dyna[nex][K];
        }
        return ret;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 4; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 0; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {36, 36, 36, 36, 36}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 36; int Arg2 = 1; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {3, 2, 11, 5, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 20; int Arg2 = 474640725; verify_case(3, Arg2, count(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {31, 4, 15, 9, 26, 5, 35, 8, 9, 7, 9, 32, 3, 8, 4, 6, 26}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 58; int Arg2 = 12133719; verify_case(4, Arg2, count(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {27, 18, 28, 18, 28, 4, 5, 9, 4, 5, 23, 5,
 36, 28, 7, 4, 7, 13, 5, 26, 6, 24, 9, 7,
 7, 5, 7, 24, 7, 9, 36, 9, 9, 9, 5, 9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 116; int Arg2 = 516440918; verify_case(5, Arg2, count(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    LISNumber ___test; 
    ___test.run_test(0); 
} 
// END CUT HERE
