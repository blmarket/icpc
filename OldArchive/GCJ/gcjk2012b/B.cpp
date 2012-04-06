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

int n,m,K,s4,s3,s2;
vector<string> board;
vector<PII> qq;
long long tot;
int cases;

int dx[] = {0,1,1,1};
int dy[] = {1,0,1,-1};

int calc(void)
{
    int maxl[9][9];
    memset(maxl,0,sizeof(maxl));

    int ret = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            for(int k=0;k<4;k++)
            {
                int nx = i-dx[k];
                int ny = j-dy[k];
                if(!(nx < 0 || ny < 0 || nx >= n || ny >= m))
                {
                    if(board[nx][ny] == board[i][j]) continue;
                }
                int l;
                for(l=1;;l++)
                {
                    int nx = i + l*dx[k];
                    int ny = j + l*dy[k];
                    if(nx < 0 || ny < 0 || nx >= n || ny >= m) break;
                    if(board[nx][ny] != board[i][j]) break;
                }
                for(int t=0;t<l;t++)
                {
                    int nx = i + t*dx[k];
                    int ny = j + t*dy[k];
                    maxl[nx][ny] = max(maxl[nx][ny], l);
                }
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(maxl[i][j] >= 4) ret += s4;
            else if(maxl[i][j] == 3) ret += s3;
            else if(maxl[i][j] == 2) ret += s2;
        }
    }

    return ret;
}

void go(int a)
{
    if(a == size(qq))
    {
        tot += calc();
        cases++;
        return;
    }

    int x = qq[a].first, y = qq[a].second;
    for(int i=1;i<=K;i++)
    {
        board[x][y] = '0'+i;
        go(a+1);
    }
    board[x][y]='?';
}

void process(void)
{
    cin >> n >> m >> K >> s4 >> s3 >> s2;
    board.clear(); qq.clear();
    tot=0;
    cases =0;
    for(int i=0;i<n;i++)
    {
        string str;
        cin >> str;
        board.pb(str);

        for(int j=0;j<size(str);j++)
            if(str[j] == '?') qq.pb(mp(i,j));
    }

    go(0);
    printf("%.10lf\n",(double)tot/cases);
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
