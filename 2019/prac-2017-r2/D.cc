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

const int dx[] = {-1, 0, 0, 1};
const int dy[] = {0, -1, 1, 0};

int C, R, M;
char D[105][105];
int ST[105][105];
vector<PII> VS, VT;
unordered_map<int, int> links[105];

bool bound(int x, int y) {
  return x >= 0 && y >= 0 && x < R && y < C;
}

void process() {
  for(int i=0;i<105;i++) links[i].clear();
  VS.clear(); VT.clear();
  scanf(" %d %d %d", &C, &R, &M);
  memset(ST, 0, sizeof(ST));
  for(int i=0;i<R;i++) {
    scanf(" %s", D[i]);
    for(int j=0;j<C;j++) {
      if(D[i][j] == 'S') {
        VS.pb(i,j);
        ST[i][j] = VS.size();
      }
      if(D[i][j] == 'T') {
        VT.pb(i,j);
        ST[i][j] = -VT.size();
      }
    }
  }

  int visit[105][105];

  for(int ss=0;ss<VS.size();ss++) {
    memset(visit, -1, sizeof(visit));
    function<void(int, int, int)> bfs;
    bfs = [&](int x, int y, int d) {
      if(!bound(x,y)) return;
      if(D[x][y] == '#') return;
      if(visit[x][y] != -1) return;
      if(d > M) return;
      visit[x][y] = d;
      for(int i=0;i<4;i++) {
        int xx = x, yy = y;
        while(bound(xx, yy)) {
          if(D[xx][yy] == '#') break;
          if(D[xx][yy] == 'T') {
            int tt = -ST[xx][yy];
            if (links[ss][tt] == 0 || links[ss][tt] > d) links[ss][tt] = d;
          }
          xx += dx[i];
          yy += dy[i];
        }
        bfs(x+dx[i], y+dy[i], d+1);
      }
    };

    bfs(VS[ss].first, VS[ss].second, 0);

    cerr << ss+1 << " : ";
    for(auto jt: links[ss]) {
      cerr << jt.first << "," << jt.second << " ";
    }
    cerr << endl;
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
