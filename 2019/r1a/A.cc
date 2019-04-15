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
#include <functional>

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

int r, c;
bool used[25][25];

void enumerate(int a, int b, function<void(int, int)>fn) {
  for(int i=0;i<r;i++) {
    for(int j=0;j<c;j++) if(!used[i][j]) {
      if(i == a || j == b) continue;
      if(i+j == a+b || i-j == a-b) continue;
      fn(i, j);
    }
  }
}

void process() {
  vector<PII> res;
  scanf(" %d %d", &r, &c);

  bool fail;
  for(int trial=0;trial<1;trial++) {
    res.clear();
    memset(used, 0, sizeof(used));
    fail = false;
    int cx = rand() % r;
    int cy = rand() % c;

    for(int i=0;i<r*c;i++) {
      cerr << cx + 1 << " " << cy + 1 << endl;
      res.pb(mp(cx, cy));
      used[cx][cy] = 1;

      int mx, my, mm = -1;
      enumerate(cx, cy, [&](int x, int y) {
          int ret = 0;
          enumerate(x, y, [&](int xx, int yy) { 
              ret++;
          });
          if(ret > mm) {
              mm = ret;
              mx = x;
              my = y;
          }
      });
      if(mm == -1) {
        fail = true;
        break;
      }
      cx = mx; cy = my;
    }
    if(!fail) break;
  }
  if(fail) {
    printf("IMPOSSIBLE\n");
    return;
  }
  printf("POSSIBLE\n");
  for(int i=0;i<res.size();i++) {
    printf("%d %d\n", res[i].first + 1, res[i].second + 1);
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
