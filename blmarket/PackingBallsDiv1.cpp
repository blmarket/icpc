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

int V[100005];
int K;
priority_queue<PII> Q;

int go(int nvar) {
    int ret = 0;
    for(int i=0;i<K;i++) if(V[i] > nvar) {
        ret += (V[i] - nvar + K - 1) / K;
    }
    return nvar + ret;
}

class PackingBallsDiv1 
{
public:
    int minPacks(int K_, int A, int B, int C, int D) 
    {		
        K = K_;
        V[0] = A;
        for(int i=1;i<K;i++) {
            V[i] = ((long long)V[i-1] * B + C) % D + 1;
        }

        sort(V, V+K);

        int s = 0;
        int e = V[K-1];

        while(s + 10 < e) {
            int m1 = (s*2 + e) / 3;
            int m2 = (s + e*2) / 3;
            
            int k1 = go(m1);
            int k2 = go(m2);

            if(k1 == k2) return k1;

            if(k1 < k2) {
                e = m2;
            } else {
                s = m1;
            }
        }

        cout << "here" << endl;
        int ret = go(s);
        for(int i=s+1;i<=e;i++) {
            int tmp = go(i);
            if(ret > tmp) ret = tmp;
        }
        return ret;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 4; int Arg2 = 2; int Arg3 = 5; int Arg4 = 6; int Arg5 = 4; verify_case(0, Arg5, minPacks(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 58; int Arg2 = 23; int Arg3 = 39; int Arg4 = 93; int Arg5 = 58; verify_case(1, Arg5, minPacks(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 23; int Arg1 = 10988; int Arg2 = 5573; int Arg3 = 4384; int Arg4 = 100007; int Arg5 = 47743; verify_case(2, Arg5, minPacks(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 100000; int Arg1 = 123456789; int Arg2 = 234567890; int Arg3 = 345678901; int Arg4 = 1000000000; int Arg5 = 331988732; verify_case(3, Arg5, minPacks(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    PackingBallsDiv1 ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
