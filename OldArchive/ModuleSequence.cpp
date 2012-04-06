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

LL go(LL K, LL N, LL A, LL lower, LL upper)
{
    if(A<0) return 0;

    if(K == 0) return lower==0?A+1:0;

    A++;

    LL ret = 0;

    LL nx = A / N;

    ret += nx * (upper - lower + 1);

    A %= N;


    LL nelems = N / K + 1;
    LL next = K*nelems-N;

    LL d = __gcd(K, N);

    cout << nelems << " " << next << endl;
}

class ModuleSequence 
{
public:
    long long countElements(long long K, long long N, long long A, long long B, long long lower, long long upper) 
    {
        K %= N;
        return go(K, N, B, lower, upper) - go(K, N, A-1, lower, upper);
    }
};
