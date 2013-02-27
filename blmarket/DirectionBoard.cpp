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

const int dx[] = {-1, 0,0, 1};
const int dy[] = {0,-1,1,0};

int N,M;

int intake[230];
map<int, PII> links[230];

int R(int x) { return (x + N) % N; }
int C(int y) { return (y + M) % M; }
int node(int x,int y) {
    return x*M + y;
}

int back[230];
int mincost[230];
int find_sink(int a) {
    memset(back, -1, sizeof(back));
    priority_queue<PII> Q;

    Q.push(mp(0, a));
    back[a] = a;
    mincost[a] = 0;

    int minc = 99999, mind;

    while(!Q.empty()) {
        int cur = Q.top().first;
        int pos = Q.top().second; 
        Q.pop();
        if(mincost[pos] != cur) continue;

        if(intake[pos] == -1 && minc > mincost[pos]) { minc = mincost[pos]; mind = pos; }
        
        foreach(it, links[pos]) {
            int node = it->first;
            PII cost = it->second;
            int ncost;
            if(cost.second) { // back link;
                ncost = cur - 1;
            } else if(cost.first) {
                ncost = cur + 1;
            }

            if(back[node] == -1 || mincost[node] > ncost) {
                back[node] = pos;
                mincost[node] = ncost;
                Q.push(mp(ncost, node));
            }
        }
    }

    intake[mind]++;
    intake[a]--;
    while(mind != a) {
        int b = back[mind];
        if(links[b][mind].second) {
            links[b][mind].second--;
            links[mind][b].first++;
        } else {
            links[b][mind].first--;
            links[mind][b].second++;
        }
        mind = b;
    }

    return minc;
}

class DirectionBoard 
{
public:
    int getMinimum(vector <string> board) 
    {		
        N = size(board); M = size(board[0]);
        memset(intake, 0, sizeof(intake));
        for(int i=0;i<230;i++) links[i].clear();

        for(int i=0;i<N;i++) for(int j=0;j<M;j++) {
            if(board[i][j] == 'U') board[i][j] = 0;
            else if(board[i][j] == 'L') board[i][j] = 1;
            else if(board[i][j] == 'R') board[i][j] = 2;
            else board[i][j] = 3;

            int d = board[i][j];
            int nx = R(i + dx[d]), ny = C(j + dy[d]);
            intake[node(nx,ny)]++;

            for(int k=0;k<4;k++) if(k != d) {
                int tx = R(i + dx[k]), ty = C(j + dy[k]);
                links[node(nx,ny)][node(tx,ty)].first++;
            }
        }

        for(int i=0;i<N;i++) for(int j=0;j<M;j++) intake[node(i,j)] -= 1;

        int ret = 0;
        for(int i=0;i<N;i++) for(int j=0;j<M;j++) {
            while(intake[node(i,j)] > 0) {
                ret += find_sink(node(i,j));
            }
        }
        return ret;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"RRRD",
 "URDD",
 "UULD",
 "ULLL"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(0, Arg1, getMinimum(Arg0)); }
	void test_case_1() { string Arr0[] = {"RRRD",
 "URLL",
 "LRRR"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, getMinimum(Arg0)); }
	void test_case_2() { string Arr0[] = {"RRD",
 "URD",
 "ULL"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, getMinimum(Arg0)); }
	void test_case_3() { string Arr0[] = {"ULRLRD",
 "UDDLRR"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(3, Arg1, getMinimum(Arg0)); }
	void test_case_4() { string Arr0[] = {"UDLRLDLD",
 "DLDLLDLR",
 "LLLLLDLD",
 "UUURRRDD"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; verify_case(4, Arg1, getMinimum(Arg0)); }
	void test_case_5() { string Arr0[] = {"UDUDUUDUDUDUDUR",
 "LLLLDUUDRDLUDRU",
 "DLLDLDURDURUDDL",
 "UDUDUUDUDUDUDUR",
 "LLLLDUUDRDLUDRU",
 "DLLDLDURDURUDDL",
 "UDUDUUDUDUDUDUR",
 "LLLLDUUUDDLUDRU",
 "DLLDLDURDURUDDL",
 "UDUDUUDUDUDUDUR",
 "LLLLDUUDRDLUDRU",
 "DLLDLDURDURUDDL",
 "UDUDUUDUDUDUDUR",
 "LLLLDUUDRDLUDRU",
 "RRRDLDURDURUDDR"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 73; verify_case(5, Arg1, getMinimum(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    DirectionBoard ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
