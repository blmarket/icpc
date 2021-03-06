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
#define MT make_tuple

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;
typedef long long LL;

template<typename T> int size(const T &a) { return a.size(); } 

int T, N, M;

int cs[] = { 16,9,5,7,11,13,17 };

tuple<LL, LL> euclid(LL A, LL B) {
  if(A < B) swap(A, B);

  LL s = 0, old_s = 1;
  LL t = 1, old_t = 0;
  LL r = B, old_r = A;

  while(r) {
    LL q = old_r / r;
    tie(old_r, r) = make_tuple(r, old_r - q * r);
    tie(old_s, s) = make_tuple(s, old_s - q * s);
    tie(old_t, t) = make_tuple(t, old_t - q * t);
  }

  return make_tuple(old_s, old_t);
}

tuple<LL, LL> chinese(LL A, LL a, LL B, LL b) {
  LL m1, m2;
  tie(m1, m2) = euclid(A, B);
  LL M = A * B;
  cerr << M << " " << m1 << " " << m2 << endl;
  return make_tuple(M, (m1 * A * b + m2 * B * a) % M);
}

bool process() {
  long long denom = 1;
  long long res = 0;

  for(int i=0;i<7;i++) {
    for(int j=0;j<18;j++) printf("%d ", cs[i]);
    printf("\n");
    fflush(stdout);
    int sum = 0;
    for(int j=0;j<18;j++) {
      int tmp;
      scanf(" %d", &tmp);
      sum += tmp;
    }
    sum %= cs[i];

    if (i == 0) {
      tie(denom, res) = make_tuple(cs[i], sum);
    } else {
      tie(denom, res) = chinese(denom, res, cs[i], sum);
    }
    cerr << denom << " " << res << endl;
  }

  if(res < 0) res += denom;

  printf("%lld\n", res);
  fflush(stdout);
  int judge_response;
  scanf(" %d", &judge_response);
  if(judge_response == -1) return false;
  return true;
}

int main(void) {
  scanf(" %d %d %d", &T, &N, &M);
  for(int i=1;i<=T;i++) {
    if(!process()) return 0;
  }
  return 0;
}
