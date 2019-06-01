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
VVI links;
vector<PII> ret;

void process() {
  ret.clear();
  scanf(" %d %d", &N, &M);
  links.assign(N+1, VI{});

  for(int i=0;i<M;i++) {
    int a, b;
    scanf(" %d %d", &a, &b);
    links[a].pb(b);
    links[b].pb(a);
  }

  VI link(N+1, -1), lowlink(N+1, -1);
  int cnt = 0;
  function<void(int, int)> dfs = [&](int a, int b) {
    link[a] = lowlink[a] = ++cnt;
    for(auto it: links[a]) if(it != b) {
      if(link[it] == -1) {
        dfs(it, a);
        if(lowlink[it] > link[a]) {
          ret.pb(min(it, a), max(it, a));
        }
        if(lowlink[it] < lowlink[a]) {
          lowlink[a] = lowlink[it];
        }
        continue;
      }
      lowlink[a] = min(lowlink[a], link[it]);
    }
  };

  dfs(1, -1);

  sort(ret.begin(), ret.end());
  if(ret.size() == 0) {
    printf("Sin bloqueos\n");
    return;
  }
  printf("%d\n", ret.size());
  for(auto it: ret) {
    printf("%d %d\n", it.first, it.second);
  }
}

int main(void) {
    int T;
    scanf(" %d", &T);
    for(int i=1;i<=T;i++) {
        printf("Caso #%d\n", i);
        process();
    }
    return 0;
}
