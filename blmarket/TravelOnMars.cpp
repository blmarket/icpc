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

int N;
int mindist[55];

class TravelOnMars 
{
public:
    int minTimes(vector <int> range, int startCity, int endCity) 
    {		
        N = size(range);
        memset(mindist, -1, sizeof(mindist));
        mindist[startCity] = 0;

        queue<int> Q;
        Q.push(startCity);

        while(!Q.empty()) {
            int pos = Q.front();
            Q.pop();

            int r = range[pos];
            cout << pos << " " << r << endl;
            for(int i=-r;i<=r;i++) {
                int nn = (pos + i + N) % N;
                cout << nn << endl;
                if(mindist[nn] == -1) {
                    mindist[nn] = mindist[pos] + 1;
                    Q.push(nn);
                }
            }
        }

        return mindist[endCity];
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2,1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 4; int Arg3 = 2; verify_case(0, Arg3, minTimes(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {2,1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 1; int Arg3 = 3; verify_case(1, Arg3, minTimes(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {2,1,1,2,1,2,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 6; int Arg3 = 3; verify_case(2, Arg3, minTimes(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {3,2,1,1,3,1,2,2,1,1,2,2,2,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; int Arg2 = 13; int Arg3 = 4; verify_case(3, Arg3, minTimes(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    TravelOnMars ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
