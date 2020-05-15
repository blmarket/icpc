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

struct rat {
  LL a;
  int b;

  bool operator<(const rat &rhs) const {
    return a * rhs.b < rhs.a * b;
  }
};

map<rat, vector<LL>> cand;
int N, D;

LL gcd(LL a, LL b) {
  if(a<b) return gcd(b,a);
  if(b == 0) return a;
  return gcd(b, a % b);
}

void process() {
  cand.clear();
  scanf(" %d %d", N, D);
  for(int i=0;i<N;i++) {
    LL tmp;
    scanf(" %lld", &tmp);
    cerr << tmp << endl;
    for(int j=1;j<=D;j++) {
      int gg = gcd(tmp, j);
      rat rr = rat { tmp / gg, j / gg };
      cand[rr].pb(j);
    }
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
