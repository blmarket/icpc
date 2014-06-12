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

vector<PII> links[2005];
bool hasz[2005];
int md1[2005], md2[2005];

void calcmd(int mindist[2005], int sp) {
    memset(mindist, -1, sizeof(int) * 2005);
    priority_queue<PII> Q;
    mindist[sp] = 0;
    Q.push(mp(0, sp));
    while(!Q.empty()) {
        int dist, pos;
        tie(dist, pos) = Q.top();
        Q.pop();
        dist = -dist;

        if(mindist[pos] != dist) continue;

        for(int i=0;i<size(links[pos]);i++) {
            int n, d;
            tie(n, d) = links[pos][i];
            int nd = dist + d;
            if(mindist[n] == -1 || mindist[n] > nd) {
                mindist[n] = nd;
                Q.push(mp(-nd, n));
            }
        }
    }
}

class DrivingPlans 
{
public:
    int count(int N, vector <int> A, vector <int> B, vector <int> C) 
    {		
        memset(hasz, 0, sizeof(hasz));
        for(int i=0;i<2005;i++) links[i].clear();

        for(int i=0;i<size(A);i++) {
            if(C[i] == 0) {
                hasz[A[i]] = hasz[B[i]] = true;
            }
            links[A[i]].pb(mp(B[i], C[i]));
            links[B[i]].pb(mp(A[i], C[i]));
        }

        calcmd(md1, 1);
        calcmd(md2, N);

        if(md1[N] == -1) return 0;
        for(int i=1;i<=N;i++) {
            cout << md1[i] << " ";
        }
        cout << endl;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arr1[] = {1,1,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,3,4,4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,1,1,1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 2; verify_case(0, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 4; int Arr1[] = {1,1,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,3,4,4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,1,1,0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = -1; verify_case(1, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 7; int Arr1[] = {1,1,2,3,4,4,5,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,3,4,4,5,6,7,7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,1,2,2,3,3,4,4}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 4; verify_case(2, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    DrivingPlans ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
