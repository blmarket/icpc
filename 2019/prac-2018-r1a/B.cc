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

int r,b,c;
int m[1005], s[1005], p[1005];

void process() {
  scanf(" %d %d %d", &r, &b, &c);
  for(int i=0;i<c;i++) {
    scanf(" %d %d %d", &m[i], &s[i], &p[i]);
  }
  LL ss = 0, e = 3e18;
  auto chk = [&](LL target) -> bool {
    vector<LL> cs;
    for(int i=0;i<c;i++) {
      cs.pb(min((target - p[i]) / s[i], (LL)m[i]));
    }
    sort(cs.rbegin(), cs.rend());
    cerr << "SS : ";
    for(int i=0;i<cs.size();i++) cerr << cs[i] << " ";
    cerr << endl;
    LL sum = 0;
    for(int i=0;i<r;i++) sum += cs[i];
    return sum >= b;
  };

  while(ss + 1 < e) {
    LL target = (ss+e+1) / 2;
    cerr << ss << " " << e << " " << target << " " << chk(target) << endl;
    if(chk(target)) {
      e = target;
    } else {
      ss = target;
    }
  }
  cout << e << endl;
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
