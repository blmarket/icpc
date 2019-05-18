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

struct edge {
  int n, c, f;
};

const int dx[] = {-1, 0, 0, 1};
const int dy[] = {0, -1, 1, 0};

int C, R, M;
char D[105][105];
int ST[105][105];
vector<PII> VS, VT;
vector<edge> net[205];

bool bound(int x, int y) {
  return x >= 0 && y >= 0 && x < R && y < C;
}

void add_edge(int s, int e, int c, int f) {
  for(auto &it: net[s]) {
    if(it.n == e && it.c == c) {
      it.f += f;
      return;
    }
  }
  net[s].pb(edge { e, c, f });
}

bool mcmf(int s, int e) {
  int dist[205];
  int back[205];
  memset(dist, -1, sizeof(dist));
  memset(back, -1, sizeof(back));
  dist[s] = 0;
  priority_queue<PII> Q;
  Q.push(mp(0, s));
  while(!Q.empty()) {
    int d, n;
    tie(d, n) = Q.top();
    Q.pop();
    if(dist[n] != -d) continue;
    for(auto &it: net[n]) {
      if(it.f == 0) continue;
      int dd = -d + it.c;
      if(dist[it.n] == -1 || dist[it.n] > dd) {
        back[it.n] = n;
        dist[it.n] = dd;
        Q.push(mp(-dd, it.n));
      }
    }
  }
  if(dist[e] == -1) return false;
  while(e != s) {
    cerr << e << " ";
    int ee = back[e];
    int c = dist[e] - dist[ee];
    add_edge(ee, e, c, -1);
    add_edge(e, ee, -c, 1);
    e = ee;
  }
  cerr << s << endl;
  return true;
}

void process() {
  for(int i=0;i<205;i++) net[i].clear();
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
    net[203].pb(edge { ss+1, 0, 1 });

    unordered_map<int, int> links {};

    memset(visit, -1, sizeof(visit));
    queue<PII> Q;
    visit[VS[ss].first][VS[ss].second] = 0;
    Q.push(mp(VS[ss].first, VS[ss].second));
    while(!Q.empty()) {
      int x, y;
      tie(x, y) = Q.front();
      Q.pop();
      if(D[x][y] == '#') continue;
      if(visit[x][y] != -1) continue;
      if(visit[x][y] > M) continue;
      int d = visit[x][y];
      for(int i=0;i<4;i++) {
        int xx = x, yy = y;
        while(bound(xx, yy)) {
          if(D[xx][yy] == '#') break;
          if(D[xx][yy] == 'T') {
            int tt = -ST[xx][yy];
            if (links[tt] == 0 || links[tt] > d) links[tt] = d;
          }
          xx += dx[i];
          yy += dy[i];
        }
        xx = x + dx[i], yy = y + dy[i];
        cerr << xx << " " << yy << endl;
        if(bound(xx, yy) && visit[xx][yy] == -1) {
          visit[xx][yy] = visit[x][y] + 1;
          Q.push(mp(xx, yy));
        }
      }
    }

    for(auto jt: links) {
      cerr << jt.first << "," << jt.second << " ";
      net[ss+1].pb(edge { jt.first + 100, jt.second, 1 });
    }
    cerr << endl;
  }

  for(int i=1;i<=VT.size();i++) {
    net[i + 100].pb(edge { 204, 0, 1 });
  }

  for(int i=1;i<=VS.size();i++) {
    if(net[i].size() == 0) continue;
    cerr << i << " = ";
    for(auto it: net[i]) {
      cerr << it.n << "," << it.c << "," << it.f << endl;
    }
    cerr << endl;
  }

  int tot = 0;
  while(mcmf(203, 204)) {
    tot++;
  }
  cout << tot << endl;
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
