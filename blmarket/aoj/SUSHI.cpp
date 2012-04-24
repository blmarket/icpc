#include <iostream>
#include <list>
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

template<typename T> int size(const T &a) { return a.size(); } 

int n,m;
int data[25][2];
int dp[5005];

void process(int dataId)
{
    scanf("%d %d",&n,&m);
    m /= 100;
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&data[i][0], &data[i][1]);
        data[i][0] /= 100;
    }
    memset(dp, 0, sizeof(dp));
    for(int i=1;i<=5000;i++)
    {
        dp[i] = dp[i-1];
        for(int j=0;j<n;j++) if(i >= data[j][0])
        {
            dp[i] = max(dp[i], dp[i-data[j][0]] + data[j][1]);
        }
    }

    int md = 0;
    for(int i=1;i<n;i++)
    {
        if(data[i][0] * data[md][1] > data[md][0] * data[i][1])
        {
            md = i;
        }
    }

    if(m <= 5000)
    {
        cout << dp[m] << endl;
        return;
    }

    int nc = (m - 5001 + data[md][0]) / data[md][0];
    int ret = nc * data[md][1];
    m -= nc * data[md][0];
    cout << ret + dp[m] << endl;
}

int main(void)
{
    int N;
    cin >> N;
    for(int i=1;i<=N;i++)
    {
        process(i);
    }
}
