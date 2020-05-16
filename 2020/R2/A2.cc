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
#include <cmath>

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

LL estimate1(LL sz) {
  LL tmp = max(0LL, (LL)sqrt(sz * 2) - 1);
  while(1) {
    if ((tmp+1) * (tmp+2) / 2 > sz) return tmp;
    tmp++;
  }
}

void process() {
  LL L, R;
  scanf(" %lld %lld", &L, &R);
  LL t1;
  if(L >= R) {
    t1 = estimate1(L-R);
    L -= t1 * (t1+1) / 2;
  } else {
    t1 = estimate1(R-L);
    R -= t1 * (t1+1) / 2;
  }
  bool swapped = false;
  if(L >= R) {
    swap(L, R);
    swapped = true;
  }
  cerr << t1 << " " << L << " " << R << " " << swapped << endl;
  LL s = 0, e = 1LL<<31;
  while(s+1 < e) {
    LL m = (s+e) / 2;
    LL m1 = (t1 + 1) * (m/2) + (m/2) * (m/2);
    LL m2 = (m+1)/2;
    LL m3 = (t1 + 2) * m2 + m2 * m2;
    cerr << m << " " << L-m1 << " " << R-m3 << endl;
    if(L-m1 < 0 || R-m3 < 0) {
      e = m;
    } else {
      s = m;
    }
  }
  LL m = s;
  LL m1 = (t1 + 1) * (m/2) + (m/2) * (m/2);
  LL m2 = (m+1)/2;
  LL m3 = (t1 + 2) * m2 + m2 * m2;
  L -= m1;
  R -= m3;
  if(swapped) swap(L, R);
  cout << t1 + s << " " << L << " " << R << endl;
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
