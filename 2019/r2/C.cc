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
vector<PII> V;

PII upper, lower;

int gcd(int a, int b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}

void process() {
  scanf(" %d", &N);
  for(int i=0;i<N;i++) {
    int a, b;
    scanf(" %d %d", &a, &b);
    V.pb(a, b);
  }
  upper = lower = mp(-1, -1);
  for(int i=0;i<N;i++) {
    for(int j=i+1;j<N;j++) {
      int a = V[j].first - V[i].first;
      int b = V[j].second - V[i].second;
      auto comp = [&](const PII &a, const PII &b) {
        return a.first * b.second > a.second * b.first;
      };
      if(a > 0 && b < 0) {
        int g = gcd(a, -b);
        PII t = mp(a/g, -b/g);
        if(upper.first == -1 || comp(upper, t)) {
          upper = t;
        }
      }
      if(a < 0 && b > 0) {
        int g = gcd(-a, b);
        PII t = mp(-a/g, b/g);
        if(lower.first == -1 || comp(t, lower)) {
          lower = t;
        }
      }
    }
  }
  cerr << lower.first << " " << lower.second << endl;
  cerr << upper.first << " " << upper.second << endl;

  LL s = 0, e = 2e9;
  while(s+1 < e) {
    LL m = (s+e) / 2;
    LL js = 1, je = 2e9;
    if(lower.first != -1) {
      LL lam = lower.first * m;
      js = (lam / lower.second) + 1;
    }
    if(upper.first != -1) {
      LL lam = upper.first * m;
      if(lam % upper.second == 0) lam--;
      je = (lam / upper.second);
    }
    if(js <= je) {
      cerr << m << " " << js << endl;
      e = m;
    } else {
      s = m;
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
