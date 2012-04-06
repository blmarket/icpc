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

template<typename T> int size(const T &a) { return a.size(); } 

double memo[1300][1300];

double go(int a, int b)
{
    cout << a << " " << b << endl;
    if(a == 0) return 0;
    double &ret = memo[a][b];
    if(ret > -1e-6) return ret;

    int unknown = a*2 - b;
    double prob = 1.0 / unknown;

    double pknow = prob * b;
    double pdk = 1 - pknow;

    ret = 1;
    if(b)
        ret += pknow * go(a-1,b-1);

    if(a == b)
    {
        return ret;
    }

    {
        double p2 = pdk / (unknown - 1);

        ret += p2 * go(a-1, b);

        if(b)
            ret += p2 * b * (1 + go(a-1,b));

        if(b+1 < unknown-1)
            ret += p2 * (unknown - b - 2) * go(a, b+2);
    }

    return ret;
}

class PerfectMemory 
{
public:
    double getExpectation(int N, int M) 
    {		
        for(int i=0;i<1300;i++) for(int j=0;j<1300;j++) memo[i][j] = -1;
        return go(N*M/2, 0);
    }
};
