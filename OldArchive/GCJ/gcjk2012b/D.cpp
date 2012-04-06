#include <iostream>
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

vector<LL> primes;

int combine(int minpos, int tgt, long long n, long long cur = 1)
{
    if(tgt == 1)
    {
        if(cur >= n) return 0;
        return 1;
    }
    if(cur * primes[minpos] > n) return 0;
    long long tmp = 1;
    int i = 1;
    for(i=0;i+1<=tgt;i++)
    {
        if(cur * tmp > n) break;
        tmp *= primes[minpos];
    }

    int ret = 0;
    for(;i>=1;i--)
    {
        if((tgt % (i+1)) == 0)
        {
            ret += combine(minpos+1, tgt / (i+1), n, cur * tmp);
        }
        tmp /= primes[minpos];
    }

    ret += combine(minpos+1, tgt, n, cur);
    return ret;
}

void process(void)
{
    LL n,m;
    cin >> n >> m;

    int minpos = -1;

    for(int i=0;i<size(primes);i++)
    {
        if(primes[i] >= m)
        {
            minpos = i;
            break;
        }
    }

    vector<int> vs;
    LL tmp = n;
    for(int i=0;i<size(primes);i++)
    {
        int cnt = 0;
        while((tmp % primes[i]) == 0)
        {
            tmp /= primes[i];
            cnt++;
        }

        if(cnt)
        {
            vs.pb(cnt);
        }
    }
    if(tmp != 1) vs.pb(1);

    if(size(vs) == 1 && vs[0] == 1)
    {
        cout << 0 << endl;
        return;
    }

    int lll = 1;
    for(int i=0;i<size(vs);i++)
        lll *= (1 + vs[i]);

    cout << combine(minpos, lll, n) << endl;
    return;

    int ret = 0;
    for(int i=2;i<n;i++)
    {
        vector<int> ts;
        ts.clear();
        int tmp = i;
        bool fail=false;
        for(int j=0;j<minpos;j++)
        {
            if((i % primes[j]) == 0)
            {
                fail=true; break;
            }
        }
        if(fail) continue;
        for(int j=minpos;j<size(primes);j++)
        {
            if(tmp < primes[j]) break;
            int cnt = 0;
            while((tmp % primes[j]) == 0)
            {   
                tmp /= primes[j];
                cnt++;
            }
            ts.pb(cnt + 1);
        }
        if(tmp != 1) ts.pb(2);
        int mmm = 1;
        for(int j=0;j<size(ts);j++)
            mmm *= ts[j];

        if(mmm == lll)
        {
            ret++;
        }
    }

    cout << ret << endl;
}

void precalc(void)
{
    LL limit = 10000000LL;

    primes.pb(2);
    for(LL i=3;i*i<limit;i+=2)
    {
        bool fail=false;
        for(int j=0;j<size(primes);j++)
        {
            if((i%primes[j]) == 0)
            {
                fail=true; break;
            }
        }
        if(!fail) primes.pb(i);
    }

    cerr << primes.size() << endl;
}

int main(void)
{
    precalc();
    int N;
    cin >> N;
    for(int i=1;i<=N;i++)
    {
        printf("Case #%d: ",i);
        process();
        cerr << i << endl;
    }
}
