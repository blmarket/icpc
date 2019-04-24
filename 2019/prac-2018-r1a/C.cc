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

  sort(data.begin(), data.end());
  // for(auto it: data) {
  //   cerr << it.first << "," << it.second << " ";
  // }
  // cerr << endl;

  vector<pair<double, double> > ranges, ranges2;

  for(auto it: data) {
    cerr << it.first << " " << it.second << endl;
    double r1 = it.first * 2;
    double r2 = 2 * hypot(it.first, it.second);

    ranges2 = ranges;
    
    if(r1 + base > P) {
      continue;
    }

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
      if(et < ranges2[i].first || i+1 >= ranges2.size()) {
        ranges.pb(st, et);
        st = ranges[i].first;
        et = ranges[i].second;
        if(st + base > P) break;
      } else {
        et = ranges2[i].second;
      }
    }

    for(auto jt: ranges) {
      cerr << jt.first << "," << jt.second << " ";
    }
    cerr << endl;
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