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
        }
      }
    }

    for(int j=0;j<VS.size();j++) {
      bool visit[105][105];
      memset(visit, 0, sizeof(visit));
      visit[VS[j].first][VS[j].second] = true;
      queue<state> Q;
      Q.push(state { VS[j].first, VS[j].second, 0 });
      while(!Q.empty()) {
        state st = Q.front();
        Q.pop();
        cerr << st.x << " " << st.y << " " << st.d << endl;
        if(st.d >= M) continue;
        if(active[st.x][st.y]) continue;
        for(int i=0;i<4;i++) {
          int xx = st.x + dx[i], yy = st.y + dy[i];
          if(bound(xx, yy) == false || visit[xx][yy] || D[xx][yy] == '#') continue;
          visit[xx][yy] = true;
          Q.push(state { xx, yy, st.d + 1 });
        }

        cerr << Q.size() << endl;
      }

      cerr << j << " " << VS.size() << endl;
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
