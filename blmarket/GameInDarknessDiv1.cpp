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
int dx[] = {-1,0,0,1};
int dy[] = {0,-1,1,0};

bool check(int x, int y) {
    return x>=0 && y>=0 && x<N && y<M;
}

bool isWall(int x, int y) {
    if(!check(x,y)) return true;
    return field[x][y] == '#';
}

int naver(int x, int y) {
    if(isWall(x,y)) return 0;
    int ret = 0;
    for(int i=0;i<4;i++) {
        int nx = x + dx[i], ny = y + dy[i];
        ret += !isWall(nx, ny);
    }
    return ret;
}

int removesingle(int x, int y) {
    int ret = 0;
    if(isWall(x,y)) return 0;
    for(int i=0;i<4;i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if(!isWall(nx, ny) && naver(nx, ny) > 1) {
            ret++;
        }
    }
    return ret;
}

class GameInDarknessDiv1 
{
public:
    string check(vector <string> field_) 
    {
        field = field_;
        N = size(field); M = size(field[0]);
        for(int i=0;i<N;i++) for(int j=0;j<M;j++) {
            if(naver(i,j) > 2) {
                cout << i << " " << j << endl;
            }
        }
        return "";
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
    ___test.run_test(0); 
} 
// END CUT HERE
