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

vector<bool> V;
int used[10];
bool flag[10];

int go(int a,int sz)
{
    if(a == size(V))
    {
        for(int i=0;i<sz;i++) if(used[i] == 0) return 0;
        return 1;
    }

    int ret = 0;
    for(int i=0;i<sz;i++) if(used[i] == 0 || flag[i] == V[a])
    {
        used[i]++;
        flag[i] = V[a];
        ret += go(a+1,sz);
    }
    return ret;
}

class TheQuestionsAndAnswersDivOne 
{
public:
    int find(int questions, vector <string> answers) 
    {
        V.clear();
        for(int i=0;i<size(answers);i++) V.pb(answers[i] == "Yes");
        return go(0, questions);
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; string Arr1[] = {"No", "Yes"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(0, Arg2, find(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; string Arr1[] = {"No", "No", "No"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; verify_case(1, Arg2, find(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; string Arr1[] = {"Yes", "No", "No", "Yes"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 12; verify_case(2, Arg2, find(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 3; string Arr1[] = {"Yes", "Yes", "Yes", "No"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 18; verify_case(3, Arg2, find(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    TheQuestionsAndAnswersDivOne ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
