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
