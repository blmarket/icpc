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
long long n;

bool check(LL n2, int row, bool right) {
  if(row == 0) {
    return !!n2;
  }
  if(n2 >= (1LL << row)) {
    if (check(n2 - (1LL << row), row - 1, !right)) {
      return true;
    }
  } else {
    if(check(n2 - 1, row - 1, right)) {
      return true;
    }
  }
  return false;
}

void process() {
  // scanf(" %lld", &n);
  n += 1;
  for(int i=1;i<=63;i++) {
    LL n2 = n;
    for(int j=1;j<=i;j++) {
      n2 -= cc[i][j];
      if(check(n2, i, false)) {
        // cout << "FOUND" << endl;
        return;
      }
    }
  }
  cout << "FAIL" << endl;
}

int main(void) {
  cc[1][1] = 1;
  for(int i=2;i<=500;i++) {
    for(int j=1;j<=i;j++) {
      cc[i][j] = cc[i-1][j-1] + cc[i-1][j];
    }
  }
  for(int i=0;i<100;i++) {
    cout << cc[60][i] << " ";
  }
  cout << endl;

  for(int i=0;i<10000000;i++) process();
  // int T;
  // scanf(" %d", &T);
  // for(int i=1;i<=T;i++) {
  //   printf("Case #%d:\n", i);
  //   process();
  // }
  // return 0;
}
