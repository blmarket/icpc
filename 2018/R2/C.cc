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

struct node {
  int src;
  int sink;
  vector<node *> link;
};

int N;
int V[105][105];

vector<node> srcs;
node *back[105][105];

bool try_flow() {
  return false;
}

void process() {
  memset(back, 0, sizeof(back));
  srcs.clear();
  scanf(" %d", &N);
  for(int i=0;i<N;i++) {
    for(int j=0;j<N;j++) scanf(" %d", &V[i][j]);
  }

  int ret = 0;

  for(int i=0;i<N;i++) {
    unordered_map<int, vector<int>> m2;
    m2.clear();
    for(int j=0;j<N;j++) m2[V[j][i]].pb(j);

    for(auto &it : m2) {
      if(it.second.size() == 1) continue;
      ret += it.second.size() - 1;
      node *tmp = new node { 0, (int)it.second.size() - 1, vector<node *>() };
      // fprintf(stderr, "c=%d c=%d cnt=%d\n", i, it.first, it.second.size());
      for(auto jt: it.second) {
        back[jt][i] = tmp;
      }
    }
  }

  for(int i=0;i<N;i++) {
    unordered_map<int, vector<int>> m1;
    m1.clear();
    for(int j=0;j<N;j++) m1[V[i][j]].pb(j);

    for(auto &it : m1) {
      if(it.second.size() == 1) continue;
      ret += it.second.size() - 1;

      vector<node *> tmp;
      for(auto jt: it.second) {
        if(back[i][jt] != NULL) tmp.pb(back[i][jt]);
      }

      srcs.pb(node { (int)it.second.size() - 1, 0, tmp });
    }
  }

  while(try_flow()) ret--;

  cout << ret << endl;
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
