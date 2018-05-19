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

struct conflict {
  int idx;
  vector<int> occ;
  int rem;
};

int N;
int V[105][105];
vector<conflict> row[105], col[105];
conflict *back[105][105];

void process() {
  memset(back, 0, sizeof(back));
  for(int i=0;i<105;i++) { row[i].clear(); col[i].clear(); }
  scanf(" %d", &N);
  for(int i=0;i<N;i++) {
    for(int j=0;j<N;j++) scanf(" %d", &V[i][j]);
  }

  for(int i=0;i<N;i++) {
    unordered_map<int, vector<int>> m1, m2;
    m1.clear(); m2.clear();
    for(int j=0;j<N;j++) m1[V[i][j]].pb(j);
    for(int j=0;j<N;j++) m2[V[j][i]].pb(j);

    for(auto &it : m1) {
      if(it.second.size() == 1) continue;
      fprintf(stderr, "r=%d c=%d cnt=%d\n", i, it.first, it.second.size());
      row[i].pb(conflict { i, it.second, (int)it.second.size() - 1 });
    }

    for(auto &it : m2) {
      if(it.second.size() == 1) continue;
      fprintf(stderr, "c=%d c=%d cnt=%d\n", i, it.first, it.second.size());
      col[i].pb(conflict { i, it.second, (int)it.second.size() - 1 });
      for(auto jt: it.second) {
        back[jt][i] = &col[i].back();
      }
    }
  }

  for(int i=0;i<N;i++) {
    for(int j=0;j<N;j++) {
      cout << back[i][j] << " ";
    }
    cout << endl;
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
