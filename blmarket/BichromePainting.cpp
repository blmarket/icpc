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

bool poss[25][25];

class BichromePainting 
{
public:
    string isThatPossible(vector <string> board, int k) 
    {		
        int n = size(board);
        memset(poss, 0, sizeof(poss));
        bool change;
        do {
            change = false;

            for(int i=0;i+k<n;i++) {
                for(int j=0;j+k<n;j++) {
                    bool fail = false;
                    for(int a=0;a<k;a++) {
                        char cc = 0;
                        int ii = i + a;
                        for(int b=0;b<k;b++) {
                            int jj = j + b;
                            if(poss[ii][jj]) continue;
                            if(cc == 0) cc = board[ii][jj];
                            if(board[ii][jj] != cc) {
                                fail = true; break;
                            }
                        }
                        if(fail) break;
                    }
                    if(!fail) {
                        for(int a=0;a<k;a++) for(int b=0;b<k;b++) {
                            change |= !poss[i+a][j+b];
                            poss[i+a][j+b] = true;
                        }
                    }
                }
            }
            for(int i=0;i<n;i++) {
                for(int j=0;j<n;j++) cout << poss[i][j] << " ";
                cout << endl;
            }
            cout << endl;
        } while(change);
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) if(poss[i][j] == false) {
                return "Impossible";
            }
        }
        return "Possible";
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"BBBW",
 "BWWW",
 "BWWW",
 "WWWW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; string Arg2 = "Possible"; verify_case(0, Arg2, isThatPossible(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"BW",
 "WB"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; string Arg2 = "Impossible"; verify_case(1, Arg2, isThatPossible(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"BWBWBB",
 "WBWBBB",
 "BWBWBB",
 "WBWBBB",
 "BBBBBB",
 "BBBBBB"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; string Arg2 = "Possible"; verify_case(2, Arg2, isThatPossible(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"BWBWBB",
 "WBWBWB",
 "BWBWBB",
 "WBWBWB",
 "BWBWBB",
 "BBBBBB"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; string Arg2 = "Impossible"; verify_case(3, Arg2, isThatPossible(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"BWBWBB",
 "WBWBWB",
 "BWBWBB",
 "WBWBWB",
 "BWBWBB",
 "BBBBBB"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; string Arg2 = "Possible"; verify_case(4, Arg2, isThatPossible(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"BB",
 "BB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; string Arg2 = "Possible"; verify_case(5, Arg2, isThatPossible(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    BichromePainting ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
