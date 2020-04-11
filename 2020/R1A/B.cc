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

long long cc[505][505];

int main(void) {
  cc[1][1] = 1;
  for(int i=2;i<=500;i++) {
    for(int j=1;j<=i;j++) {
      cc[i][j] = cc[i-1][j-1] + cc[i-1][j];
    }
  }
  for(int i=0;i<100;i++) {
    cout << cc[50][i] << " ";
  }
  cout << endl;
  // int T;
  // scanf(" %d", &T);
  // for(int i=1;i<=T;i++) {
  //   printf("Case #%d: ", i);
  //   process();
  // }
  // return 0;
}
