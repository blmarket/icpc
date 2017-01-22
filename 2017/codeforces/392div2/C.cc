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

int N, M, x, y;
LL K;

int main(void) {
  cin >> N >> M >> K >> x >> y;
  LL pn = (N-1) * M;
  LL np = K / pn;
  LL nr = K % pn;

  auto fn = [&](int x, int y) -> LL {
    LL ret = 0;
    if(x == 0) {
    }
  };

  LL r1,r2,r3;
  if (K <= N * M) {
    r1 = 1;
  } else {
    r1 = np + 1;
  }

  if (K < N * M) {
    r2 = 0;
  } else {
  }
}
