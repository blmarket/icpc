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

bool process() {
  vector<string> data;
  int c1[105], c2[105];
  int n, m, h, v;
  scanf(" %d %d %d %d", &n, &m, &h, &v);
  for(int i=0;i<n;i++) {
    char tmp[1024];
    scanf(" %s", tmp);
    data.pb(tmp);
  }

  memset(c1, 0, sizeof(c1));
  memset(c2, 0, sizeof(c2));

  int cnt = 0;
  for(int i=0;i<n;i++) {
    for(int j=0;j<m;j++) {
      cnt += (data[i][j] == '@');
      c1[i] += (data[i][j] == '@');
      c2[j] += (data[i][j] == '@');
    }
  }

  if(cnt % ((h+1) * (v+1))) {
    return false;
  }
  int targetsize = cnt / (h+1) / (v+1);

  vector<int> s1, s2;
  int cc1 = 0;
  for(int i=0;i<n;i++) {
    cc1 += c1[i];
    if(cc1 > (cnt / (h+1))) {
      return false;
    }
    if(cc1 == (cnt / (h+1))) {
      s1.pb(i + 1);
      cc1 = 0;
    }
  }

  int cc2 = 0;
  for(int i=0;i<m;i++) {
    cc2 += c2[i];
    if(cc2 > (cnt / (v+1))) {
      return false;
    }
    if(cc2 == (cnt / (v+1))) {
      s2.pb(i+1);
      cc2 = 0;
    }
  }

  auto area = [&](int sx, int ex, int sy, int ey) -> int {
    int ret = 0;
    for(int i=sx;i<ex;i++) {
      for(int j=sy;j<ey;j++) {
        ret += data[i][j] == '@';
      }
    }
    return ret;
  };

  for(int i=0;i<h;i++) {
    for(int j=0;j<v;j++) {
      if (area(s1[i], s1[i+1], s2[j], s2[j+1]) != targetsize)
        return false;
    }
  }

  // for(int i=0;i<s1.size();i++) cout << s1[i] << " ";
  // cout << endl;
  // for(int i=0;i<s2.size();i++) cout << s2[i] << " ";
  // cout << endl;

  return true;
}

int main(void) {
  int T;
  scanf(" %d", &T);
  for(int i=1;i<=T;i++) {
    printf("Case #%d: ", i);
    if (process()) {
      printf("POSSIBLE\n");
    } else {
      printf("IMPOSSIBLE\n");
    }
  }
  return 0;
}
