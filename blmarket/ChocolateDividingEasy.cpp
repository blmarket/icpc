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

int N, M;
int ret = 0;

bool check(vector<int> V[3], int t) {
    int acc[3] = {0,0,0};
    int cc = 0;
    for(int i=0;i<M;i++) {
        for(int j=0;j<3;j++) acc[j] += V[j][i];
        if(acc[0] >= t && acc[1] >= t && acc[2] >= t) {
            if(++cc == 3) return true;
            memset(acc, 0, sizeof(acc));
        }
    }
    return false;
}

void maxcut(vector<int> V[3]) {
    int s = ret;
    int e = 2505;

    while(s < e) {
        int m = (s+e) / 2;
        if(check(V, m)) {
            ret = m;
            s = m + 1;
        } else {
            e = m;
        }
    }
}

class ChocolateDividingEasy 
{
public:
    int findBest(vector <string> chocolate) 
    {		
        N = size(chocolate);
        M = size(chocolate[0]);

        ret = 0;
        vector<int> sum(M);
        for(int i=0;i<N;i++) {
            for(int j=0;j<M;j++) {
                chocolate[i][j] -= '0';
                sum[j] += chocolate[i][j];
            }
        }

        vector<int> acc[3];

        acc[0].resize(M);
        for(int i=0;i<N;i++) {
            for(int j=0;j<M;j++) {
                acc[0][j] += chocolate[i][j];
            }
            acc[1] = vector<int>(M, 0);
            for(int j=i+1;j<N;j++) {
                acc[2] = sum;
                for(int k=0;k<M;k++) {
                    acc[1][k] += chocolate[j][k];
                    acc[2][k] -= acc[0][k] + acc[1][k];
                }
                maxcut(acc);
            }
        }

        return ret;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {
"9768",
"6767",
"5313"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, findBest(Arg0)); }
	void test_case_1() { string Arr0[] = {
"36753562",
"91270936",
"06261879",
"20237592",
"28973612",
"93194784"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 15; verify_case(1, Arg1, findBest(Arg0)); }
	void test_case_2() { string Arr0[] = {
"012",
"345",
"678"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, findBest(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    ChocolateDividingEasy ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
