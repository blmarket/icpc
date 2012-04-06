#include <iostream>
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

LL gcd(LL a,LL b)
{
    if(a<b) return gcd(b,a);
    if(b == 0) return a;
    return gcd(b,a%b);
}

void process(void)
{
    long long a,b,c;
    cin >> a >> b >> c;
    long long dd = a*b;
    long long tmp1 = dd / c;
    long long tmp2 = gcd(b,c);
    long long tmp3 = c / tmp2;
    cout << tmp1 + a - (a/tmp3) << endl;
}

int main(void)
{
    int N;
    cin >> N;
    for(int i=1;i<=N;i++)
    {
        printf("Case #%d: ",i);
        process();
        cerr << i << endl;
    }
}
