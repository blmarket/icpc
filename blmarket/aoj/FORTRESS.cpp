#include <iostream>
#include <list>
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

template<typename T> int size(const T &a) { return a.size(); } 

int n;
int x[105], y[105], r[105];
int way[105][105];

void process(int dataId)
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d %d",&x[i], &y[i], &r[i]);
    }

    memset(way, 0, sizeof(way));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++) if(r[i] > r[j])
        {
            int xd = x[i] - x[j];
            int yd = y[i] - y[j];
            if(xd*xd + yd*yd < r[i]*r[i])
            {
                way[i][j] = 1;
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++) if(way[i][j])
        {
            for(int k=0;k<n;k++)
            {
                if(way[i][k] && way[k][j])
                {
                    way[i][j] = 0;
                }
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(way[j][i]) way[i][j] = 1;
        }
    }

    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++) if(way[i][k])
        {
            for(int j=0;j<n;j++) if(way[k][j])
            {
                if(way[i][j] == 0 || way[i][j] > way[i][k] + way[k][j])
                    way[i][j] = way[i][k] + way[k][j];
            }
        }
    }

    int ret = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++) if(i != j)
        {
            ret = max(ret, way[i][j]);
        }
    }

    cout << ret << endl;

}

int main(void)
{
    int N;
    cin >> N;
    for(int i=1;i<=N;i++)
    {
        process(i);
    }
}
