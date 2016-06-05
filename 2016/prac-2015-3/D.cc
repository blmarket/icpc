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

vector<int> ret;

bool search(map<int, int> &cur) {
  if(cur.size() == 1) {
    int &tmp = cur[0];
    while(tmp > 1) {
      ret.pb(0);
      tmp /= 2;
    }
    return true;
  }

  auto it = cur.rbegin();
  auto jt = cur.rbegin();
  ++jt;

  auto chk = [&](int a) {
    map<int, int> nex;
    for(auto it = cur.rbegin(); it != cur.rend(); ++it) {
      if(it->second == 0) continue;
      nex[it->first-a] = it->second;
      if((cur[it->first-a] -= it->second) < 0) return false;
    }
    each(xt, cur) {
      cerr << xt.first << "=" << xt.second << " ";
    }
    cerr << endl;
    bool tmp = search(nex);
    if(tmp) ret.pb(a);
    return tmp;
  };

  auto chk2 = [&](int a) {
    map<int, int> nex;
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
  if(it->first > 0 && chk(c1)) return true;
  if(cur.begin()->first < 0) { // can be negative
    if(chk2(-c1)) return true;
  }
  return false;
}

void process() {
  ret.clear();
  int p;
  map<int, int> cur;

  vector<int> d1, d2;
  scanf(" %d", &p);
  d1.resize(p); d2.resize(p);
  for(int i=0;i<p;i++) scanf(" %d", &d1[i]);
  for(int i=0;i<p;i++) {
    int tmp;
    scanf(" %d", &tmp);
    cur[d1[i]] = tmp;
  }

  cerr << "here" << endl;

  search(cur);
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
