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

class KleofasTail 
{
public:
    long long countGoodSequences(long long K, long long A, long long B) 
    {		
        if(K > B) return 0;
        long long ret = 0;

        if(K >= A) ret++;
        if((K%2) == 1)
        {
            return ret + countGoodSequences(K*2, A, B);
        }

        return ret + countGoodSequences(K*2,A,B) + countGoodSequences(K*2+1, A,B);
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 3LL; long long Arg1 = 4LL; long long Arg2 = 8LL; long long Arg3 = 2LL; verify_case(0, Arg3, countGoodSequences(Arg0, Arg1, Arg2)); }
	void test_case_1() { long long Arg0 = 1LL; long long Arg1 = 23457LL; long long Arg2 = 123456LL; long long Arg3 = 100000LL; verify_case(1, Arg3, countGoodSequences(Arg0, Arg1, Arg2)); }
	void test_case_2() { long long Arg0 = 1234567890123456LL; long long Arg1 = 10LL; long long Arg2 = 1000000LL; long long Arg3 = 0LL; verify_case(2, Arg3, countGoodSequences(Arg0, Arg1, Arg2)); }
	void test_case_3() { long long Arg0 = 0LL; long long Arg1 = 0LL; long long Arg2 = 2LL; long long Arg3 = 3LL; verify_case(3, Arg3, countGoodSequences(Arg0, Arg1, Arg2)); }
	void test_case_4() { long long Arg0 = 2LL; long long Arg1 = 3LL; long long Arg2 = 3LL; long long Arg3 = 1LL; verify_case(4, Arg3, countGoodSequences(Arg0, Arg1, Arg2)); }
	void test_case_5() { long long Arg0 = 13LL; long long Arg1 = 12345LL; long long Arg2 = 67890123LL; long long Arg3 = 8387584LL; verify_case(5, Arg3, countGoodSequences(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    KleofasTail ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
