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

struct atk {
    int d;
    int w,e;
    int s;

    bool operator<(const atk &rhs) const {
        return d < rhs.d;
    }
};

vector<atk> V;
vector<PII> walls[2097155];
vector<int> ssx;
map<int,int> sidx;

void process(void) {
    V.clear();
    int N;
    scanf("%d", &N);
    for(int i=0;i<N;i++) {
        int d,n,w,e,s,dd,dm,ds;
        scanf("%d %d %d %d %d %d %d %d", &d, &n, &w, &e, &s, &dd, &dm, &ds);
        for(int j=0;j<n;j++) {
            atk tmp;
            tmp.d = d; tmp.w = w; tmp.e = e; tmp.s = s; 

            V.pb(tmp);
            ssx.pb(s);

            d += dd; w += dm; e += dm; s += ds;
        }
    }
    sort(V.begin(), V.end());
    sort(ssx.begin(), ssx.end());
    ssx.erase(unique(ssx.begin(), ssx.end()), ssx.end());
    for(int i=0;i<size(ssx);i++) sidx[ssx[i]] = i + 1;

    int ret = 0;
    for(int i=0;i<size(V);i++) {
        int idx = sidx[V[i].s];
        if(idx == 0) throw 0;
    }
    cout << ret << endl;
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
