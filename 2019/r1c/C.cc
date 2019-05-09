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

int R, C;
LL methods[20][20][20][20];
char board[20][20];

int go(int sx, int sy, int ex, int ey) {
  if(methods[sx][sy][ex][ey] != -1) return methods[sx][sy][ex][ey];
  if(sx >= ex || sy >= ey) return 0;

  int ret = 0;
  for(int i=sx;i<ex;i++) {
    for(int j=sy;j<ey;j++) {
      bool fail = false;
      for(int k=sx;k<ex;k++) {
        if(board[i][j] == '#') {
          fail=true; break;
        }
      }
      if(!fail) {
        bool t1 = !!go(sx, sy, ex, j);
        bool t2 = !go(sx, j+1, ex, ey);
        ret += t1 ^ t2;
      }
      fail = false;
      for(int k=sy;k<ey;k++) {
        if(board[i][j] == '#') {
          fail=true; break;
        }
      }
      if(!fail) {
        bool t1 = !!go(sx, sy, i, ey);
        bool t2 = !go(i+1, sy, ex, ey);
        ret += t1 ^ t2;
      }
    }
  }
  return methods[sx][sy][ex][ey] = ret;
}

void process() {
  scanf(" %d %d", &R, &C);
  for(int i=0;i<R;i++) {
    scanf(" %s", board[i]);
  }
  memset(methods, -1, sizeof(methods));
  cout << go(0, 0, R, C) << endl;
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
