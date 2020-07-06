#include <iostream>
#include <functional>
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

string a, b;
int dp[65][65];
bool same[65][65];

void process(void) {
  cin >> a >> b;
  memset(dp, 0, sizeof(dp));
  memset(same, 0, sizeof(same));
  int aa = a.size(), bb = b.size();
  for(int i=0;i<=aa;i++) dp[i][0] = i;
  for(int i=0;i<=bb;i++) dp[0][i] = i;
  for(int i=1;i<=aa;i++) {
    for(int j=1;j<=bb;j++) {
      same[i][j] = a[i-1] == b[j-1];
      dp[i][j] = dp[i-1][j-1] + !same[i][j];
      dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
      dp[i][j] = min(dp[i][j], dp[i][j-1] + 1);
    }
  }
  cout << endl;
  for(int i=0;i<=aa;i++) {
    for(int j=0;j<=bb;j++) {
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }

  string ret;
  bool flag = false;
  while(aa || bb) {
    // cerr << aa << " " << bb << " " << dp[aa][bb] << " " << dp[aa-1][bb]+1 << endl;
    if(aa && bb && same[aa][bb] && dp[aa][bb] == dp[aa-1][bb-1]) {
      ret = a[aa-1] + ret;
    } else if(aa && bb && dp[aa][bb] == dp[aa-1][bb-1] + 1) {
      if(flag) ret = a[aa-1] + ret; else ret = b[bb-1] + ret;
      aa--; bb--; flag = !flag;
    } else if(bb && dp[aa][bb] == dp[aa][bb-1] + 1) {
      if(!flag) ret = b[bb-1] + ret;
      bb--; flag = !flag;
    } else if(aa && dp[aa][bb] == dp[aa-1][bb] + 1) {
      if(flag) ret = a[aa-1] + ret;
      aa--; flag = !flag;
    }
  }
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
