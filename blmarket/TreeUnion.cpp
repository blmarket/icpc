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

int dist1[305][305], dist2[305][305];
int dd1[305], dd2[305];
int N;

void build(vector<string> &vs, int tgt[][305], int *rr) {
    string str;
    for(int i=0;i<size(vs);i++) str += vs[i];
    istringstream sin(str);
    int tmp;
    int i = 0;
    while(sin >> tmp) {
        tgt[i+1][tmp] = tgt[tmp][i+1] = 1;
        i++;
    }
    N = i + 1;

    for(int k=0;k<N;k++) for(int i=0;i<N;i++) if(tgt[i][k] != -1) {
        for(int j=0;j<N;j++) if(tgt[k][j] != -1) {
            if(tgt[i][j] == -1 || tgt[i][j] > tgt[i][k] + tgt[k][j]) {
                tgt[i][j] = tgt[i][k] + tgt[k][j];
            }
        }
    }

    for(int i=0;i<N;i++) for(int j=i+1;j<N;j++) {
        rr[tgt[i][j]]++;
    }
}

class TreeUnion 
{
public:
    double expectedCycles(vector <string> tree1, vector <string> tree2, int K) 
    {
        memset(dist1, -1, sizeof(dist1));
        memset(dist2, -1, sizeof(dist2));
        memset(dd1, 0, sizeof(dd1)); memset(dd2, 0, sizeof(dd2));
        build(tree1, dist1, dd1);
        build(tree2, dist2, dd2);

        long double cnts = 0;
        for(int i=1;i<N;i++) if(dd1[i]) {
            int tt = K - 2 - i;
            if(tt < 1) break;
            cout << i << " : " << dd1[i] << " " << dd2[tt] << endl;
            cnts += dd1[i] * dd2[tt] * 2;
        }
        cout << cnts << endl;

        cnts /= N * (N-1);

        
        cout << cnts << endl;
        return cnts;

    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; double Arg3 = 1.0; verify_case(0, Arg3, expectedCycles(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"0 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0 1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; double Arg3 = 1.3333333333333333; verify_case(1, Arg3, expectedCycles(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"0 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0 1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; double Arg3 = 0.3333333333333333; verify_case(2, Arg3, expectedCycles(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"0 ", "1 1 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0 1 0 ", "1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; double Arg3 = 4.0; verify_case(3, Arg3, expectedCycles(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"0 1 2 0 1 2 0 1 2 5 6 1", "0 11", " 4"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0 1 1 0 2 3 4 3 4 6 6", " 10 12 12"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 7; double Arg3 = 13.314285714285713; verify_case(4, Arg3, expectedCycles(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    TreeUnion ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
