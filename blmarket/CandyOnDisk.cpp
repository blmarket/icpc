#include <iostream>
#include <cmath>
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

int N;
vector<LL> x,y,r;
double visit[55];

void go(int a) {
    for(int i=0;i<N;i++) if(i != a) {
        LL dxx = x[a] - x[i];
        LL dyy = y[a] - y[i];
        LL ddd = sqr(dxx) + sqr(dyy);
        double d = sqrt(ddd);
        double d2 = d - r[a];
    }
}

class CandyOnDisk 
{
public:
    string ableToAchieve(vector <int> x_, vector <int> y_, vector <int> r_, int sx, int sy, int tx, int ty) 
    {
        N = size(x_); x=y=r=vector<LL>(N, 0);
        for(int i=0;i<N;i++) { x[i] = x_[i]; y[i] = y_[i]; r[i] = r_[i]; }
        for(int i=0;i<55;i++) visit[i] = -1;

        for(int i=0;i<N;i++) {
            LL dx = x[i] - sx;
            LL dy = y[i] - sy;
            LL dd = sqr(dx) + sqr(dy);
            LL tt = sqr(r[i]);
            double d1 = sqrt(tt);
            if(dd <= tt) { // on disk
                for(int j=0;j<N;j++) if(i != j) {
                    LL dxx = x[i] - x[j];
                    LL dyy = y[i] - y[j];
                    LL ddd = sqr(dxx) + sqr(dyy);
                    double d = sqrt(ddd);
                    double d2 = d - d1 - r[j];
                    cout << "d2 = " << d2 << endl;
                    if(d2 > 1e-3) continue;
                    d2 = -d2;
                    if(d2 > r[j] + r[j]) continue;
                    if(d2 > r[j]) {
                        d2 = (double)r[j] + r[j] - d2;
                    }
                    visit[j] = d2;
                }
            }
        }

        for(int i=0;i<N;i++) {
            if(visit[i] > -1e-3) {
                go(i);
            }
        }

        for(int i=0;i<N;i++) {
            cout << visit[i] << " ";
        }
        cout << endl;
        
        return "";
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3, 3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -1; int Arg4 = -2; int Arg5 = 6; int Arg6 = 1; string Arg7 = "YES"; verify_case(0, Arg7, ableToAchieve(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_1() { int Arr0[] = {0, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {5, 3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -4; int Arg4 = 0; int Arg5 = -2; int Arg6 = 0; string Arg7 = "YES"; verify_case(1, Arg7, ableToAchieve(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_2() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; int Arg4 = 0; int Arg5 = 571; int Arg6 = 571; string Arg7 = "NO"; verify_case(2, Arg7, ableToAchieve(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_3() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 571; int Arg4 = 571; int Arg5 = 571; int Arg6 = 571; string Arg7 = "YES"; verify_case(3, Arg7, ableToAchieve(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_4() { int Arr0[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; int Arg4 = 2; int Arg5 = 19; int Arg6 = 19; string Arg7 = "YES"; verify_case(4, Arg7, ableToAchieve(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_5() { int Arr0[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; int Arg4 = 2; int Arg5 = 19; int Arg6 = 19; string Arg7 = "NO"; verify_case(5, Arg7, ableToAchieve(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    CandyOnDisk ___test; 
    ___test.run_test(1); 
} 
// END CUT HERE
