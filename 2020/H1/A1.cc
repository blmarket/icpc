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

int N, K, W;
LL L[1000005];
LL H[1000005];
const LL mod = 1000000007LL;

void read_data(LL L[]) {
  for(int i=1;i<=K;i++) {
    scanf(" %d", &L[i]);
  }
  long long a,b,c,d;
  scanf(" %lld %lld %lld %lld", &a, &b, &c, &d);
  for(int i=K+1;i<=N;i++) {
    L[i] = (a * L[i-2] + b * L[i-1] + c) % d;
  }
}

void process() {
  scanf(" %d %d %d", &N, &K, &W);
  read_data(L);
  read_data(H);
  // for(int i=1;i<=N;i++) {
  //   cout << L[i] << " " << H[i] << endl;
  // }
  cout << endl;
  LL ret = 1;
  LL p = 0;
  vector<pair<LL, LL> > stack;
  for(int i=1;i<=N;i++) {
    LL pmax = 0;
    while(stack.size()) {
      if (stack.back().first < L[i]) {
        stack.pop_back();
        continue;
      }
      pmax = max(pmax, stack.back().second);
      if(stack.back().second < H[i]) {
        stack.pop_back();
      } else break;
    }
    
    if(stack.size() == 0) {
      p += W * 2 + (H[i] - pmax) * 2;
    } else {
      p += (L[i] - L[i-1]) * 2;
    }
    stack.pb(mp(L[i] + W, H[i]));

    p %= mod;
    ret = (ret * p) % mod;
    cerr << p << " " << ret << " " << pmax << endl;
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
