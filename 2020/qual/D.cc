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
int b[55][55];

void process() {
  scanf(" %d %d", &n, &k);
  for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++) {
      b[i][j] = ((i+j) % n) + 1;
    }
  }

  for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++) {
      cout << b[i][j] << " ";
    }
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
