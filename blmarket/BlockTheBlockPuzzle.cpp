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

vector<string> board;
int ls = 0;
vector<PII> links[5500];
bool sink[5500];

template<typename T> int label(const T &a) {
    static map<T, int> M;
    if(M.count(a)) return M[a];
    return M[a] = ls++;
}

const int dx[4] = {0,-1,1,0};
const int dy[4] = {-1,0,0,1};

class BlockTheBlockPuzzle 
{
public:
    int minimumHoles(vector <string> board_) 
    {		
        int px, py;
        board = board_;
        int n = size(board);
        int sp;
        for(int i=0;i<size(board);i++) {
            for(int j=0;j<size(board[i]);j++) if(board[i][j] == '$') {
                sp = label(make_tuple(i,j,1));
                px = (i % 3);
                py = (j % 3);
                break;
            }
        }

        for(int i=0;i<size(board);i++) for(int j=0;j<size(board);j++) {
            if((i-px) % 3 == 0 && (j - py) % 3 == 0) if(board[i][j] != 'H') {
                int n1 = label(make_tuple(i, j, 0));
                int n2 = label(make_tuple(i, j, 1));
                if(board[i][j] == 'b') sink[n1] = true;
                links[n1].pb(mp(n2, 1));

                for(int k=0;k<4;k++) {
                    int nx = i + dx[k] * 3;
                    int ny = j + dy[k] * 3;
                    if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

                    char c1 = board[i+dx[k]][j+dy[k]];
                    char c2 = board[i+dx[k]*2][j+dy[k]*2];
                    int flow = 0;
                    if(c1 == 'b' || c2 == 'b') flow = 50000;
                    flow += (c1 == '.') + (c2 == '.');

                    int n3 = label(make_tuple(nx, ny, 0));
                    links[n2].pb(mp(n3, flow));
                }
            }
        }

        int ret = 0;
        int back[5500];

        function<int(int)> try_flow = [&](int sp) -> int {
            if(back[sp] != -1) return 0;
            for(auto it : links[sp]) {
                int np, flow; tie(np, flow) = it;
            }
            return 0;
        };
        while(true) {
            memset(back, -1, sizeof(back));
            int tmp = try_flow(sp);
            if(tmp == 0) break;
            if(tmp > 100) return -1;
            ret += tmp;
        }
        return ret;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"b..$",
 "....",
 "HHHH",
 "HHHH"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, minimumHoles(Arg0)); }
	void test_case_1() { string Arr0[] = {"............H..",
 "...............",
 "...............",
 "HHH$HHH.....H..",
 "HHHHHHH........",
 "HHHHHHHH.......",
 "......b..H.....",
 "...............",
 "...............",
 "...H..H..H.....",
 "...............",
 "...............",
 "...............",
 "...............",
 "..............."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, minimumHoles(Arg0)); }
	void test_case_2() { string Arr0[] = {"............H..",
 "...............",
 "...............",
 "HHH$HHH........",
 "HHHHHHH........",
 "HHHHHHHH.......",
 "......b..H.....",
 "...............",
 "...............",
 "...H..H..H.....",
 "...............",
 "...............",
 "...............",
 "...............",
 "..............."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, minimumHoles(Arg0)); }
	void test_case_3() { string Arr0[] = {"b..$...",
 "...H...",
 ".......",
 "b..b..b",
 "...H...",
 ".......",
 "b..b..b"}

; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(3, Arg1, minimumHoles(Arg0)); }
	void test_case_4() { string Arr0[] = {"b..b..b",
 "..b..b.",
 ".......",
 "b..$bbb",
 ".b.....",
 "....b..",
 "b..b..b"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(4, Arg1, minimumHoles(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    BlockTheBlockPuzzle ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
