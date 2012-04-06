#include <iostream>
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
typedef long long int8;

template<typename T> int size(const T &a) { return a.size(); } 

int8 n,m;

int8 get_num(int8 x,int8 y)
{
    return x*x + x*100000LL + y*y - 100000LL*y +x*y;
}

int8 row_low(int8 x,int8 low)
{
    int8 s=1,e=n;

    if(get_num(x,e) >= low) return 0;
    if(get_num(x,1) < low) return n;

    while((e-s)>1)
    {
        int8 m=(s+e)/2;
        int8 num = get_num(x,m);
        if(num >= low) s=m;
        else e=m;
    }

    return (n+1-e);
}

int8 cnt_all(int8 low)
{
    int8 ret=0;
    for(int i=1;i<=n;i++)
    {
        ret += row_low(i,low);
    }
    return ret;
}

int8 process(void)
{
    int8 low = get_num(1,n);
    int8 high = get_num(n,1)*2;

    while((high-low)>1)
    {
        int8 med = (low+high)/2;
        int8 cnt = cnt_all(med);
        if(cnt >= m) high = med;
        else low = med;
    }
    cout << low << endl;
    return low;
}

int8 solve2(void)
{
    vector<int8> V;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            V.pb(get_num(i,j));
    sort(V.begin(), V.end());
    return V[m-1];
}

int main(void)
{
    int N;
    cin >> N;
    for(int i=1;i<=N;i++)
    {
        cin >> n >> m;
        process();
    }
}
