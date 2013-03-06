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

int N;
vector<string> guess;
map<pair<int, VI>, int> memo;
string result;

int go(int pos, const VI &bull) {
    pair<int, VI> key = mp(pos, bull);
    if(memo.count(key)) return memo[key];

    int ret = 0;
    
    for(int i='0';i<='9';i++) {
        bool fail = false;
        vector<int> tmp = bull;
        for(int j=0;j<size(guess);j++) {
            if(guess[j][pos] == i) {
                if(tmp[j] == 0) { fail = true; break; }
                tmp[j]--;
            }
        }
        if(fail) continue;
        int tmp2 = go(pos+1, tmp);
        if(tmp2 < 1) continue;
        result[pos] = i;
        ret += tmp2;
        if(ret > 1) break;
    }
    return memo[key] = ret;
}

class EllysBulls 
{
public:
    string getNumber(vector <string> guesses, vector <int> bulls) 
    {
        guess = guesses;
        N = size(guesses[0]);
        result = string(N, '?');
        int ret = go(0, bulls);
        if(ret == 1) return result;
        if(ret == 0) return "Liar";
        return "Ambiguity";
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"1234", "4321", "1111", "2222", "3333", "4444", "5555", "6666", "7777", "8888", "9999"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 1, 1, 0, 2, 0, 0, 0, 1, 0, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "1337"; verify_case(0, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"0000", "1111", "2222"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 2, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Liar"; verify_case(1, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"666666", "666677", "777777", "999999"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 3, 1, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Ambiguity"; verify_case(2, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"000", "987", "654", "321", "100", "010"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 1, 0, 0, 1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "007"; verify_case(3, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"28", "92", "70", "30", "67", "63", "06", "65",
 "11", "06", "88", "48", "09", "65", "48", "08"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "54"; verify_case(4, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"0294884", "1711527", "2362216", "7666148", "7295642",
 "4166623", "1166638", "2767693", "8650248", "2486509",
 "6138934", "4018642", "6236742", "2961643", "8407361",
 "2097376", "6575410", "6071777", "3569948", "2606380"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 0, 1, 3, 4, 4, 3, 2, 1, 1, 0, 4, 4, 3, 0, 0, 0, 0, 2, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "4266642"; verify_case(5, Arg2, getNumber(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    EllysBulls ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
