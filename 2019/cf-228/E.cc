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

struct links {
  int a, b, c;
};
int n, m;
vector<PII> links[10005];

int main(void) {
  scanf(" %d %d", &n, &m);
  for(int i=0;i<m;i++) {
    int a, b, c;
    scanf(" %d %d %d", &a, &b, &c);
    links[a].pb(mp(b, c));
    links[b].pb(mp(a, c));
  }

  vector<int> mark(n+1, 0);
  function<bool(int)> go = [&](int a) {
    for(auto it: links[a]) {
      int expect = mark[a] * (it.second * 2 - 1);
      if(mark[it.first] && mark[it.first] != expect) return false;
      if(!mark[it.first]) {
        mark[it.first] = expect;
        go(it.first);
      }
    }
    return true;
  };
  for(int i=1;i<=n;i++) if(!mark[i]) {
    mark[i] = -1;
    if(!go(i)) {
      printf("Impossible\n");
      return 0;
    }
  }
  vector<int> res;
  for(int i=1;i<=n;i++) if(mark[i] == 1) {
    res.pb(i);
  }
  printf("%lu\n", res.size());
  for(auto it: res) printf("%d ", it);
  printf("\n");
  return 0;
}
