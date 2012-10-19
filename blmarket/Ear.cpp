#include <iostream>
#include <queue>
#include <set>
#include <sstream>
#include <algorithm>
#include <numeric>
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

bool comp(const PII &lhs, const PII &rhs) {
		int xx1 = lhs.first;
		int xx2 = rhs.first;
		int yy1 = lhs.second;
		int yy2 = rhs.second;

		return ((LL)xx1 * yy2 < (LL)xx2 * yy1);
}

vector<int> reds;
vector<PII> blues;

int count(int l, int r) {
		int lx = reds[l] + 1;
		int rx = reds[r];
		vector<PII>::const_iterator iter, jter, kter;
		iter = lower_bound(blues.begin(), blues.end(), mp(lx, 0));
		jter = lower_bound(blues.begin(), blues.end(), mp(rx, 0));

		vector<PII> tmps;
		vector<int> index;
		vector<PII> tmp2;
		for(kter = iter; kter != jter; ++kter) {
				PII tt = *kter;
				tt.first -= reds[l];
				tmps.pb(tt);
				tt.first += reds[l];
				tt.first -= reds[r];
				tmp2.pb(tt);
		}
		index.resize(tmps.size());
		sort(tmps.begin(), tmps.end(), comp);
		sort(tmp2.begin(), tmp2.end(), comp);

		for(int i=0;i<size(tmps);i++) {
				cout << tmps[i].first << "," << tmps[i].second << " ";
		}
		cout << endl;
		for(int i=0;i<size(tmps);i++) {
				cout << tmp2[i].first << "," << tmp2[i].second << " ";
		}
		cout << endl;

		int ret = 0;
		for(int i=0;i<size(tmps);i++) {
				PII t1 = tmps[i];
				t1.first += reds[l];
				for(int j=0;j<size(tmp2);j++) {
						PII t2 = tmp2[j];
						t2.first += reds[r];
						if(t1 == t2) {
								ret += j;
								tmp2.erase(tmp2.begin() + j);
								break;
						}
				}
		}
		return ret;
}

class Ear 
{
public:
    long long getCount(vector <string> redX, vector <string> blueX, vector <string> blueY) 
    {		
				reds.clear();
				blues.clear();
				{
						string tmp = accumulate(redX.begin(), redX.end(), string(""));
						istringstream sin(tmp);
						int tmp2;
						while(sin >> tmp2) { reds.pb(tmp2); }
				}
				{
						string tmp = accumulate(blueX.begin(), blueX.end(), string());
						istringstream sin(tmp);
						int tmp2;
						while(sin >> tmp2) { blues.pb(mp(tmp2, 0)); }
				}
				{
						string tmp = accumulate(blueY.begin(), blueY.end(), string());
						istringstream sin(tmp);
						for(int i=0;i<size(blues);i++) {
								int tmp2;
								sin >> tmp2;
								blues[i].second = tmp2;
						}
				}

				long long ret = 0;
				sort(reds.begin(), reds.end());
				sort(blues.begin(), blues.end());
				for(int i=0;i<size(reds);i++) {
						for(int j=i+3;j<size(reds);j++) {
								int btw = j - i;
								long long base = (btw * (btw - 1));
								base /= 2;

								ret += base * count(i,j);
						}
				}

				return ret;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"3 2 8 7"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"5 4"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"2 4"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 1LL; verify_case(0, Arg3, getCount(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"3 2 8 7"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"2 8"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"3 4"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 0LL; verify_case(1, Arg3, getCount(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"1 2 6 9"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"3 6 8 5"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"1 5 4 3"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 4LL; verify_case(2, Arg3, getCount(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"10000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"10000 9999"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"10000 9999"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 0LL; verify_case(3, Arg3, getCount(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"100 2", "00", " 39", "9", " 800 900 9", "99"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"15", "0 250 ", "349"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"2 3 1"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 12LL; verify_case(4, Arg3, getCount(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arr0[] = {"1", " ", "2", " ", "3", " ", "4 5 6", " 7 8 9"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"4", " ", "5", " ", "6", " 7 ", "8"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"1", " 2 ", "3 4", " 5"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 204LL; verify_case(5, Arg3, getCount(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    Ear ___test; 
    ___test.run_test(0); 
} 
// END CUT HERE
