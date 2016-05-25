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

int r,c;
int total = 0;
LL mod = 1e9 + 7;

LL go(int rot) {
  LL dp[205][2] = {0};
  dp[100][0] = 1;
  dp[100][1] = 1;

  for(int i=101;i<=100+r;i++) {
    dp[i][0] = dp[i-2][1];
    dp[i][1] = dp[i-1][0];

    if((c%6) && (rot%6)) {
      dp[i][1] += dp[i-2][0] * 6;
    }
    if((c%3) && (rot%3)) {
      dp[i][1] += dp[i-2][0] * 3;
    }
    if((c%4) && (rot%4)) {
      dp[i][1] += dp[i-3][0] * 4;
    }

    dp[i][0] %= mod;
    dp[i][1] %= mod;
  }

  return dp[100+r][0] + dp[100+r][1];
}

void process() {
  scanf(" %d %d", &r, &c);

  // 3-cycle
  // 221
  // 221

  // 4-cycle
  // 2122
  // 2121
  // 2221

  // 6-cycle
  // 211222
  // 222211

  // 1-cycle
  // 222...
  //
  // 333...
  // 333...

  LL ret = 0;
  for(int i=0;i<c;i++) {
    ret = (ret + go(i)) % mod;
  }
  while(ret % c) ret += mod;
  ret /= c;
  cout << ret << endl;
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
