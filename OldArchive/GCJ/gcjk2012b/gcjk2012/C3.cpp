#include <iostream>
#include <sstream>
#include <numeric>
#include <cstdio>
#include <cstring>
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
    int dist[150][150];
    int xs[20], vs[20];

    memset(dist, -1, sizeof(dist));
    cin >> n >> p >> m;

    for(int i=0;i<p;i++)
    {
        cin >> xs[i] >> vs[i];
    }

    for(int i=1;i<=n;i++)
        dist[i][i] = 0;

    for(int i=0;i<m;i++)
    {
        int cost;
        int nn;
        cin >> cost >> nn;

        int fps;
        int prev;
        cin >> prev;
        for(int j=1;j<nn;j++)
        {
            int tmp;
            cin >> tmp;

            dist[prev][tmp] = dist[tmp][prev] = cost;

            prev = tmp;
        }
    }

    /*
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cout << dist[i][j] << " ";
        cout << endl;
    }
    */

    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            if(dist[i][k] == -1) continue;
            for(int j=1;j<=n;j++)
            {
                if(dist[k][j] == -1) continue;

                if(dist[i][j] == -1 || dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    /*
    cout << endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cout << dist[i][j] << " ";
        cout << endl;
    }
    */

    int ret = -1;
    for(int i=1;i<=n;i++)
    {
        int tmp = 0;
        for(int j=0;j<p;j++)
        {
            if(dist[i][xs[j]] == -1)
            {
                tmp = -1;
                break;
            }
            int tmp2 = dist[i][xs[j]] * vs[j];
            tmp = max(tmp, tmp2);
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
