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

const int mod = 1e9 + 7;

int S;
vector<int> data;
int maxp[3001][3001];
int lhs[3001][3001];
int rhs[3001][3001];

void process() {
  scanf(" %d", &S);
  data.resize(S);
  for(int i=0;i<S;i++) scanf(" %d", &data[i]);

  for(int i=0;i<S;i++) {
    maxp[i][i] = i;
    lhs[i][i] = 0;
    int cp = i;
    int cl = -1;
    for(int j=i;j<S;j++) {
      if(data[j] > data[cp]) cp = j;
      if(data[j] > cl) cl = data[j];
      maxp[i][j+1] = cp;
      lhs[i][j+1] = lhs[i][j] + (cl - data[j]);
      if(lhs[i][j+1] > mod) lhs[i][j+1] -= mod;
    }
  }

  for(int i=S-1;i>=0;i--) {
    int cl = -1;
    rhs[i+1][i+1] = 0;
    for(int j=i;j>=0;j--) {
      if(data[j] > cl) cl = data[j];
      rhs[j][i+1] = rhs[j+1][i+1] + (cl - data[j]);
      if(rhs[j][i+1] > mod) rhs[j][i+1] -= mod;
    }
  }

  LL ret = 0;
  for(int i=0;i+3<=S;i++) {
    for(int j=i+3;j<=S;j++) {
      int mp = maxp[i][j];
      int lc = lhs[i][mp];
      int rc = rhs[mp][j];
      // cerr << i << " " << j << " " << mp << " " << lc << " " << rc << endl;
      ret += lc + rc;
      if(ret > mod) ret -= mod;
    }
  }
  printf("%lld\n", (ret % mod));
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
