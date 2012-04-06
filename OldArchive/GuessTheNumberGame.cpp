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

vector<int> primes;

class GuessTheNumberGame 
{
public:
    int possibleClues(int n) 
    {
        primes.pb(2);
        for(int i=3;i<=n;i++)
        {
            bool good=false;
            for(int j=0;j<size(primes);j++)
            {
                if(primes[j] * primes[j] > i) break;
                if((i % primes[j]) == 0) { good=true; break; }
            }
            if(!good) primes.pb(i);
        }

        LL ret = 1;
        for(int i=0;i<size(primes);i++)
        {
            int tmp = 1;
            int tmp2 = n;

            while(tmp2 > 0)
            {
                tmp2 /= primes[i];
                tmp++;
            }

            tmp--;

            cout << primes[i] << " " << tmp << endl;

            ret = (ret * tmp) % 1000000007LL;
        }

        return ret;
    }
};
