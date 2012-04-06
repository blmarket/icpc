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

void process(void)
{
    int n,p,m;
    vector<int> xs, vs;
    int dist[150][150];

    memset(dist, -1, sizeof(dist));
    scanf("%d %d %d",&n,&p,&m);
    for(int i=1;i<=n;i++)
        dist[i][i] = 0;
    for(int i=0;i<p;i++)
    {
        int t1,t2;
        scanf("%d %d",&t1,&t2);
        xs.pb(t1);
        vs.pb(t2);
    }

    for(int i=0;i<m;i++)
    {
        int t1,t2;
        scanf("%d %d",&t1,&t2);
        int prev = -1;
        for(int j=0;j<t2;j++)
        {
            int tmp;
            scanf("%d",&tmp); 

            if(prev != -1)
            {
                if(dist[prev][tmp] == -1 || dist[prev][tmp] > t1)
                {
                    dist[prev][tmp] = dist[tmp][prev] = t1;
                }
            }
            prev = tmp;
        }
    }

    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            if(dist[i][k] == -1) continue;
            for(int j=1;j<=n;j++)
            {
                if(dist[k][j] == -1) continue;
                if(dist[i][j] == -1 || dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    int ret = -1;
    for(int i=1;i<=n;i++)
    {
        int tmp = 0;
        for(int j=0;j<p;j++)
        {
            if(dist[i][xs[j]] == -1) { tmp = -1; break; }
            tmp += dist[i][xs[j]] * vs[j];
        }

        if(tmp == -1) continue;
        if(ret < 0 || ret > tmp) ret = tmp;
    }

    cout << ret << endl;
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
