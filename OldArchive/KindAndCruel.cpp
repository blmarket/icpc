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

typedef long long LL;

template<typename T> int size(const T &a) { return a.size(); } 

string f;
int k,c;

LL simulate(LL mask, int sec)
{
    LL tmask = 0;
    for(int i=0;i<size(f)-1;i++)
        if(mask & (1LL<<(i+1))) tmask |= (1LL<<i);
    for(int i=1;i<size(f);i++)
        if(mask & (1LL<<(i-1))) tmask |= (1LL<<i);
    mask |= tmask;

    for(int i=0;i<size(f);i++) if(mask & (1LL<<i))
    {
        if(f[i] == 'K' && ((sec % k) == 0))
            mask ^= (1LL<<i);
        if(f[i] == 'C' && ((sec % c) != 0))
            mask ^= (1LL<<i);
    }

    return mask;
}

class KindAndCruel 
{
public:
    int crossTheField(string field, int K, int C) 
    {		
        f = field;
        k = K;
        c = C;
        int n = size(f)-1;
        int ret = 0;

        LL mask = 1;

        int tt = k*c;

        while(true)
        {
            LL tmask = mask;
            for(int i=0;i<tt;i++)
            {
                cout << ret << " " << mask << endl;
                if(mask & (1LL<<n))
                    return ret;
                mask = simulate(mask, i+1);
                ret++;
            }

            if(mask == tmask) return -1;
        }
    }
};
