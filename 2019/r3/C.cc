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

int R, C;
vector<string> data;
int flag[105][105];

const int dx[] = {-1, 0, 0, 1};
const int dy[] = {0, -1, 1, 0};

bool chk(char t) {
  bool visit[105][105];
  memset(visit, 0, sizeof(visit));
  bool found = false;
  cerr << data[1] << endl;
  for(int i=1;i<=R;i++) for(int j=1;j<=C;j++) if(!visit[i][j] && data[i][j] == t) {
    if(found) return false;
    found = true;
    cerr << i << " " << j << endl;
    vector<PII> bfs;
    visit[i][j] = true;
    bfs.pb(i, j);
    auto moves = [&](int a, int b) {
      auto chk = [&](int na, int nb) {
        if(data[na][nb] == t && !visit[na][nb]) {
          visit[na][nb] = true;
          bfs.pb(na, nb);
        }
      };
      for(int i=0;i<4;i++) {
        chk(a + dx[i], b + dy[i]);
      }
      if(flag[a][b] == 1) chk(a+1, b+1);
      if(flag[a-1][b-1] == 1) chk(a+1, b+1);
      if(flag[a][b-1] == 2) chk(a+1, b-1);
      if(flag[a-1][b] == 2) chk(a-1, b+1);
    };
    for(int k=0;k<bfs.size();k++) {
      int a, b;
      tie(a,b) = bfs[k];
      moves(a, b);
    }
  }
  return true;
}

bool go(int a, int b) {
  if(a == R) {
    return chk('A') && chk('B');
  }
  if(b == C) {
    return go(a+1, 0);
  }
  flag[a][b] = 0;
  if(go(a, b+1)) return true;
  if(data[a][b] == data[a+1][b+1]) {
    flag[a][b] = 1;
    if(go(a, b+1)) return true;
  }
  if(data[a+1][b] == data[a][b+1]) {
    flag[a][b] = 2;
    if(go(a, b+1)) return true;
  }
  return false;
}

void process() {
  scanf(" %d %d", &R, &C);
  data.clear();
  data.pb(string(C+1, '0'));
  for(int i=0;i<R;i++) {
    char tmp[1024];
    tmp[0] = '0';
    scanf(" %s", tmp + 1);
    data.pb(tmp + '0');
  }
  data.pb(string(C+1, '0'));
  const char out[] = {'.', '\\', '/' };
  if(go(1, 1)) {
    for(int i=1;i<R;i++) {
      for(int j=1;j<C;j++) {
        printf("%c", out[flag[i][j]]);
      }
      printf("\n");
    }
  } else {
    printf("IMPOSSIBLE\n");
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
