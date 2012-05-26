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
vector<int> V;
vector<int> ret;

const int high = 1000000000;

bool ccw(long long dx1, long long dy1, long long dx2, long long dy2)
{
    long long xx1 = dx1 * dy2;
    long long xx2 = dy1 * dx2;
    return xx1 < xx2;
}

int nearest(int s,int e,int m)
{
    int dx1 = e - s;
    int dy1 = ret[e] - ret[s];
    int dx2 = m - s;

    int a = 0, b = high;
    while(a < b)
    {
        int mid = (a+b+1)/2;
        if(ccw(dx1, dy1, dx2, mid - ret[s]))
        {
            a = mid;
        }
        else
        {
            b = mid - 1;
        }
    }
    cerr << "set " << m << " = " << a << endl;
    return a;
}

bool between(int s,int e);

bool leap(int s, int e, int m)
{
    if(V[m] > e) return false;
    if(V[m] == e)
    {
        ret[m] = nearest(s,e,m);
        return between(m, e);
    }
    if(leap(s,e,V[m]) == false) return false;
    ret[m] = nearest(V[m], e, m);
    return between(m, V[m]);
}

bool between(int s,int e)
{
    cerr << "btw " << s << " " << e << endl;
    if(e <= s+1) return true;
    return leap(s,e,s+1);
    /*
    if(V[s+1] > e) return false;
    if(V[s+1] == e)
    {
        ret[s+1] = nearest(s,e,s+1);
        return between(s+1,e);
    }
    leap(s, e, V[s+1]);
    ret[V[s+1]] = nearest(s,e,V[s+1]); // check for V[s+1] first
    ret[s+1] = nearest(V[s+1],e,s+1);
    if(between(s+1, V[s+1]) == false) return false;
    if(V[V[s+1]] > e) return false;
    return between(V[s+1],e);
    */
}

void process(int dataId)
{
    scanf("%d",&n);
    V.resize(n+1);
    ret.resize(n+1);
    for(int i=1;i<=n-1;i++)
    {
        scanf("%d",&V[i]);
    }
    ret[1] = high;
    int pos = 1;
    while(pos != n)
    {
        ret[V[pos]] = high;
        if(between(pos, V[pos]) == false)
        {
            cout << "Impossible" << endl;
            return;
        }
        pos = V[pos];
    }
    for(int i=1;i<=n;i++)
    {
        cout << ret[i] << " ";
    }
    cout << endl;
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
