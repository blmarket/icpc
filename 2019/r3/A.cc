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

unordered_map<LL, int> memo;

int nimber(LL sz) {
  set<int> zz;
  if(sz < chunk) return 0;
  if(memo.count(sz)) return memo[sz];
  for(LL i=0;i+chunk<=sz;i+=chunk) {
    zz.insert(nimber(i) ^ nimber(sz - i - chunk));
  }
  for(LL i=(sz % chunk) + 1;i+chunk<=sz;i+=chunk) {
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
  for(LL i=(sz % chunk) + 1;i+chunk<=sz;i+=chunk) {
    int tmp = (nimber(i) ^ nimber(sz - i - chunk));
    if(tmp == target) return i;
  }
  for(LL i=chunk-1;i+chunk<=sz;i+=chunk) {
    int tmp = (nimber(i) ^ nimber(sz - i - chunk));
    if(tmp == target) return i;
  }
  cerr << "CANNOT HAPPEN " << sz << " " << nimber(sz) << " " << target << endl;
  return -1;
}

void process() {
  LL p;
  vector<pair<LL, LL> > groups;
  scanf(" %lld", &p);
  groups.pb(mp(1, p));
  groups.pb(mp(p + chunk, total_size + 1));

  auto add_cut = [&](int idx, LL pos) {
    groups.pb(pos + chunk, groups[idx].second);
    groups[idx].second = pos;
  };

  while(true) {
    int nim = 0;
    for(int i=0;i<groups.size();i++) {
      auto g2 = groups[i];
      int m2 = nimber(g2.second - g2.first);
      nim ^= m2;
    }
    // cerr << "Current nim: " << nim << endl;
    if(nim) {
      bool found = false;
      for(int i=0;i<groups.size();i++) {
        auto &g = groups[i];
        int m = nimber(g.second - g.first);
        if((m ^ nim) < m) {
          found = true;
          // cerr << "HERE " << nim << " " << m << " " << (nim ^ m) << endl;
          LL cut = find(g.second - g.first, nim ^ m);
          printf("%lld\n", g.first + cut);
          fflush(stdout);
          add_cut(i, g.first + cut);
          break;
        }
      }
      if(!found) {
        cerr << "CANNOT HAPPEN" << endl;
        printf("-1\n");
        fflush(stdout);
      }
    } else {
      int mx = 0;
      for(int i=1;i<groups.size();i++) {
        if(groups[i].second - groups[i].first > groups[mx].second - groups[mx].first) {
          mx = i;
        }
      }
      auto g = groups[mx];

      LL sz = g.second - g.first;
      int cur = nimber(sz);
      {
        LL pos = 0;
        for(LL i=0;i+chunk<=sz;i+=chunk) {
          int tmp = (nimber(i) ^ nimber(sz - i - chunk));
          if(cur != tmp) {
            pos = i;
            break;
          }
        }
        printf("%lld\n", (g.first + pos));
        fflush(stdout);
        add_cut(mx, (g.first + pos));
      }
    }

    scanf(" %lld", &p);
    // cerr << "got " << p << endl;
    if(p < 0) {
      nim = 0;
      for(int i=0;i<groups.size();i++) {
        auto g2 = groups[i];
        if(g2.second - g2.first >= chunk) {
          cerr << g2.first << "-" << g2.second << " ";
        }
        int m2 = nimber(g2.second - g2.first);
        nim ^= m2;
      }
      cerr << nim << " = " << p << endl;
      return;
    }
    for(int i=0;i<groups.size();i++) {
      pair<LL, LL> &g = groups[i];
      if(g.first <= p && g.second > p) {
        // cerr << "found " << g.first << " " << g.second << endl;
        add_cut(i, p);
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
