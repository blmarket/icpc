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
int arr[355], arr2[355], arr3[355];
const int mod = 1000000007;

void walk(int *src, int move, int *dst) {
    memset(dst, 0, sizeof(arr));
    for(int i=0;i<N;i++) if(src[i]) {
        dst[(i + move) % N] += src[i];
        if(move == 0 || move * 2 == N) continue;
        dst[(i + N - move) % N] += src[i];
    }
}

void mul(int *src, int *src2, int *dst) {
    memset(dst, 0, sizeof(arr));
    for(int i=0;i<N;i++) if(src[i]) {
        for(int j=0;j<N;j++) if(src2[i]) {
            long long tmp = (long long)src[i] * src2[i];
            tmp += dst[(i+j)%N];
            tmp %= mod;
            dst[(i+j) % N] = tmp;
        }
    }
}

class PenguinEmperor 
{
public:
    int countJourneys(int numCities, long long daysPassed) 
    {
        N = numCities;
        memset(arr, 0, sizeof(arr));
        arr[0] = 1;

        int *t1 = arr, *t2 = arr2, *t3 = arr3;
        for(int i=1;i<N;i++) {
            walk(t1, (i % N), t2);
            swap(t1, t2);
        }

        long long tmp = daysPassed / N;
        while(tmp) {
            if(tmp & 1) {
                mul(t2, t1, t3);
                swap(t2, t3);
            }
            tmp >>= 1;
            if(tmp == 0) break;
            mul(t1, t1, t3);
            swap(t1, t3);
        }

        daysPassed %= N;
        return t1[0];
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; long long Arg1 = 2LL; int Arg2 = 2; verify_case(0, Arg2, countJourneys(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 4; long long Arg1 = 3LL; int Arg2 = 2; verify_case(1, Arg2, countJourneys(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 5; long long Arg1 = 36LL; int Arg2 = 107374182; verify_case(2, Arg2, countJourneys(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 300; long long Arg1 = 751LL; int Arg2 = 413521250; verify_case(3, Arg2, countJourneys(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 300; long long Arg1 = 750LL; int Arg2 = 0; verify_case(4, Arg2, countJourneys(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 350; long long Arg1 = 1000000000000000000LL; int Arg2 = 667009739; verify_case(5, Arg2, countJourneys(Arg0, Arg1)); }
	void test_case_6() { int Arg0 = 5; long long Arg1 = 7LL; int Arg2 = 12; verify_case(6, Arg2, countJourneys(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    PenguinEmperor ___test; 
    ___test.run_test(2); 
} 
// END CUT HERE
