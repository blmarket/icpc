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

const int MOD = 1e9+7;

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

  vector<int> group(M+1, 0);
  VVI G(1);
  {
    function<void(int)> assign = [&](int a) {
      group[a] = G.size() - 1;
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

  // cerr << "Gsize=" << G.size() << endl;

  vector<LL> D(M+1, 0);
  {
    function<void(int)> assign = [&](int a) {
      auto &it = G[a];
      int cnt = 0;
      bool chk = false;
      for(int j=0;j<it.size();j++) {
        int jt = it[j];
        if(jt == 1) chk = true;
        for(int k=0;k<2;k++) {
          if(group[edge[jt][k]] == a) cnt++;
        }
      }
      if(chk) {
        // cerr << cnt <<  " " << it.size() << endl;
        if(cnt > it.size()) {
          for(auto &jt: it) D[jt] = -1;
        } else if(cnt == it.size()) {
          for(auto &jt: it) D[jt] = 1;
        } else {
          D[1] = 1;
        }
        return;
      }
      if(cnt > 0) {
        bool found = false;
        for(auto &jt: it) {
          for(auto kt: edge[jt]) {
            if(D[kt]) { found = true; break; }
          }
          if(found) break;
        }
        if(found) {
          for(auto &jt: it) D[jt] = -1;
        }
        return;
      }
      for(auto &jt: it) {
        if(D[edge[jt][0]] == -1 || D[edge[jt][1]] == -1) {
          D[jt] = -1;
        } else {
          D[jt] = (D[edge[jt][0]] + D[edge[jt][1]]) % MOD;
        }
      }
    };
    for(int i=1;i<G.size();i++) {
      assign(i);
    }
  }

  LL ret = 0;
  for(int i=1;i<=M;i++) {
    if(D[i] == -1 && init[i]) {
      printf("UNBOUNDED\n");
      return;
    }
    ret += D[i] * init[i];
    ret %= MOD;
  }
  printf("%lld\n", ret);
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
