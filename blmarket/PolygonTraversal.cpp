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

map<vector<PII>, long long> memo;

void cut(vector<PII> &cur, int pos) {
    for(int i=0;i<size(cur);i++) {
        if(cur[i].first <= pos && cur[i].second >= pos) {
            if(pos+1 <= cur[i].second) cur.pb(mp(pos+1, cur[i].second));
            if(cur[i].first <= pos - 1) cur[i].second = pos - 1;
            else {
                swap(cur[i], cur.back());
                cur.pop_back();
            }
            sort(cur.begin(), cur.end());
            return;
        }
    }
}

class PolygonTraversal 
{
public:
    long long count(int N, vector <int> points) 
    {
        memo.clear();
        for(int i=1;i<size(points);i++) {
            points[i] = (points[i] - points[0] + N) % N;
        }
        points[0] = 0;

        vector<PII> cur;
        if(points[1] == 1) {
            cur.pb(mp(2, N-1));
        } else if(points[1] == N-1) {
            cur.pb(mp(1, N-2));
        } else {
            cur.pb(mp(1, points[1] - 1));
            cur.pb(mp(points[1]+1, N-1));
        }

        for(int i=2;i<size(points);i++) {
            cut(cur, points[i]);
        }
        for(int i=0;i<size(cur);i++) {
            cout << cur[i].first << "-" << cur[i].second << " ";
        }
        cout << endl;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arr1[] = {1, 3, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 1LL; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 6; int Arr1[] = {1, 4, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 1LL; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 7; int Arr1[] = {2, 4, 7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 2LL; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 7; int Arr1[] = {1, 2, 3, 4, 6, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 0LL; verify_case(3, Arg2, count(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 18; int Arr1[] = {1, 7, 18}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 4374612736LL; verify_case(4, Arg2, count(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    PolygonTraversal ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
