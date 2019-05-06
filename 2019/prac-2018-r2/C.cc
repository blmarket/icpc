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
int board[105][105];
bool mask[105][105];
int used[105];
bool visit[105];

bool tryflow(int a) {
  if(visit[a]) return false;
  visit[a] = true;
  for(int i=0;i<N;i++) if(mask[a][i]) {
    if(used[i] == -1) {
      used[i] = a;
      return true;
    } else {
      if(tryflow(used[i])) {
        used[i] = a;
        return true;
      }
    }
  }
  return false;
}

int match(int a) {
  memset(mask, 0, sizeof(mask));
  int c1 = 0, c2 = 0;
  for(int i=0;i<N;i++) for(int j=0;j<N;j++) {
    if(board[i][j] == a) {
      c1++;
      mask[i][j] = true;
    }
  }
  memset(used, -1, sizeof(used));
  for(int i=0;i<N;i++) {
    memset(visit, 0, sizeof(visit));
    if(tryflow(i)) {
      c2++;
    }
  }
  return c1 - c2;
}

void process() {
  scanf(" %d", &N);
  for(int i=0;i<N;i++) {
    for(int j=0;j<N;j++) scanf(" %d", &board[i][j]);
  }
  int ret = 0;
  for(int i=-N;i<=N;i++) {
    ret += match(i);
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
