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

int R, C;
VS data;
map<VS, int> memo;

int go(const VS &a) {
  if(memo.count(a)) return memo[a];
  int ret = 0;
  for(int i=0;i<R;i++) {
    for(int j=0;j<C;j++) {
      if(a[i][j] != '.') continue;
      for(int k=0;k<2;k++) {
        VS b = a;
        bool fail = false;
        for(int l=-1;l<2;l+=2) {
          int ii = i, jj = j;
          cerr << l << " " << ii << " " << jj << endl;
          while(ii >= 0 && jj >= 0 && ii < R && jj < C) {
            if(b[ii][jj] == '#') { fail = true; break; }
            if(b[ii][jj] == '$') break;
            b[ii][jj] = '$';
            ii += l * k; jj += l * !k;
          }
          if(fail) break;
        }
        if(fail) continue;
        cerr << i << " " << j << " " << k << endl;
        for(int l=0;l<R;l++) cerr << b[l] << endl;
        cerr << endl;
        // if(go(b) == 0) ret++;
      }
    }
  }

  for(int i=0;i<R;i++) cerr << a[i] << endl;
  cerr << ret << endl;
  return memo[a] = ret;
}

void process() {
  scanf(" %d %d", &R, &C);
  data.clear(); memo.clear();
  for(int i=0;i<R;i++) {
    char tmp[25];
    scanf(" %s", tmp);
    data.pb(tmp);
  }
  printf("%d\n", go(data));
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
