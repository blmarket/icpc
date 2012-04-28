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

    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&data[i].second, &data[i].first);
    }
    sort(data.rbegin(), data.rend());


    for(int i=0;i<n;i++)
    {
        int a = data[i].second;
        int b = data[i].first;
        int elasp = n-i;
        elasp = max(0, k - elasp);
        for(int j=k-1;j>=elasp;j--)
        {
            foreach(it, memo[j])
            {
                map<int,int>::iterator jt = memo[j+1].lower_bound(it->first + a);
                if(jt != memo[j+1].end() && (it->first+a)*jt->second > jt->first * (it->second + b))
                    continue;
                cout << j+1 << " " << it->first+a << " = " << it->second+b << endl;
                memo[j+1][it->first + a] = it->second + b;
            }
        }
    }

    double rate = 1;
    foreach(it, memo[k])
    {
        double tmp = (double)it->first / it->second;
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
