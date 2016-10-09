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

void go(int a) {
    if(a == N) return;
    if(avail[a]) return;
    avail[a] = true;
    for(auto it: roads[a]) {
        cout << it.first << endl;
        go(it.first);
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
    return 0;
}
