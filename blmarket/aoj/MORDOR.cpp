#include <iostream>
#include <functional>
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

#define XX 131072

int n,q;
unsigned int maxs[300000];
unsigned int mins[300000];
int s,e;

template<class Func>
int get(unsigned int arr[], int pos, int a, int b, const Func &func)
{
    int reala = a, realb = min(b, n + XX);
    //cout << reala << " - " << realb << " = " << arr[pos] << endl;

    if(s <= reala && e >= realb) return arr[pos];
    
    int mid = (a+b)/2;

    unsigned int v1 = -1, v2 = -1;
    if(s < mid)
        v1 = get(arr, pos*2, a, mid, func);
    if(mid < e)
        v2 = get(arr, pos*2+1, mid, b, func);
    if(v1 == -1) return v2;
    if(v2 == -1) return v1;

    if(func(v1,v2)) return v1;
    return v2;
}

void process(int dataId)
{
    scanf("%d %d",&n,&q);
    memset(maxs, 0, sizeof(maxs));
    memset(mins, -1, sizeof(mins));
    for(int i=0;i<n;i++)
    {
        scanf("%d", &maxs[XX+i]);
        mins[XX+i] = maxs[XX+i];
    }
    for(int i=XX-1;i>=1;i--)
    {
        maxs[i] = max(maxs[i*2], maxs[i*2+1]);
        mins[i] = min(mins[i*2], mins[i*2+1]);
    }
    for(int i=0;i<q;i++)
    {
        scanf("%d %d",&s,&e);
        s += XX;
        e += XX+1;
        int maxv = get(maxs, 1, XX, XX*2, greater<unsigned int>());
        int minv = get(mins, 1, XX, XX*2, less<unsigned int>());
        printf("%d\n", maxv-minv);
    }
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
