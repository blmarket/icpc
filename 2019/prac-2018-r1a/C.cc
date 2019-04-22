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
  int idx = lower_bound(h2.begin(), h2.begin() + a, rem) - h2.begin();
  if(idx == 0) {
    mmax = min(mmax, max(0.0, rem - buff));
    return;
  }
  for(idx = idx-1; idx >= 0; idx--) {
    go(idx, rem - h2[idx], buff + sqrt(sqr(data[idx].first) + sqr(data[idx].second)) - h2[idx]);
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
  mmax = P - base;
  sort(data.begin(), data.end());
  for(int i=0;i<N;i++) {
    h2.pb(data[i].first * 2);
  }
  // cerr << rem << endl;
  // for(int i=0;i<N;i++) cerr << data[i].first << "," << data[i].second << " ";
  // cerr << endl;
  go(N, P-base, 0.0);
  printf("%.12lf\n", P - mmax);
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
