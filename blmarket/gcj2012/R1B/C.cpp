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

int n;
vector<long long> data;
vector<long long> sums;
map<long long, pair<int, long long> > back[505];

bool btrack(int pos)
{
    if(pos == 0)
    {
        return false;
    }

    int np = pos-1;
    foreach(it, back[pos])
    {
        back[np][it->first] = mp(pos, it->first);
        if(it->first + data[np] == 0) return true;
        if(it->first + data[np] <= sums[np])
        {
            back[np][it->first + data[np]] = mp(pos, it->first);
        }
        if(it->first - data[np] == 0) return true;
        if(it->first - data[np] >= -sums[np])
        {
            back[np][it->first - data[np]] = mp(pos, it->first);
        }
    }
}

void process(int dataId)
{
    cin >> n;
    for(int i=0;i<=n;i++)
        back[i].clear();
    data.resize(n);
    for(int i=0;i<n;i++)
    {
        cin >> data[i];
    }
    printf("\n");
    sort(data.begin(), data.end());

    sums.resize(n);
    sums[0] = 0;

    for(int i=1;i<n;i++)
        sums[i] = sums[i-1] + data[i-1];

    back[n][0] = mp(-1,-1);

    btrack(n);
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
