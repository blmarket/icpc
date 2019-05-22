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

int M;
int edge[100005][2];
VVI back;
LL init[100005];

void process() {
  scanf(" %d", &M);

  back.assign(M+1, VI {});
  for(int i=1;i<=M;i++) {
    int a, b;
    scanf(" %d %d", &a, &b);
    edge[i][0] = a; edge[i][1] = b;
    back[a].pb(i);
    back[b].pb(i);
  }
  for(int i=1;i<=M;i++) scanf(" %lld", &init[i]);

  vector<int> L;
  vector<bool> reach(M+1, false);
  {
    function<void(int)> dfs = [&](int a) {
      reach[a] = true;
      for(auto &it: back[a]) {
        if(!reach[it]) dfs(it);
      }
      L.pb(a);
    };
    for(int i=1;i<=M;i++) if(!reach[i]) dfs(i);
  }

  for(auto &it: L) cerr << it << " ";
  cerr << endl;

  vector<int> group(M+1, 0);
  VVI G(1);
  {
    function<void(int)> assign = [&](int a) {
      group[a] = G.size();
      G.back().pb(a);
      for(auto &it: edge[a]) if(!group[it]) {
        assign(it);
      }
    };
    for(int i=L.size()-1;i>=0;i--) {
      int it = L[i];
      if(!group[it]) {
        G.pb(VI {});
        assign(it);
      }
    }
  }

  cerr << "g ";
  for(auto &it: group) cerr << it << " ";
  cerr << endl;

  for(auto &it: G) {
    for(auto &jt: it) cerr << jt << " ";
    cerr << endl;
  }

  for(int i=1;i<G.size();i++) {
    auto &it = G[i];
    int cnt = 0;
    for(int j=0;j<it.size();j++) {
      int jt = it[j];
      for(int k=0;k<2;k++) {
        cerr << "d " << edge[jt][k] << " " << group[edge[jt][k]] << " " << i << endl;
        if(group[edge[jt][k]] == i) cnt++;
      }
    }
    cerr << "cnt=" << cnt << endl;
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
