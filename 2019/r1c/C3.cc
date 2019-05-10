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
int methods[20][20][20][20];
char board[20][20];

int go(int sx, int sy, int ex, int ey, bool first = false) {
  if(methods[sx][sy][ex][ey] != -1) return methods[sx][sy][ex][ey];
  if(sx >= ex || sy >= ey) return 0;

  int ret = 0;
  set<int> S;
  for(int i=sx;i<ex;i++) {
    bool fail = false;
    for(int j=sy;j<ey;j++) {
      if(board[i][j] == '#') { fail = true; break; }
    }
    if(fail) continue;
    int t1 = go(sx, sy, i, ey);
    int t2 = go(i+1, sy, ex, ey);
    if(first && (t1 ^ t2) == 0) ret += (ey - sy);
    S.insert(t1 ^ t2);
  }

  for(int j=sy;j<ey;j++) {
    bool fail = false;
    for(int i=sx;i<ex;i++) {
      if(board[i][j] == '#') { fail = true; break; }
    }
    if(fail) continue;
    int t1 = go(sx, sy, ex, j);
    int t2 = go(sx, j+1, ex, ey);
    if(first && (t1 ^ t2) == 0) ret += (ex - sx);
    S.insert(t1 ^ t2);
  }

  if(first) {
    if(S.count(0)) return ret;
    else return 0;
  }

  for(int i=0;;i++) {
    if(!S.count(i)) {
      return methods[sx][sy][ex][ey] = i;
    }
  }
}

void process() {
  scanf(" %d %d", &R, &C);
  for(int i=0;i<R;i++) {
    scanf(" %s", board[i]);
  }
  memset(methods, -1, sizeof(methods));
  cout << go(0, 0, R, C, true) << endl;
  for(int i=0;i<R;i++) {
    for(int j=0;j<C;j++) {
      for(int k=0;k<R;k++) {
        for(int l=0;l<C;l++) {
          if(methods[i][j][k][l] != -1) {
            cerr << i << " " << j << " " << k << " " << l << " = " << methods[i][j][k][l] << endl;
          }
        }
      }
    }
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
