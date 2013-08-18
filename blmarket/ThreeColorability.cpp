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

char apply(int same, char k) {
    if(k == '?') return '?';
    if(same == 1) return k;
    if(k == 'N') return 'Z';
    return 'N';
}

class ThreeColorability 
{
public:
    vector <string> lexSmallest(vector <string> cells) 
    {		
        int N = size(cells);
        int M = size(cells[0]);

        for(int i=0;i<N;i++) {
            for(int j=i+1;j<N;j++) {
                int same = 0;
                for(int k=0;k<M;k++) if(cells[i][k] != '?' && cells[j][k] != '?') {
                    int tmp = (cells[i][k] == cells[j][k]) ? 1 : -1;
                    if(same == 0) same = tmp;
                    if(same != tmp) return vector<string>();
                }

                if(same == 0) continue;
                for(int k=0;k<M;k++) {
                    if(cells[i][k] == '?') cells[i][k] = apply(same, cells[j][k]);
                }
            }

            for(int j=i+1;j<N;j++) {
                int same = 0;
                for(int k=0;k<M;k++) if(cells[i][k] != '?' && cells[j][k] != '?') {
                    int tmp = (cells[i][k] == cells[j][k]) ? 1 : -1;
                    if(same == 0) same = tmp;
                    break;
                }
                if(same == 0) continue;
                for(int k=0;k<M;k++) if(cells[j][k] == '?') {
                    cells[j][k] = apply(same, cells[i][k]);
                }
            }

            // debug();
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
    ___test.run_test(1); 
} 
// END CUT HERE
