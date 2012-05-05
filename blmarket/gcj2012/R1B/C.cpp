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

bool perm(vector<pair<long long, long long> > &ret, int s, int e)
{
    int sz = e - s;
    if(sz < 4)
    {
        ret.clear();
        for(int i=1;i<(1<<sz);i++)
        {
            long long sum = 0;
            for(int j=0;j<sz;j++) if((1LL<<j) & i)
                sum += data[s + j];
            ret.pb(mp(sum, (long long)i << s));
        }
        return false;
    }

    vector<pair<long long, long long> > p1,p2;
    if(perm(p1, s, (s+e)/2)) return true;
    if(perm(p2, (s+e)/2, e)) return true;

    ret.clear();
    for(int i=0;i<size(p2);i++) ret.pb(p2[i]);
    for(int i=0;i<size(p1);i++)
    {
        ret.pb(p1[i]);
        for(int j=0;j<size(p2);j++)
        {
            ret.pb(mp(p1[i].first + p2[j].first, p1[i].second | p2[j].second));
        }
    }

    sort(ret.begin(), ret.end());
    for(int i=0;i+1<size(ret);i++)
    {
        if(ret[i].first == ret[i+1].first && sz <= 24)
        {
            long long sum = 0;
            for(int j=0;j<48;j++)
            {
                if((1LL<<j) & ret[i].second)
                {
                    cout << data[j] << " ";
                    sum += data[j];
                }
            }
            cout << endl << sum << endl;
            sum = 0;
            for(int j=0;j<48;j++)
            {
                if((1LL<<j) & ret[i+1].second)
                {
                    cout << data[j] << " ";
                    sum += data[j];
                }
            }
            cout << endl << sum << endl;
            return true;
        }
    }
    cout << sz << " failed" << endl;
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
    vector<pair<long long, long long> > p1;
    perm(p1, 0, 48);
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
