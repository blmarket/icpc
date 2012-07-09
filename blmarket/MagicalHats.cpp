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

vector<int> b;
int n,m;
int memo[13][13][9000];

int go(int row, int cnt, int mask) {
    if(cnt < 0) return -2;

    if(row == n) {
        if(cnt == 0 && mask == 0) return 0;
        return -2; // infeasible solution.
    }

    if(memo[row][cnt][mask] != -1) return memo[row][cnt][mask];

    vector<PII> avail_mask;

    int cnt3 = 0;
    for(int i=0;i<m;i++) if(b[row] & (1<<i)) cnt3++;

    for(int i=0;i<(1<<m);i++) if((b[row] & i) == i) {
        int cnt2 = 0;
        for(int j=0;j<m;j++) if(i & (1<<j)) cnt2++;

        if(((cnt2+cnt3)%2) != 0) continue;
        int tmp = go(row+1, cnt - cnt2, mask ^ i);
        if(tmp == -2) continue;

        if(row == 0) {
            for(int j=0;j<m;j++) cout << ((i>>j)&1);
            cout << " : " << tmp << endl;
        }
        avail_mask.pb(mp(i, tmp));
    }

    if(size(avail_mask) == 0)
        return memo[row][cnt][mask] = -2;

    int ret = -2;
    for(int i=0;i<(1<<m);i++) if((b[row] & i) == i) {
        int tmp3 = 0;
        for(int j=0;j<size(avail_mask);j++) {
            int tmp = i & (~avail_mask[j].first);
            int tmp2 = 0;
            while(tmp) {
                tmp2 += (1 & tmp);
                tmp >>= 1;
            } 
            tmp2 += avail_mask[j].second;
            if(tmp3 < tmp2) {
                tmp3 = tmp2;
            }
        }
        if(ret < 0 || ret > tmp3) ret = tmp3;
    }

    cout << row << " " << cnt << " " << mask << " = " << ret << endl;

    return memo[row][cnt][mask] = ret;
}

class MagicalHats 
{
public:
    int findMaximumReward(vector <string> board, vector <int> coins, int numGuesses) 
    {
        b.clear();
        memset(memo, -1, sizeof(memo));
        n = size(board); m = size(board[0]);
        for(int i=0;i<size(board);i++) {
            int tmp = 0;
            for(int j=0;j<size(board[i]);j++) {
                if(board[i][j] == 'H') tmp |= (1<<j);
            }
            b.pb(tmp);
        }


        int mask = 0;
        for(int i=0;i<size(board[0]);i++) {
            bool cnt = false;
            for(int j=0;j<size(board);j++) {
                if(board[j][i] == 'H') cnt = !cnt;
            }
            mask |= (cnt << i);
        }

        int ret = go(0, size(coins), mask);
        cout << ret << endl;
        sort(coins.begin(), coins.end());
        if(ret >= numGuesses) return 0;
        ret = numGuesses - ret;
        int rr = 0;
        for(int i=0;i<ret;i++) {
            rr += coins[i];
        }
        return rr;
    }
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"H"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 1; verify_case(0, Arg3, findMaximumReward(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"HHH",
 "H.H",
 "HH."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 9; verify_case(1, Arg3, findMaximumReward(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"HH",
 "HH"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arg3 = 6; verify_case(2, Arg3, findMaximumReward(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"HHH",
 "HHH",
 "H.H"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {13,13,13,13}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 13; verify_case(3, Arg3, findMaximumReward(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"HHH",
 "HHH",
 "H.H"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {13,13,13,13}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arg3 = 26; verify_case(4, Arg3, findMaximumReward(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arr0[] = {"H.H.",
 ".H.H",
 "H.H."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {17}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; int Arg3 = -1; verify_case(5, Arg3, findMaximumReward(Arg0, Arg1, Arg2)); }
	void test_case_6() { string Arr0[] = {"HHH",
 "H.H",
 "HHH",
 "H.H",
 "HHH"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {33,337,1007,2403,5601,6003,9999}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; int Arg3 = 1377; verify_case(6, Arg3, findMaximumReward(Arg0, Arg1, Arg2)); }
	void test_case_7() { string Arr0[] = {".............",
 ".............",
 ".............",
 ".............",
 ".............",
 ".............",
 ".....H.H.....",
 "......H......",
 ".....H.H.....",
 ".............",
 ".............",
 ".............",
 "............."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {22}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arg3 = 22; verify_case(7, Arg3, findMaximumReward(Arg0, Arg1, Arg2)); }

// END CUT HERE

};



// BEGIN CUT HERE 
int main() {
	MagicalHats ___test;
	___test.run_test(3);
}
// END CUT HERE
