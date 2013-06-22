#include <iostream>
#include <cmath>
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

int N,M;
int A[22][22];
int total = 0;
int B[22];
double EE[1<<21];

double calc(int state) {
    if(EE[state] >= 0) return EE[state];
    int nsame = 0;
    double ret = 1;
    for(int i=0;i<M;i++) if(state & (1<<i)) {
        nsame += B[i];
    } else {
        ret += (double)B[i] / total * calc(state | (1<<i));
    }
    ret *= (double)total / (total - nsame);

    return EE[state] = ret;
}

class RandomPaintingOnABoard 
{
public:
    double expectedSteps(vector <string> prob) 
    {
        N = size(prob); M = size(prob[0]);
        if(N <= M) {
            for(int i=0;i<N;i++) for(int j=0;j<M;j++) A[i][j] = prob[i][j] - '0';
        } else {
            for(int i=0;i<N;i++) for(int j=0;j<M;j++) A[j][i] = prob[i][j] - '0';
            swap(N, M);
        }
        total = 0;
        for(int i=0;i<N;i++) for(int j=0;j<M;j++) total += A[i][j];

        double ret = 0;
        for(int i=0;i<(1<<N);i++) {
            int cnt = 0;
            memset(B, 0, sizeof(B));
            for(int j=0;j<N;j++) if(i & (1<<j)) {
                cnt++;
                for(int k=0;k<M;k++) {
                    B[k] += A[j][k];
                }
            }

            bool fail = false;
            for(int i=0;i<M;i++) if(B[i] == 0) { fail=true; break; }
            if(fail) continue;

            for(int j=0;j<(1<<M);j++) EE[j] = -1;
            EE[(1<<M)-1] = 0;
            double tmp = calc(0);
            ret += tmp * (cnt&1)?1:-1;
            cout << tmp << " " << ret << endl;
        }
        return fabs(ret);
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"10",
 "01"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 3.0; verify_case(0, Arg1, expectedSteps(Arg0)); }
	void test_case_1() { string Arr0[] = {"11",
 "11"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 3.6666666666666665; verify_case(1, Arg1, expectedSteps(Arg0)); }
	void test_case_2() { string Arr0[] = {"11",
 "12"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 3.9166666666666665; verify_case(2, Arg1, expectedSteps(Arg0)); }
	void test_case_3() { string Arr0[] = {"0976",
 "1701",
 "7119"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 11.214334077031307; verify_case(3, Arg1, expectedSteps(Arg0)); }
	void test_case_4() { string Arr0[] = {"000000000000001000000",
 "888999988889890999988",
 "988889988899980889999",
 "889898998889980999898",
 "988889999989880899999",
 "998888998988990989998",
 "998988999898990889899"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 1028.7662876159634; verify_case(4, Arg1, expectedSteps(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    RandomPaintingOnABoard ___test; 
    ___test.run_test(0); 
} 
// END CUT HERE
