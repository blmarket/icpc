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

struct point {
  LL v[3];

  point operator-(const point &rhs) {
    return point { v[0] - rhs.v[0], v[1] - rhs.v[1], v[2] - rhs.v[2] };
  }
};
int N;
vector<point> data;

point cross(const point &a, const point &b) {
  point r;
  for(int i=0;i<3;i++) {
    int n1 = (i+1)%3;
    int n2 = (i+2)%3;
    r.v[i] = a.v[n1] * b.v[n2] - a.v[n2] * b.v[n1];
  }
  return r;
}

LL dot(const point &a, const point &b) {
  LL ret = 0;
  for(int i=0;i<3;i++) ret += a.v[i] * b.v[i];
  return ret;
}

point norm(const point &a, const point &b) {
  if(dot(point {0, 0, 10},b) < 0) {
    return point {} - b;
  }
  return b;
}

LL high(point &a, point &b, point &c, point &d) {
  point v1 = b - a;
  point v2 = c - a;
  point v3 = d - a;
  return dot(norm(a, cross(v1, v2)), v3);
}

void process() {
  scanf(" %d", &N);
  for(int i=0;i<N;i++) {
    int a,b,c;
    scanf(" %d %d %d", &a, &b, &c);
    data.emplace_back(point {a, b, c});
  }
  cerr << high(data[3], data[2], data[0], data[4]) << endl;
  cerr << high(data[2], data[0], data[1], data[3]) << endl;
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
