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

void process(void) {
  cin >> a >> b;
  memset(dp, 0, sizeof(dp));
  int aa = a.size(), bb = b.size();
  for(int i=0;i<=aa;i++) dp[i][0] = i;
  for(int i=0;i<=bb;i++) dp[0][i] = i;
  cout << endl;
  for(int i=1;i<=aa;i++) {
    for(int j=1;j<=bb;j++) {
      dp[i][j] = dp[i-1][j-1] + (a[i-1] != b[j-1]);
      dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
      dp[i][j] = min(dp[i][j], dp[i][j-1] + 1);
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }
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
