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

int N;
int V[5][5];
bool x[5][5];

int ret = 25;

bool good() {
  for(int i=0;i<N;i++) {
    map<int, int> m;
    m.clear();
    for(int j=0;j<N;j++) {
      if(x[i][j]) continue;
      m[V[i][j]]++;
    }
    for(auto it:m) if(it.second > 1) return false;
    m.clear();
    for(int j=0;j<N;j++) {
      if(x[j][i]) continue;
      m[V[j][i]]++;
    }
    for(auto it:m) if(it.second > 1) return false;
  }
  return true;
}

void go(int a, int b, int c) {
  if(a == N) {
    if(good()) {
      if(ret > c) ret = c;
    }
    return;
  }
  if(b == N) {
    go(a+1, 0, c);
    return;
  }
  x[a][b] = false;
  go(a, b+1, c);
  x[a][b] = true;
  go(a, b+1, c+1);
}

void process() {
  scanf(" %d", &N);
  for(int i=0;i<N;i++) {
    for(int j=0;j<N;j++) scanf(" %d", &V[i][j]);
  }
  go(0, 0, 0);
  printf("%d\n", ret);
}

int main(void) {
    int T;
    scanf(" %d", &T);
    for(int i=1;i<=T;i++) {
        printf("Case #%d: ", i);
        fflush(stdout);
        process();
        fflush(stdout);
    }
    return 0;
}
