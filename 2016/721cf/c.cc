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

int N, M, T;
vector<PII> roads[5005];
bool avail[5005];
int bc[5005];
map<int, int> moves[5005];

void go(int a) {
    if(a == N) return;
    if(avail[a]) return;
    avail[a] = true;
    for(auto it: roads[a]) {
        go(it.first);
    }
}

void go2(int a) {
    const map<int, int> &cur = moves[a];
    int prev = 1e9 + 1;
    for(auto &it: cur) {
        int nv = it.first;
        int cost = it.second;
        cerr << nv << " " << cost << endl;
        if (cost >= T || cost >= prev) continue;
        prev = cost;
        for(auto &jt: roads[a]) {
            int nc = cost + jt.second;
            int npos = jt.first;
            if(moves[npos].count(nv-1) == 0 || moves[npos][nv-1] > nc) {
                moves[npos][nv-1] = nc;
            }
        }
    }

    for(auto &jt: roads[a]) {
        int npos = jt.first;
        bc[npos]--;
        if(bc[npos] == 0) {
            go2(npos);
        }
    }
}

int main(void) {
    scanf(" %d %d %d", &N, &M, &T);
    for(int i=0;i<M;i++) {
        int a,b,c;
        scanf(" %d %d %d", &a, &b, &c);
        roads[a].pb(mp(b,c));
    }
    go(1);
    for(int i=1;i<N;i++) if(avail[i]) {
        for(auto &it: roads[i]) {
            bc[it.first]++;
        }
    }

    moves[1][0] = 0;
    go2(1);

    for(auto &it : moves[N]) {
        cout << it.first << " " << it.second << endl;
    }

    return 0;
}
