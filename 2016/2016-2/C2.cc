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
#define each(it, v) for(auto &it: v)
#define pb emplace_back

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;
typedef long long LL;

template<typename T> int size(const T &a) { return a.size(); } 

const int dx[] = {-1,0,0,1};
const int dy[] = {0,-1,1,0};

int r,c;
int n;
bool flow[105][105][4];
PII track[105][105];
vector<PII> gates;
vector<PII> pairs;

bool good(int x, int y) {
  return x>=0 && y>=0 && x<r && y<c;
}

int trace(int a, int b, bool move) {
  PII pos = gates[a];
  memset(track, 0, sizeof(track));
  int sx,sy;
  for(int i=0;i<4;i++) {
    sx = pos.first + dx[i];
    sy = pos.second + dy[i];
    if(good(sx,sy)) break;
  }

  queue<PII> Q;
  Q.push(mp(sx,sy));
  while(!Q.empty()) {
    tie(sx,sy) = Q.front();
    Q.pop();
  }
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
        flow[i][j][0] = flow[i][j][3] = true;
      } else {
        flow[i][j][1] = flow[i][j][2] = true;
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

  for(int i=0;i<size(pairs);i++) {
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
