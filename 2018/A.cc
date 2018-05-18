#include <iostream>
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

int N, L;
vector<string> words;
vector<char> chrs[15];

char build[15];

bool enumerate(int a) {
  if (a == L) {
    build[L] = 0;
    if(*lower_bound(words.begin(), words.end(), build) == build) return false;
    printf("%s\n", build);
    return true;
  }
  auto &tmp = chrs[a];
  for(int i=0;i<tmp.size();i++) {
    build[a] = tmp[i];
    if(enumerate(a+1)) return true;
  }
  return false;
}

void process() {
  scanf(" %d %d", &N, &L);
  for(int i=0;i<L;i++) chrs[i].clear();

  for(int i=0;i<N;i++) {
    char buf[15];
    scanf(" %s", buf);
    for(int i=0;i<L;i++) {
      chrs[i].pb(buf[i]);
    }
    words.pb(buf);
  }
  sort(words.begin(), words.end());

  for(int i=0;i<L;i++) {
    auto &tmp = chrs[i];
    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
  }

  if (enumerate(0)) {
    return;
  }
  printf("-\n");
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
