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
            cerr << "Applying " << i << endl;
            bool fail = false;
            foreach(it, reach)
            {
                PII npos = mp(it->first.first + dx[i], it->first.second + dy[i]);
                if(data[npos.first][npos.second] == '#') npos = it->first;
                if(reach.count(npos) == 0)
                {
                    fail = true;
                    break;
                }
            }

            if(fail == false)
            {
                cerr << "GOTIT" << endl;
                foreach(it, reach)
                {
                    cerr << it->first.first << " x " << it->first.second << endl;
                    while(it != reach.end() && it->second == 0)
                    {
                        cerr << it->first.first << " v " << it->first.second << endl;
                        map<PII, int>::iterator jt = it;
                        ++it;
                        reach.erase(jt);
                    }
                    if(it != reach.end())
                        it->second = 0;
                }
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
