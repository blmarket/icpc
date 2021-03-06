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
#define foreach(it,c) for(auto it=(c).begin(); it != (c).end(); ++it)

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;

template<typename T> int size(const T &a) { return a.size(); }

vector<string> cells;
int N,M;
bool update = false;

char apply(char a, bool flag) {
    if(a == '?' || flag) return a;
    if(a == 'Z') return 'N';
    return 'Z';
}

bool equil(int a, int b, bool same) {
    for(int i=0;i<M;i++) if(cells[a][i] != '?' || cells[b][i] != '?') {
        if(cells[a][i] == '?') update=true, cells[a][i] = apply(cells[b][i], same);
        if(cells[b][i] == '?') update=true, cells[b][i] = apply(cells[a][i], same);
        if(cells[a][i] != apply(cells[b][i], same)) return false;
    }
    return true;
}

class ThreeColorability 
{
public:
    vector <string> lexSmallest(vector <string> cells_) 
    {
        cells = cells_;
        N = size(cells);
        M = size(cells[0]);

a:
        do {
            update = false;
            for(int i=0;i<N;i++) for(int j=i+1;j<N;j++) {
                for(int k=0;k<M;k++) if(cells[i][k] != '?' && cells[j][k] != '?') {
                    if(equil(i,j, cells[i][k] == cells[j][k]) == false) return vector<string>();
                }
            }
        } while(update);

        for(int i=0;i<N;i++) for(int j=0;j<M;j++) {
            if(cells[i][j] == '?') {
                cells[i][j] = 'N';
                goto a;
            }
        }

        return cells;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"Z"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"Z" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, lexSmallest(Arg0)); }
	void test_case_1() { string Arr0[] = {"??", "?N"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NN", "NN" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, lexSmallest(Arg0)); }
	void test_case_2() { string Arr0[] = {"ZZZ", "ZNZ"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, lexSmallest(Arg0)); }
	void test_case_3() { string Arr0[] = {"N?N??NN","??ZN??Z","NN???Z?","ZZZ?Z??","Z???NN?","N?????N","ZZ?N?NN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, lexSmallest(Arg0)); }
	void test_case_4() { string Arr0[] = {"ZZZZ","ZZZZ","ZZZZ"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"ZZZZ", "ZZZZ", "ZZZZ" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, lexSmallest(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    ThreeColorability ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
