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
  x--;y--;
  LL pn = (N*2-2) * M;
  LL np = K / pn;
  LL nr = K % pn;

  cerr << pn << " " << np << " " << nr << endl;

  auto fn = [&](int x, int y) -> LL {
    LL ret = 0;
    if(x == 0 || x == N - 1) {
      ret = np;
    } else {
      ret = np * 2;
    }

    LL rr = nr;
    for(int i=0;i<N;i++) {
      for(int j=0;j<M;j++) {
        if(rr == 0) return ret;
        rr--;
        if(x == i && y == j) {
          ret++;
        }
      }
    }
    for(int i=N-2;i>=0;i--) {
      for(int j=0;j<M;j++) {
        if(rr == 0) return ret;
        rr--;
        if(x == i && y == j) {
          ret++;
        }
      }
    }
  };

  LL r1,r2,r3;
  if(N == 1) {
    r1 = fn(0,0);
  } else {
    r1 = max(fn(1,0), fn(N-2,0));
  }
  r2 = min(fn(0,M-1), fn(N-1,M-1));
  r3 = fn(x,y);
  cout << r1 << " " << r2 << " " << r3 << endl;
}
