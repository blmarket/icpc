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

map<int, int> ips[4];

int maxvar[55][55][55][55];

int token(string str) {
		if(str[0] == '*') return -1;
		return atoi(str.c_str());
}

void tokenize(string str, int *res) {
		for(int i=0;i<size(str);i++) if(str[i] == '.') {
				string tmp = str.substr(0, i);
				*res = token(tmp);
				tokenize(str.substr(i+1), ++res);
				return;
		}
		*res = token(str);
}

int get(int pos, int key) {
		if(ips[pos].count(key)) return ips[pos][key];
		return ips[pos][key] = ips[pos].size() - 1;
}

void fill(int *arr, int c) {
		for(int i=0;i<55;i++) if(arr[0] == 0 || arr[0] == i) {
				for(int j=0;j<55;j++) if(arr[1] == 0 || arr[1] == j) {
						for(int k=0;k<55;k++) if(arr[2] == 0 || arr[2] == k) {
								for(int l=0;l<55;l++) if(arr[3] == 0 || arr[3] == l) {
										if(maxvar[i][j][k][l] < c)
												maxvar[i][j][k][l] = c;
								}
						}
				}
		}
}

class IPv444 
{
public:
    long long getMaximumMoney(vector <string> request, vector <int> price) 
    {		
				memset(maxvar, 0, sizeof(maxvar));

				for(int i=0;i<4;i++) { ips[i].clear(); ips[i][-1] = 0; }
				for(int i=0;i<size(price);i++) {
						int arr[4];
						tokenize(request[i], arr);
						for(int j=0;j<4;j++) arr[j] = get(j, arr[j]);

						fill(arr, price[i]);

						for(int j=0;j<4;j++) cout << arr[j] << " ";
						cout << endl;
				}

				return -1;
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
