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

  point operator-(const point &rhs) const {
    return point { v[0] - rhs.v[0], v[1] - rhs.v[1], v[2] - rhs.v[2] };
  }
};

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

LL high(const point &a, const point &b, const point &c, const point &d) {
  point v1 = b - a;
  point v2 = c - a;
  point v3 = d - a;
  return dot(norm(a, cross(v1, v2)), v3);
}

int N;
vector<point> data;
vector<int> stack;
bool used[25];

bool go(int a) {
  if(a == N) {
    for(int i=0;i<N;i++) cout << stack[i]+1 << " ";
    cout << endl;
    return true;
  }
  for(int i=0;i<N;i++) if(!used[i]) {
    if(a >= 3) {
      const auto &p1 = data[stack[stack.size() - 3]];
      const auto &p2 = data[stack[stack.size() - 2]];
      const auto &p3 = data[stack[stack.size() - 1]];
      const auto &p4 = data[i];
      auto tmp = high(p4, p3, p2, p1);
      if(tmp > 0) continue;
    }
    used[i] = true;
    stack.pb(i);
    go(a+1);
    stack.pop_back();
    used[i] = false;
  }
  return false;
}

void process() {
  scanf(" %d", &N);
  for(int i=0;i<N;i++) {
    int a,b,c;
    scanf(" %d %d %d", &a, &b, &c);
    data.emplace_back(point {a, b, c});
  }
  go(0);
  cerr << high(data[1], data[2], data[3], data[0]) << endl;
  cerr << high(data[2], data[1], data[3], data[0]) << endl;
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
