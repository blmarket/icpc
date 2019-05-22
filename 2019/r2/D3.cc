#include <iostream>
#include <algorithm>
#include <functional>
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

const LL MOD = 1e9 + 7;

int M;
int D[100005][2];
LL S[100005];
VVI net;

void process() {
  scanf(" %d", &M);
  net.assign(M, VI {});
  for(int i=0;i<M;i++) {
    int a, b;
    scanf(" %d %d", &a, &b);
    a--;b--;
    tie(D[i][0], D[i][1]) = { a, b };
    net[a].pb(i); net[b].pb(i);
  }
  for(int i=0;i<M;i++) scanf(" %lld", &S[i]);

  vector<int> bfs;
  {
    vector<bool> visit(M, false);
    visit[0] = true;
    bfs.pb(0);
    int s = 0;
    while(s < bfs.size()) {
      s++;
      for(auto it: net[bfs[s]]) if(!visit[it]) {
        visit[it] = true;
        bfs.pb(it);
      }
    }
  }
}

int main(void) {
    int T;
    scanf(" %d", &T);
    for(int i=1;i<=T;i++) {
        printf("Case #%d: ", i);
        process();
    }
    return 0;
}
