#include <iostream>
#include <unordered_map>
#include <bitset>
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

#include <message.h>

#define each(it, v) for(auto &it: v)
#define mp make_pair
#define pb push_back
#define sqr(x) ((x)*(x))
#define foreach(it,c) for(typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;
typedef long long LL;

template<typename T> int size(const T &a) { return a.size(); } 

#include "kolakoski.h"

vector<int> v;
unordered_map<int, pair<int, LL> > cache;
const int SZ = 20;

pair<int, LL> slow(int seed) {
  int now = 0;
  LL buf = 0;
  int jt = 0;

  for(int j=0;j<SZ;j++) {
    // cerr << ((seed >> j) & 1)+1 << " " << now << " " << jt << endl;
    if(seed & (1<<j)) {
      buf |= now * 3 * (1<<jt);
      jt += 2;
    } else {
      buf |= now * (1<<jt);
      ++jt;
    }
    now = !now;
  }

  return make_pair(jt, buf);
}

int main(void) {
  int nn = NumberOfNodes() - 1;
  int my = MyNodeId();

  if(my == nn) {
    LL sum = 0;
    for(int i=0;i<nn;i++) {
      Receive(i);
      sum += GetLL(i);
    }
    cout << sum << endl;
    return 0;
  }

  LL N = GetIndex();
  LL ls = N * my / nn;
  LL rs = N * (my + 1) / nn;

  // 1 2 2 1 1 2 1 2 2 1 2 2 1 1 2 1 1 2 2 1
  v.pb(413094);
  v.pb(447081);
  v.pb(635482);
  int pos = 0;

  LL buf = 0;
  int cur = 0;

  for(int i=0;i<2e8;i++) {
    int seed = v[i];

    pair<int, LL> ps;
    if (cache.count(seed)) {
      ps = cache[seed];
    } else {
      ps = cache[seed] = slow(seed);
    }

    buf |= ps.second << cur;
    cur += ps.first;

    while (cur >= SZ) {
      if(pos == v.size()) {
        v.pb(buf & ((1<<SZ) - 1));
      }
      ++pos;
      buf >>= SZ;
      cur -= SZ;
    }
  }

  LL sum = 0;
  cerr << ls << " " << rs << endl;
  for(LL i=ls;i<rs;i++) {
    int tmp = (v[i/20] >> (i%20))&1;
    if (tmp) sum += GetMultiplier(i);
  }

  PutLL(nn, sum);
  Send(nn);

  return 0;
}
