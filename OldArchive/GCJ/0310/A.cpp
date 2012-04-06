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
typedef long long LL;

template<typename T> int size(const T &a) { return a.size(); } 

long long flow[10][10];
long long cost[10][10];

bool try_flow(int s,int e, long long &ret)
{
    int back[10];
    LL curflow[10];
    LL curcost[10];
    
    memset(back, -1, sizeof(back));
    memset(curcost, -1, sizeof(curcost));

    priority_queue<pair<long long, int> > Q;
    Q.push(mp(0, s));
    curflow[0] = 50000000000000LL;
    curcost[0] = 0;

    ret = 0;

    while(!Q.empty())
    {
        LL cc = -Q.top().first;
        LL pos = Q.top().second;
        Q.pop();

        if(cc != curcost[pos]) continue;

        if(pos == 7)
        {
            long long ff = curflow[pos];
            ret += curflow[pos] * curcost[pos];
            while(pos != 0)
            {
                flow[back[pos]][pos] -= ff;
                flow[pos][back[pos]] += ff;
                pos = back[pos];
            }
            return true;
        }

        for(int i=0;i<8;i++)
        {
            if(flow[pos][i] == 0) continue;

            if(curcost[i] == -1 || curcost[i] > cc+cost[pos][i])
            {
                curcost[i] = cc + cost[pos][i];
                back[i] = pos;
                curflow[i] = min(curflow[pos], flow[pos][i]);
                Q.push(mp(-curcost[i], i));
            }
        }
    }

    return false;
}

void process(void)
{
    memset(flow, 0, sizeof(flow));
    memset(cost, 0, sizeof(cost));
    long long n;
    cin >> n;
    for(int i=0;i<3;i++)
        cin >> flow[0][1+i];
    for(int i=0;i<3;i++)
        cin >> flow[4+i][7];

    long long maxcost = -150000;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin >> cost[1+i][4+j];
            maxcost = max(maxcost, cost[1+i][4+j]);
            flow[1+i][4+j] = 50000000000000LL;
        }
    }

    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
        {
            cost[1+i][4+j] = maxcost - cost[1+i][4+j];
            cost[4+j][1+i] = -cost[1+i][4+j];
        }

    long long ret = 0;
    while(true)
    {
        long long tmp;
        if(try_flow(0, 7, tmp))
        {
            ret += tmp;
        }
        else
        {
            cout << maxcost * n - ret << endl;
            return;
        }
    }
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
