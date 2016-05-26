#include <iostream>
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

char line[20005];
map<string, int> M;

unordered_map<int, int> links[5000];
bool visit[5000];

bool try_flow(int s, int e) {
  cerr << s << " " << e << endl;
  if(s == e) {
    return true;
  }
  if(visit[s]) return false;
  visit[s] = true;
  each(it, links[s]) if(it.second) {
    if(try_flow(it.first, e)) {
      links[s][it.first]--;
      links[it.first][s]++;
      return true;
    }
  }
  return false;
}

void process() {
  int n;

  for(int i=0;i<n;i++) {
    fgets(line, 20005, stdin);
    istringstream sin(line);
    string tmp;
    while(sin >> tmp) {
      if(M.count(tmp) == 0) M[tmp] = 2 * M.size() + 200;
      links[i][M[tmp]] = 5000;
      links[M[tmp]+1][i] = 5000;
    }
  }

  each(it, M) links[it.second][it.second+1] = 1;

  int ret = 0;
  while(true) {
    memset(visit, 0, sizeof(visit));
    if(try_flow(0,1) == false) break;
    ret++;
  }
  cout << ret << endl;
}

int main(void) {
  int T;
  scanf(" %d", &T);
  for(int i=1;i<=T;i++) {
    printf("Case #%d: ",i);
    process();
  }
  return 0;
}
