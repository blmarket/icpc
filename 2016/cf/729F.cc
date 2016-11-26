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

struct state {
  int L, R;
  int k;
  bool turn;

  LL key() {
    return L + (LL) N * R + (LL) N * N * k + (LL) N*N*N*turn;
  }
};

unordered_map<LL, int> memo;
int v[100005];
int s[100005];

int go(int L, int R, int k, bool turn) {
  state ss = { L, R, k, turn };
  LL key = ss.key();
  if(memo.count(key)) return memo[key];

  if(turn) {
    if(L + k >= R) return memo[key] = 0;
    int tmp = go(L+k, R, k, !turn) + s[L+k] - s[L];
    if(L+k+1 < R) {
      int tmp2 = go(L+k+1, R, k+1, !turn) + s[L+k+1] - s[L];
      if(tmp2 > tmp) {
        return memo[key] = tmp2;
      }
    }
    return memo[key] = tmp;
  }

  if(R-k < L) return memo[key] = 0;
  int tmp = go(L, R-k, k, !turn) + s[R] - s[R-k];
  if(R-k-1 >= L) {
    int tmp2 = go(L, R-k-1, k+1, !turn) + s[R] - s[R-k-1];
    if(tmp2 < tmp) {
      return memo[key] = tmp2;
    }
  }
  return memo[key] = tmp;
}

int main(void) {
  scanf(" %d", &N);
  s[0] = 0;
  for(int i=0;i<N;i++) {
    scanf(" %d", &v[i]);
    s[i+1] = s[i] + v[i];
  }
  int tmp = go(0, N, 1, true);
  memo.clear();
  for(int i=0;i<N;i++) v[i] = -v[i];
  int tmp2 = go(0, N, 1, true);
  if(tmp > tmp2) cout << tmp << endl;
  cout << -tmp2 << endl;
  return 0;
}
