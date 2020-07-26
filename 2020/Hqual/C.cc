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

struct log {
  LL a, b;
  bool operator<(const log &rhs) {
    return a < rhs.a;
  }
};

int N;
unordered_map<LL, LL> dp;
vector<log> V;

void setmax(LL &a, LL b) {
  if(a < b) a = b;
}

void process() {
  dp.clear();
  V.clear();
  scanf(" %d", &N);
  for(int i=0;i<N;i++) {
    LL a, b;
    cin >> a >> b;
    V.pb(log {a,b});
  }
  sort(V.begin(), V.end());

  for(auto it: V) {
    // cout << it.a << " " << it.b << endl;
    if(dp.count(it.a)) {
      setmax(dp[it.a+it.b], it.b + dp[it.a]);
    } else {
      setmax(dp[it.a+it.b], it.b);
    }
    if(dp.count(it.a - it.b)) {
      setmax(dp[it.a], it.b + dp[it.a-it.b]);
    } else {
      setmax(dp[it.a], it.b);
    }
  }

  LL ret = 0;
  for(auto it: dp) {
    // cout << it.first << " " << it.second << endl;
    ret = max(ret, it.second);
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
