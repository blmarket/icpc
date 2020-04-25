#include <iostream>
#include <functional>
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

int r, s;
vector<PII> v;

vector<PII> ret;

void process() {
  scanf(" %d %d", &r, &s);
  v.clear();
  for(int i=0;i<s;i++) {
    for(int j=0;j<r;j++) {
      v.pb(mp(j, 1));
    }
  }

  ret.clear();

  while(v.size() > r) {
    if(v.size() == r+1) {
      // r 1 2 3 ...
      break;
    }
    for(auto it: v) cout << it.first << " "; cout << endl;
    int c1 = v[0].second + v[1].second;
    int c2 = 0;
    for(int i=2;i+1<v.size();i++) {
      c2 += v[i].second;
      if(v[i].first == v[0].first && v[i+1].first == v[1].first) {
        ret.pb(mp(c1, c2));
        v[i].second += v[0].second;
        v[i+1].second += v[1].second;
        rotate(v.begin(), v.begin() + 2, v.end());
        v.resize(v.size() - 2);
        break;
      }
    }
  }
  for(auto it: v) cout << it.first << " "; cout << endl;
  cout << ret.size() << endl;
  for(auto it : ret) cout << it.first << " " << it.second << endl;
}

// 123412341234
// 123123412344
// 123123123444
// 121231233444
// 121212333444
// 112122333444
// 111222333444

// 123451234512345
// 345112234512345
// 511223344512345
// 112233445512345
// 334455111222345
// 551112223334445
// 111222333444555



int main(void) {
    int T;
    scanf(" %d", &T);
    for(int i=1;i<=T;i++) {
        printf("Case #%d: ", i);
        process();
    }
    return 0;
}
