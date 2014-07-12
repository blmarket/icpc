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

double f(int a) {
    double ret = 1.0;
    for(int i=1;i<=a;i++) ret *= i;
    return ret;
}

double c(int a, int b) {
    return f(a) / f(b) / f(a-b);
}

double go(vector<int> &V) {
    int sum = 0;
    double ret = 1.0;
    for(int it : V) {
        sum += it;
        ret *= c(sum, it);
        ret *= f(it*2);
    }
    return ret / f(sum*2);
}

class PalindromePermutations 
{
public:
    double palindromeProbability(string word) 
    {		
        map<char, int> M;
        for(auto it : word) M[it] += 1;
        bool haveone = false;
        double ret = 1.0;
        vector<int> V;
        for(auto it : M) {
            if(it.second % 2) {
                if(haveone) return 0;
                haveone = true;
                ret /= size(word);
            }
            V.pb(it.second / 2);
        }

        cout << ret << endl;
        ret *= go(V);
        cout << ret << endl;
        return ret;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "haha"; double Arg1 = 0.3333333333333333; verify_case(0, Arg1, palindromeProbability(Arg0)); }
	void test_case_1() { string Arg0 = "xxxxy"; double Arg1 = 0.2; verify_case(1, Arg1, palindromeProbability(Arg0)); }
	void test_case_2() { string Arg0 = "xxxx"; double Arg1 = 1.0; verify_case(2, Arg1, palindromeProbability(Arg0)); }
	void test_case_3() { string Arg0 = "abcde"; double Arg1 = 0.0; verify_case(3, Arg1, palindromeProbability(Arg0)); }
	void test_case_4() { string Arg0 = "hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhff"; double Arg1 = 0.025641025641025637; verify_case(4, Arg1, palindromeProbability(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    PalindromePermutations ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
