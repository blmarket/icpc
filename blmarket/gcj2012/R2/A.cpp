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

int n, D;
vector<PII> V;
set<PII> fails;

bool tryit(int a, int b)
{
    if(fails.count(mp(a,b))) return false;
    int dist = V[b].first - V[a].first;
    if(V[b].first + dist >= D) return true;
    for(int i=b+1;i<n;i++)
    {
        if(V[i].first <= V[b].first + dist && tryit(b,i)) return true;
    }
    fails.insert(mp(a,b));
    return false;
}

void process(int dataId)
{
    scanf("%d",&n);
    fails.clear();
    V.resize(n);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&V[i].first, &V[i].second);
    }
    scanf("%d", &D);
    for(int i=1;i<n;i++)
    {
        if(V[i].first <= V[0].first * 2)
        {
            if(tryit(0,i))
            {
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
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
