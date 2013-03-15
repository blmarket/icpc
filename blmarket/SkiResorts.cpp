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
typedef long long LL;

template<typename T> int size(const T &a) { return a.size(); }

long long mincost[55][55];
int N;
vector<int> als, alti;
vector<string> road;

class SkiResorts 
{
public:
    long long minCost(vector <string> road_, vector <int> altitude) 
    {
        N = size(altitude);
        alti = altitude;
        als = altitude;
        road = road_;
        sort(als.begin(), als.end());
        als.erase(unique(als.begin(), als.end()), als.end());

        for(int i=0;i<N;i++) {
            for(int j=0;j<size(als);j++) if(alti[i] == als[j]) { alti[i] = j; break; }
            cout << alti[i] << " ";
        }
        cout << endl;

        memset(mincost, -1, sizeof(mincost));

        priority_queue<pair<PII, LL> > Q;

        for(int i=0;i<size(als);i++) {
            mincost[0][i] = abs(als[i] - als[alti[0]]);
            cout << mincost[0][i] << " ";
            Q.push(mp(mp(0,i), mincost[0][i]));
        }
        cout << endl;

        while(!Q.empty()) {
            int p1 = Q.top().first.first;
            int p2 = Q.top().first.second;
            LL cur = Q.top().second;
            Q.pop();

            if(mincost[p1][p2] != cur) continue;
            for(int i=0;i<N;i++) if(road[p1][i] == 'Y') {
                for(int j=0;j<=p2;j++) {
                    LL tmp = cur + abs(als[j] - als[alti[i]]);
                    if(mincost[i][j] == -1 || mincost[i][j] > tmp) {
                        mincost[i][j] = tmp;
                        Q.push(mp(mp(i,j), tmp));
                    }
                }
            }
        }

        long long ret = -1;
        for(int i=0;i<size(als);i++) if(mincost[N-1][i] != -1) {
            if(ret == -1 || ret > mincost[N-1][i]) ret = mincost[N-1][i];
        }
        return ret;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"NYN",
 "YNY",
 "NYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {30, 20, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 0LL; verify_case(0, Arg2, minCost(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"NY",
 "YN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10, 20}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 10LL; verify_case(1, Arg2, minCost(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"NYN",
 "YNN",
 "NNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {573, 573, 573}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = -1LL; verify_case(2, Arg2, minCost(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"NNYNNYYYNN",
 "NNNNYNYNNN",
 "YNNNNYYNNN",
 "NNNNNNYNYY",
 "NYNNNNNNYY",
 "YNYNNNNYNN",
 "YYYYNNNYNN",
 "YNNNNYYNNN",
 "NNNYYNNNNN",
 "NNNYYNNNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {7, 4, 13, 2, 8, 1, 8, 15, 5, 15}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 12LL; verify_case(3, Arg2, minCost(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    SkiResorts ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
