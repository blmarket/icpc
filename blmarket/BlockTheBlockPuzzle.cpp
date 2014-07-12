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

/**o
 * Problem: 500
 * Test Case: 16
 * Succeeded: No
 * Execution Time: 0 ms
 * Peak memory used: 11.750MB
 * Args:
 * {{"...........H....bb.....b...", "...........................", "........HH.b..b.....H......", ".............b.Hb..H.....H.", "....H........H.............", ".............HH..b.........", "b....H..........b.........b", "..HH.Hb....$.....H...b..H..", "..........H................", "..........H....HH..........", "...............H.........b.", "H...........bH....HbH..HbH.", "...H........H.............b", "........H.....b...H.H....H.", "................H....b...H.", "bb..........H....b..Hb.....", "..............b..H.........", "...H......b................", "b......H...HH..............", ".....H.....................", "..............H............", "..H.........b....b.........", "..........b................", "...b.bH..........H.........", "...HH..................H..H", "...........H......H........", "b........H............bb..."}}
 *
 * Expected:
 * 4
 *
 * Received:
 * 1
 *
 * Answer checking result:
 * Returned value must exactly match the expected one.
 *
 */

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

void add_link(int s, int e, int f) {
    for(auto &it : links[s]) {
        if(it.first == e) {
            it.second += f;
            if(it.second == 0) {
                swap(it, links[s].back());
                links[s].pop_back();
            }
            return;
        }
    }
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
                // cout << i << " " << j << " " << n1 << endl;
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
                    if(flow == 0) continue;

                    int n3 = label(make_tuple(nx, ny, 0));
                    links[n2].pb(mp(n3, flow));
                }
            }
        }

        int ret = 0;
        bool back[5500];

        function<bool(int)> try_flow = [&](int sp) -> bool {
            if(back[sp]) return false;
            if(sink[sp]) {
                cout << sp << endl;
                return true;
            }

            back[sp] = true;

            for(auto &it : links[sp]) {
                int np, flow; tie(np, flow) = it;
                if(try_flow(np)) {
                    cout << sp << endl;
                    add_link(sp, np, -1);
                    add_link(np, sp, 1);
                    return true;
                }
            }
            return false;
        };
        while(true) {
            memset(back, 0, sizeof(back));
            int tmp = try_flow(sp);
            cout << tmp << endl;
            if(!tmp) break;
            ret += tmp;
            if(ret > 5000) return -1;
        }
        return ret;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = 
           {"............H..", "...............", "...............", "HHH$HHH........", "HHHHHHH........", "HHHHHHHH.......", "......b..H.....", "...............", "...............", "...H..H..H.....", "...............", "...............", "...............", "...............", "..............."} ;
            vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, minimumHoles(Arg0)); }
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
    ___test.run_test(0); 
} 
// END CUT HERE
