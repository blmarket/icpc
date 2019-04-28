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

const int base = 131072;

int find_bigger(int *arr, int s, int e, int target, bool first) {
  function<int(int, int, int)> go;
  go = [&](int pos, int ps, int pe) {
    if(pe <= s || ps >= e) return -1;
    if(arr[pos] <= target) return -1;
    if(ps+1 == pe) return ps;
    int pm = (ps+pe)/2;
    if(first) {
      int ret = go(pos*2, ps, pm);
      if(ret != -1) return ret;
      return go(pos*2+1, pm, pe);
    } else {
      int ret = go(pos*2+1, pm, pe);
      if(ret != -1) return ret;
      return go(pos*2, ps, pm);
    }
  };
  return go(1, 0, base);
}

int P, K;
int arr1[262144], arr2[262144];

void process() {
  long long ret = 0;
  scanf(" %d %d",&P, &K);
  for(int i=0;i<P;i++) {
    scanf(" %d", &arr1[i]);
  }
  for(int i=0;i<P;i++) {
    scanf(" %d", &arr2[i]);
  }

  for(int i=0;i<P;i++) {
    int r1 = find_bigger(arr1, i+1, P, arr1[i], true);
    if(r1 < 0) r1 = P;
    int l1 = find_bigger(arr1, 0, i, arr1[i], false);
    if(l1 < 0) l1 = 0; else ++l1;
    int r2 = find_bigger(arr2, i+1, P, arr1[i] + K, true);
    if(r2 < 0) r2 = P;
    int l2 = find_bigger(arr2, 0, i, arr1[i] + K, false);
    if(l2 < 0) l2 = 0; else ++l2;
    r1 = min(r1, r2);
    l1 = max(l1, l2);
    int r3 = find_bigger(arr2, i+1, P, arr1[i] - K, true);
    int l3 = find_bigger(arr2, 0, i, arr1[i] - K, false);
  }
}

int main(void) {
  int T;
  scanf(" %d", &T);
  for(int i=1;i<=T;i++) {
    printf("Case #%d: ", i);
    process();
  }
  return 0;
}
