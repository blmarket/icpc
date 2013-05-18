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
vector<int> pts;
int maxsz;
bool leaf[5000000];
int walls[5000000];

int getpts(int a) {
    return lower_bound(pts.begin(), pts.end(), a) - pts.begin();
}

void addone(int pos, int a, int b, int l, int r, int s) {
    if(l < a) l = a;
    if(r > b) r = b;

    if(l >= b || r <= a) return;

    if(leaf[pos] && l==a && r== b) {
        walls[pos] = max(walls[pos], s);
        return;
    } 
    
    if(leaf[pos]) {
        leaf[pos] = false;
        leaf[pos*2] = leaf[pos*2+1] = true;
        walls[pos*2] = walls[pos*2+1] = walls[pos];
    }
    int mid = (a+b)/2;
    addone(pos*2, a, mid, l, r, s);
    addone(pos*2+1, mid, b, l, r, s);

    if(leaf[pos*2] && leaf[pos*2+1] && walls[pos*2] == walls[pos*2+1]) {
        leaf[pos] = true;
        walls[pos] = walls[pos*2];
    }
}

int getone(int pos, int a, int b, int l, int r) {
    if(l < a) l = a;
    if(r > b) r = b;

    if(l >= b || r <= a) return -1;
    if(leaf[pos]) return walls[pos];

    int mid = (a+b) / 2;
    int t1 = getone(pos*2, a, mid, l, r);
    int t2 = getone(pos*2+1, mid, b, l, r);
    if(t1 == -1 || t2 == -1) return t1+t2+1;
    return min(t1, t2);
}

int getmin(int l, int r) {
    return getone(1, 0, maxsz, l, r);
}

void add_wall(int a) {
    int l,r,s;
    l = getpts(V[a].w);
    r = getpts(V[a].e);
    s = V[a].s;

    addone(1, 0, maxsz, l, r, s);
}

bool block_wall(int a) {
    int l,r,s;
    l = getpts(V[a].w);
    r = getpts(V[a].e);
    s = V[a].s;

    return getmin(l, r) >= s;
}

void process(void) {
    V.clear();
    pts.clear();
    int N;
    scanf("%d", &N);
    for(int i=0;i<N;i++) {
        int d,n,w,e,s,dd,dm,ds;
        scanf("%d %d %d %d %d %d %d %d", &d, &n, &w, &e, &s, &dd, &dm, &ds);
        for(int j=0;j<n;j++) {
            atk tmp;
            tmp.d = d; tmp.w = w; tmp.e = e; tmp.s = s; 

            pts.pb(e); pts.pb(w);
            V.pb(tmp);

            d += dd; w += dm; e += dm; s += ds;
        }
    }
    sort(V.begin(), V.end());
    sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end()), pts.end());

    maxsz = 1;
    while(maxsz <= size(pts)) maxsz *= 2;

    int ret = 0;
    int j = 0;
    for(int i=0;i<size(V);i++) {
        while(V[j].d < V[i].d) {
            add_wall(j++);
        }
        if(block_wall(i) == false) {
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
