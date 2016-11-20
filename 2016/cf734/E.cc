#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <cstdlib>
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
#define each(it, v) for(auto &it: v)
#define pb emplace_back

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;
typedef long long LL;

template<typename T> int size(const T &a) { return a.size(); } 

int n;
int c[200005];
int r[200005];
vector<pair<int, int> > ve;
vector<int> link[200005];

int root(int a) {
    return r[a] == a ? a : (r[a] = root(r[a]));
}

int main(void) {
    scanf(" %d", &n);
    for(int i=1;i<=n;i++) scanf(" %d", &c[i]);
    for(int i=1;i<=n;i++) r[i] = i;
    for(int i=1;i<n;i++) {
        int a,b;
        scanf(" %d %d", &a, &b);
        ve.pb(mp(a,b));
        if(c[a] == c[b]) {
            r[root(a)] = root(b);
        }
    }

    for(int i=0;i<size(ve);i++) {
        int a,b;
        tie(a,b) = ve[i];
        a = root(a);
        b = root(b);
        if(c[a] != c[b]) {
            link[a].pb(b);
            link[b].pb(a);
        }
    }

    int s;
    for(s=1;s<=n;s++) if(r[s] == s) break;
    vector<int> vn;
    int dis[200005];
    memset(dis, -1, sizeof(dis));
    vn.pb(s);
    dis[s] = 0;

    for(int i=0;i<size(vn);i++) {
        s = vn[i];
        for(auto it : link[s]) {
            if(dis[it] >= 0) continue;
            dis[it] = dis[s] + 1;
            vn.pb(it);
        }
    }

    s = vn.back();
    memset(dis, -1, sizeof(dis));
    vn.clear(); vn.pb(s);

    for(int i=0;i<size(vn);i++) {
        s = vn[i];
        for(auto it : link[s]) {
            if(dis[it] >= 0) continue;
            dis[it] = dis[s] + 1;
            vn.pb(it);
        }
    }

    cout << (vn.back() + 1) / 2 << endl;
    return 0;
}
