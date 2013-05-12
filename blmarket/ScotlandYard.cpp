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
typedef long long LL;

template<typename T> int size(const T &a) { return a.size(); }

int N;
vector<string> m[3];
vector<LL> mm[3];
set<LL> cur, n[3];

bool try_move(int a) {
    n[a].clear();
    foreach(it, cur) {
        LL pos = *it;
        LL next = 0;
        for(int i=0;i<N;i++) if(pos & (1LL << i)) {
            next |= mm[a][i];
        }
        if(next == 0) continue;
        n[a].insert(next);
    }
    if(n[a].size() == 0) {
        return false;
    }
    if(n[a].size() == 1) {
        LL tmp = *(n[a].begin());
        if((tmp & (tmp-1)) == 0) {
            n[a].clear();
        }
    }
    return true;
}

class ScotlandYard 
{
public:
    int maxMoves(vector <string> taxi, vector <string> bus, vector <string> metro) 
    {
        N = size(taxi);
        m[0] = taxi; m[1] = bus; m[2] = metro;
        for(int i=0;i<3;i++) {
            mm[i].resize(N);
            for(int j=0;j<N;j++) {
                mm[i][j] = 0;
                for(int k=0;k<N;k++) {
                    if(m[i][j][k] == 'Y') mm[i][j] |= (1LL << k);
                }
            }
        }
        cur.insert((1LL << N) - 1);

        for(int t=0;t<100000;t++) {
            bool hasmove = false;
            for(int i=0;i<3;i++) {
                hasmove |= try_move(i);
                cout << i << endl;
                foreach(it, n[i]) {
                    for(int j=0;j<N;j++) if(*it & (1LL << j)) cout << "1"; else cout << "0";
                    cout << endl;
                }
            }
            if(!hasmove) return t;

            cur.swap(n[0]);
            for(int i=1;i<3;i++) foreach(it, n[i]) cur.insert(*it);
            cout << endl;
            if(size(cur) == 0) return t+1;
        }
        return -1;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"NYN",
 "NNY",
 "NNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NNN",
 "NNN",
 "NNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"NNN",
 "NNN",
 "NNN"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(0, Arg3, maxMoves(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"NYY",
 "NNN",
 "NNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NNN",
 "NNN",
 "NNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"NNN",
 "NNN",
 "NNN"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(1, Arg3, maxMoves(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"NYYY",
 "YNYY",
 "YYNY",
 "YYYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NNNN",
 "NNNN",
 "NNNN",
 "NNNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"NNNN",
 "NNNN",
 "NNNN",
 "NNNN"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -1; verify_case(2, Arg3, maxMoves(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"NNY",
 "NNY",
 "NNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NYN",
 "NNY",
 "NNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"NNN",
 "NNN",
 "YNN"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(3, Arg3, maxMoves(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"NNN",
 "YNY",
 "NNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NNN",
 "YNN",
 "YNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"NNN",
 "NNN",
 "YYN"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -1; verify_case(4, Arg3, maxMoves(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arr0[] = {"NNNNYNNNYY",
 "NNYNNYYYYY",
 "NNNNNNNNNN",
 "YYNNYYNNNY",
 "NNYNNNNNNN",
 "YNYNYNNNYN",
 "NNYNYNNNYN",
 "NNNNNNYNNN",
 "NNNNNNNNNN",
 "NNNNNNYNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NNYNNNYNNY",
 "YNYNNYYNYY",
 "NNNNNNNNNN",
 "YNYNNYNYNY",
 "NNYNNNNNYN",
 "YNYNYNYNYN",
 "NNYNNNNNNY",
 "YNYNNNNNNN",
 "NNNNNNNNNN",
 "NNYNYNNNNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"NNNNNNNYNN",
 "YNYNNNNNYN",
 "NNNNNNNNNN",
 "NYNNYNNNYY",
 "NNYNNNNNNN",
 "YNYNNNNNYY",
 "NNNNYNNNYN",
 "NNYNNNYNNN",
 "NNNNNNNNNY",
 "NNYNYNNNNN"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 21; verify_case(5, Arg3, maxMoves(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    ScotlandYard ___test; 
    ___test.run_test(5); 
} 
// END CUT HERE
