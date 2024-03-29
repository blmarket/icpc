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

int r,n,m,k;
int kk[15];

void go() {
    int lcm = 1;
    for(int i=0;i<k;i++) {
        lcm = lcm * kk[i] / __gcd(lcm, kk[i]);
    }
    cout << lcm << endl;
}

void process(void) {
    scanf("%d %d %d %d",&r,&n,&m,&k);
    for(int i=0;i<r;i++) {
        for(int j=0;j<k;j++) {
            scanf("%d",&kk[j]);
        }
        go();
    }
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
