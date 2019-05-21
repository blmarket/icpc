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

void tarjan() {
  VI stack;
  VI index;
  VI back;
  vector<bool> active;
  int label;

  index = back = VI(M+1, 0);
  active = vector<bool>(M+1, false);
  label = 0;

  function<void(int)> go;
  go = [&](int a) {
    cerr << a << " " << label+1 << endl;
    stack.pb(a);
    index[a] = back[a] = ++label;
    active[a] = true;

    for(auto it: net[a]) {
      cerr << it << endl;
      if(!index[it]) {
        go(it);
        back[a] = min(back[a], back[it]);
      } else if(active[it]) {
        back[a] = min(back[a], index[it]);
      }
    }

    if(back[a] == index[a]) {
      cerr << "a=" << a << endl;
      while(stack.size()) {
        int tmp = stack.back();
        cerr << tmp << " ";
        stack.pop_back();
        if(tmp == a) break;
      }
      cerr << endl;
    }
  };

  go(1);
}

void process() {
  scanf(" %d", &M);
  net = VVI(M + 1);
  for(int i=1;i<=M;i++) {
    int a, b;
    scanf(" %d %d", &a, &b);
    tie(D[i][0], D[i][1]) = { a, b };
    if(i > 1) {
      net[a].pb(i); net[b].pb(i);
    }
  }
  tarjan();
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
