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

int water, land;
vector<int> block;
int depth;

int check(VI &a, int sz, int cur) {
		if(size(a) < sz) return -1;
		for(int i=0;i<sz;i++) {
				if(a[i] == cur || a[i] == cur + 1) {
						cur = a[i];
						continue;
				}
				return i;
		}
		return sz;
}

class CrossingTheRiver 
{
public:
    string isItEvenPossible(int waterWidth_, int landWidth_, vector <int> blockHeight, int depth_) 
    {		
				water = waterWidth_; land = landWidth_; block = blockHeight; depth = depth_;

				sort(block.begin(), block.end());

				vector<int> left, right, tmp;

				for(int i=0;i<size(block);i++) {
						if(block[i] < depth) {
								right.pb(block[i]);
						} else {
								left.pb(block[i] - depth);
						}
				}
				sort(left.begin(), left.end());

				while(true) {
						if(check(left, water, 0) != water) return "IMPOSSIBLE";

						if(left[water - 1] == 0) {
								return "POSSIBLE";
						}

						tmp = right;
						for(int i=water;i<size(left);i++) {
								tmp.pb(left[i] + depth);
						}
						sort(tmp.begin(), tmp.end());
						cout << "first one = " << left[water-1] << endl;
						int tmp2 = check(tmp, land, left[water-1]);

						if(tmp2 == land) return "POSSIBLE";
						if(tmp2 == -1) return "IMPOSSIBLE";

						int target = tmp[tmp2] - 1 - depth;
						if(target < 0) return "IMPOSSIBLE";

						bool fail = true;
						for(int i=0;i<size(left);i++) {
								if(left[i] == target) {
										right.pb(left[i] + depth);
										left.erase(left.begin() + i);
										fail = false;
										break;
								}
						}
						if(fail) return "IMPOSSIBLE";
				}


				return "IMPOSSIBLE";
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 3; int Arr2[] = {3,4,4,5,5, 6}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; string Arg4 = "POSSIBLE"; verify_case(0, Arg4, isItEvenPossible(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 3; int Arr2[] = {3,4,4,5,6, 6}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; string Arg4 = "IMPOSSIBLE"; verify_case(1, Arg4, isItEvenPossible(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 2; int Arr2[] = {4,4,4,4,4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 4; string Arg4 = "POSSIBLE"; verify_case(2, Arg4, isItEvenPossible(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 5; int Arg1 = 5; int Arr2[] = {5,5,5,5,5,5, 2,3,4,4,6, 7, 3, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; string Arg4 = "POSSIBLE"; verify_case(3, Arg4, isItEvenPossible(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 5; int Arg1 = 7; int Arr2[] = {6,6,6,6,6,6,6, 6,6,6,6,6,7,8,9,10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 5; string Arg4 = "POSSIBLE"; verify_case(4, Arg4, isItEvenPossible(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arg0 = 1; int Arg1 = 1; int Arr2[] = {5,3,4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; string Arg4 = "IMPOSSIBLE"; verify_case(5, Arg4, isItEvenPossible(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    CrossingTheRiver ___test; 
    ___test.run_test(4); 
} 
// END CUT HERE
