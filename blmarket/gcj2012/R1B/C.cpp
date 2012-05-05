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
vector<int> data;
map<int, long long> memo;

void out(int mask)
{
    for(int i=0;i<n;i++) if( mask & (1<<i))
    {
        printf("%d ", data[i]);
    }
    printf("\n");
}

void process(int dataId)
{
    scanf("%d",&n);
    memo.clear();
    data.resize(n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&data[i]);
    }
    printf("\n");
    int tt = (1<<n);
    for(int i=1;i<tt;i++)
    {
        int sum = 0;
        for(int j=0;j<n;j++) if(i & (1<<j))
            sum += data[j];
        if(memo.count(sum) != 0)
        {
            out(memo[sum]);
            out(i);
            return;
        }
        memo[sum] = i;
    }
    printf("Impossible\n");
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
