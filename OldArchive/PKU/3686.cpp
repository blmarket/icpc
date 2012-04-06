#include <iostream>
#include <queue>
#include <set>
#include <map>
#include <vector>

#define mp make_pair
#define pb push_back
#define sqr(x) ((x)*(x))
#define INF 999999999

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;

template<typename T> int size(const T &a) { return a.size(); } 

int n,m;
VVI data;
vector<int> used;
VI L1,L2;
VVI cost;
set<int> S,T;

bool try_flow(int a)
{
    if(S.count(a)) return false;
    S.insert(a);
    for(int i=0;i<cost[a].size();i++)
    {
        if(cost[a][i] <= (L1[a] + L2[i]))
        {
            if(used[i] == -1 || try_flow(used[i]))
            {
                used[i]=a;
                return true;
            }
            else
            {
                T.insert(i);
            }
        }
    }
    return false;
}

int solve3(void)
{
    used.clear();
    cost.clear();
    L1.clear(); L2.clear();
    int n1 = data.size();
    int n2 = data.size() * data[0].size();
    used.resize(n2,-1);
    cost.resize(data.size());

    for(int i=0;i<data.size();i++)
    {
        for(int j=0;j<data[i].size();j++)
        {
            for(int k=1;k<=data.size();k++)
            {
                cost[i].pb(data[i][j] * k);
            }
        }
    }

    L1.resize(data.size());
    L2.resize(used.size(),0);
    for(int i=0;i<data.size();i++)
    {
        L1[i] = data[i][0];
        for(int j=1;j<data[i].size();j++)
            if(L1[i] > data[i][j]) L1[i] = data[i][j];
    }

    for(int i=0;i<n1;i++)
    {
        S.clear(); T.clear();
        while(try_flow(i) == false)
        {
            int minalpha = INF;
            for(int j=0;j<n1;j++) if(S.count(j))
            {
                for(int k=0;k<n2;k++) if(T.count(k)==0)
                {
                    int alpha = cost[j][k] - L1[j] - L2[k];
                    if(alpha < minalpha) minalpha = alpha;
                }
            }

            set<int>::iterator it;
            for(it = S.begin(); it != S.end(); ++it) L1[*it] += minalpha;
            for(it = T.begin(); it != T.end(); ++it) L2[*it] -= minalpha;
            S.clear(); T.clear();
        }
    }

    int ret = 0;
    for(int i=0;i<L1.size();i++) ret += L1[i];
    for(int i=0;i<L2.size();i++) ret += L2[i];
    return ret;
}

void process(void)
{
    cin >> n >> m;
    data = VVI(n,VI(m));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cin >> data[i][j];
    }

    printf("%.6lf\n",(double)solve3() / n);
}

int main(void)
{
    int N;
    cin >> N;
    for(int i=1;i<=N;i++)
    {
        process();
    }
    return 0;
}

