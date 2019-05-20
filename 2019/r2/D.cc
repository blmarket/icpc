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

const LL MOD = 1e9 + 7;

int M;
int D[105][2];
LL S[105];
int R[105][105];

void process() {
  scanf(" %d", &M);
  memset(R, 0, sizeof(R));
  for(int i=1;i<=M;i++) {
    scanf(" %d %d", &D[i][0], &D[i][1]);
    R[i][D[i][0]] = 1;
    R[i][D[i][1]] = 1;
  }
  R[1][D[1][0]] = 0;
  R[1][D[1][1]] = 0;
  for(int i=1;i<=M;i++) scanf(" %lld", &S[i]);

  while(true) {
    bool change = false;
    for(int i=2;i<=M;i++) for(int j=0;j<2;j++) {
      int r = D[i][j];
      for(int k=1;k<=M;k++) if(R[r][k]) {
        if(!R[i][k]) {
          change = true;
          R[i][k] = 1;
        }
      }
    }
    if(!change) break;
  }

  for(int i=1;i<=M;i++) {
    for(int j=1;j<=M;j++) cerr << R[i][j] << " ";
    cerr << endl;
  }

  for(int i=1;i<=M;i++) {
    if(R[i][i] && R[i][1] && S[i]) {
      printf("UNBOUNDED\n");
      return;
    }
  }

  while(true) {
    bool change = false;
    for(int i=2;i<=M;i++) if(R[i][1] && S[i]) {
      for(int j=0;j<2;j++) {
        int r = D[i][j];
        S[r] = (S[r] + S[i]) % MOD;
      }
      S[i] = 0;
      change = true;
    }
    if(!change) break;
  }
  LL r1 = S[1];
  S[D[1][0]] = 1;
  S[D[1][1]] = 1;
  S[1]--;
  while(true) {
    bool change = false;
    for(int i=2;i<=M;i++) if(R[i][1] && S[i]) {
      for(int j=0;j<2;j++) {
        int r = D[i][j];
        S[r] = (S[r] + S[i]) % MOD;
      }
      S[i] = 0;
      change = true;
    }
    if(!change) break;
  }
  LL r2 = S[1];
  if(r2 > r1) {
    printf("UNBOUNDED\n");
  }
  printf("%lld\n", r1);
  // printf("%lld\n", S[1]);
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
