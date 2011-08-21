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

vector<string> maze;
int n,m;
vector<PII> rs, fs;
int dist1[52][52];
int dist2[52][52];
int dist3[52][52];

const int dx[] = { -1,0,0,1};
const int dy[] = {0,-1,1,0};

bool check(int x,int y)
{
    return x>=0 && y>=0 && x<n && y<m && maze[x][y] != '#';
}

void bfs(const PII &start, int dis[][52])
{
    memset(dis, -1, sizeof(dis));
    dis[start.first][start.second] = 0;

    queue<PII> Q;
    Q.push(start);

    while(!Q.empty())
    {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();

        for(int i=0;i<4;i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if(check(nx,ny) == false) continue;
            if(dis[nx][ny] != -1) continue;

            dis[nx][ny] = dis[x][y] + 1;
            cout << nx << " " << ny << " = " << dis[x][y]+1 << endl;
            Q.push(mp(nx,ny));
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cout << dis[i][j] << " ";
        cout << endl;
    }
}

void bfs2(const PII &start)
{
    bfs(start, dist2);
    dist3[start.first][start.second] = dist[start.first][start.second];

    priority_queue<pair<PII,int> > Q;
    Q.push(mp(start, dist[start.first][start.second]));

    while(!Q.empty())
    {
        PII pos = Q.top().first;
        int x = pos.first, y = pos.second;
        int dis = -Q.top().second;
        Q.pop();

        if(dist3[pos.first][pos.second] != dis) continue;

        if(maze[x][y] == 'L')
        {
            cout << dist[x][y] << " " << dist2[x][y] << " " << dist3[x][y] << endl;
        }

        for(int i=0;i<4;i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(check(nx,ny) == false) continue;
            int tmp = min(dist[nx][ny] + dist2[nx][ny], dist3[x][y] + 1);

            if(dist3[nx][ny] == -1 || dist3[nx][ny] > tmp)
            {
                dist3[nx][ny] = tmp;
                Q.push(mp(mp(nx,ny), -tmp));
            }
        }
    }
}

class MeetInTheMaze 
{
public:
    string getExpected(vector <string> maze_) 
    {
        maze = maze_;
        n = size(maze); m = size(maze[0]);
        rs.clear(); fs.clear();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(maze[i][j] == 'R')
                    rs.pb(mp(i,j));
                else if(maze[i][j] == 'F')
                    fs.pb(mp(i,j));
            }
        }

        for(int i=0;i<size(rs);i++)
        {
            bfs(rs[i], dist);

            for(int j=0;j<n;j++)
            {
                for(int k=0;k<n;k++)
                    cout << dist[j][k] << " ";
                cout << endl;
            }

            for(int j=0;j<size(fs);j++)
            {
                memset(dist2, -1, sizeof(dist2));
                memset(dist3, -1, sizeof(dist3));
                bfs2(fs[j]);
            }
        }
        return "";
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = { "#########", 
  "####F####", 
  "##L...R##", 
  "####L####", 
  "#########" }
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "9/2"; verify_case(0, Arg1, getExpected(Arg0)); }
	void test_case_1() { string Arr0[] = { "LR", 
  "RF" }
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "2/1"; verify_case(1, Arg1, getExpected(Arg0)); }
	void test_case_2() { string Arr0[] = { "..F.#...", 
  "L.F.#..L", 
  "..F.#...", 
  ".R.#..L.", 
  "...#....", 
  "..R#.L.." }
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = ""; verify_case(2, Arg1, getExpected(Arg0)); }
	void test_case_3() { string Arr0[] = { ".L..L..L..", 
  "..........", 
  "..........", 
  "..........", 
  "........R.", 
  "...R......", 
  "..........", 
  "..........", 
  "..........", 
  ".......F.." }
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "40/3"; verify_case(3, Arg1, getExpected(Arg0)); }
	void test_case_4() { string Arr0[] = { "#.#....#...#.#", 
  "#...#..#......", 
  ".L#...#R#..#F.", 
  "#...#......#..", 
  "#......#.....#", 
  ".R.....F....L.", 
  "##..#.......#.", 
  "#........##...", 
  ".F...##L#..#R#" }
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "362/27"; verify_case(4, Arg1, getExpected(Arg0)); }
	void test_case_5() { string Arr0[] = { "LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLFLLLLLLLLLFLLLL", 
  "LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL", 
  "LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL", 
  "LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL", 
  "LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL", 
  "LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL", 
  "LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL", 
  "LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL", 
  "LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLFFLLLLLLLLLLRLLLL", 
  "LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL", 
  "LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL", 
  "LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL", 
  "LLLLLLLLLLLLLLLLLLLLLLLLLLLLRLLLLLFLLLLLLLLLLLLLLF", 
  "LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL", 
  "LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLF", 
  "LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLFLLL", 
  "LLLLLLLLLLLRLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL", 
  "LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLRRL", 
  "LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL", 
  "LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL", 
  "LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLRLLLLLLLLLLLLLLLL", 
  "LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLR", 
  "LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL", 
  "LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLRLLL", 
  "LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL", 
  "LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLRLLLLLL", 
  "LLLLLLLLLLLLLLLLLLLLLLLRLLLLLLLLLLLLLLLLLLLLLLLLLL", 
  "LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL", 
  "LLLLLLLLLLLLLLLLRLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL", 
  "LLLLLLLLLFFLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL", 
  "FLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL", 
  "LLLLLLLLLLLLLLLLRLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL", 
  "LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL", 
  "LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL", 
  "LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLRLLLLLLLLLLLLLL", 
  "LLLLLLLLLLLLLLLLLLLLLLFLLLLLLLLLLLLLLLLLLLLLLLLLLL", 
  "LLLLLLLLLLLLLLLLFLLLLLLLLLRLLLLLLLLLLLLLLLLLLLRLLL", 
  "LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL", 
  "LLLLLLLFLLLLLLLLLLLLLLLLRLLLLLLLLLRLLLLLLLLLLLLRLL", 
  "LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLRLLLLL", 
  "LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL", 
  "LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL", 
  "LLLFLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL", 
  "LLLLLLLLLLLLLLLLLLLLLLLLLFLLLLLLLLLLLLLLLLLLLLLLLL", 
  "LLLLLLLLLLLLLLLLLLLLFLLLLLLLLLLLLLLLLLLLLLLLLLLLLL", 
  "FLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL", 
  "LLLLLLLLLRLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL", 
  "LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL", 
  "LLLLLLLLLFLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL", 
  "LLLLLLLLLLLLLLLLLLLLLLLLLLLFLLLLLLLLLLLLLLLLLLLLLL" }
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "210623/4100"; verify_case(5, Arg1, getExpected(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    MeetInTheMaze ___test; 
    ___test.run_test(0); 
} 
// END CUT HERE
