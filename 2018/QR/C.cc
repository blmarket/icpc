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

int A;

void process(void) {
  scanf(" %d", &A);
  int x = 3, y = 3;

  int state[3];
  memset(state, 0, sizeof(state));

  while(true) {
    printf("%d %d\n", x + 1, y + 1);
    fflush(stdout);
    int rx, ry;
    scanf(" %d %d", &rx, &ry);
    if(rx == -1 && ry == -1) {
      break;
    }
    if(rx == 0 && ry == 0) {
      break;
    }
    rx -= x; ry -= y;
    state[rx] |= (1<<ry);
    if(state[0] & state[1] & state[2] & 1) {
      y++;
      state[0] >>= 1; state[1] >>= 1; state[2] >>= 1;
    }
  }
}

int main(void) {
    int T;
    scanf(" %d", &T);
    for(int i=1;i<=T;i++) {
        process();
    }
    return 0;
}
