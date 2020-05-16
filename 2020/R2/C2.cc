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

LL gcd(LL a, LL b) {
  if(a < b) return gcd(b, a);
  if(b == 0) return a;
  return gcd(b, a%b);
}

struct vec2 {
  LL xx, yy;

  bool operator==(const vec2 &rhs) const {
    return xx == rhs.xx && yy == rhs.yy;
  }
  
  bool operator<(const vec2 &rhs) const {
    return xx * rhs.yy < yy * rhs.xx;
  }

  vec2 operator-(const vec2 &rhs) const {
    return vec2 { xx - rhs.xx, yy - rhs.yy };
  }

  vec2 norm() const {
    LL gg = gcd(abs(xx), abs(yy));
    LL x1 = xx / gg;
    LL y1 = yy / gg;
    if(xx < 0) {
      x1 = -x1; y1 = -y1;
    }
    return vec2 { x1, y1 };
  }
};

vector<vec2> V;
set<vec2> rats;

int chk(const vec2 &rr) {
  vector<PII> G;
  for(int i=0;i<V.size();i++) {
    bool found = false;
    for(int j=0;j<G.size();j++) {
      vec2 tmp = V[i] - V[G[j].second];
      tmp = tmp.norm();
      if(tmp == rr) {
        G[j].first++;
        found = true;
        break;
      }
    }
    if(!found) G.pb(mp(1, i));
  }

  sort(G.rbegin(), G.rend());

  int ret = 0;
  int t1 = 0;

  for(auto it: G) {
    if(it.first > 1) {
      ret += it.first;
      t1 ^= (it.first & 1);
    } else {
      ret += 1;
      if(t1 == 1) return ret;
      t1 = 1;
    }
  }
  return ret;
}

void process() {
  int N;
  scanf(" %d", &N);
  V.clear();
  rats.clear();
  for(int i=0;i<N;i++) {
    LL x, y;
    scanf(" %lld %lld", &x, &y);
    V.pb(vec2 { x, y });
    for(int j=0;j<i;j++) {
      vec2 tmp = V[i] - V[j];
      rats.insert(tmp.norm());
    }
  }

  int ret = 1;
  for(auto &rr: rats) {
    int tmp = chk(rr);
    ret = max(ret, tmp);
  }
  cout << ret << endl;
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
