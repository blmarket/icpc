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

const LL BIG = 1LL << 60;

int n,m;
LL c[2100000];

LL findmin(int s, int e, int p=1,int ss=0, int ee=1<<20) {
  if(s > ee || e < ss) return BIG;
  if(s <= ss && e >= ee) return c[p];
  int m = (ss+ee) / 2;
  return min(
      findmin(s,e,p*2,ss,m),
      findmin(s,e,p*2+1,m,ee));
}

void process() {
  for(int i=0;i<=(1<<21);i++) c[i] = BIG;
  scanf(" %d %d", &n, &m);
  for(int i=0;i<n;i++) {
    scanf(" %d", &c[i]);
  }
  int SP = 1<<20;
  c[SP] = 0;
  c[SP+n-1] = 0;

  for(int i=n-1;i>=0;i--) {
    c[SP+i] += findmin(i+1, min(i+m, n-1));
    for(int j=(SP+i)>>1;j;j>>=1) {
      c[i] = min(c[i*2], c[i*2+1]);
    }
  }
  cout << ((c[SP]==(1LL<<60))?-1LL:c[SP]) << endl;
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
