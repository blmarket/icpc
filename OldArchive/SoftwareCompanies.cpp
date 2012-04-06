#include <iostream>
#include <sstream>
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

map<string, int> mapper;
int source, sink;
int move[40][40];
int usemask = 0;
int nn;

bool visit[40];
int go[40][40];

int go1(int a, int b, int c)
{
    if(visit[a]) return 0;
    visit[a]=true;

    if(c==0) return 0;
    if(a==b) return c;

    for(int i=0;i<nn;i++) if(go[a][i]) 
    {
        if((1<<(i/2)) & usemask)
        {
            int tmp = (go1(i,b, min(c, go[a][i])));

            if(tmp != 0)
            {
                go[a][i] -= tmp;
                go[i][a] += tmp;
                return tmp;
            }
        }
    }

    return 0;
}

int try_flow(int src, int sink)
{
    memcpy(go, move, sizeof(go));
    int ret = 0;

    while(true)
    {
        memset(visit, 0, sizeof(visit));
        int tmp = go1(src, sink, 99999999);
        if(tmp == 0) break;
        ret += tmp;
    }

    return ret;
}

class SoftwareCompanies 
{
public:
    vector <string> produceData(vector <string> names, vector <string> process, vector <int> cost, vector <int> amount, string company1, string company2) 
    {
        for(int i=0;i<size(names);i++)
        {
            mapper[names[i]]=i;
            move[i*2][i*2+1]=amount[i];
        }

        for(int i=0;i<size(process);i++)
        {
            istringstream sin(process[i]);
            string str;
            while(sin >> str)
            {
                int idx = mapper[str];
                move[i*2+1][idx*2]=99999999;
            }
        }

        int source = mapper[company1]*2;
        int sink = mapper[company2]*2+1;

        int n = size(names);
        nn = n*2;
        int maxflow = 0;
        int mincost = 0;

        vector<string> ret;

        for(int i=1;i<(1<<n);i++)
        {
            usemask = i;
//            usemask = (1<<n)-1;
            int curcost = 0;
            for(int j=0;j<n;j++) if(i & (1<<j))
                curcost += cost[j];
            int flow = try_flow(source, sink);

            if(flow > maxflow || (flow == maxflow && curcost <= mincost))
            {
                vector<string> tmp;
                for(int j=0;j<n;j++) if(i & (1<<j))
                    tmp.pb(names[j]);
                sort(tmp.begin(), tmp.end());

                if(flow > maxflow || (flow == maxflow && curcost < mincost) || (flow == maxflow && curcost == mincost && tmp < ret))
                {
                    mincost = curcost;
                    maxflow = flow;
                    ret = tmp;
                }
            }
        }

        cout << maxflow << " " << mincost << endl;

        return ret;
    }
};
