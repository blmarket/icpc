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

int n, k;
VVI b;

void process() {
  scanf(" %d %d", &n, &k);
  b = VVI(n, VI(n, -1));
  for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++) {
      b[i][j] = ((i-j+n) % n) + 1;
    }
  }

  int sum;
  while(true) {
a:  
    sum = 0;
    for(int i=0;i<n;i++) sum += b[i][i];
    if(sum == k) break;

    for(int t=0;t<500000;t++) {
      int n1 = rand() % n;
      int n2 = rand() % n;
      int tmp = sum - b[n1][n1] - b[n2][n2] + b[n1][n2] + b[n2][n1];
      if(abs(k - sum) > abs(k - tmp)) {
        swap(b[n1], b[n2]);
        goto a;
      }
    }
    break;
  }
  if(sum != k) {
    cout << "IMPOSSIBLE" << endl;
    return;
  }
  cout << "POSSIBLE" << endl;
  for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++) 
      cout << b[i][j] << " ";
    cout << endl;
  }
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
