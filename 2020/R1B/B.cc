#include <iostream>
#include <random>
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
#define mt make_tuple

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;
typedef long long LL;

template<typename T> int size(const T &a) { return a.size(); } 

mt19937 rnd(time(NULL));
int t, a, b;

int safe_rnd() {
  int tmp = (int)rnd();
  while(tmp <= -1e9 || tmp >= 1e9) {
    tmp = (int) rnd();
  }
  return tmp;
}

char chk(int x, int y) {
  char buf[10];
  printf("%d %d\n", x, y);
  fflush(stdout);
  scanf(" %s", buf);
  return buf[0];
}

tuple<int, int> stage1() {
  while(true) {
    int t1, t2;
    t1 = safe_rnd();
    t2 = safe_rnd();
    char tmp = chk(t1, t2);
    if(tmp == 'C') return make_tuple(2e9, 2e9);
    if(tmp == 'H') return mt(t1, t2);
  }
}

int bs2(int s, int e, int d, const function<char(int)> &func) {
  while(abs(e-s) > 1) {
    int m = (s+e) / 2;
    char tmp = func(m);
    // cerr << s << " " << e << " " << d << " " << m << " " << tmp << endl;
    if(tmp == 'C') return 2e9;
    if(tmp == 'M') e = m;
    else s = m;
  }
  return s;
}

int bs(int v, const function<char(int)> &func) {
  int r1 = bs2(v, 1e9+1, 0, func);
  if(r1 == 2e9) return 2e9;
  int r2 = bs2(v, -1e9-1, -1, func);
  if(r2 == 2e9) return 2e9;
  return (r1+r2) / 2;
}

void process() {
  int x, y;
  tie(x, y) = stage1();
  if(x == 2e9) return;
  int rx = bs(x, [y](int x) -> int {
      return chk(x, y);
      });
  if(rx == 2e9) return;
  int ry = bs(y, [x](int y) -> int {
      return chk(x, y);
      });
  if(ry == 2e9) return;
  char tmp = chk(rx, ry);
  cerr << tmp << endl;
}

int main(void) {
  scanf(" %d %d %d", &t, &a, &b);
  for(int i=0;i<t;i++) process();
}
