#include <iostream>
#include <functional>
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

struct tmp {
  int i, a, b;

  bool operator<(const tmp &rhs) {
    return a < rhs.a;
  };
};

int n;
vector<tmp> v;

void process() {
  scanf(" %d", &n);
  for(int i=0;i<n;i++) {
    int a, b;
    scanf(" %d %d", &a, &b);
    v.pb(tmp { i, a, b });
  }
  sort(v.begin(), v.end());
  char ret[1005];
  int ce = -1, je = -1;
  for(int i=0;i<n;i++) {
    cerr << v[i].i << endl;
    if(v[i].a >= ce) {
      ce = v[i].b;
      ret[v[i].i] = 'C';
      continue;
    }
    if(v[i].a >= je) {
      je = v[i].b;
      ret[v[i].i] = 'J';
      continue;
    }
    cout << "IMPOSSIBLE" << endl;
    return;
  }
  ret[n] = 0;
  cout << ret << endl;
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
