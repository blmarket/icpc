#include <iostream>
#include <cmath>
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

void process(void) {
  double A;
  scanf(" %lf", &A);
  if (A <= sqrt(2.0)) {
    double s = 0;
    double e = M_PI / 2;
    for(int i=0;i<200;i++) {
      double m = (s+e) / 2;
      double t = cos(m) + sin(m);
      if(t < A) {
        s = m;
      } else {
        e = m;
      }
    }
    printf("%.12lf %.12lf %.12lf\n", 0.5 * cos(s), 0.5 * sin(s), 0.0);
    printf("%.12lf %.12lf %.12lf\n", -0.5 * sin(s), 0.5 * cos(s), 0.0);
    printf("%.12lf %.12lf %.12lf\n", 0.0, 0.0, 0.5);
  } else {
    double s = 0;
    double e = atan(1.0 / sqrt(2.0));
    for(int i=0;i<20;i++) {
      double m = (s+e)/2;
      double t = (cos(m) + sin(m) * sqrt(2.0) / 2) * sqrt(2.0);
      if(t < A) {
        s = m;
      } else {
        e = m;
      }
    }
    printf("%.12lf %.12lf %.12lf\n", 0.5 * cos(s), 0.5 * sin(s), 0.0);
    printf("%.12lf %.12lf %.12lf\n", -0.5 * sin(s), 0.5 * cos(s), 0.0);
    printf("%.12lf %.12lf %.12lf\n", 0.0, 0.0, 0.5);
  }
}

int main(void) {
    int T;
    scanf(" %d", &T);
    for(int i=1;i<=T;i++) {
        printf("Case #%d:\n", i);
        process();
    }
    return 0;
}
