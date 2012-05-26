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

int n,m;
vector<string> data;
int caves[10][2];

const int dx[] = {1,0,0};
const int dy[] = {0,-1,1};

map<PII, int> reach, r2, nex;

map<PII, int> apply(map<PII, int> now, int move, bool &flag)
{
    map<PII, int> ret;
    bool fail = false;
    foreach(it, now)
    {
        PII npos = mp(it->first.first + dx[move], it->first.second + dy[move]);
        if(data[npos.first][npos.second] == '#') npos = it->first;
        if(r2.count(npos) == 0)
        {
            flag = false;
            return map<PII, int>();
        }
        ret[npos] = 0;
    }
    flag = true;
    return ret;
}

void go(int x,int y)
{
    reach.clear();
    PII pos = mp(x,y);
    reach[pos] = 0;
    queue<PII> Q;
    Q.push(pos);
    while(!Q.empty())
    {
        pos = Q.front();
        Q.pop();
        for(int i=0;i<3;i++)
        {
            int nx = pos.first - dx[i];
            int ny = pos.second - dy[i];
            if(data[nx][ny] == '#') continue;
            PII npos = mp(nx,ny);
            if(reach.count(npos)) continue;
            reach[npos] = 0;
            Q.push(npos);
        }
    }

    // it's sn
    cout << reach.size() << " ";

    r2 = reach;

here:
    cout << "HERE : " << reach.size() << endl;
    foreach(it, reach)
        cout << it->first.first << "," << it->first.second << " ";
    cout << endl;
    if(reach.size() == 1)
    {
        cout << "Lucky" << endl;
        return;
    }

    while(true)
    {
        bool flag = false;
        nex = apply(reach, 1, flag);
        if(nex == reach) break;
        reach = nex;
    }

    if(reach.size() == 1)
    {
        cout << "Lucky" << endl;
        return;
    }

    while(true)
    {
        bool flag = false;
        nex = apply(reach, 0, flag);
        if(flag && reach != nex) 
        {
            reach = nex;
            goto here;
        }
        nex = apply(reach, 2, flag);
        if(nex == reach) break;
        reach = nex;
    }

    if(reach.size() == 1)
    {
        cout << "Lucky" << endl;
        return;
    }

    cout << "Unlucky" << endl;
}

void process(int dataId)
{
    memset(caves, -1, sizeof(caves));
    cin >> n >> m;
    data.resize(n);
    for(int i=0;i<n;i++)
    {
        cin >> data[i];
        for(int j=0;j<m;j++)
        {
            if(data[i][j] >= '0' && data[i][j] <= '9')
            {
                int id = data[i][j] - '0';
                caves[id][0] = i; caves[id][1] = j;
                data[i][j] = '.';
            }
        }
    }

    cout << endl;
    for(int i=0;i<10;i++) if(caves[i][0] != -1) 
    {
        printf("%d: ", i);
        go(caves[i][0], caves[i][1]);
    }
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
