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

LL high(const point &a, const point &b, const point &c, const point &d) {
  point v1 = b - a;
  point v2 = c - a;
  point v3 = d - a;

  return dot(cross(v1, v2), v3);
}

int N;
vector<point> data;

void process() {
  scanf(" %d", &N);
  for(int i=0;i<N;i++) {
    int a,b,c;
    scanf(" %d %d %d", &a, &b, &c);
    data.emplace_back(point {a, b, c});
  }

  vector<int> p;
  for(int i=0;i<N;i++) p.pb(i);
  do {
    bool fail=false;
    for(int i=3;i<N;i++) {
      point t1 { data[p[i]].v[0], data[p[i]].v[1], 0 };
      auto v = [&](const point &pp) {
        return high(data[p[i]], data[p[i-1]], data[p[i-2]], pp);
      };
      LL v1 = v(t1);
      for(int j=0;j<i-2;j++) {
        if( (v(data[p[j]]) < 0) != (v1 < 0)) {
          fail = true;
          break;
        }
      }
      if(fail) break;
    }
    if(!fail) {
      for(int i=0;i<N;i++) {
        cout << p[i]+1 << " ";
      }
      cout << endl;
      break;
    }
  } while(next_permutation(p.begin(), p.end()));


  // for(int i=0;i<N;i++) {
  //   for(int j=i+1;j<N;j++) {
  //     for(int k=j+1;k<N;k++) {
  //       for(int l=0;l<N;l++) if(l != i && l != j && l != k) {
  //         cerr << i << " " << j << " " << k << " " << l << " " << high(data[i], data[j], data[k], data[l]) << endl;
  //       }
  //     }
  //   }
  // }
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
