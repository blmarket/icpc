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

int C, D;
VI cs;

void process() {
  scanf(" %d %d", &C, &D);
  cs.resize(C+1);
  vector<PII> v1, v2;
  for(int i=2;i<=C;i++) {
    scanf(" %d", &cs[i]);
    if(cs[i] > 0) {
      v1.pb(mp(cs[i], i));
    } else {
      v2.pb(mp(-cs[i], i));
    }
  }
  sort(v1.begin(), v1.end());
  sort(v2.begin(), v2.end());
  int it = 0;
  vector<int> order;
  order.pb(1);

  for(int i=0;i<=v1.size();i++) {
    while(it < v2.size() && v2[it].first >= order.size()) {
      order.pb(v2[it].second);
      ++it;
    }
    if(i < v1.size()) {
      order.pb(v1[i].second);
    }
  }

  for(auto it: order) cerr << it << " ";
  cerr << endl;
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
