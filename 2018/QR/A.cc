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

int D;
char P[32];

void process(void) {
  scanf(" %d %s", &D, P);
  int L = strlen(P);
  for(int i=0;i<1000;i++) {
    LL cur = 0;
    LL pow = 1;
    int lp = -1;
    for(int j=0;j<L;j++) {
      if(P[j] == 'S') {
        cur += pow;
      } else {
        pow *= 2;
        if(j+1 < L && P[j+1] == 'S') {
          lp = j;
        }
      }
    }
    if(cur <= D) {
      printf("%d\n", i);
      return;
    }
    if(lp == -1) {
      printf("IMPOSSIBLE\n");
      return;
    }
    swap(P[lp], P[lp+1]);
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
