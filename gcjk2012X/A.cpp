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

int n,m,b;
vector<int> ps, qs;

void process(void)
{
    scanf("%d %d %d",&n, &m, &b);
    ps.resize(m);
    qs.resize(m);
    for(int i=0;i<m;i++)
    {
        scanf("%d %d",&ps[i], &qs[i]);
    }

    long long ret =0 ;

    while(n)
    {
        // one
        int mincost = 1000000;
        int md1,md2=-1;

        for(int i=0;i<m;i++) if(qs[i])
        {
            if(ps[i] >= b && mincost > ps[i])
            {
                mincost = ps[i];
                md1 = i;
            }
        }
        for(int i=0;i<m;i++) if(qs[i])
        {
            for(int j=i;j<m;j++) if(qs[j])
            {
                if(i == j && qs[i] == 1) continue;
                if(ps[i] + ps[j] >= b && mincost > ps[i] + ps[j])
                {
                    mincost = ps[i] + ps[j];
                    md1 = i;
                    md2 = j;
                }
            }
        }

        if(mincost == 1000000)
        {
            cout << -1 << endl;
            return;
        }

        int qty = qs[md1];
        if(md2 != -1) qty = min(qty, qs[md2]);
        if(md1 == md2) qty /= 2;
        qty = min(qty, n);

        ret += mincost * qty;
        n -= qty;
        qs[md1] -= qty;
        if(md2 != -1) qs[md2] -= qty;
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
