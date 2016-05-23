#include <iostream>
#include <sys/wait.h>
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
#define pb push_back
#define sqr(x) ((x)*(x))
#define foreach(it,c) for(typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;

template<typename T> int size(const T &a) { return a.size(); } 

map<string, int> m1;
map<string, int> m2;
int n;

vector<int> links[1024];
int back[1024];
bool visit[1024];

bool tryflow(int a) {
  if(visit[a]) return false;
  visit[a] = true;
  vector<int> &v = links[a];
  for(auto it: v) {
    if(back[it] == -1) {
      back[it] = a;
      return true;
    }
    if (tryflow(back[it])) {
      back[it] = a;
      return true;
    }
  }
  return false;
}

void process(void) {
  for(int i=0;i<1024;i++) links[i].clear();
  memset(back, -1, sizeof(back));
  scanf(" %d", &n);
  m1.clear();
  m2.clear();
  char s1[32], s2[32];
  for(int i=0;i<n;i++) {
    scanf(" %s %s", s1, s2);
    if(m1.count(s1) == 0) {
      m1[s1] = m1.size();
    }
    if(m2.count(s2) == 0) {
      m2[s2] = m2.size();
    }

    int p1 = m1[s1];
    int p2 = m2[s2];

    links[p1].pb(p2);
  }

  int matched = 0;
  int sz = m1.size();
  for(int i=1;i<=sz;i++) {
    memset(visit, 0, sizeof(visit));
    if (tryflow(i)) {
      matched += 1;
    }
  }

  cout << n - (m1.size() + m2.size() - matched) << endl;
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
