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

int n, X, Y;
vector<PII> V;
vector<PII> ret;

void process(int dataId)
{
    scanf("%d %d %d",&n, &X, &Y);
    V.resize(n);
    ret.resize(n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&V[i].first);
        V[i].second = i;
    }
    sort(V.rbegin(), V.rend());

    int x=0,y=0;
    int maxx = 0;
    for(int i=0;i<size(V);i++)
    {
        int pos = V[i].second;
        ret[pos] = mp(x,y);
        maxx = max(maxx, x + V[i].first);

        if(i+1 == size(V)) break;
        y += V[i].first;
        y += V[i+1].first;
        if(y > Y)
        {
            y = 0;
            x = maxx + V[i+1].first;
        }
    }

    for(int i=0;i<n;i++)
        cout << ret[i].first << " " << ret[i].second << " ";
    cout << endl;
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
