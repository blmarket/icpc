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

map<int,int> memo[1002];

void process(int dataId)
{
    for(int i=0;i<1002;i++)
        memo[i].clear();
    int n,k;
    scanf("%d %d",&n,&k);
    memo[0][0]=0;
    for(int i=0;i<n;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        int elasp = n-i;
        elasp = max(0, k - elasp);
        for(int j=k-1;j>=elasp;j--)
        {
            foreach(it, memo[j])
            {
                int &tmp = memo[j+1][it->first + b];
                if(tmp == 0 || tmp > it->second + a)
                {
                    tmp = it->second + a;
                    for(map<int,int>::iterator jt = memo[j+1].begin(); jt->first < it->first+b;)
                    {
                        long long t1 = (long long)jt->first * tmp;
                        long long t2 = (long long)(it->first + b) * jt->second;
                        if(t2 > t1) memo[j+1].erase(jt++);
                        else ++jt;
                    }
                }
            }
        }
    }

    double rate = 1;
    foreach(it, memo[k])
    {
        double tmp = (double)it->second / it->first;
        if(rate > tmp) rate = tmp;
    }
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
