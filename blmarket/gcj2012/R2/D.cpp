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

const int dx[] = {0,0,1};
const int dy[] = {-1,1,0};

map<PII, int> reach;

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

    cout << reach.size() << " ";

    while(reach.size() > 1)
    {
        bool done = false;
        for(int i=0;i<3;i++)
        {
            bool fail = false;
            foreach(it, reach)
            {
                cout << it->first.first << " " << it->first.second << " ";
                PII npos = mp(it->first.first + dx[i], it->first.second + dy[i]);
                if(data[npos.first][npos.second] == '#') npos = it->first;
                if(reach.count(npos) == 0)
                {
                    fail = true;
                    break;
                }
            }
            cout << endl;

            if(fail == false)
            {
                map<PII, int>::iterator it, jt;
                for(it = reach.begin(); it != reach.end();)
                {
                    if(it->second == 0)
                    {
                        jt = it;
                        ++it;
                        reach.erase(jt);
                    }
                    else
                    {
                        it->second = 0;
                        ++it;
                    }
                }
                cout << "RESULT REACH SIZE : " << size(reach) << endl;
                done = true;
                break;
            }
        }
        if(done == false)
        {
            cout << "Unlucky" << endl;
            return;
        }
    }
    cout << "Lucky" << endl;
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
