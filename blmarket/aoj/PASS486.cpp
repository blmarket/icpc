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

vector<int> primes;

int nn;
int nums[1000005];
int cnts[1000005];

void process(int dataId)
{
    int n,l,h;
    cin >> n >> l >> h;
    nn = h-l+1;
    for(int i=0;i<nn;i++)
    {
        nums[i] = i+l;
        cnts[i] = 1;
    }

    for(int i=0;i<size(primes);i++)
    {
        int left = (l / primes[i]) * primes[i];
        if(left < l) left += primes[i];
        while(left <= h)
        {
            int tmp = left;
            int j = 0;
            while((tmp % primes[i]) == 0)
            {
                tmp /= primes[i];
                j++;
            }
            cnts[left - l] *= j;
            left += primes[i];
        }
    }

    int ret = 0;
    for(int i=0;i<nn;i++)
    {
        cout << i+l << ":" << cnts[i] << " ";
        if(cnts[i] == n) ret++;
    }
    cout << endl;
    cout << ret << endl;
}

void precalc(void)
{
    primes.pb(2);
    for(int i=3;i<=10000000;i+=2)
    {
        bool fail = false;
        for(int j=0;j<size(primes);j++)
        {
            if(primes[j] * primes[j] > i) break;
            if((i % primes[j]) == 0) { fail=true; break; }
        }
        if(!fail) primes.pb(i);
    }
    cout << size(primes) << endl;
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
