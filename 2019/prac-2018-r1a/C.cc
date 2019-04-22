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
#include <cmath>

#define mp make_pair
#define each(it, v) for(auto &it: v)
#define sqr(x) ((x)*(x))
#define pb emplace_back

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;
typedef long long LL;

template<typename T> int size(const T &a) { return a.size(); } 

int N, P;
vector<PII> data;
vector<double> h2;
double mmax;

void go(int a, double rem, double buff) {
  int idx = a;

  if(idx == 0) {
    mmax = min(mmax, max(0.0, rem - buff));
    return;
  }
  for(idx = idx-1; idx >= 0; idx--) {
    go(idx, rem - h2[idx], buff + 2 * sqrt(sqr(data[idx].first) + sqr(data[idx].second)) - h2[idx]);
    return;
  }
}

void process() {
  scanf(" %d %d", &N, &P);
  int base = 0;
  data.clear();
  h2.clear();
  for(int i=0;i<N;i++) {
    int a, b;
    scanf(" %d %d", &a, &b);
    if(a > b) swap(a,b);
    data.pb(mp(a, b));
    base += a*2+b*2;
  }
  double buff = 0;
  for(int i=0;i<N;i++) {
    if (base + data[i].first * 2 <= P) {
      base += data[i].first * 2;
      buff += 2 * sqrt(sqr(data[i].first) + sqr(data[i].second)) - data[i].first * 2;
    } else {
      break;
    }
  }
  if (buff + base >= P) {
    printf("%.12lf\n", (double)P);
  } else {
    printf("%.12lf\n", buff + base);
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
