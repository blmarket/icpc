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

template<typename T> int size(const T &a) { return a.size(); } 

int n;
long long nn;
long long p;

long long go2(void) {
    if(nn == p) return nn-1;
    long long mincut = nn - p;

    long long cur = 0;
    long long ret = 1;
    for(int i=1;i<=n;i++) {
        cur |= (1LL << (n-i));
        if(cur >= mincut) {
            return ret;
        }
        ret = (ret * 2) + 1;
    }
}

long long go1(void) {
    if(nn == p) return nn-1;
    long long mincut = nn - p;
    int ret = 1;
    for(int i=1;i<=n;i++) {
        if(mincut & (1LL << (n-i))) {
            return ret - 1;
        }
        ret = (ret * 2) + 1;
    }
}

void process(void) {
    cin >> n >> p;
    nn = (1LL << n);

    cout << go1() << " " << nn-1 - go2() << endl;
}

int main(void)
{
    int T;
    scanf("%d", &T);
    for(int i=1;i<=T;i++) {
        printf("Case #%d: ", i);
        process();
        cerr << i << endl;
    }
}
