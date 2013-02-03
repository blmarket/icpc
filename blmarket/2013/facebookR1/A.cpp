#include <iostream>
#include <algorithm>
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

int n,k;
LL inverse[10005];
const LL mod = 1000000007LL;

void process(void) {
    scanf("%d %d",&n, &k);
}

void precalc(void) {
    inverse[1] = 1;
    for(int i=2;i<=10000;i++) {
        int mul = (mod + i - 1) / i;
        int mulx = (i * mul) % mod;
        inverse[i] = (inverse[mulx] * mul) % mod;
        cout << i << " = " << inverse[i] << endl;
    }
}

int main(void)
{
    precalc();
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;i++) {
        printf("Case #%d: ",i);
        process();
    }
}
