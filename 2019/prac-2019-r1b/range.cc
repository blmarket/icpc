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

int arr[262144];

const int base = 131072;

int find_max(int s, int e) {
  function<int(int, int, int)> go;
  go = [&](int pos, int ps, int pe) {
    if(ps >= s && pe <= e) return arr[pos];
    if(pe <= s || ps >= e) return -1;
    int pm = (ps+pe)/2;
    int ret = max(go(pos*2, ps, pm), go(pos*2+1, pm, pe));
    // cerr << pos << " " << ps << " " << pe << " = " << ret << endl;
    return ret;
  };
  return go(1, 0, base);
}

int main(void) {
  memset(arr, 0, sizeof(arr));
  int N = 16;
  for(int i=0;i<N;i++) {
    arr[base+i] = rand() % 100;
  }
  for(int i=base-1;i>=1;i--) {
    arr[i] = max(arr[i*2], arr[i*2+1]);
  }

  int nn = N;
  int bb = base;
  while(nn>1) {
    for(int i=0;i<nn;i++) {
      cout << arr[bb+i] << " ";
    }
    cout << endl;
    nn = (nn+1)/2;
    bb/=2;
  }

  cout << find_max(0, 4) << endl;
  cout << find_max(8, N) << endl;
  return 0;
}
