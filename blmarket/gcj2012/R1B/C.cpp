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

bool perm(vector<pair<long long, pair<long long, long long> > > &ret, int s, int e)
{
    int sz = e - s;
    if(sz < 1)
    {
        ret.clear();
        ret.pb(mp(data[s], mp(1LL<<s,0)));
    }

    vector<pair<long long, pair<long long, long long> > > p1,p2;
    if(perm(p1, s, (s+e)/2)) return true;
    if(perm(p2, (s+e)/2, e)) return true;

    sort(p1.begin(), p1.end());
    sort(p2.begin(), p2.end());

    for(int i=0;i<size(p1);i++)
    {
        pair<LL, pair<LL, LL> > key = mp(p1[i].first, mp(-1,-1));
        int j = lower_bound(p2.begin(), p2.end(), key) - p2.begin();
        if(p2[j].first == p1[i].first)
        {
            cout << "write here" << endl;
            return true;
        }
    }

    ret.clear();
    for(int i=0;i<size(p2);i++)
        ret.pb(p2[i]);
    for(int i=0;i<size(p1);i++)
    {
        ret.pb(p1[i]);
        LL k1 = p1[i].second.first;
        LL k2 = p1[i].second.second;
        for(int j=0;j<size(p2);j++)
        {
            LL k3 = p2[j].second.first;
            LL k4 = p2[j].second.second;

            ret.pb(mp(p1[i].first + p2[j].first, mp(k1|k3, k2|k4)));
            if(p1[i].first > p2[j].first)
            {
                ret.pb(mp(p1[i].first - p2[j].first, mp(k1|k4, k2|k3)));
            }
            else
            {
                ret.pb(mp(p2[j].first - p1[i].first, mp(k2|k3, k1|k4)));
            }
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
    vector<pair<long long, pair<long long, long long> > > p1;
    while(true)
    {
        if(perm(p1, 0, 32)) return;
        random_shuffle(data.begin(), data.end());
    }
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
