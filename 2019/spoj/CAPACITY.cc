#include <iostream>
#include <functional>
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

int N, M;
VVI E, F;

int main(void) {
  scanf(" %d %d", &N, &M);
  E = F = VVI(N+1, VI {});
  for(int i=0;i<M;i++) {
    int a, b;
    scanf(" %d %d", &a, &b);
    E[a].pb(b);
    F[b].pb(a);
  }
  vector<int> L;
  {
    vector<bool> visit(N+1, false);
    function<void(int)> dfs = [&](int a) {
      visit[a] = true;
      for(auto it: E[a]) if(!visit[it]) dfs(it);
      L.pb(a);
    };
    for(int i=1;i<=N;i++) if(!visit[i]) dfs(i);
  }
  vector<int> groups(N+1, 0);
  VVI G;
  function<void(int)> dfs2 = [&](int a) {
    cerr << a << " " << groups[a] << endl;
    groups[a] = G.size();
    G.back().pb(a);
    for(auto it: F[a]) if(!groups[it]) dfs2(a);
  };
  for(int i=L.size() - 1;i>=0;i--) {
    int it = L[i];
    if(groups[it] == 0) {
      G.pb(VI {});
      dfs2(it);
    }
  }

  printf("%lu\n", G.back().size());
  sort(G.back().begin(), G.back().end());
  for(auto &it: G.back()) {
    printf("%d ", it);
  }
  printf("\n");

  return 0;
}
