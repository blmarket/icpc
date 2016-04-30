#include <iostream>
#include <iomanip>
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

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int,int> PII;

template<typename T> int size(const T &a) { return a.size(); } 

char as[32], bs[32];
int len;

bool comp(pair<LL, LL> t1, pair<LL, LL> t2) {
  if(abs(t1.first - t1.second) < abs(t2.first - t2.second)) return true;
  if(abs(t1.first - t1.second) > abs(t2.first - t2.second)) return false;
  if(t1.first < t2.first) return true;
  if(t1.first > t2.first) return false;
  return t1.second < t2.second;
}

pair<LL, LL> go(int a, LL t1, LL t2) {
  if(a == len) {
    return mp(t1, t2);
  }

  t1 *= 10;
  t2 *= 10;

  bool l1 = t1 < t2;
  bool l2 = t2 < t1;

  if(as[a] != '?') {
    t1 += as[a] - '0';
  }
  if(bs[a] != '?') {
    t2 += bs[a] - '0';
  }

  if(as[a] != '?' && bs[a] != '?') {
    return go(a+1, t1, t2);
  }

  if(l1) {
    if(as[a] == '?') {
      t1 += 9;
    }
    return go(a+1, t1, t2);
  }
  if(l2) {
    if(bs[a] == '?') {
      t2 += 9;
    }
    return go(a+1, t1, t2);
  }

  auto r1 = go(a+1, t1, t2);
  for(int i=0;i<10;i++) {
    for(int j=0;j<10;j++) {
      auto tmp = go(a+1, t1 + (as[a] == '?' ? i : 0), 
          t2 + (bs[a] == '?' ? j : 0));
      if(comp(tmp, r1)) r1 = tmp;
      if(bs[a] != '?') break;
    }
    if(as[a] != '?') break;
  }
  return r1;
}

void process(void) {
  scanf(" %s %s", as, bs);
  len = strlen(as);
  auto tmp = go(0, 0, 0);
  cout << setfill('0') << setw(len) << tmp.first << " " << setfill('0') << setw(len) << tmp.second << endl;
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
