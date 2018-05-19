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

int N;
int V[105][105];

void process() {
  scanf(" %d", &N);
  for(int i=0;i<N;i++) {
    for(int j=0;j<N;j++) scanf(" %d", &V[i][j]);
  }

  for(int i=0;i<N;i++) {
    unordered_map<int, int> m1, m2;
    m1.clear(); m2.clear();
    for(int j=0;j<N;j++) m1[V[i][j]]++;
    for(int j=0;j<N;j++) m2[V[j][i]]++;

    for(auto &it : m1) {
      if(it.second == 1) continue;
      fprintf(stderr, "r=%d c=%d cnt=%d\n", i, it.first, it.second);
    }

    for(auto &it : m2) {
      if(it.second == 1) continue;
      fprintf(stderr, "c=%d c=%d cnt=%d\n", i, it.first, it.second);
    }
  }
}

int main(void) {
    int T;
    scanf(" %d", &T);
    for(int i=1;i<=T;i++) {
        printf("Case #%d: ", i);
        fflush(stdout);
        process();
        fflush(stdout);
    }
    return 0;
}
