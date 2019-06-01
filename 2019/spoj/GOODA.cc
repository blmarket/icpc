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

int N, M, SS, EE;
vector<int> fun;
VVI E, F;

int main(void) {
  scanf(" %d %d %d %d", &N, &M, &SS, &EE);
  fun.resize(N+1);
  E.assign(N+1, VI {});
  F.assign(N+1, VI {});
  for(int i=1;i<=N;i++) scanf(" %d", &fun[i]);
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
      for(auto it: E[a]) {
        if(!visit[it]) dfs(it);
      }
      L.pb(a);
    };
    dfs(SS);
  }
  reverse(L.begin(), L.end());

  VVI groups;
  vector<bool> visit(N+1, false);
  function<void(int)> dfs2 = [&](int a) {
    visit[a] = true;
    groups.back().pb(a);
    for(auto it: F[a]) {
      if(!visit[it]) dfs2(it);
    }
  };
  for(auto it : L) {
    if(!visit[it]) {
      groups.pb(VI {});
      dfs2(it);
    }
  }

  for(auto &it: groups) {
    for(auto jt: it) cerr << jt << " ";
    cerr << endl;
  }

  return 0;
}
