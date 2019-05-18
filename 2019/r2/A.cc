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

int N;
vector<PII> V;
set<PII> V2;

void process() {
  scanf(" %d", &N);
  V.clear(); V2.clear();
  for(int i=0;i<N;i++) {
    int a, b;
    scanf(" %d %d", &a, &b);
    V.pb(a, b);
  }
  for(int i=0;i<N;i++) {
    for(int j=0;j<N;j++) if(i != j) {
      int a = V[i].first - V[j].first;
      int b = V[i].second - V[j].second;
      if(a > 0 && b < 0) {
        V2.insert(mp(a, -b));
      }
      if(a < 0 && b > 0) {
        V2.insert(mp(-a, b));
      }
    }
  }

  for(auto it: V2) {
    cerr << it.first << " " << it.second << endl;
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
