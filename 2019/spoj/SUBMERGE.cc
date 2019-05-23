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

VVI links;

bool process() {
  int N, M;
  scanf(" %d %d", &N, &M);
  links.assign(N+1, VI {});
  if(N == 0 && M == 0) return false;
  for(int i=0;i<M;i++) {
    int a, b;
    scanf(" %d %d", &a, &b);
    links[a-1].pb(b-1);
    links[b-1].pb(a-1);
  }

  int ret = 0;
  {
    VI visit(N, 0);
    VI lowlink(N, 0);
    int cnt = 0;
    function<void(int, bool)> dfs = [&](int a, bool root) {
      visit[a] = lowlink[a] = ++cnt;
      int c2 = 0;
      bool found = false;
      for(auto it: links[a]) {
        if(!visit[it]) {
          c2++;
          dfs(it, false);
          if(lowlink[it] >= visit[a]) found = true;
        }
        lowlink[a] = min(lowlink[a], visit[it]);
      }
      if(root) {
        if(c2 > 1) ret++;
      } else {
        ret += found;
      }
    };
    dfs(0, true);
  }
  printf("%d\n", ret);
  return true;
}

int main(void) {
  while(process());
  return 0;
}
