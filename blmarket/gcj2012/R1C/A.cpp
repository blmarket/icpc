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

int flo[1005][1005];
int n;

void process(int dataId)
{
    memset(flo, 0, sizeof(flo));
    scanf("%d", &n);
    for(int i=1;i<=n;i++)
    {
        int m;
        scanf("%d",&m);
        for(int j=0;j<m;j++)
        {
            int tmp;
            scanf("%d", &tmp);
            flo[i][tmp] = 1;
        }
    }

    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(flo[i][k] && flo[k][j])
                {
                    if(flo[i][j] == 1)
                    {
                        printf("Yes\n");
                        return;
                    }
                    flo[i][j] = 1;
                }
            }
        }
    }
    printf("No\n");
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
