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

const LL chunk = 1e10;

int nimber(LL sz) {
  cerr << sz << endl;
  set<int> zz;
  if(sz < chunk) return 0;
  for(LL i=0;i+chunk<sz;i+=chunk) {
    zz.insert(nimber(i) ^ nimber(sz - i - chunk));
  }
  for(LL i=chunk-1;i+chunk<sz;i+=chunk) {
    zz.insert(nimber(i) ^ nimber(sz - i - chunk));
  }
  for(int i=0;;i++) {
    if(zz.count(i) == 0) return i;
  }
}

int main(void) {
  cout << nimber(1e12) << endl;
  return 0;
}
