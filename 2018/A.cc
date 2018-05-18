#include <iostream>
#include <algorithm>
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
set<string> words;
vector<set<char> > chrs;

char build[15];

bool enumerate(int a) {
  if (a == L) {
    build[L] = 0;
    if (words.count(build)) {
      return false;
    }
    printf("%s\n", build);
    return true;
  }
  cerr << a << " " << L << endl;
  auto &tmp = chrs[a];
  for(auto &it: tmp) {
    build[a] = it;
    if(enumerate(a+1)) return true;
  }
  return false;
}

void process() {
  scanf(" %d %d", &N, &L);
  chrs.clear(); chrs.resize(L);
  words.clear();

  for(int i=0;i<N;i++) {
    char buf[15];
    scanf(" %s", buf);
    for(int i=0;i<L;i++) {
      chrs[i].insert(buf[i]);
    }
    words.insert(buf);
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
