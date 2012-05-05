#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <sstream>
#include <numeric>
#include <iterator>
#include <queue>
#include <set>
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

int h,n,m;
int ceil[105][105];
int floo[105][105];
int reach[105][105];

const int dx[] = {-1,0,0,1};
const int dy[] = {0,-1,1,0};

int check(int curtime, int tc, int tf)
{
    if(tc < tf+50) return -1;
    int curh = h - curtime * 10;
    int low = max(curh, tf);

    if(tc - low >= 50) // you can move right now
    {
        if(curh - tf >= 20) return curtime+10;
        return curtime + 100;
    }

    int tgt = tc - 50;
    int elasp = (curh - tgt);

    cout << "wait " << elasp << endl;

    if(tgt - tf >= 20)
        return curtime + elasp + 10;
    return curtime + elasp + 100;
}

void process(int dataId)
{
    scanf("%d %d %d" ,&h, &n, &m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d", &ceil[i][j]);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d", &floo[i][j]);

    memset(reach, -1, sizeof(reach));
    reach[0][0] = 0;
    queue<PII> Q;
    Q.push(mp(0,0));
    while(!Q.empty())
    {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();

        for(int i=0;i<4;i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

            if(ceil[nx][ny] >= 50 + h)
            {
                reach[nx][ny] = 0;
                Q.push(mp(nx,ny));
            }
        }
    }

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) if(reach[i][j] == 0) 
        {
            Q.push(mp(i,j));
        }

    while(!Q.empty())
    {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();

        for(int i=0;i<4;i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            int tmp = check(reach[x][y], ceil[nx][ny], floo[nx][ny]);
            if(reach[nx][ny] == -1 || reach[nx][ny] > tmp)
            {
                reach[nx][ny] = tmp;
                Q.push(mp(nx,ny));
            }
        }
    }

    printf("%.12lf\n", (double)reach[n-1][m-1]/10);
}

int main(void)
{
    int N;
    cin >> N;
    for(int i=1;i<=N;i++)
    {
        printf("Case #%d: ",i);
        process(i);
        cerr << i << endl;
    }
}
