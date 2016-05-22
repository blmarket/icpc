#include <iostream>
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

vector<int> V;

int main(void) {
  LL N = GetIndex();
  N = 2000;

  // 1 2 2 1 1 2 1 2 2 1 2 2 1 1 2 1 1 2 2 1
  int seed = 413094;
  int now = 1;

  V.pb(seed);
  int idx = 0;
  for(int i=0;i<10;i++) {
    seed = V[idx];
    LL buf = 0;
    LL jt = 1LL;
    for(int j=0;j<20;j++) {
      if(seed & (1<<j)) {
        buf |= now * (jt + (jt << 1));
        jt <<= 2;
      } else {
        buf |= now * jt;
        jt <<= 1;
      }
      now = !now;

      if (jt >= (1<<20)) {
        V.pb(buf & ((1<<20)-1));
        buf >>= 20;
        jt >>= 20;
      }
    }
  }

  each(it, V) {
    cout << bitset<20>(it) << " ";
  }
  cout << endl;
  return 0;
}
