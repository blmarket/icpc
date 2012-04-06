#include <iostream>
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

template<typename T> int size(const T &a) { return a.size(); } 

int k;
vector<vector<int> > floor[55];
int idx;
int n1,n2;

set<int> flow[5000];
int used[5000];
bool visit[5000];

int dx[] = {-1,0,0,1};
int dy[] = {0,-1,1,0};

bool try_flow(int a)
{
    if(visit[a]) return false;
    visit[a]=true;
    foreach(it, flow[a])
    {
        int i = *it;
        if(used[i] == 0 || try_flow(used[i]))
        {
            used[i] = a;
            return true;
        }
    }
    return false;
}

void link(vector<vector<int> > &a, vector<vector<int> > &b)
{
    for(int i=0;i<size(a);i++)
    {
        for(int j=0;j<size(a[i]);j++)
        {
            if(a[i][j] == -1) continue;
            if(b[i][j] == -1) continue;

            flow[a[i][j]].insert(b[i][j]);
        }
    }
}

void dfs(vector<vector<int> > &a, int x, int y, int c)
{
    a[x][y] = c;
    for(int i=0;i<4;i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny<0 || nx >=size(a) || ny >= size(a[x])) continue;
        if(a[nx][ny] != 0) continue;
        dfs(a, nx,ny,c);
    }
}

void mark(vector<vector<int> > &a)
{
    for(int i=0;i<size(a);i++)
    {
        for(int j=0;j<size(a[i]);j++)
        {
            if(a[i][j] == 0)
            {
                dfs(a,i,j,idx++);
            }
        }
    }
}

void process(void)
{
    int n,m;
    cin >> n >> m >> k;
    for(int i=0;i<k;i++)
    {
        floor[i].clear();
        floor[i].resize(n);
        for(int j=0;j<n;j++)
        {
            string tmp;
            cin >> tmp;
            for(int k=0;k<size(tmp);k++)
            {
                if(tmp[k] == '.')
                    floor[i][j].pb(0);
                else
                    floor[i][j].pb(-1);
            }
        }
    }

    memset( used, 0, sizeof(used) );

    idx = 1;
    for(int i=0;i<k;i+=2)
    {
        mark(floor[i]);
    }

    n1 = idx;

    for(int i=1;i<n1;i++)
        flow[i].clear();

    idx = 1;
    for(int i=1;i<k;i+=2)
    {
        mark(floor[i]);

        for(int j=-1;j<=1;j+=2)
        {
            if(i+j >= k) break;
            link(floor[i+j], floor[i]);
        }
    }

    n2 = idx;

    cerr << n1 << " " << n2 << endl;

    int flow = 0;
    for(int i=1;i<n1;i++)
    {
        memset(visit, 0, sizeof(visit));
        if(try_flow(i)) flow++;
    }

    cout << n1+n2-2-flow << endl;
}

int main(void)
{
    int N;
    cin >> N;
    for(int i=1;i<=N;i++)
    {
        printf("Case #%d: ",i);
        process();
        cerr << i << endl;
    }
}
