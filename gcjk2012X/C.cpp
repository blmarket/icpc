#include <iostream>
#include <cmath>
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

int n,m,h,o;
int a[10000],b[10000],s[10000],r[10000],d[10000],p[10000];
double memo[10000][61];
vector<int> avail[200];

double move(int proad, int turn)
{
    double &key = memo[proad][turn];

    cout << proad << " " << turn << endl;

    if(proad >= 0 && key > -2) return key;

    int pos = h;
    int tt = 0;
    if(proad != -1)
    {
        pos = b[proad];
        tt = s[proad] + r[proad] + d[proad] * turn;
    }

    if(pos < 0 || pos >= n) return -1;
    
    if(pos == o) return 0;

    double ret = -1;
    int stt = (tt % 60);

    for(int it = 0; it < size(avail[pos]); it++)
    {
        int i = avail[pos][it];
        if(p[i] == 100) continue;
        
        int wait = s[i] - stt;
        while(wait < 0) wait += 60;

        int iter = 60 / __gcd(60, d[i]);
        iter = 60;

        double x[61];
        for(int j=0;j<=iter;j++)
        {
            x[j] = move(i, j);
        }
        if(x[0] < 0) continue;

        double ppower = 1;

        double pp = (double)p[i] / 100;
        double tmp2 = r[i] + x[0] - pp * x[0];
        double tmp3 = 0;

        for(int j=1;j<=iter;j++)
        {
            ppower *= pp;
            double tt = ppower * (d[i] + (1. - pp) * x[j % iter]);
            tmp3 += tt;
        }

        double tmp = wait + tmp2 + tmp3 / (1. - ppower);
        if(ret < 0 || ret > tmp) ret = tmp;
    }
    return key = ret;
}

void process(void)
{
    cin >> n >> m >> h >> o;

    for(int i=0;i<10000;i++) for(int j=0;j<61;j++)
        memo[i][j] = -5;

    for(int i=0;i<200;i++) avail[i].clear();
    for(int i=0;i<m;i++)
    {
        cin >> a[i] >> b[i] >> s[i] >> r[i] >> d[i] >> p[i];
        avail[a[i]].pb(i);
    }
    double ret = move(-1, -1);
    if(ret < 0)
    {
        cout << -1 << endl;
        return;
    }
    printf("%.12lf\n",ret);
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
