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

int N;
vector<bool> used;
vector<int> occur;

void process() {
  scanf(" %d", &N);
  used.assign(N, false);
  occur.assign(N, 0);
  for(int i=0;i<N;i++) {
    int minn = -1;
    int D;
    scanf(" %d", &D);
    for(int j=0;j<D;j++) {
      int a;
      scanf(" %d", &a);
      occur[a]++;
      if(used[a]) continue;
      if(minn == -1 || occur[minn] > occur[a]) minn = a;
    }
    if(minn != -1) used[minn] = true;
    printf("%d\n", minn);
    fflush(stdout);
  }
}

int main(void) {
    int T;
    scanf(" %d", &T);
    for(int i=1;i<=T;i++) {
        process();
    }
    return 0;
}
