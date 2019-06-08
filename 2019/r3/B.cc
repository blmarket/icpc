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

LL go(int s, int e) {
  int mx = -1;
  int mi = s;
  for(int i=s;i<e;i++) {
    if(data[i] > mx) {
      mx = data[i];
      mi = i;
    }
  }

  LL ret = 0;

  int cl = -1;
  for(int i=s;i<mi;i++) {
    if(data[i] > cl) { cl = data[i]; }
    ret += (cl - data[i]);
    if(ret > mod) ret -= mod;
  }
  cl = -1;
  for(int i=e-1;i>=mi;i--) {
    if(data[i] > cl) { cl = data[i]; }
    ret += (cl - data[i]);
    if(ret > mod) ret -= mod;
  }
  return ret;
}

void process() {
  scanf(" %d", &S);
  data.resize(S);
  for(int i=0;i<S;i++) scanf(" %d", &data[i]);

  LL ret = 0;
  for(int i=0;i+3<=S;i++) {
    for(int j=i+3;j<=S;j++) {
      ret += go(i, j);
      if(ret > mod) ret -= mod;
    }
  }
  printf("%lld\n", ret);
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
