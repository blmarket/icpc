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

int N, M;
char data[25][25];

int c1(int sx, int sy, int ex, int ey, int flag) {
  int ret = 0;
  for(int i=sx;i<ex;i++) {
    for(int j=sy;j<ey;j++) {
      if((!!flag) ^ (data[i][j] == 'B'))
        ret++;
    }
  }
  return ret;
}

int cnt(int a, int b, int c) {
  return c1(0, 0, a, b, c & 1) + c1(a, 0, N, b, c & 2) + c1(0, b, a, M, c & 4) + c1(a, b, N, M, c & 8);
}

void process() {
  scanf(" %d %d", &N, &M);
  for(int i=0;i<N;i++) {
    scanf(" %s", data[i]);
  }

  int ret = 0;
  for(int i=0;i<N;i++) {
    for(int j=0;j<M;j++) {
      for(int k=0;k<(1<<4);k++) {
        int tmp = cnt(i, j, k);
        if (ret < tmp) {
          cerr << i << " " << j << " " << k << " " << tmp << endl;
        }
        ret = max(ret, tmp);
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
