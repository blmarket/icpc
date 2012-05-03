#include <algorithm>
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

bool comp(const PII &a, const PII &b)
{
    if(a.first * b.second == a.second * b.first)
    {
        return a.second < b.second;
    }
    return a.first * b.second < a.second * b.first;
}

ostream& operator<<(ostream &ost, const PII &a) {
    return ost << a.first << "," << a.second;
}

void process(int dataId)
{
    int n,k;
    cin >> n >> k;
    vector<pair<int,int> > V;
    for(int i=0;i<n;i++)
    {
        int t1,t2;
        cin >> t1 >> t2;
        V.pb(mp(t1,t2));
    }
    sort(V.begin(), V.end(), comp);

    int s1=V[0].first, s2=V[0].second;
    for(int i=1;i<k;i++)
    {
        PII t = mp(s1 + V[i].first, s2 + V[i].second);

        for(int j=i+1;j<n;j++)
        {
            PII tt = mp(s1 + V[j].first, s2 + V[j].second);
            //cout << t << " vs " << tt << endl;
            if(comp(t,tt) == false)
            {
                swap(V[i], V[j]);
                t=tt;
            }
        }

        s1 = t.first;
        s2 = t.second;
    }
    double ret = (double)s1 / s2;
    printf("%.12lf\n",ret);
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
