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

            d += dd; w += dm; e += dm; s += ds;
        }
    }
    sort(V.begin(), V.end());

    cout << size(V) << endl;

    int ret = 0;
    for(int i=0;i<size(V);i++) {
        bool failed = false;
        for(int j=V[i].w;j<=V[i].e;j++) {
            bool blocked = false;
            for(int k=0;k<i;k++) if(V[k].d < V[i].d) {
                if(V[k].w <= j && V[k].e >= j && V[k].s >= V[i].s) {
                    blocked = true;
                    break;
                }
            }
            if(!blocked) {
                failed = true;
                break;
            }
        }
        if(failed) {
            ret++;
        }
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
