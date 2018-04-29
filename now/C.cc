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

int M;
int form[105][2];
LL G[105];
bool visit[105];

bool go(int a, int depth, LL req) {
  cerr << a << endl;
  if(depth == 0) memset(visit, 0, sizeof(visit));
  if(visit[a]) return false;
  visit[a] = true;
  if(visit[form[a][0]] || visit[form[a][1]]) return false;
  LL &G1 = G[form[a][0]];
  LL &G2 = G[form[a][1]];
  if(G1 && G2) {
    LL ff = min(req, min(G1, G2));
    G[a] += ff;
    G1 -= ff;
    G2 -= ff;
    return true;
  }
  if(!G1) {
    go(form[a][0], 1, 1LL);
    return true;
  }
  if(!G2) {
    go(form[a][1], 1, 1LL);
    return true;
  }
  return false;
}

void process() {
  scanf(" %d", &M);
  for(int i=1;i<=M;i++) {
    scanf(" %d %d", &form[i][0], &form[i][1]);
  }
  for(int i=1;i<=M;i++) {
    scanf(" %lld", &G[i]);
  }
  while(go(1, 0, 1e9));
  printf("%lld\n", G[1]);
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
