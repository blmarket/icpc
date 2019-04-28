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

int find_max(int *arr, int s, int e) {
  int ret = -1;
  function<void(int, int, int)> go;
  go = [&](int pos, int ps, int pe) {
    if(pe <= s || ps >= e) return;
    if(ret != -1 && arr[pos] <= arr[base + ret]) return;
    if(ps+1 == pe) {
      ret = ps;
      return;
    }
    int pm = (ps + pe) / 2;
    go(pos*2, ps, pm);
    go(pos*2+1, pm, pe);
  };
  go(1, 0, base);
  return ret;
}

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
long long ret;

void go(int s, int e) {
  if(s >= e) return;

  int i = find_max(arr1, s, e);

  int r2 = find_bigger(arr2, i, e, arr1[base+i] + K, true);
  if(r2 < 0) r2 = e;
  int l2 = find_bigger(arr2, s, i+1, arr1[base+i] + K, false);
  if(l2 < 0) l2 = s; else l2++;

  ret += (LL)(r2 - i) * (i - l2 + 1);

  int r3 = find_bigger(arr2, i, e, arr1[base+i] - K - 1, true);
  if(r3 < 0) r3 = e;
  int l3 = find_bigger(arr2, s, i + 1, arr1[base+i] - K - 1, false);
  if(l3 < 0) l3 = s;

  ret -= (LL)(r3 - i) * (i - l3 + 1);

  cerr << i << " " << l2 << " " << r2 << " " << l3 << " " << r3 << " = " << ret << endl;

  go(s, i);
  go(i+1, e);
}

void process() {
  scanf(" %d %d",&P, &K);
  for(int i=0;i<P;i++) {
    scanf(" %d", &arr1[base + i]);
  }
  for(int i=0;i<P;i++) {
    scanf(" %d", &arr2[base + i]);
  }
  for(int i=base-1;i>=1;i--) {
    arr1[i] = max(arr1[i*2], arr1[i*2+1]);
    arr2[i] = max(arr2[i*2], arr2[i*2+1]);
  }

  // cerr << find_bigger(arr2, 0, 3, 8, false) << endl;

  ret = 0;
  go(0, P);
  cout << ret << endl;
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
