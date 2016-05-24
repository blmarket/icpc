#include <iostream>
#include <cstdlib>
#include <cstring>
#include <unordered_map>
#include <unordered_set>
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
#define each(it, v) for(auto &it: v)
#define pb emplace_back

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;
typedef long long LL;

template<typename T> int size(const T &a) { return a.size(); } 

// #include "load_balance.h"

int n;
vector<LL> w;

bool simple() {
  LL total = 0;
  each(it, w) total += it;
  for(int i=0;i<(1<<n);i++) {
    LL sum = 0;
    for(int j=0;j<n;j++) if(i & (1<<j)) {
      sum += w[j];
    }
    if(sum *2 == total) {
      return true;
    }
  }
  return false;
}

vector<LL> gen(int s, int e) {
  vector<LL> ret;
  ret.clear();
  ret.pb(0);
  for(int i=s;i<e;i++) {
    for(int j = ret.size() - 1; j>= 0;j-- ) {
      ret.pb(ret[j] + w[i]);
    }
  }
  return ret;
}

bool comp() {
  int mid = N / 2;
  vector<LL> v1, v2;
  v1 = gen(0, mid);
  v2 = gen(mid, N);
}

void process(void) {
}

int main(void) {
  int my = MyNodeId();
  int nn = NumberOfNodes();

  while(true) {
    srand(time(NULL));
    n = 10;
    w.clear();
    for(int i=0;i<n;i++) {
      w.pb(rand() % 100);
    }

    process();
  }

  return 0;
}
