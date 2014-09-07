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

int K;
vector<int> dk;

bool chk(const string &a) {
    int ret = 1;
    for(int i=2;i<size(a);i++) {
        if(size(a) % i) continue;
        bool fail = false;
        for(int j=0;j<size(a);j++) {
            if(a[j] != a[(j+i)%size(a)]) { fail = true; break; }
        }
        if(!fail) ret++;
    }
    return ret == K;
}

int fact(int a) { if(a == 0) return 1; else return a * fact(a-1); }

class MagicWords 
{
public:
    int count(vector <string> S, int K_) 
    {
        string tmp;
        for(int i=0;i<size(S);i++) tmp += S[i];
        bool fail = false;
        for(int i=1;i<size(tmp);i++) {
            if(tmp[i] != tmp[0]) { fail = true; break; }
        }
        if(!fail) {
            cout << "HERE" << endl;
            if(K == size(tmp)) return fact(size(S));
        }

        K = K_;
        for(int i=2;i<K;i++) {
            if((K % i) == 0) dk.pb(i);
        }
        int ret = 0;
        vector<int> V;
        for(int i=0;i<size(S);i++) V.pb(i);
        do {
            string tmp; tmp.clear();
            for(int j=0;j<size(V);j++) tmp += S[V[j]];
            ret += chk(tmp);
        } while(next_permutation(V.begin(), V.end()));
        return ret;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"CAD","ABRA","ABRA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 6; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"AB","RAAB","RA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 3; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"AA","AA","AAA","A"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 0; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"AA","AA","AAA","A","AAA","AAAA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 15; int Arg2 = 720; verify_case(3, Arg2, count(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"ABC","AB","ABC","CA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 0; verify_case(4, Arg2, count(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"A","B","C","A","B","C"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 672; verify_case(5, Arg2, count(Arg0, Arg1)); }
	void test_case_6() { string Arr0[] = {"AAAAAAAAAAAAAAAAAAAA",
 "AAAAAAAAAAAAAAAAAAAA",
 "AAAAAAAAAAAAAAAAAAAA",
 "AAAAAAAAAAAAAAAAAAAA",
 "AAAAAAAAAAAAAAAAAAAA",
 "AAAAAAAAAAAAAAAAAAAA",
 "AAAAAAAAAAAAAAAAAAAA",
 "AAAAAAAAAAAAAAAAAAAB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 40320; verify_case(6, Arg2, count(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    MagicWords ___test; 
    ___test.run_test(3); 
} 
// END CUT HERE
