#include <iostream>
#include <cstdio>
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
typedef long long LL;

template<typename T> int size(const T &a) { return a.size(); }

const int dx[] = {-2,-2,-1,-1,1,1,2,2};
const int dy[] = {-1,1,-2,2,-2,2,-1,1};

int N,M;
bool data[151][151];
vector<PII> V;

bool pick(int a,int b)
{
    data[a][b] ^= 1;
    for(int i=0;i<8;i++)
    {
        int nx = a + dx[i];
        int ny = b + dy[i];
        if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
        data[nx][ny] ^= 1;
    }
}

bool resolve()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(data[i][j])
            {
                if(i+2 >= N || j+1 >= M) return false;
                V.pb(mp(i+2,j+1));
                pick(i+2,j+1);
            }
        }
    }
    return true;
}

class KnightsOut 
{
public:
    int count(int N_, int M_) 
    {
        N = N_;
        M = M_;
        memset(data,0, sizeof(data));

        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                V.clear();
                pick(i+2,j+1);
                pick(i+1,j+2);
                if(resolve())
                {
                    V.pb(mp(i+2,j+1));
                    V.pb(mp(i+1,j+2));
                    sort(V.begin(),V.end());
                    for(int i=0;i<size(V);i++)
                    {
                        printf("%d,%d ",V[i].first, V[i].second);
                    }
                    printf("\n");
                }
            }
        }
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
