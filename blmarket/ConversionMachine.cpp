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

class ConversionMachine 
{
public:
    int countAll(string word1, string word2, vector <int> costs, int maxCost) 
    {		
        vector<int> ncs(size(word1), 0);
        for(int i=0;i<size(word1);i++) {
            while(word1[i] != word2[i]) {
                cout << word1[i] << " " << word2[i] << endl;
                ncs[i]++;
                cout << word1[i] - 'a' << " ";
                maxCost -= costs[word1[i]-'a'];
                word1[i] = word1[i] + 1;
                if(word1[i] == 'd') word1[i] = 'a';
            }
        }

        cout << maxCost << endl;
        for(int i=0;i<size(ncs);i++)
            cout << ncs[i] << " ";
        cout << endl;

        if(maxCost < 0) return 0;
        return 0;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "a"; string Arg1 = "b"; int Arr2[] = {100,2,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 205; int Arg4 = 2; verify_case(0, Arg4, countAll(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { string Arg0 = "abcba"; string Arg1 = "abcba"; int Arr2[] = {67,23,43}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; int Arg4 = 1; verify_case(1, Arg4, countAll(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { string Arg0 = "cccccccc"; string Arg1 = "aaaaaaaa"; int Arr2[] = {10000000,1,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 100; int Arg4 = 40320; verify_case(2, Arg4, countAll(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { string Arg0 = "aa"; string Arg1 = "cc"; int Arr2[] = {1,10,100}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1787; int Arg4 = 123611681; verify_case(3, Arg4, countAll(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    ConversionMachine ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
