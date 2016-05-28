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

int n,r,p,s;

const char *rps = "PRS";

int vec[5000];
string ret;

bool check() {
  for(int i=n*2-1;i>=3;i-=2) {
    if(vec[i] == vec[i-1]) {
      return false;
    }
    switch(vec[i] + vec[i-1]) {
      case 1: vec[i/2] = 0; break;
      case 2: vec[i/2] = 2; break;
      case 3: vec[i/2] = 1; break;
    }
  }
  return true;
}

void go(int a) {
  if(a == n*2) {
    if(check()) {
      string tmp;
      for(int i=n;i<n*2;i++) {
        tmp += rps[vec[i]];
      }
      if(ret.size() == 0 || ret > tmp) ret = tmp;
    }
    return;
  }

  if(p) {
    p--;
    vec[a] = 0;
    go(a+1);
    p++;
  }
  if(r) {
    r--;
    vec[a] = 1;
    go(a+1);
    r++;
  }
  if(s) {
    s--;
    vec[a] = 2;
    go(a+1);
    s++;
  }
}

void process() {
  ret.clear();
  scanf(" %d %d %d %d",&n, &r,&p,&s);

  pair<int, string> cur[3], nex[3];
  cur[0] = mp(p, "P");
  cur[1] = mp(r, "R");
  cur[2] = mp(s, "S");

  auto concat = [&](const string &a, const string &b) {
    if(a<b) return a + b;
    return b + a;
  };

  while(n) {
    for(int i=0;i<3;i++) {
      cout << cur[i].first << " " << cur[i].second << endl;
      if(cur[i].first < 0) {
        cout << "IMPOSSIBLE" << endl;
        return;
      }
    }

    n--;
    int c1 = (cur[0].first + cur[1].first - cur[2].first) / 2;
    int c2 = (cur[0].first + cur[2].first - cur[1].first) / 2;
    int c3 = (cur[1].first + cur[2].first - cur[0].first) / 2;
    nex[0] = mp(c1, concat(cur[0].second, cur[1].second));
    nex[1] = mp(c2, concat(cur[1].second, cur[2].second));
    nex[2] = mp(c3, concat(cur[0].second, cur[2].second));

    for(int i=0;i<3;i++) cur[i] = nex[i];
  }

  for(int i=0;i<3;i++) {
    if(cur[i].first < 0) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
  }

  for(int i=0;i<3;i++) {
    if(cur[i].first == 1) {
      cout << cur[i].second << endl;
      return;
    }
  }
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
