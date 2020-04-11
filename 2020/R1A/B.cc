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
      if(right) {
        for(int i=1;i<=row;i++) cout << row << " " << i << endl;
      } else {
        for(int i=row;i>=1;i--) cout << row << " " << i << endl;
      }
      return true;
    }
  } else {
    if(check(n2 - 1, row - 1, right)) {
      if(right) {
        cout << row << " " << row << endl;
      } else {
        cout << row << " " << 1 << endl;
      }
      return true;
    }
  }
  return false;
}

void process() {
  scanf(" %lld", &n);
  for(int i=1;i<=63;i++) {
    LL n2 = n;
    for(int j=1;j<=i;j++) {
      n2 -= cc[i][j];
      if(check(n2, i, false)) {
        for(int k=1;k<=j;k++) {
          cout << i << " " << k << endl;
        }
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

  int T;
  scanf(" %d", &T);
  for(int i=1;i<=T;i++) {
    printf("Case #%d:\n", i);
    process();
  }
  return 0;
}
