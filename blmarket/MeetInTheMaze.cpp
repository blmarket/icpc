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
typedef long long LL;

template<typename T> int size(const T &a) { return a.size(); }

vector<string> maze;
int n,m;
vector<PII> rs, fs;
int dist1[52][52];
int dist2[52][52];
int dist3[52][52];
long long distsum = 0;
long long denomi = 0;

const int dx[] = { -1,0,0,1};
const int dy[] = {0,-1,1,0};

bool check(int x,int y)
{
    return x>=0 && y>=0 && x<n && y<m && maze[x][y] != '#';
}

void bfs(const PII &start, int dis[][52])
{
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
            Q.push(mp(nx,ny));
        }
    }

}

void bfs2(const PII &start)
{
    int totalvisit = 0;
    bfs(start, dist2);
    dist3[start.first][start.second] = dist1[start.first][start.second];
    if(dist1[start.first][start.second] == -1)
    {
        denomi = 0;
        return;
    }

    priority_queue<pair<int,PII> > Q;
    Q.push(mp(-dist3[start.first][start.second],start));

    while(!Q.empty())
    {
        PII pos = Q.top().second;
        int x = pos.first, y = pos.second;
        int dis = -Q.top().first;
        Q.pop();

        if(dist3[pos.first][pos.second] != dis) continue;

        if(maze[x][y] == 'L')
        {
            distsum += dist3[x][y];
            totalvisit++;
        }

        for(int i=0;i<4;i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(check(nx,ny) == false) continue;
            int tmp = min(dist1[nx][ny] + dist2[nx][ny], dist3[x][y] + 1);

            if(dist3[nx][ny] == -1 || dist3[nx][ny] > tmp)
            {
                dist3[nx][ny] = tmp;
                Q.push(mp(-tmp, mp(nx,ny)));
            }
        }
    }

    if(totalvisit != denomi)
    {
        cout << "fail" << start.first << " " << start.second << endl;
        denomi = 0;
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
                else if(maze[i][j] == 'L')
                    denomi++;
            }
        }

        for(int i=0;i<size(rs);i++)
        {
            memset(dist1, -1, sizeof(dist1));
            bfs(rs[i], dist1);

            for(int j=0;j<size(fs);j++)
            {
                memset(dist2, -1, sizeof(dist2));
                memset(dist3, -1, sizeof(dist3));
                bfs2(fs[j]);
            }
        }

        denomi *= size(rs);
        denomi *= size(fs);
        if(denomi == 0) return "";
        LL gc = __gcd(denomi, distsum);
        denomi /= gc;
        distsum /= gc;
        ostringstream ost;
        ost << distsum << "/" << denomi;
        return ost.str();
    }

    

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
