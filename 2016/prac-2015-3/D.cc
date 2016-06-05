#include <iostream>
#include <algorithm>
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

#define STR(p) (p).first << " " << (p).second

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;
typedef long long LL;

template<typename T> int size(const T &a) { return a.size(); } 

vector<LL> ret;

bool search(map<LL, LL> &cur) {
  if(cur.size() == 1) {
    LL &tmp = cur[0];
    while(tmp > 1) {
      ret.pb(0);
      tmp /= 2;
    }
    return true;
  }

  auto it = cur.rbegin();
  auto jt = cur.rbegin();
  ++jt;

  auto chk = [&](LL a) {
    map<LL, LL> nex;
    for(auto it = cur.rbegin(); it != cur.rend(); ++it) {
      if(it->second == 0) continue;
      nex[it->first-a] = it->second;
      cur[it->first-a] -= it->second;
    }
    cerr << a << endl;
    //each(xt, cur) {
    //  cerr << xt.first << "=" << xt.second << " ";
    //}
    //cerr << endl;
    bool tmp = search(nex);
    if(tmp) ret.pb(a);
    return tmp;
  };

  auto chk2 = [&](int a) {
    map<LL, LL> nex;
    for(auto it = cur.begin(); it != cur.end(); ++it) {
      if(it->second == 0) continue;
      nex[it->first-a] = it->second;
      cur[it->first-a] -= it->second;
    }
    bool tmp = search(nex);
    if(tmp) ret.pb(a);
    return tmp;
  };

  int c1 = it->first - jt->first;
  cerr << it->first << " " <<jt->first << " " << c1 << endl;

  chk(c1);
}

void process() {
  ret.clear();
  int p;
  map<LL, LL> cur, init;

  vector<LL> d1, d2;
  scanf(" %lld", &p);
  d1.resize(p); d2.resize(p);
  for(int i=0;i<p;i++) scanf(" %lld", &d1[i]);
  for(int i=0;i<p;i++) {
    LL tmp;
    scanf(" %lld", &tmp);
    cur[d1[i]] = tmp;
  }

  init = cur;

  auto remove = [&](map<LL, LL> &cur, int candi) -> bool {
    map<LL, LL> nex;
    if(candi > 0) {
      for(auto it = cur.rbegin(); it != cur.rend(); ++it) {
        if(it->second == 0) continue;
        nex[it->first - candi] = it->second;
        cur[it->first - candi] -= it->second;
      }
    } else {
      for(auto it = cur.begin(); it != cur.end(); ++it) {
        if(it->second == 0) continue;
        nex[it->first - candi] = it->second;
        cur[it->first - candi] -= it->second;
      }
    }
    cur.swap(nex);
    each(it, cur) {
      cerr << it.first << "=" << it.second << " ";
    }
    cerr << endl;
  };

  vector<LL> cs;
  while(cur.size() > 1) {
    auto it = cur.rbegin();
    auto it2 = it; ++it2;

    LL candi = it->first - it2->first;
    cs.pb(candi);

    remove(cur, candi);
  }

  cerr << cur[0] << endl;
  while(cur[0] > 1) {
    cs.pb(0);
    cur[0] /= 2;
  }

  sort(cs.rbegin(), cs.rend());
  cur = move(init);
  vector<LL> ret;
  for(int i=0;i<size(cs);i++) {
    if(cs[i] == 0) {
      ret.pb(0);
      continue;
    }
    if(cur[-cs[i]]) {
      ret.pb(-cs[i]);
      remove(cur, -cs[i]);
    } else {
      ret.pb(cs[i]);
      remove(cur, cs[i]);
    }
  }
  sort(ret.begin(), ret.end());
  each(it, ret) cout << it << " ";
  cout << endl;
}

int main(void) {
  int T;
  scanf(" %d", &T);
  for(int i=1;i<=T;i++) {
    printf("Case #%d: ",i);
    process();
  }
  return 0;
}
