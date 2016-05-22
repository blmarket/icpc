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
const int SZ = 10;

int main(void) {
  LL N = GetIndex();
  N = 2000;

  // 1 2 2 1 1 2 1 2 2 1 2 2 1 1 2 1 1 2 2 1
  int seed = 413094;

  int idx = 0;
  for(int i=0;i<5;i++) {
    auto slow = [&]() -> pair<int, LL> {
      cerr << seed << endl;
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
    };

    LL buf = 0;
    int cur = 0;

    pair<int, LL> ps = slow();
//    if (cache.count(seed)) {
//      ps = cache[seed];
//    } else {
//      ps = cache[seed] = slow();
//    }

    buf |= ps.second << cur;
    cerr << bitset<20>(buf) << endl;
    cur += ps.first;

    if (cur >= SZ) {
      v.pb(buf & ((1<<SZ) - 1));
      buf >>= SZ;
      cur -= SZ;
    }

    seed = v[idx++];
  }

  each(it, v) {
    cout << bitset<SZ>(it) << " ";
  }
  cout << endl;
  return 0;
}
