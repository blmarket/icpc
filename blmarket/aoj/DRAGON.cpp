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

long long boom[55];

void xgo(int n, long long s, long long e);

void ygo(int n, long long s, long long e)
{
    if(e == 0) return;
    if(n == 0)
    {
        cout << "Y";
        return;
    }
    if(s == 0)
    {
        cout << "F";
        s++;
    }
    s--;e--;
    if(boom[n-1] > s)
    {
        xgo(n-1, s, min(boom[n-1], e));
        if(boom[n-1] >= e) return;
        s = boom[n-1];
    }
    s -= boom[n-1];
    e -= boom[n-1];
    if(s == 0)
    {
        cout << "+";
        s = 1;
    }
    s--;e--;
    ygo(n-1, s, e);
}

void xgo(int n, long long s, long long e)
{
    if(e == 0) return;
    if(n == 0)
    {
        cout << "X";
        return;
    }

    if(boom[n-1] > s)
    {
        xgo(n-1, s, min(boom[n-1], e));
        if(boom[n-1] >= e) return;
        s = boom[n-1];
    }
    s -= boom[n-1];
    e -= boom[n-1];
    if(s == 0)
    {
        cout << "+";
        s = 1;
    }
    s--;e--;
    if(boom[n-1] > s)
    {
        ygo(n-1, s, min(boom[n-1], e));
        if(boom[n-1] >= e) return;
        s = boom[n-1];
    }
    s -= boom[n-1];
    e -= boom[n-1];
    if(e)
        cout << "F";
}

void go(int n, long long s, long long e)
{
    if(e == s)
    {
        return;
    }
    if(s == 0)
    {
        cout << "F";
        s++;
    }
    xgo(n, s - 1, e - 1);
}

void process(int dataId)
{
    int n;
    long long p,l;

    cin >> n >> p >> l;
    p--;
    go(n,p,p + l);
    cout << endl;
}

void precalc()
{
    boom[0] = 1;
    for(int i=1;i<=50;i++)
    {
        boom[i] = boom[i-1] + boom[i-1] + 2;
    }
}

int main(void)
{
    precalc();
    int N;
    cin >> N;
    for(int i=1;i<=N;i++)
    {
        process(i);
    }
}
