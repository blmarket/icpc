#include <iostream>
#include <algorithm>
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

#include "load_balance.h"

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
  LL total = 0;
  each(it, w) total += it;

  if(total & 1) return false;

  int mid = n / 2;
  vector<LL> v1, v2;
  v1 = gen(0, mid);
  v2 = gen(mid, n);
  sort(v1.begin(), v1.end());
  sort(v2.begin(), v2.end());
  
  int j = v2.size() - 1;
  for(int i=0;i<size(v1);i++) {
    while(j > 0 && v1[i] + v2[j] > total/2) j--;
    if(v1[i] + v2[j] == total/2) {
      return true;
    }
    if(j == 0) break;
  }
  return false;
}

int main(void) {
  int my = MyNodeId();
  int nn = NumberOfNodes();

  if (my != 0) return 0;

  n = GetN();
  w.clear();
  for(int i=0;i<n;i++) {
    w.pb(GetWeight(i));
  }

  cout << (comp() ? "POSSIBLE" : "IMPOSSIBLE") << endl;
  return 0;
}
