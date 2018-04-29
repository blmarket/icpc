#include <iostream>
#include <algorithm>
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
int v[100005][2];

bool chk(int s, int e) {
  if(e <= s+2) return true;
  bool f1 = true, f2 = false;
  int v1 = v[s][0], v2 = -1;

  auto fn = [&]() -> bool {
    for(int i=s+1;i<e;i++) {
      cerr << v1 << " " << v2 << endl;
      if(f1 && v[i][0] == v1) continue;
      if(f2 && v[i][1] == v2) continue;
      if(!f1) {
        f1 = true;
        v1 = v[i][0];
        continue;
      }
      if(!f2) {
        f2 = true;
        v2 = v[i][1];
        continue;
      }
      return false;
    }
    return true;
  };

  if(fn()) {
    return true;
  }

  f1 = false, f2 = true;
  v2 = v[s][1];

  return fn();
}

void process() {
  scanf(" %d", &N);
  for(int i=0;i<N;i++) {
    int a,b,c;
    scanf(" %d %d %d", &a, &b, &c);
    b = a + b;
    c = a - c;
    v[i][0] = b;
    v[i][1] = c;
  }
  for(int i=N;i>=1;i--) {
    int cnt = 0;
    for(int j=0;j+i<=N;j++) {
      if(chk(j, j+i)) {
        cerr << j << " " << j+i << endl;
        cnt++;
      }
    }
    if(cnt) {
      cout << i << " " << cnt << endl;
      break;
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
