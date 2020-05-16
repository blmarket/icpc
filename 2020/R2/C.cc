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

struct rat {
  LL xx, yy;
  bool operator<(const rat &rhs) const {
    return xx * rhs.yy < yy * rhs.xx;
  }
};

int gcd(int a, int b) {
  if(a < b) return gcd(b, a);
  if(b == 0) return a;
  return gcd(b, a%b);
}

map<rat, set<int> > rats;

void process() {
  rats.clear();
  int N;
  scanf(" %d", &N);
  vector<PII> V(N);
  for(int i=0;i<N;i++) {
    scanf(" %d %d", &V[i].first, &V[i].second);
    for(int j=0;j<i;j++) {
      int xx = V[i].first - V[j].first;
      int yy = V[i].second - V[j].second;
      int g = gcd(xx, yy);
      xx /= g; yy /= g;
      if(xx < 0) {
        xx *= -1;
        yy *= -1;
      }
      rat r = rat { xx, yy };
      rats[r].insert(i);
      rats[r].insert(j);
    }
  }

  for(auto &it: rats) {
    cout << it.first.xx << " " << it.first.yy << " : ";
    for(auto &jt: it.second) {
      cout << jt << " ";
    }
    cout << endl;
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
