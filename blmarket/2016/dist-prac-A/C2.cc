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

int main(void) {
  LL N = GetIndex();
  N = 2000;

  // 1 2 2 1 1 2 1 2 2 1 2 2 1 1 2 1 1 2 2 1
  int seed = 413094;

  int idx = 0;
  for(int i=0;i<1;i++) {
    auto slow = [&]() -> pair<int, LL> {
      int now = 0;
      LL buf = 0;
      int jt;

      for(int j=0;j<20;j++) {
        cerr << ((seed >> j) & 1)+1 << " " << now << endl;
        if(seed & (1<<j)) {
          buf |= now * (1<<(jt+2) - (1<<jt));
          jt += 2;
        } else {
          buf |= now * (1<<jt);
          ++jt;
        }
        cerr << buf << endl;
        now = !now;
      }

      return make_pair(jt, buf);
    };

    LL buf = 0;
    int cur = 0;

    pair<int, LL> ps;
    if (cache.count(seed)) {
      ps = cache[seed];
    } else {
      ps = cache[seed] = slow();
    }

    buf |= ps.second << cur;
    cur += ps.first;

    if (cur >= 20) {
      v.pb(buf & ((1<<20) - 1));
      buf >>= 20;
      cur -= 20;
    }

    seed = v[idx++];
  }

  cout << v[0] << endl; 

  each(it, v) {
    cout << bitset<20>(it) << " ";
  }
  cout << endl;
  return 0;
}
