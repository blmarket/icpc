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
      int g = gcd(abs(xx), abs(yy));
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
  
  int ret = 1;
  for(auto &it: rats) {
    auto &v = it.second;
    vector<PII> groups;

    for(auto &jt: v) {
      bool found = false;
      for(auto &kt: groups) {
        int xx = V[jt].first - V[kt.first].first;
        int yy = V[jt].second - V[kt.first].second;
        int g = gcd(abs(xx), abs(yy));
        xx /= g; yy /= g;
        if(xx < 0) {
          xx *= -1;
          yy *= -1;
        }
        if(xx == it.first.xx && yy == it.first.yy) {
          found = true;
          kt.second += 1;
          break;
        }
      }
      if(!found) groups.pb(mp(jt, 1));
    }

    int sum = 0;

    for(auto &jt: groups) {
      // cerr << jt.second << " ";
      sum += jt.second;
    }
    // cerr << endl;
    while(sum < N) {
      groups.pb(mp(-1, 1));
      sum++;
    }
    sort(groups.rbegin(), groups.rend());
    VI tmp; for(auto &it: groups) tmp.pb(it.second);
    int r1 = 0;
    int r2 = 0;
    for(int i=0;i<tmp.size();i++) {
      if(tmp[i] & 1) {
        r1 += tmp[i] - 1;
        r2++;
      } else {
        r1 += tmp[i];
      }
    }
    cerr << r1 << " " << r2 << endl;
    if(r2 > 2) r2 = 2;
    r1 += r2;
    ret = max(ret, r1);
  }
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
