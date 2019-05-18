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
typedef pair<int,int> PII;
typedef long long LL;

template<typename T> int size(const T &a) { return a.size(); } 

int C, R, M;
char D[105][105];
vector<PII> VS, VT;

void process() {
  VS.clear(); VT.clear();
  scanf(" %d %d %d", &C, &R, &M);
  for(int i=0;i<R;i++) {
    scanf(" %s", D[i]);
    for(int j=0;j<C;j++) {
      if(D[i][j] == 'S') {
        VS.pb(i, j);
      }
      if(D[i][j] == 'T') {
      }
    }
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
