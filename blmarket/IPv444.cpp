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

struct data {
		int a[4];
		int p;

		bool operator<(const data &rhs) const {
				return p < rhs.p;
		}
};

ostream& operator<<(ostream &ost, const data &rhs) {
		return ost << rhs.p << " " << rhs.a[0] << "." << rhs.a[1] << "." << rhs.a[2] << "." << rhs.a[3];
}

vector<data> V;

int token(string tmp) {
		if(tmp == "*") return -1;
		return atoi(tmp.c_str());
}

void tokenize(string str, int *res) {
		for(int i=0;i<size(str);i++) {
				if(str[i] == '.') {
						string tmp = str.substr(0, i);
						*res = token(tmp);
						tokenize(str.substr(i+1), ++res);
						return;
				}
		}
		*res = token(str);
}

long long go(int a, LL mask, int pos) {
		if(pos == 4) {
				return !mask;
		}

		if(V[a].a[pos] != -1) {
				for(int i=0;i<size(V);i++) if(mask & (1LL << i)) {
						if(V[i].a[pos] != V[a].a[pos]) {
								mask ^= (1LL << i);
						}
				}
				return go(a, mask, pos + 1);
		}

		bool dirty = false;
		for(int i=0;i<size(V);i++) if(mask & (1LL << i)) {
				if(V[i].a[pos] != -1) {
						dirty = true;
						break;
				}
		}
		if(!dirty) return go(a, mask, pos+1) * 1000;

		LL ret = 0;
		for(int i=0;i<1000;i++) {
				LL tmask = mask;
				for(int j=0;j<size(V);j++) if(mask & (1LL << j)) {
						if(V[j].a[pos] != i && V[j].a[pos] != -1) {
								tmask ^= (1LL << j);
						}
				}
				ret += go(a, tmask, pos+1);
		}

		return ret;
}

class IPv444 
{
public:
    long long getMaximumMoney(vector <string> request, vector <int> price) 
    {		
				V.clear();
				for(int i=0;i<size(price);i++) {
						data tmp;
						tokenize(request[i], tmp.a);
						tmp.p = price[i];
						V.pb(tmp);
				}
				sort(V.rbegin(), V.rend());

				long long ret = 0;
				
				for(int i=0;i<size(V);i++) {
						long long mask = (1LL << i) - 1;
						ret += go(i, mask, 0) * V[i].p;
				}

				return ret;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"66.37.210.86"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {47}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 47LL; verify_case(0, Arg2, getMaximumMoney(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"0.0.0.*", "0.0.0.3", "0.0.0.5"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 3, 9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 1010LL; verify_case(1, Arg2, getMaximumMoney(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"*.*.*.*", "123.456.789.0", "434.434.434.434", "999.*.999.*"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 5, 3, 6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 1000005000006LL; verify_case(2, Arg2, getMaximumMoney(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"*.*.999.999", "888.888.999.*", "888.888.*.999", "777.777.777.777", "777.*.*.777"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {19, 33, 42, 777, 7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 26075718LL; verify_case(3, Arg2, getMaximumMoney(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"127.0.0.1", "*.0.0.*", "*.*.255.255", "192.68.*.*"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {999999, 629851, 294016, 438090}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 1361957076132LL; verify_case(4, Arg2, getMaximumMoney(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    IPv444 ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
