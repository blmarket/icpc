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

void process() {
  scanf(" %d %d", &N, &P);
  int base = 0;
  data.clear();
  for(int i=0;i<N;i++) {
    int a, b;
    scanf(" %d %d", &a, &b);
    if(a > b) swap(a,b);
    data.pb(mp(a, b));
    base += a*2+b*2;
  }

  vector<pair<double, double> > ranges, ranges2;

  for(auto it: data) {
    double r1 = it.first * 2;
    double r2 = 2 * hypot(it.first, it.second);

    ranges2 = ranges;
    
    ranges2.pb(mp(r1, r2));
    for(auto rr: ranges) {
      double nr1 = rr.first + r1;
      double nr2 = rr.second + r2;
      ranges2.pb(mp(nr1, nr2));
    }
    sort(ranges2.begin(), ranges2.end());

    ranges.clear();
    //merge ranges
    double st = ranges2[0].first, et = ranges2[0].second;
    for(int i=1;i<ranges2.size();i++) {
      if(et < ranges2[i].first) {
        ranges.pb(st, et);
        st = ranges2[i].first;
        et = ranges2[i].second;
      } else {
        et = ranges2[i].second;
      }
    }
    ranges.pb(st, et);

    // for(auto jt: ranges) {
    //   cerr << jt.first << "," << jt.second << " ";
    // }
    // cerr << endl;
  }

  // cerr << base << endl;

  while(ranges.size()) {
    if (base + ranges.back().first <= P) {
      printf("%.15lf\n", min((double)P, ranges.back().second + base));
      return;
    }
    ranges.pop_back();
  }
  printf("%.15lf\n", (double)base);
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
