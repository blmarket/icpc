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
#include <algorithm>

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

vector<PII> data;
map<int,int> memo[1002];

void process(int dataId)
{
    for(int i=0;i<1002;i++)
        memo[i].clear();
    int n,k;
    scanf("%d %d",&n,&k);
    data.resize(n);
    memo[0][0]=0;

    long long s1=0,s2=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&data[i].second, &data[i].first);
        s1 += data[i].second;
        s2 += data[i].first;
    }

    while(size(data) > k)
    {
        long long t1 = s1 - data.back().second;
        long long t2 = s2 - data.back().first;

        for(int i=0;i<size(data)-1;i++)
        {
            long long tt1 = s1 - data[i].second;
            long long tt2 = s2 - data[i].first;

            if(t1*tt2 > tt1 * t2)
            {
                t1 = tt1;
                t2 = tt2;
                swap(data[i], data.back());
            }
        }
        data.pop_back();
        s1 = t1;
        s2 = t2;
    }

    double rate = (double)s1 / s2;

    printf("%.12lf\n",rate);
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
