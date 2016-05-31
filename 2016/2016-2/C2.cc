#include <iostream>
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
#define mt make_tuple
#define each(it, v) for(auto &it: v)
#define pb emplace_back

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;
typedef tuple<int,int,int> TI;
typedef long long LL;

template<typename T> int size(const T &a) { return a.size(); } 

const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};

int r,c;
int n;
bool flow[105][105][4];
bool visit[105][105];
int track[105][105];
vector<PII> gates;
vector<PII> pairs;

char ret[105][105];

bool good(int x, int y) {
  return x>=0 && y>=0 && x<r && y<c;
}

int trace(int a, int b, bool move) {
  PII pos = gates[a];
  PII tgt = gates[b];
  memset(track, -1, sizeof(track));
  int sx,sy;
  for(int i=0;i<4;i++) {
    sx = pos.first + dx[i];
    sy = pos.second + dy[i];
    if(good(sx,sy)) {
      track[sx][sy] = i;
      break;
    }
  }

  auto apply = [&](int x, int y, int d) {
    while(true) {
      int px = x + dx[(d+2)%4];
      int py = y + dy[(d+2)%4];
      if(!good(px, py)) break;

      cerr << d - track[px][py] << " " << px << " " << py << endl;
      ret[px][py] = '/';
      
      flow[px][py][d] = false;
      x = px; y = py;
      d = track[x][y];
    }
  };

  queue<TI> Q;
  Q.push(mt(sx,sy,0));
  while(!Q.empty()) {
    int dist;
    tie(sx,sy,dist) = Q.front();
    Q.pop();
    for(int i=0;i<4;i++) {
      if(flow[sx][sy][i]) {
        int nx = sx + dx[i];
        int ny = sy + dy[i];
        if(mp(nx,ny) == tgt) {
          if(move) {
            apply(nx, ny, i);
          }
          return dist+1;
        }
        if(!good(nx,ny)) continue;
        if(track[nx][ny] != -1) continue;
        track[nx][ny] = i;
        Q.push(mt(nx,ny, dist+1));
      }
    }
  }
  return -1;
}

void process() {
  scanf(" %d %d", &r, &c);
  n = (r+c)*2;

  gates.clear();
  for(int i=0;i<c;i++) gates.pb(mp(-1, i));
  for(int i=0;i<r;i++) gates.pb(mp(i, c));
  for(int i=c-1;i>=0;i--) gates.pb(mp(r, i));
  for(int i=r-1;i>=0;i--) gates.pb(mp(i, -1));

  memset(flow, 0, sizeof(flow));
  for(int i=0;i<r;i++) {
    for(int j=0;j<c;j++) {
      if((i^j)&1) {
        flow[i][j][0] = flow[i][j][2] = true;
      } else {
        flow[i][j][1] = flow[i][j][3] = true;
      }
    }
  }

  pairs.clear();
  for(int i=0;i<n/2;i++) {
    int a,b;
    scanf(" %d %d", &a, &b);
    a--;b--;
    if(a & 1) swap(a, b);
    pairs.pb(mp(a,b));
  }

  vector<bool> used(pairs.size(), false);

  for(int i=0;i<size(pairs);i++) {
    int md = -1;
    int mdist = -1;
    for(int j=0;j<size(pairs);j++) if(!used[j]) {
      int a,b;
      tie(a,b) = pairs[i];
      int tmp = trace(a,b,false);
      if(tmp == -1){
        cout << "IMPOSSIBLE" << endl;
        return;
      }
      if(md == -1 || mdist < tmp) {
        md = j;
        mdist = tmp;
      }
    }
    trace(pairs[md].first, pairs[md].second, true);
    used[md] = true;
  }
  for(int i=0;i<r;i++) {
    for(int j=0;j<c;j++) printf("%c", ret[i][j]);
    printf("\n");
  }
}

int main(void) {
  int T;
  scanf(" %d", &T);
  for(int i=1;i<=T;i++) {
    printf("Case #%d:\n",i);
    process();
  }
  return 0;
}
