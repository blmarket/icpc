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

char str[105];

void process() {
  scanf(" %s", str);
  int n = strlen(str);
  int cur = 0;
  for(int i=0;i<n;i++) {
    int v = str[i] - '0';
    while(cur < v) {
      cout << '(';
      cur++;
    }
    while(cur > v) {
      cout << ')';
      cur--;
    }
    cout << v;
  }
  while(cur > 0) {
    cout << ')';
    cur--;
  }
  cout << endl;
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
