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
typedef long long LL;
typedef pair<int, int> PII;

template<typename T> int size(const T &a) { return a.size(); } 

vector<PII> V;

void process() {
  int d;
  int cur = 1;
  int mark = -1;
  int mark2 = -1;
  V.clear();
  for(int i=1;i<=100;i++) {
    scanf(" %d", &d);
    if(d == -1) {
      cerr << "wrong" << endl;
      exit(0);
    }
    if(d == 100) {
      // cerr << cur << endl;
      printf("20 100\n");
      fflush(stdout);
      break;
    }

    if(d > 60 && cur <= 20) {
      printf("%d 0\n", cur);
      fflush(stdout);
      int n;
      scanf(" %d", &n);
      for(int j=0;j<n;j++) {
        int tmp;
        scanf(" %d", &tmp);
      }
      V.pb(mp(n, cur));
      cur++;
      continue;
    }

    if(d > 60) {
      sort(V.begin(), V.end());
      printf("%d 100\n", V[1].second);
      fflush(stdout);
      V[1].first++;
      continue;
    }

    int v = (d % 20) + 1;
    printf("%d %d\n", v, 100 - ((d-1) / 20));
    fflush(stdout);
  }
}

int main(void) {
    int T;
    scanf(" %d", &T);
    for(int i=1;i<=T;i++) {
        process();
    }
    return 0;
}
