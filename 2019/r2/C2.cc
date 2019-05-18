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

pair<LL, LL> upper, lower;

int gcd(int a, int b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}

void process() {
  scanf(" %d", &N);
  V.clear();
  for(int i=0;i<N;i++) {
    int a, b;
    scanf(" %d %d", &a, &b);
    V.pb(a, b);
  }

  for(int i=1;i<=10000;i++) {
    for(int j=1;j<=10000;j++) {
      LL w = V[0].first * i + V[0].second * j;
      bool fail = false;
      for(int k=1;k<N;k++) {
        LL w2 = V[k].first * i + V[k].second * j;
        if(w >= w2) { fail=true; break; }
        w = w2;
      }
      if(!fail) {
        cout << i << " " << j << endl;
        return;
      }
    }
  }
  cout << "IMPOSSIBLE" << endl;
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
