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
  n = (1<<n);
  go(n);
  if(ret.size()) {
    cout << ret << endl;
  } else {
    cout << "IMPOSSIBLE" << endl;
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
