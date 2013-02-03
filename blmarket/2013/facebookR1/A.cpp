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
vector<int> data;
LL inverse[10005];
const LL mod = 1000000007LL;

int combination(int a, int b) {
    long long ret = 1;
    for(int i=1;i<=a;i++) {
        ret *= i;
        ret %= mod;
    }
    for(int i=1;i<=b;i++) {
        ret *= inverse[i];
        ret %= mod;
    }
    return ret;
}

void process(void) {
    scanf("%d %d",&n, &k);
    data.resize(n);
    for(int i=0;i<n;i++) {
        scanf("%d", &data[i]);
    }
    sort(data.rbegin(), data.rend());
    int cc = combination(n-1, k-1);
    cout << cc << endl;
    for(int i=0;i<=n-k;i++) {
    }
}

void precalc(void) {
    inverse[1] = 1;
    for(int i=2;i<=10000;i++) {
        int mul = (mod + i - 1) / i;
        int mulx = (i * mul) % mod;
        inverse[i] = (inverse[mulx] * mul) % mod;
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
