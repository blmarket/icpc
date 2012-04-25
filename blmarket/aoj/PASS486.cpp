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

void process(int dataId)
{
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
