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
#define abs(x) ((x)<0?-(x):(x))

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;
typedef long long LL;

template<typename T> int size(const T &a) { return a.size(); } 

int n;
vector<long long> data;

template<typename T> bool perm(vector<long long> &ret, const T &begin, const T &end)
{
    int sz = end - begin;
    cout << end-begin << endl;
    if(end - begin < 4)
    {
        int sz = end - begin;
        ret.clear();
        for(int i=1;i<(1<<sz);i++)
        {
            long long sum = 0;
            for(int j=0;j<sz;j++) if((1<<j) & i)
                sum += *(begin + j);
            ret.pb(sum);
        }
        return false;
    }

    vector<long long> p1,p2;
    T mid = begin + sz/2;
    if(perm(p1, begin, mid)) return true;
    if(perm(p2, mid, end)) return true;

    ret.clear();
    for(int i=0;i<size(p2);i++) ret.pb(p2[i]);
    for(int i=0;i<size(p1);i++)
    {
        ret.pb(p1[i]);
        for(int j=0;j<size(p2);j++)
        {
            ret.pb(p1[i] + p2[j]);
        }
    }
    sort(ret.begin(), ret.end());
    for(int i=0;i+1<size(ret);i++)
    {
        if(ret[i] == ret[i+1])
        {
            cout << "write here" << endl;
            return true;
        }
    }
    return false;
}

void process(int dataId)
{
    cin >> n;
    data.resize(n);
    for(int i=0;i<n;i++)
    {
        cin >> data[i];
    }

    printf("\n");

    // i think 48 bits are enough...
    // 48, 24, 12, 6, 3
    vector<long long> p1;
    perm(p1, &data[0], &data[48]);
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
