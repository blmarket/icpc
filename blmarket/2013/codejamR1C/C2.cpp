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
int maxsz = 1;
pair<bool, int> arr[5000000];

void setmax(int &a, int b) { a=max(a,b); }

void put(int pos, int a, int b, int l, int r, int s) {
    if(l < a) l = a;
    if(r > b) r = b;
    printf("put(%d,%d,%d,%d,%d)\n",pos,a,b,l,r);
    if(l >= r) return;

    int mid = (a+b)/2;

    if(l == a && r == b) {
        if(arr[pos].first == true) {
            setmax(arr[pos].second, s);
        } else {
            put(pos*2,a,mid,l,r,s);
            put(pos*2+1,a,mid,l,r,s);
        }
    } else {
        if(arr[pos].first == true) {
            printf("put child %d %d %d\n", pos, a, b);
            arr[pos].first = false;
            arr[pos*2].first = arr[pos*2+1].first = true;
            arr[pos*2].second = arr[pos*2+1].second = arr[pos].second;
        }
        put(pos*2,a,mid,l,r,s);
        put(pos*2+1,a,mid,l,r,s);
    }
    if(arr[pos].first == true) return;
    if(arr[pos*2].first && arr[pos*2+1].first && arr[pos*2].second == arr[pos*2+1].second) {
        printf("aggregate %d(%d,%d)\n", pos, arr[pos*2].second, arr[pos*2+1].second);
        arr[pos].first = true;
        arr[pos].second = arr[pos*2].second;
    }
}

bool check(int pos, int a, int b, int l, int r, int s) {
    if(l < a) l = a;
    if(r > b) r = b;
    if(l >= r) return true;

    printf("check child %d(%d) %d %d\n", pos, arr[pos].first, a, b);

    int mid = (a+b)/2;
    if(arr[pos].first) {
        return arr[pos].second >= s;
    }

    bool c1,c2;
    c1 = check(pos*2, a, mid, l, r, s);
    c2 = check(pos*2+1, mid, b, l, r, s);
    return c1 && c2;
}

void insert_wall(int pos) {
    int l = lower_bound(pts.begin(), pts.end(), V[pos].w) - pts.begin();
    int r = lower_bound(pts.begin(), pts.end(), V[pos].e) - pts.begin();
    int s = V[pos].s;

    put(1, 0, maxsz, l, r, s);
}

bool check_wall(int pos) {
    int l = lower_bound(pts.begin(), pts.end(), V[pos].w) - pts.begin();
    int r = lower_bound(pts.begin(), pts.end(), V[pos].e) - pts.begin();
    int s = V[pos].s;

    bool tmp = check(1, 0, maxsz, l, r, s);

    cout << l << " " << r << " " << s << " = " << tmp << endl;

    return tmp;
}

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
            pts.pb(w); pts.pb(e);

            d += dd; w += dm; e += dm; s += ds;
        }
    }
    sort(V.begin(), V.end());
    sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end()), pts.end());

    while(maxsz <= size(pts)) maxsz*=2;
    arr[1] = mp(true, 0);

    int ret = 0;
    int j = 0;
    for(int i = 0;i<size(V);i++) {
        if(V[i].d > V[j].d) {
            insert_wall(j++);
        }
        if(check_wall(i) == false) {
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
