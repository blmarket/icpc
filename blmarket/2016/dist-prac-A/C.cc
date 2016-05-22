#include <iostream>
#include <sys/wait.h>
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

vector<LL> V;

int main(void) {
  LL N = GetIndex();

  LL ret = 0;

  V.pb(1);
  ret += 1;
  V.pb(3);
  ret += 2 * 2;
  V.pb(5);
  ret += 2 * 1;
  int idx = 2;
  int now = 1;
  while(V.back() <= N) {
    cerr << idx << " ";
    for(int i=0;i<V[idx] - V[idx - 1];i++) {
      V.pb(V.back() + now);
    }
    idx++;
    now = 3-now;
  }

  cerr << V[0];
  for(int i=1;i<N;i++) {
    cerr << V[i] - V[i-1];
  }
  cerr << endl;

  return 0;
}
