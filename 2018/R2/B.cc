#include <iostream>
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

int R, B;
int cum[33] = { -1,  0,  1,  3,  6, 10, 15, 21, 28, 36, 45, 55,  66,  78,  91,  105,  120,  136,  153,  171,  190,  210,  231,  253,  276,  300,  325,  351,  378,  406,  435,  465,  496 };
int ret;

void go(int r, int b, int h, int bb, int cnt) {
  if(cnt > ret) {
    ret = cnt;
  }
  if(b < bb * (ret - cnt)) return;
  for(int i=h;i>0;i--) {
    if(r >= cum[i] && b >= i * bb) {
      go(r - cum[i], b - i * bb, i, bb+1, cnt + i);
    }
  }
}

void process() {
  ret = 0;
  scanf(" %d %d", &R, &B);
  go(R, B, 32, 0, 0);
  cout << ret - 1 << endl;
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
