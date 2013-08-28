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

string color;
vector<string> graph;

bool visit[55];
vector<int> links[55];
int used[55];

bool try_flow(int a) {
    if(visit[a]) return false;
    visit[a] = true;

    for(int i=0;i<size(links[a]);i++) {
        int v = links[a][i];
        if(used[v] == -1 || try_flow(used[v])) {
            used[v] = a;
            return true;
        }
    }
    return false;
}

int go(char a, char b) {
    for(int i=0;i<size(graph);i++) links[i].clear();

    for(int i=0;i<size(graph);i++) if(color[i] == a) {
        for(int j=0;j<size(graph[i]);j++) if(graph[i][j] == 'Y') if(color[j] == b) {
            links[i].pb(j);
        }
    }

    memset(used, -1, sizeof(used));

    int flow = 0;
    for(int i=0;i<size(graph);i++) if(links[i].size()) {
        memset(visit, 0, sizeof(visit));
        if(try_flow(i)) {
            flow++;
        }
    }
    return flow;
}

class GearsDiv1 
{
public:
    int getmin(string color_, vector <string> graph_) 
    {
        color = color_; graph = graph_;
        int t1 = go('R', 'G');
        t1 = min(t1, go('R', 'B'));
        t1 = min(t1, go('G', 'B'));
        return t1;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "RGB"; string Arr1[] = {"NYY","YNY","YYN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(0, Arg2, getmin(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "RGBR"; string Arr1[] = {"NNNN","NNNN","NNNN","NNNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(1, Arg2, getmin(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "RGBR"; string Arr1[] = {"NYNN","YNYN","NYNY","NNYN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(2, Arg2, getmin(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "RRRRRGRRBGRRGBBGGGBRRRGBRGRRGG"; string Arr1[] = {"NNNNNYNNNYNNYNNNYNNNNNNNNYNNYY",
 "NNNNNNNNYNNNYNYNNYNNNNYNNYNNYY",
 "NNNNNYNNNNNNNNNNNNYNNNNNNYNNNY",
 "NNNNNNNNNYNNYNNYYYNNNNYNNYNNNN",
 "NNNNNNNNNYNNYNNYYYNNNNYNNNNNNN",
 "YNYNNNYYYNNYNYYNNNNNYYNYNNYYNN",
 "NNNNNYNNNNNNNNNYYYNNNNYNNYNNYY",
 "NNNNNYNNNNNNNNNYNNNNNNNNNNNNYN",
 "NYNNNYNNNYNNYNNYYYNNNNYNNYNNYY",
 "YNNYYNNNYNNNNYYNNNYNYYNYNNNNNN",
 "NNNNNNNNNNNNYNNYNYNNNNYNNNNNNY",
 "NNNNNYNNNNNNYNNYYYNNNNNNNNNNYN",
 "YYNYYNNNYNYYNYYNNNYNYNNYNNNNNN",
 "NNNNNYNNNYNNYNNYYYNNNNYNNYNYYY",
 "NYNNNYNNNYNNYNNYYYNNNNYNNYNNYY",
 "NNNYYNYYYNYYNYYNNNYNYNNYYNYYNN",
 "YNNYYNYNYNNYNYYNNNYNNNNYYNNYNN",
 "NYNYYNYNYNYYNYYNNNNYYNNYYNYNNN",
 "NNYNNNNNNYNNYNNYYNNNNNYNNYNNNY",
 "NNNNNNNNNNNNNNNNNYNNNNYNNYNNNY",
 "NNNNNYNNNYNNYNNYNYNNNNYNNNNNYY",
 "NNNNNYNNNYNNNNNNNNNNNNYNNNNNNN",
 "NYNYYNYNYNYNNYYNNNYYYYNYYNYNNN",
 "NNNNNYNNNYNNYNNYYYNNNNYNNNNNNY",
 "NNNNNNNNNNNNNNNYYYNNNNYNNYNNYY",
 "YYYYNNYNYNNNNYYNNNYYNNNNYNYYNN",
 "NNNNNYNNNNNNNNNYNYNNNNYNNYNNYN",
 "NNNNNYNNNNNNNYNYYNNNNNNNNYNNYY",
 "YYNNNNYYYNNYNYYNNNNNYNNNYNYYNN",
 "YYYNNNYNYNYNNYYNNNYYYNNYYNNYNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(3, Arg2, getmin(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    GearsDiv1 ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
