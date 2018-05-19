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

struct range {
  int s,e,t;
};

int N;
int V[105];

vector<range> r;

void process() {
  scanf(" %d", &N);
  for(int i=0;i<N;i++) {
    scanf(" %d", &V[i]);
  }

  if(V[0] == 0 || V[N-1] == 0) {
    printf("IMPOSSIBLE\n");
    return;
  }

  int s = 0;
  for(int i=0;i<N;i++) {
    if(!V[i]) continue;
    // fprintf(stderr, "s=%d e=%d t=%d\n", s, s+V[i], i);
    r.pb(range {s, s+V[i], i});

    s += V[i];
  }

  vector<string> output;
  while(true) {
    bool found = false;
    string row = string(N, '.');
    for(auto &it : r) {
      if(it.s < it.t) {
        row[it.s] = '\\';
        it.s++;
        found = true;
      }
      if(it.e > it.t+1) {
        row[it.e-1] = '/';
        it.e--;
        found = true;
      }
    }
    output.pb(row);
    if(!found) break;
  }

  printf("%d\n", output.size());
  for(auto &it: output) printf("%s\n", it.c_str());
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
