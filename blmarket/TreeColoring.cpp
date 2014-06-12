#include <iostream>
#include <functional>
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

int parent[100005];
int dist[100005];
int queryType[100005];
int queryNode[100005];

bool isblue[100005];
int nblue[100005];
long long sumblue;

void markBlue(int a) {
    if(isblue[a]) return;
    isblue[a] = true;

    while(a != 0) {
        nblue[a]++;
        sumblue += dist[a];
        a = parent[a];
    }
    nblue[0]++;
}

long long calc(int a) {
    cout << a << endl;
    long long ret = sumblue;
    while(a != 0) {
        ret += -nblue[a] * dist[a] + (nblue[0] - nblue[a]) * dist[a];
        a = parent[a];
    }
    return ret;
}

class TreeColoring 
{
public:
    long long color(int N, int Q, int startSeed, int threshold, int maxDist) 
    {		

        int curValue = startSeed;
        function<int()> genNextRandom = [&]() {
            curValue = (curValue * 1999 + 17) % 1000003;
            return curValue;
        };

        function<void()> generateInput = [&]() {
            for (int i = 0; i < N-1; i++) {
                dist[i] = genNextRandom() % maxDist;
                parent[i] = genNextRandom();
                if (parent[i] < threshold) {
                    parent[i] = i;
                } else {
                    parent[i] = parent[i] % (i + 1);
                }
            }

            for (int i = 0; i < Q; i++) {
                queryType[i] = genNextRandom() % 2 + 1;
                queryNode[i] = genNextRandom() % N;
            }
        };

        generateInput();

        sumblue = 0;
        long long ret = 0;
        for(int i=0;i<Q;i++) {
            cout << i << endl;
            if(queryType[i] == 1) {
                markBlue(queryNode[i]);
            } else {
                ret ^= calc(queryNode[i]);
            }
        }
        return ret;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 6; int Arg2 = 15; int Arg3 = 2; int Arg4 = 5; long long Arg5 = 7LL; verify_case(0, Arg5, color(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 5; int Arg2 = 2; int Arg3 = 9; int Arg4 = 10; long long Arg5 = 30LL; verify_case(1, Arg5, color(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 8; int Arg1 = 8; int Arg2 = 3; int Arg3 = 5; int Arg4 = 7; long long Arg5 = 6LL; verify_case(2, Arg5, color(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 14750; int Arg1 = 50; int Arg2 = 29750; int Arg3 = 1157; int Arg4 = 21610; long long Arg5 = 2537640LL; verify_case(3, Arg5, color(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 100000; int Arg1 = 100000; int Arg2 = 123456; int Arg3 = 500000; int Arg4 = 474747; long long Arg5 = 726915029831LL; verify_case(4, Arg5, color(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_5() { int Arg0 = 100000; int Arg1 = 100000; int Arg2 = 654321; int Arg3 = 1000003; int Arg4 = 1000003; long long Arg5 = 562600687570528LL; verify_case(5, Arg5, color(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    TreeColoring ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
