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

LL mask[32];

const int dx[] = {-2,-2,-1,-1,1,1,2,2};
const int dy[] = {-1,1,-2,2,-2,2,-1,1};

class KnightsOut 
{
public:
    int count(int N, int M) 
    {		
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                LL tmp = 1LL << (i*M + j);
                for(int k=0;k<8;k++)
                {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
                    tmp |= 1LL << (nx * M + ny);
                }
                mask[i*M+j] = tmp;
            }
        }

        int nodes = N*M;
        int ret = 0;
        for(int i=0;i<(1<<nodes);i++)
        {
            LL tmp = 0;
            for(int j=0;j<nodes;j++) if(i & (1<<j))
            {
                tmp ^= mask[j];
            }

            if(tmp == (1<<nodes)-1)
            {
                ret++;
                for(int j=0;j<nodes;j++) if(i & (1<<j))
                    cerr << "(" << j/M << "," << (j%M) << ") ";
                cerr << endl;
            }
        }

        return ret;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 3; int Arg2 = 4; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 1; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 7; int Arg1 = 5; int Arg2 = 16; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 1; verify_case(3, Arg2, count(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 69; int Arg1 = 142; int Arg2 = 77502052; verify_case(4, Arg2, count(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    KnightsOut ___test; 
    ___test.run_test(0); 
} 
// END CUT HERE
