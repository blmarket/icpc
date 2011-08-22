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

inline void setmax(int &a, int b) { if(a < b) a = b; }
inline void setmin(int &a, int b) { if(b != -1) if(a == -1 || a > b) a = b; }

vector<int> points;
vector<vector<int> > V;
int w,d;
int sum;

class TheTournamentDivOne 
{
public:
    int find(vector <int> points_, int w_, int d_) 
    {		
        points = points_;
        w = w_;
        d = d_;

        sum = 0; 
        for(int i=0;i<size(points);i++) sum += points[i];

        V.clear();
        V.resize(size(points));

        for(int i=0;i<size(points);i++)
        {
            int tmp = points[i];
            for(int j=0;tmp >= 0;j++, tmp -= d)
            {
                if((tmp % w) == 0)
                {
                    V[i].pb(j);
                }
            }
            sort(V[i].begin(), V[i].end());
            for(int j=0;j<size(V[i]);j++)
                cout << V[i][j] << " ";
            cout << endl;
        }

        int ret = -1;

        int vmax = 0;
        int vsum;

        while(true)
        {
            vmax = 0;
            vsum = 0;
            for(int i=0;i<size(V);i++)
            {
                if(V[i].back() > V[vmax].back())
                    vmax = i;
                vsum += V[i].back();
            }

            if((vsum % 2) == 0 && vsum >= V[vmax].back() * 2)
            {
                cout << vsum << " " << V[vmax].back() << endl;
                int tmp = (sum - vsum * d) / w + vsum / 2;
                if(ret < 0 || ret > tmp) ret = tmp;
            }

            if(V[vmax].size() == 1) break;
            V[vmax].pop_back();
        }

        return ret;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {10, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 1; int Arg3 = 6; verify_case(0, Arg3, find(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {1, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 1; int Arg3 = -1; verify_case(1, Arg3, find(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {1, 4, 0, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 1; int Arg3 = 3; verify_case(2, Arg3, find(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {8, 3, 8, 5, 9, 2, 7, 11}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 2; int Arg3 = 15; verify_case(3, Arg3, find(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    TheTournamentDivOne ___test; 
    ___test.run_test(3); 
} 
// END CUT HERE
