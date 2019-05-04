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

const int dx[] = {-1, 0, 0, 1};
const int dy[] = {0, -1, 1, 0};

int N, M;
char data[25][25];
int mask[25][25];

int ret;

int c1(int sx, int sy, int ex, int ey, bool flag) {
  int ret = 0;
  for(int i=sx;i<ex;i++) {
    for(int j=sy;j<ey;j++) {
      if(flag ^ (data[i][j] == 'W'))
        mask[i][j] = 1;
    }
  }
  return ret;
}

int c2(int x, int y) {
  int r2 = 1;
  mask[x][y] = 2;
  for(int i=0;i<4;i++) {
    int nx = x + dx[i], ny = y + dy[i];
    if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
    if(mask[nx][ny] == 1) r2 += c2(nx, ny);
  }
  return r2;
}

void cnt(int a, int b, int c) {
  memset(mask, 0, sizeof(mask));
  c1(0, 0, a, b, c & 1) + c1(a, 0, N, b, c & 2) + c1(0, b, a, M, c & 4) + c1(a, b, N, M, c & 8);

  int r2 = 0;
  for(int i=0;i<N;i++) for(int j=0;j<M;j++) if(mask[i][j] == 1) {
    int tmp = c2(i, j);
    if(r2 < tmp) {
      r2 = tmp;
    }
  }

  cerr << a << " " << b << " " << c << " = " << r2 << endl;
  for(int i=0;i<N;i++) {
    for(int j=0;j<M;j++) cerr << mask[i][j];
    cerr << endl;
  }

  if(ret < r2) ret = r2;
}

void process() {
  scanf(" %d %d", &N, &M);
  for(int i=0;i<N;i++) {
    scanf(" %s", data[i]);
  }

  ret = 0;

  for(int i=0;i<N;i++) {
    for(int j=0;j<M;j++) {
      for(int k=0;k<(1<<4);k++) {
        cnt(i, j, k);
      }
    }
  }
  printf("%d\n", ret);
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
