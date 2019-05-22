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
  int N = 50;
  for(int i=1;i<=100;i++) {
    scanf(" %d", &d);
    if(d == -1) {
      cerr << "wrong" << endl;
      exit(0);
    }

    if(d > N && cur <= 20) {
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

    if(d > N) {
      sort(V.begin(), V.end());
      printf("%d %d\n", V[1].second, d == 100 ? 100 : (rand()%100)+1);
      fflush(stdout);
      V[1].first++;
      continue;
    }

    if(d <= 20) {
      printf("%d %d\n", d, 100);
      fflush(stdout);
      continue;
    }

    int v = (rand() % 20) + 1;
    printf("%d %d\n", v, (rand() % 99) + 1);
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
