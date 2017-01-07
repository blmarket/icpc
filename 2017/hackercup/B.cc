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

int n;
int v[105];

void process() {
  scanf(" %d", &n);
  for(int i=0;i<n;i++) {
    scanf(" %d", &v[i]);
  }
  sort(v, v+n);
  reverse(v, v+n);

  int ret = 0;

  for(int i=0;i<n;i++) {
    int rem = n - i;
    int cnt = (50 + v[i] - 1) / v[i];
    if(rem < cnt) {
      printf("%d\n", ret);
      return;
    }
    ret++;
    n -= (cnt - 1);
  }
  printf("%d\n", ret);
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
