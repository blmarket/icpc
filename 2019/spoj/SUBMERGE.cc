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

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef long long ll;

template<typename t> int size(const t &a) { return a.size(); } 

vvi links;

bool process() {
  int n, m;
  scanf(" %d %d", &n, &m);
  links.assign(n+1, vi {});
  if(n == 0 && m == 0) return false;
  for(int i=0;i<m;i++) {
    int a, b;
    scanf(" %d %d", &a, &b);
    links[a-1].pb(b-1);
    links[b-1].pb(a-1);
  }

  int ret = 0;
  {
    vi visit(n, 0);
    vi lowlink(n, 0);
    int cnt = 0;
    function<void(int, int)> dfs = [&](int a, int parent) {
      visit[a] = lowlink[a] = ++cnt;
      int c2 = 0;
      bool found = false;
      for(auto it: links[a]) {
        if(it == parent) continue;
        if(!visit[it]) {
          c2++;
          dfs(it, a);
          if(lowlink[it] >= visit[a]) found = true;
          lowlink[a] = min(lowlink[a], lowlink[it]);
        } else {
          lowlink[a] = min(lowlink[a], visit[it]);
        }
      }

      if(parent == -1) {
        if(c2 > 1) {
          // cerr << a+1 << endl;
          ret++;
        }
      } else {
        // cerr << a+1 << " " << parent << " " << visit[a] << " " << lowlink[a] << " " << found << endl;
        ret += found;
      }
    };
    dfs(0, -1);
  }
  printf("%d\n", ret);
  return true;
}

int main(void) {
  while(process());
  return 0;
}
