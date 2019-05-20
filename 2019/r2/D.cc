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

int M;
int D[105][2];
int S[105];
int R[105][105];

void process() {
  scanf(" %d", &M);
  memset(R, 0, sizeof(R));
  for(int i=1;i<=M;i++) {
    scanf(" %d %d", D[i][0], D[i][1]);
    R[i][D[i][0]] = 1;
    R[i][D[i][1]] = 1;
  }
  for(int i=1;i<=M;i++) scanf(" %d", &S[i]);

  while(true) {
    bool change = false;
    for(int i=1;i<=M;i++) for(int j=0;j<2;j++) {
      int r = D[i][j];
      for(int k=1;k<=M;k++) if(D[r][k]) {
        if(!D[i][k]) {
          change = true;
          D[i][k] = 1;
        }
      }
    }
  }

  for(int i=1;i<=M;i++) {
    if(D[i][i] && D[i][1] && S[i]) {
      printf("UNBOUNDED\n");
      return;
    }
  }

  printf("0\n");
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
