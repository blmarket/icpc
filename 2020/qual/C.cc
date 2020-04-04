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

int t, b;
vector<PII> bs[10][2];

void process() {
  int it = 0;
  for(int j=0;j<10;j++) {
    for(int i=0;i<5;i++) {
      printf("%d\n", it + 1);
      fflush(stdout);
      int r1, r2;
      scanf(" %d", &r1);
      printf("%d\n", b - it);
      fflush(stdout);
      scanf(" %d", &r2);
      bs[j][r1 ^ r2].pb(mp(it, r1));
      it = (it + 1) % b;
    }
  }
  for(int j=0;j<5;j++) {
    int cnt = 5;
    if(bs[0][0].size() > 0) {
      printf("%d\n", bs[0][0][0].first);
      fflush(stdout);
      int r1;
      scanf(" %d", &r1);
      if(r1 != bs[0][0][0].second) {
        for(auto &it : bs[0][0]) it.second = 1 - it.second;
      }
      cnt--;
    }
  }
}

int main(void) {
  scanf("%d %d", &t, &b);
  cerr << t << b << endl;
  for(int i=0;i<t;i++) {
    process();
  }
  return 0;
}
