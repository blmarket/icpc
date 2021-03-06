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

const int maxN = 4000;
int N;

unordered_map<unsigned int, int> memo;
int v[100005];
int s[100005];

int go(int L, int R, int k, bool turn) {
  if(R-L < k) return 0;
  if(R-L == k) return s[R] - s[L];

  unsigned int key = ((turn * 91 + k) * maxN + R) * maxN + L;
  if(memo.count(key)) return memo[key];

  int ans;
  if(turn) {
    ans = max(-go(L+k, R, k, !turn) + s[L+k] - s[L], -go(L+k+1, R, k+1, !turn) + s[L+k+1] - s[L]);
  } else {
    ans = max(-go(L, R-k, k, !turn) + s[R] - s[R-k], -go(L, R-k-1, k+1, !turn) + s[R] - s[R-k-1]);
  }
  // cerr << L << " " << R << " " << k << " " << turn << " = " << ans << endl;
  return memo[key] = ans;
}

int main(void) {
  memo.rehash(7e7);
  scanf(" %d", &N);
  s[0] = 0;
  for(int i=0;i<N;i++) {
    scanf(" %d", &v[i]);
    s[i+1] = s[i] + v[i];
  }
  cout << go(0, N, 1, true) << endl;
  return 0;
}
