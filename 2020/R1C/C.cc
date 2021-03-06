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

vector<LL> V;
set<rat> cand;
int N, D;

LL gcd(LL a, LL b) {
  if(a<b) return gcd(b,a);
  if(b == 0) return a;
  return gcd(b, a % b);
}

bool ok(LL v1, const rat &d) {
  return (v1 * d.b) % d.a == 0;
}

void process() {
  cand.clear();
  V.clear();
  scanf(" %d %d", &N, &D);
  for(int i=0;i<N;i++) {
    LL tmp;
    scanf(" %lld", &tmp);
    V.pb(tmp);
    for(int j=1;j<=D;j++) {
      int gg = gcd(tmp, j);
      // cerr << tmp << " " << j << " " << gg << endl;
      rat rr = rat { tmp / gg, j / gg };
      cand.insert(rr);
    }
  }
  sort(V.begin(), V.end());

  int ret = D - 1;

  for(auto &it: cand) {
    int sum = 0;
    int cut = 0;
    // cerr << it.a << "/" << it.b << " = " << endl;
    for(int i=0;i<V.size();i++) if(ok(V[i], it)) {
      if(sum == D) break;
      int cnt = V[i] * it.b / it.a;
      // cerr << V[i] << ":" << cnt << endl;
      if(cnt == 0) continue;
      if (sum + cnt <= D) {
        sum += cnt;
        cut += cnt - 1;
      } else {
        cut += D - sum;
        sum = D;
      }
    }
    // cerr << sum << " " << cut << endl;
    for(int i=0;i<V.size();i++) if(!ok(V[i], it)) {
      if(sum == D) break;
      int cnt = V[i] * it.b / it.a;
      if(cnt == 0) continue;
      if (sum + cnt <= D) {
        sum += cnt;
        cut += cnt;
      } else {
        cut += D - sum;
        sum = D;
      }
    }
    // cerr << sum << " " << cut << endl;
    if(sum == D) {
      ret = min(ret, cut);
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
