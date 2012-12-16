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

const int dx[] = {-2,-2,-1,-1,1,1,2,2};
const int dy[] = {-1,1,-2,2,-2,2,-1,1};

bool visit[105][105];
int w,h;

bool check(int a, int b) {
    return a>=0 && b>=0 && a<w && b<h;
}

int go(int a, int b) {
    if(visit[a][b]) return 0;
    visit[a][b] = true;
    int ret = 1;
    for(int i=0;i<8;i++) {
        int nx = a + dx[i];
        int ny = b + dy[i];
        if(check(nx,ny) == false) continue;
        ret += go(nx,ny);
    }
    return ret;
}

class KnightCircuit2 
{
public:
    int maxSize(int w_, int h_) 
    {
        w=w_;h=h_;
        for(int i=0;i<3;i++) {
            for(int j=0;j<2;j++) {
                if(!check(i,j)) continue;
                memset(visit, 0, sizeof(visit));
                cout << go(i,j) << endl;
            }
        }
        return 0;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 1; verify_case(0, Arg2, maxSize(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 15; int Arg1 = 2; int Arg2 = 8; verify_case(1, Arg2, maxSize(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 100; int Arg1 = 100; int Arg2 = 10000; verify_case(2, Arg2, maxSize(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    KnightCircuit2 ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
