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

string target;
vector<int> cs;
int SC, PC;

int check(int L, int pos) {
		for(int i=pos;i<size(cs);i++) {
				if(cs[i] != 0) {
						for(int j=i+1;j<size(cs);j++) {
								if(cs[j] != 0 && cs[j] != cs[i]) {
										int len = j - pos;
										if(len < L) return -1;
										int st = (len / L) * L;

										int mincost = -1;
										for(int k=len;k>=st;k--) {
												int tmp = check(L, pos + k);
												if(tmp != -1) {
														int tmp2 = (k + (L-1)) / L;
														tmp += tmp2;
														if(mincost == -1 || mincost > tmp) mincost = tmp;
												}
												if(cs[pos + k - 1] != 0) break;
										}
										cout << L << " " << pos << " = " << mincost << endl;
										return mincost;
								}
						}
						int len = size(cs) - pos;
						return (len + (L-1)) / L;
				}
		}
		int len = size(cs) - pos;
		return (len + (L-1)) / L;
}

class Stamp 
{
public:
    int getMinimumCost(string desiredColor, int stampCost, int pushCost) 
    {		
				target = desiredColor;
				cs.resize(target.size());
				for(int i=0;i<size(target);i++) {
						cs[i] = target[i] == 'R' ? 1 : (target[i] == 'G' ? 2 : ( target[i] == 'B' ? 3 : 0));
						cout << cs[i] << " ";
				}
				cout << endl;
				SC = stampCost;
				PC = pushCost;
				
				int mincost = -1;
				for(int i=1;i<size(target);i++) {
						int tmp = i * stampCost;
						int tmp2 = check(i, 0);
						if(tmp2 == -1) continue;
						tmp2 *= pushCost;
						tmp += tmp2;
						if(mincost == -1 || mincost > tmp) mincost = tmp;
				}
				return mincost;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "RRGGBB"; int Arg1 = 1; int Arg2 = 1; int Arg3 = 5; verify_case(0, Arg3, getMinimumCost(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "R**GB*"; int Arg1 = 1; int Arg2 = 1; int Arg3 = 5; verify_case(1, Arg3, getMinimumCost(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "BRRB"; int Arg1 = 2; int Arg2 = 7; int Arg3 = 30; verify_case(2, Arg3, getMinimumCost(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "R*RR*GG"; int Arg1 = 10; int Arg2 = 58; int Arg3 = 204; verify_case(3, Arg3, getMinimumCost(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "*B**B**B*BB*G*BBB**B**B*"; int Arg1 = 5; int Arg2 = 2; int Arg3 = 33; verify_case(4, Arg3, getMinimumCost(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arg0 = "*R*RG*G*GR*RGG*G*GGR***RR*GG"; int Arg1 = 7; int Arg2 = 1; int Arg3 = 30; verify_case(5, Arg3, getMinimumCost(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    Stamp ___test; 
    ___test.run_test(3); 
} 
// END CUT HERE
