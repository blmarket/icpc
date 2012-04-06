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

int n,p,m;
vector<int> xs, vs;
vector<vector<PII> > near;
int visit[12000];

int move(int a)
{
    memset(visit, -1, sizeof(visit));
    priority_queue<PII> Q;
    Q.push(mp(0,a));
    visit[a] = 0;

    while(Q.empty() == false)
    {
        int cost = -Q.top().first;
        int pos = Q.top().second;
        Q.pop();
        if(visit[pos] != cost) 
        {
            //cerr << "Hello " << pos << " " << cost << " " << visit[pos] << endl;
            continue;
        }
        
        for(int i=0;i<size(near[pos]);i++)
        {
            int npos = near[pos][i].second;
            int ncost = cost + near[pos][i].first;

            if(visit[npos] == -1 || visit[npos] > ncost)
            {
                visit[npos] = ncost;
                Q.push(mp(-ncost, npos));
            }
        }
    }

    int ret = 0;
    for(int i=0;i<size(xs);i++)
    {
        if(visit[xs[i]] == -1) return -1;
        ret = max(ret, vs[i] * visit[xs[i]]);
    }
    return ret;
}

void process(void)
{
    scanf("%d %d %d",&n,&p,&m);
    xs.clear(); vs.clear();
    for(int i=0;i<p;i++)
    {
        int t1,t2;
        scanf("%d %d",&t1,&t2);
        xs.pb(t1);
        vs.pb(t2);
    }
    near.clear(); near.resize(n+1);
    for(int i=0;i<m;i++)
    {
        int t1,t2,prev;
        scanf("%d %d %d",&t1,&t2,&prev);
        for(int j=1;j<t2;j++)
        {
            int tmp;
            scanf("%d",&tmp);
            near[prev].pb(mp(t1,tmp));
            near[tmp].pb(mp(t1,prev));
            prev = tmp;
        }
    }

    int ret = -1;
    for(int i=1;i<=n;i++)
    {
        if((i % 100) == 0) cerr << i << " ";
        int tmp = move(i);
        if(tmp < 0) continue;
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
