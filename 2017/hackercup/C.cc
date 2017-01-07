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

int hp, n;

void process() {
  scanf(" %d %d", &hp, &n);
  char buf[1024];
  char ind;
  int nd, y;
  int offset;

  double maxx = 0;

  double ps[2][500];

  for(int i=0;i<n;i++) {
    offset = 0;
    scanf(" %dd%d%c", &nd, &y, &ind);
    if(ind == '+' || ind == '-') {
      scanf("%d", &offset);
      if(ind == '-') offset = -offset;
    }

    cout << nd << " " << y << " " << offset << endl;

    memset(ps[0], 0, sizeof(ps[0]));
    ps[0][0] = 1;

    for(int j=0;j<nd;j++) {
      int cur = j&1;
      int nex = !cur;

      memset(ps[nex], 0, sizeof(ps[nex]));

      for(int k=0;k<=400;k++) {
        for(int l=0;l<y;l++) {
          ps[nex][k+l+1] += ps[cur][k] / y;
        }
      }
    }

    offset = hp - offset;
    if(offset <= 0) {
      maxx = 1;
      continue;
    }

    if(offset > 500) {
      continue;
    }

    double tmp = 0;
    for(int j=offset;j<500;j++) {
      tmp += ps[nd&1][j];
    }
    if(tmp > maxx) maxx = tmp;
  }
  printf("%.12lf\n", maxx);
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
