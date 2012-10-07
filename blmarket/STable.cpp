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
typedef long long LL;

template<typename T> int size(const T &a) { return a.size(); }

int move[33][33];
LL cnt[33][33];
string test[33][33];
string s,t;

string go(int x, int y, int pos, int sz) 
{
		if(sz == 0) return "";
		if(y == 0) {
				if(pos == 0) return string(1, s[x-1]);
				return "";
		}

		if(x == 0) {
				if(pos == 0) return string(1, t[y-1]);
				return "";
		}

		if(pos >= cnt[x][y]) return "";
		if(pos + sz > cnt[x][y]) sz = cnt[x][y] - pos;

		int fx,fy, lx,ly;
		if(move[x][y] == 1) {
				fx = x; fy = y-1;
				lx = x-1; ly = y;
		} else {
				fx = x-1; fy = y;
				lx = x; ly = y-1;
		}

		string ret;
		if(cnt[fx][fy] > pos) {
				ret = go(fx,fy,pos,sz);
				if(size(ret) < sz) ret += go(lx,ly,0,sz - size(ret));
				return ret;
		} else {
				return go(lx, ly, pos - cnt[fx][fy], sz);
		}
}

void propagate(int x, int y) {
		for(int i=x;i<=size(s);i++) {
				for(int j=y;j<=size(t);j++) {
						int xdiff = i-x;
						int ydiff = j-y;
						if(xdiff == ydiff) continue;
						if(xdiff > ydiff) move[i][j] = 2;
						else move[i][j] = 1;
				}
		}
}

class STable 
{
public:
    string getString(string s_, string t_, long long pos) 
    {		
				s=s_; t=t_;
				string order = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
				reverse(order.begin(), order.end());
				for(int i=0;i<size(order);i++) {
						for(int j=0;j<size(s);j++) if(s[j] == order[i]) {
								propagate(j+1, 1);
								move[j+1][1] = 1;
						}
						for(int j=0;j<size(t);j++) if(t[j] == order[i]) {
								propagate(1, j+1);
								move[1][j+1] = 2;
						}
				}

				for(int i=1;i<=size(s);i++) { cnt[i][0] = 1; test[i][0] = string(1, s[i-1]); }
				for(int i=1;i<=size(t);i++) { cnt[0][i] = 1; test[0][i] = string(1, t[i-1]); }
				for(int i=1;i<=size(s);i++) {
						for(int j=1;j<=size(t);j++) {
								cnt[i][j] = cnt[i-1][j] + cnt[i][j-1];
						}
				}
				
				for(int i=1;i<=size(s);i++) {
						for(int j=1;j<=size(t);j++) {
								cout << move[i][j] << " ";
						}
						cout << endl;
				}

				return go(size(s), size(t), pos, 50);
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "ad"; string Arg1 = "cb"; long long Arg2 = 0LL; string Arg3 = "acbacd"; verify_case(0, Arg3, getString(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "fox"; string Arg1 = "cat"; long long Arg2 = 0LL; string Arg3 = "acfcfoacftacfcfocfox"; verify_case(1, Arg3, getString(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "Ra6b1t"; string Arg1 = "W0lf"; long long Arg2 = 66LL; string Arg3 = "RWab0RWRWa0RWl0RWRWa6RWa0RWRWa6RWa6RWab0RWRWa6RWa6"; verify_case(2, Arg3, getString(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "M0HAXG"; string Arg1 = "COFU12"; long long Arg2 = 919LL; string Arg3 = "MOFU2"; verify_case(3, Arg3, getString(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "a0B1c2D3e4F5gHiJkLmN"; string Arg1 = "A9b8C7d6EfGhIjKlMn"; long long Arg2 = 9876543210LL; string Arg3 = "B10AaB1c0Aa9Aa0AaB0AaB10AaB1c0AaB1c20Aa9Aa0AaB0Aa9"; verify_case(4, Arg3, getString(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arg0 = "TCOR2"; string Arg1 = "MEDiUm"; long long Arg2 = 350LL; string Arg3 = "MTDEMTiCMTEMTDEMTDEMTiDEMTiUCMTEMTCMTOCMTEMTDEMTCM"; verify_case(5, Arg3, getString(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    STable ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
