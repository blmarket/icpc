#include <iostream>
#include <bitset>
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
typedef pair<int,int> PII;
typedef long long LL;

template<typename T> int size(const T &a) { return a.size(); } 

const int dx[] = {-1,0,0,1};
const int dy[] = {0,-1,1,0};

struct state {
  int x, y, d;
};

int C, R, M;
char D[105][105];
vector<PII> VS, VT;
int sight[1<<10][10];

bool bound(int x, int y) { return x >= 0 && y >= 0 && x < R && y < C; }

int go(int mask1, int mask2) {
  int ret = 0;
  for(int i=0;i<VS.size();i++) if(mask1 & (1<<i)) {
    int m2 = sight[mask2][i];
    for(int j=0;j<VT.size();j++) if(m2 & (1<<j)) {
      cerr << "here" << endl;
      int tmp = go(mask1 ^ (1<<i), mask2 ^ (1<<j));
      if(ret < tmp + 1) ret = tmp;
    }
  }
  // cerr << bitset<10>(mask1) << " " << bitset<10>(mask2) << " = " << ret << endl;
  return ret;
}

void process() {
  memset(sight, -1, sizeof(sight));
  VS.clear(); VT.clear();
  scanf(" %d %d %d", &C, &R, &M);
  for(int i=0;i<R;i++) {
    scanf(" %s", D[i]);
    for(int j=0;j<C;j++) {
      if(D[i][j] == 'S') {
        VS.pb(i, j);
      }
      if(D[i][j] == 'T') {
        VT.pb(i, j);
      }
    }
  }

  int n = VT.size();
  for(int mask=0;mask<(1<<n);mask++) {
    int active[105][105];
    memset(active, 0, sizeof(active));
    for(int i=0;i<VT.size();i++) if(mask & (1<<i)) {
      int x, y; tie(x, y) = VT[i];
      active[x][y] = 1;
      for(int j=0;j<4;j++) {
        int xx = x + dx[j], yy = y + dy[j];
        while(bound(xx, yy) && D[xx][yy] != '#') {
          active[xx][yy] = 1;
          xx += dx[j]; yy += dy[j];
        }
      }
    }

    for(int j=0;j<VS.size();j++) {
      bool visit[105][105];
      memset(visit, 0, sizeof(visit));
      visit[VS[j].first][VS[j].second] = true;
      queue<state> Q;
      Q.push(state { VS[j].first, VS[j].second, 0 });
      int r1 = 0;
      while(!Q.empty()) {
        state st = Q.front();
        Q.pop();
        for(int i=0;i<4;i++) {
          int xx = st.x + dx[i], yy = st.y + dy[i];
          if(bound(xx, yy) == false || D[xx][yy] == '#') continue;
          if(!active[st.x][st.y] && !visit[xx][yy] && st.d < M) {
            visit[xx][yy] = true;
            Q.push(state { xx, yy, st.d + 1 });
          }
          while(bound(xx, yy) && D[xx][yy] != '#') {
            for(int k=0;k<VT.size();k++) if(mask & (1<<k)) {
              if(VT[k] == mp(xx, yy)) r1 |= (1<<k);
            }
            xx += dx[i]; yy += dy[i];
          }
        }
      }

      cerr << " " << bitset<10>(mask) << " " << j << " = " << r1 << endl;

      sight[mask][j] = r1;
    }
  }

  cout << go((1<<VS.size())-1, (1<<VT.size())-1) << endl;
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
