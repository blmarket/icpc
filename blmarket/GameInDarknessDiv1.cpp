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

vector<string> field;
int N,M;
int ax,ay,bx,by;
const int dx[] = {-1,0,0,1};
const int dy[] = {0,-1,1,0};

bool chk(int x, int y) { return x>=0 && y>=0 && x<N && y<M; }
bool wall(int x, int y) { return !chk(x,y) || field[x][y] == '#'; }
int ways(int x, int y) {
    int ret = 0;
    for(int i=0;i<4;i++) if(!wall(x+dx[i], y+dy[i])) ret++;
    return ret;
}

int ad,bd = 0;

int dfs(int x, int y, int px, int py, int dist) {
    cout << x << " " << y << endl;
    int ret = dist;
    for(int i=0;i<4;i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if(nx == px && ny == py) continue;
        int tmp = dfs(nx,ny,x,y, dist + 1);
        ret = max(ret, tmp);
    }
    return ret;
}

bool calc(int x, int y) {
    int holes = 0;
    for(int i=0;i<4;i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if(wall(nx,ny)) continue;
        int md = dfs(nx, ny, x, y, 1);
        if(md > 2) holes++;
    }
    if(holes > 1) return true;
}

class GameInDarknessDiv1 
{
public:
    string check(vector <string> field_) 
    {
        field = field_;
        N = size(field); M = size(field[0]);
        for(int i=0;i<N;i++) for(int j=0;j<M;j++) {
            if(field[i][j] == 'A') { ax=i;ay=j; }
            if(field[i][j] == 'B') { bx=i;by=j; }
        }

        for(int i=0;i<N;i++) for(int j=0;j<M;j++) {
            if(!wall(i,j)) {
                cout << i << " " << j << " = " << ways(i,j) << endl;
                if(ways(i,j) > 2) { // hiding place
                    cout << i << " " << j << endl;
                    if(calc(i,j)) return "Bob wins";
                }
            }
        }
        return "Alice wins";
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"A.B..",
 "##.##",
 "##.##"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Alice wins"; verify_case(0, Arg1, check(Arg0)); }
	void test_case_1() { string Arr0[] = {"A.B..",
 ".#.#.",
 "#..##"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Bob wins"; verify_case(1, Arg1, check(Arg0)); }
	void test_case_2() { string Arr0[] = {"#...#",
 ".#A#.",
 "..B..",
 ".#.#.",
 "#...#"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Alice wins"; verify_case(2, Arg1, check(Arg0)); }
	void test_case_3() { string Arr0[] = {"##..#",
 "A.#..",
 "#B..#",
 "#.##.",
 "....."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Alice wins"; verify_case(3, Arg1, check(Arg0)); }
	void test_case_4() { string Arr0[] = {"##################################################",
 "###..................#................#........###",
 "###.################.########.#######.########.###",
 "###.################.########.#######.########.###",
 "###.################.########.#######.########.###",
 "###.################.########.#######.########.###",
 "###.################.########.#######.########.###",
 "###.################.########.#######.########.###",
 "###.################.########.#######.########.###",
 "###.################.########.#######.########.###",
 "###..........#######........#.#######........#.###",
 "############.#######.########.#######.########.###",
 "############.#######.########.#######.########.###",
 "############.#######.########.#######.########.###",
 "############.#######.########.#######.########.###",
 "############.#######.########.#######.########.###",
 "############.#######.########.#######.########.###",
 "############.#######.########.#######.########.###",
 "############.#######.########.#######.########.###",
 "###B.........#######..........#######..A.......###",
 "##################################################"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Bob wins"; verify_case(4, Arg1, check(Arg0)); }
	void test_case_5() { string Arr0[] = {"###.#",
 "###..",
 "A..B#",
 "###..",
 "###.#"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Alice wins"; verify_case(5, Arg1, check(Arg0)); }
	void test_case_6() { string Arr0[] = {".....#.##.##.#.#",
 ".###.#.##.##....",
 "#......B#...#.#.",
 "#.#A#.#.#.#..##.",
 "...#..#....#...."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Alice wins"; verify_case(6, Arg1, check(Arg0)); }
	void test_case_7() { string Arr0[] = {"...#.....###....#.....#...#.#.",
 ".#..#.##..#..#.#..###...#.....",
 "..#..#..#...#.#..#....##.#.###",
 ".#.#...###.#..#.#..###....#...",
 "...##.###..#.#..#.#...#.##..#.",
 ".#..#..#..#...#.#.#.#.#..#.#..",
 "..#..#.#.#..#..##.#.#..#.##..#",
 ".#.###.#.##..#.....A##......#.",
 "#.........#.#..#.###..###.#...",
 "..###.#.#.#..#.#....#.....#.#.",
 ".#..#.#.####.#..#.#..#.#.###..",
 "..#...#...#..#.#...#.#..#.#..#",
 "#..#.#..#.#.#..###.#.#.#....#.",
 "..#..##.##...#....#..#.#.####.",
 "#..#...#...#..#.#..###.#......",
 "#.#.##...#..#..#.#....#..#.#.#",
 "....#..##.#..#....#.#.#.#...#.",
 ".#.#..#....#.#.##..#..##..#.#.",
 "..##.#..##.#..#..#..#...#.#...",
 "#.#..##..#..#..#..#..##.#.#.#.",
 "..#.#.#.#.#..#...##.#...#..#..",
 ".##.....#..#.#.#.#..#.##.#..#.",
 "...#.#.#..#..#.###.#..#...#.#.",
 ".#..#....#..#.#...###.#.#..#..",
 ".#.#.#####.#....#..#..#.##.#.#",
 ".#...#......#.#..###B#....#...",
 "..###..####.#..#.#...#.#.#..#.",
 "#.#..#.#..#.#.#..#.#..#....#..",
 "..#.##..#.#.#.####..#.#####..#",
 "#.....#...#.#......#.......#.."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Bob wins"; verify_case(7, Arg1, check(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    GameInDarknessDiv1 ___test; 
    ___test.run_test(1); 
} 
// END CUT HERE
