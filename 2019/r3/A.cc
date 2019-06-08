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

const LL chunk = 1e10;
const LL total_size = 1e12;

map<LL, int> memo;

int nimber(LL sz) {
  set<int> zz;
  if(sz < chunk) return 0;
  if(memo.count(sz)) return memo[sz];
  for(LL i=0;i+chunk<=sz;i+=chunk) {
    zz.insert(nimber(i) ^ nimber(sz - i - chunk));
  }
  for(LL i=chunk-1;i+chunk<=sz;i+=chunk) {
    zz.insert(nimber(i) ^ nimber(sz - i - chunk));
  }
  for(int i=0;;i++) {
    if(zz.count(i) == 0) return memo[sz] = i;
  }
}

LL find(LL sz, int target) {
  for(LL i=0;i+chunk<=sz;i+=chunk) {
    int tmp = (nimber(i) ^ nimber(sz - i - chunk));
    if(tmp == target) return i;
  }
  for(LL i=chunk-1;i+chunk<=sz;i+=chunk) {
    int tmp = (nimber(i) ^ nimber(sz - i - chunk));
    if(tmp == target) return i;
  }
  return -1;
}

void process() {
  LL p;
  vector<pair<LL, LL> > groups;
  scanf(" %lld", &p);
  groups.pb(mp(1, p));
  groups.pb(mp(p + chunk, total_size));

  while(true) {
    int nim = 0;
    int mi = 0, mg = 0;
    for(int i=0;i<groups.size();i++) {
      auto g2 = groups[i];
      int m2 = nimber(g2.second - g2.first);
      nim ^= m2;
      if(m2 > mg) {
        mi = i;
        mg = m2;
      }
    }
    if(nim) {
      auto g = groups[mi];
      LL cut = find(g.second - g.first, nim ^ mg);
      printf("%lld\n", g.first + cut);
      fflush(stdout);
    } else {
      for(int i=0;i<groups.size();i++) {
        auto g = groups[i];
        if(g.second - g.first >= chunk) {
          printf("%lld\n", g.first);
          fflush(stdout);
          break;
        }
      }
    }
    scanf(" %lld", &p);
    if(p < 0) return;
    for(int i=0;i<groups.size();i++) {
      auto &g = groups[i];
      if(g.first <= p && g.second > p) {
        groups.pb(mp(p + chunk, g.second));
        g.second = p;
        break;
      }
    }
  }
}

int main(void) {
  int t, w;
  scanf(" %d %d", &t, &w);
  for(int i=0;i<t;i++) process();
  return 0;
}
