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

char output[32];

bool chk(int s, int t, int x, int y) {
  if(s == -1) {
    return x == 0 && y == 0;
  }
  if(abs(x) > abs(y)) {
    if(x < 0) {
      output[s] = 'W';
      return chk(s-1, t>>1, x+t, y);
    } else {
      output[s] = 'E';
      return chk(s-1, t>>1, x-t, y);
    }
  } else {
    if(y < 0) {
      output[s] = 'S';
      return chk(s-1, t>>1, x, y+t);
    } else {
      output[s] = 'N';
      return chk(s-1, t>>1, x, y-t);
    }
  }
}

void process() {
  int x, y;
  scanf(" %d %d", &x, &y);
  int t1 = 1;
  for(int i=0;i<31;i++) {
    output[i+1] = 0;
    if(chk(i, t1, x, y)) {
      cout << output << endl;
      return;
    }
    t1 <<= 1;
  }
  cout << "IMPOSSIBLE" << endl;
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
